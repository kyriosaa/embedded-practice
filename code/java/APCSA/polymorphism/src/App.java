public class App {
    public static void main(String[] args) throws Exception {
        
        // POLY = MANY
        // MORPH = SHAPE

        Car car = new Car();
        Bike bike = new Bike();
        Boat boat = new Boat();

        Vehicle[] vehicles = {car, bike, boat};

        // vehicles[1].go();

        // car.go();
        // bike.go();
        // boat.go();

        for(Vehicle vehicle : vehicles) {
            vehicle.go();
        }
    }
}
