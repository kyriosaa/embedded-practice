public class App {
    public static void main(String[] args) throws Exception {
        // variable - a reusable container for a value
        //            a variable behaves as if it was the value it contains

        // Primitive - simple value stored directly in memory (stack)
        // Reference - memory address (stack) that points to the (heap)

        // Primitive vs Reference
        // ----------------------
        // int          string
        // double       array
        // char         object
        // boolean

        // 2 steps to creating a variable
        // ------------------------------
        // 1. declaration
        // 2. assignment

        
        // Primitive ---------------------------------------------------------------------
        int age = 23;
        int year = 2025;
        int quantity = 1;

        System.out.println("I am " + age + " years old");
        System.out.println("The year is " + year);
        System.out.println("I want " + quantity + " Nintendo Switch");

        double price = 19.99;
        double gpa = 3.5;
        double temperature = -12.5;

        System.out.println("The price is: $" + price);
        System.out.println("My gpa is: " + gpa);
        System.out.println("Today's temperature is: " + temperature);
        
        char grade = 'A';
        char symbol = '!';
        char currency = '$';

        System.out.println("I got an " + grade + " this semester!");
        System.out.println("I am very fond of the " + symbol + " symbol");
        System.out.println("When talking about global currency, we use the " + currency + " sign");

        boolean isStudent = true;
        boolean forSale = false;
        boolean isOnline = true;

        if(isStudent) {
            System.out.println("You are a student!");
        } else {
            System.out.println("You are not a student!");
        }

        if(forSale) {
            System.out.println("This item is for sale");
        } else {
            System.out.println("This item is not for sale");
        }

        if(isOnline) {
            System.out.println("You are online");
        } else {
            System.out.println("You are not online");
        }
        // ---------------------------------------------------------------------

        System.out.println("");

        // Reference ---------------------------------------------------------------------
        String name = "Kin";
        String food = "tacos";
        String email = "kin@gmail.com";
        String car = "Mustang";
        String color = "Yellow";

        System.out.println("Hello " + name);
        System.out.println("Your favorite food is " + food);
        System.out.println("Send any complaints to " + email);
        System.out.println("Your car is a " + car);
        System.out.println("I really like the color " + color);
        // ---------------------------------------------------------------------
    }
}
