public class App {
    public static void main(String[] args) throws Exception {
        
        // Object = An entity that holds data (attributes) and can perform actions (methods).
        //          It is a reference data type.

        Car car = new Car();

        System.out.println(car.make);
        System.out.println(car.model);
        System.out.println(car.year);
        System.out.println(car.price);
        System.out.println(car.isRunning);
        System.out.println();

        if(car.isRunning) {
            System.out.printf("%s is running", car.model);
        } else {
            System.out.printf("%s is not running", car.model);
        }
    }
}
