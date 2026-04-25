public class App {
    public static void main(String[] args) throws Exception {
        
        // polymorphism = "POLY" = "MANY"
        //                "MORPH" = "SHAPE"
        //                Objects can identify as other objects.
        //                Objects can be treated as objects of a common superclass.

        Car car = new Car();
        Bike bike = new Bike();
        Boat boat = new Boat();

        Vehicle[] vehicles = {car, bike, boat};

        bike.go();
        vehicles[1].go();

        for(Vehicle vehicle : vehicles) {
            vehicle.go();
        }

    }
}
