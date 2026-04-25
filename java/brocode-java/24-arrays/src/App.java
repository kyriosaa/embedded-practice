import java.util.Arrays;

public class App {
    public static void main(String[] args) throws Exception {
        
        // array = a collection of values of the same data type
        //         * think of it as a variable that can store more than 1 value *

        String[] fruits = {"apple", "orange", "banana", "coconut"};

        // fruits[0] = "pineapple";
        // int numOfFruits = fruits.length;

        Arrays.sort(fruits);  // sorts alphabetically
        Arrays.fill(fruits, "pineapple");

        for(int i = 0; i < fruits.length; i++) {
            System.out.println(fruits[i]);
        }

        System.out.println();

        // enhanced for loop
        for(String fruit : fruits) {
            System.out.println(fruit);
        }
    }
}
