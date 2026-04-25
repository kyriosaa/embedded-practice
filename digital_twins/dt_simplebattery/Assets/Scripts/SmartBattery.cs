using UnityEngine;
using UnityEngine.UI;
using uPLibrary.Networking.M2Mqtt;
using uPLibrary.Networking.M2Mqtt.Messages;
using System.Text;

public class SmartBattery : MonoBehaviour
{
    private MqttClient client;
    public string broker = "broker.hivemq.com";
    public string tempTopic = "thesis/bess/temp";

    // Drag your Text UI here
    public Text tempDisplayText;

    // Internal variable to store the latest data
    private float currentTemp = 25.0f;
    private Renderer batteryRenderer;

    void Start()
    {
        batteryRenderer = GetComponent<Renderer>();

        // 1. Connect to Public Broker
        // We use a random ID so we don't get kicked off
        client = new MqttClient(broker);
        client.MqttMsgPublishReceived += MessageReceived;
        string clientId = "Unity_Student_" + System.Guid.NewGuid().ToString();
        client.Connect(clientId);

        // 2. Subscribe
        client.Subscribe(new string[] { tempTopic }, new byte[] { MqttMsgBase.QOS_LEVEL_AT_MOST_ONCE });

        Debug.Log("Connected to MQTT! Waiting for data...");
    }

    // This happens on a different thread! Be careful.
    void MessageReceived(object sender, MqttMsgPublishEventArgs e)
    {
        string msg = Encoding.UTF8.GetString(e.Message);
        Debug.Log("Received: " + msg);

        // Parse the data
        float.TryParse(msg, out currentTemp);
    }

    void Update()
    {
        // 3. Visualization Logic (Runs every frame)

        // A. Update the UI Text
        if (tempDisplayText != null)
            tempDisplayText.text = currentTemp.ToString("F1") + " °C";

        // B. Color Gradient (20C = Green, 100C = Red)
        float t = Mathf.InverseLerp(20f, 100f, currentTemp);
        Color targetColor = Color.Lerp(Color.green, Color.red, t);

        // Apply to the material
        batteryRenderer.material.color = targetColor;

        // Optional: Make it glow if hot (Emission)
        if (currentTemp > 80)
            batteryRenderer.material.SetColor("_EmissionColor", targetColor * 1.5f); // Glow!
        else
            batteryRenderer.material.SetColor("_EmissionColor", Color.black);
    }

    void OnApplicationQuit()
    {
        if (client != null && client.IsConnected)
            client.Disconnect();
    }
}