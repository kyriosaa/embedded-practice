public class App {
    public static void main(String[] args) throws Exception {
        
        // Car car1 = new Car("Mustang", "Red");
        // Car car2 = new Car("Corvette", "Blue");
        // Car car3 = new Car("Charger", "Yellow"); 

        Car[] cars = {new Car("Mustang", "Red"), 
                      new Car("Corvette", "Blue"), 
                      new Car("Charger", "Yellow")};

        for(int i = 0; i < cars.length; i++) {
            cars[i].drive();
        }

        System.out.println();

        for(Car car : cars) {
            car.drive();
        }

    }
}
