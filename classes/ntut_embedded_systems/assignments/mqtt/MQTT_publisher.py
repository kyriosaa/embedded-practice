from machine import Pin, ADC
from time import sleep
import network
from umqtt.simple import MQTTClient
import config

# Initialize ADC. The internal temperature sensor is connected to channel 4
sensor_temp = ADC(4)
# Conversion factor: Convert 16-bit reading (0-65535) to voltage (0-3.3V)
conversion_factor = 3.3 / 65535

# Constants for MQTT Topics
QOS0_TOPIC = 'pico/temp/qos0'
QOS1_TOPIC = 'pico/temp/qos1'
QOS2_TOPIC = 'pico/temp/qos2'

# MQTT Parameters
MQTT_SERVER = config.mqtt_server
MQTT_PORT = 0
MQTT_USER = config.mqtt_username
MQTT_PASSWORD = config.mqtt_password
MQTT_CLIENT_ID = b"raspberrypi_pico2w"
MQTT_KEEPALIVE = 60
MQTT_SSL = True   # set to False if using local Mosquitto MQTT broker
MQTT_SSL_PARAMS = {'server_hostname': MQTT_SERVER}

def get_sensor_readings():
    reading = sensor_temp.read_u16()
    voltage = reading * conversion_factor
    
    temperature = 27 - (voltage - 0.706) / 0.001721
    print("Temperature: {:.2f} °C".format(temperature))

    return temperature

def initialize_wifi(ssid, password):
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)

    # Connect to the network
    wlan.connect(ssid, password)

    # Wait for Wi-Fi connection
    connection_timeout = 10
    while connection_timeout > 0:
        if wlan.status() >= 3:
            break
        connection_timeout -= 1
        print('Waiting for Wi-Fi connection...')
        sleep(1)

    # Check if connection is successful
    if wlan.status() != 3:
        return False
    else:
        print('Connection successful!')
        network_info = wlan.ifconfig()
        print('IP address:', network_info[0])
        return True

def connect_mqtt():
    try:
        client = MQTTClient(client_id=MQTT_CLIENT_ID,
                            server=MQTT_SERVER,
                            port=MQTT_PORT,
                            user=MQTT_USER,
                            password=MQTT_PASSWORD,
                            keepalive=MQTT_KEEPALIVE,
                            ssl=MQTT_SSL,
                            ssl_params=MQTT_SSL_PARAMS)
        client.connect(clean_session=False)
        return client
    except Exception as e:
        print('Error connecting to MQTT:', e)
        raise  # Re-raise the exception to see the full traceback

def publish_mqtt(topic, value, qos):
    try:
        client.publish(topic, value, qos=qos)
        print(f"Published to {topic} with QoS {qos}")
    except AssertionError:
        print(f"QoS {qos} not supported by library. Skipped.")
    except Exception as e:
        print(f"Failed to publish: {e}")
        raise
    print(topic)
    print(value)
    print(qos)
    print("Publish Done")

initialize_wifi(config.wifi_ssid, config.wifi_password)
client = None
while True:
    try:
        if client is None:
            client = connect_mqtt()

        # Read sensor data
        temperature = get_sensor_readings()
        msg = str(temperature)

        # Publish QoS 
        publish_mqtt(QOS0_TOPIC, msg, qos=0)
        publish_mqtt(QOS1_TOPIC, msg, qos=1)
        publish_mqtt(QOS2_TOPIC, msg, qos=2)

        # Delay 5 sec
        sleep(5)
    except OSError as e:
        print('Connection error: ', e)
        print('Reconnecting...')
        client = None
        sleep(2)