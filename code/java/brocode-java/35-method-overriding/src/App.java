public class App {
    public static void main(String[] args) throws Exception {
        
        // method overriding = When a subclass provides its own implementation
        //                     of a method that is already defined.
        //                     Alllows for code reusability and give specific implementations.

        Dog dog = new Dog();
        Cat cat = new Cat();
        Fish fish = new Fish();

        dog.move();
        cat.move();
        fish.move();
    }
}
