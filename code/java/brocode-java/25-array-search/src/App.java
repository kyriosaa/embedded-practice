public class App {
    public static void main(String[] args) throws Exception {
        
        int[] numbers = {1, 9, 2, 8, 3, 5, 4};
        int intTarget = 7;

        String[] fruits = {"apple", "orange", "banana"};
        String stringTarget = "orange";

        boolean isFound = false;

        intSearch(numbers, intTarget, isFound);
        stringSearch(fruits, stringTarget, isFound);
    }

    static void intSearch(int[] numbers, int intTarget, boolean isFound) {
        for(int i = 0; i < numbers.length; i++) {
            if(intTarget == numbers[i]) {
                System.out.println("Element found at index: " + i);
                isFound = true;
                break;
            }
        }

        if(!isFound) {
            System.out.println("Element not found in array");
        }
    }

    static void stringSearch(String[] fruits, String stringTarget, boolean isFound) {
        for(int i = 0; i < fruits.length; i++) {
            if(fruits[i].equals(stringTarget)) {
                System.out.println("Element found at index: " + i);
                isFound = true;
                break;
            }
        }

        if(!isFound) {
            System.out.println("Element not found in array");
        }
    }
}
