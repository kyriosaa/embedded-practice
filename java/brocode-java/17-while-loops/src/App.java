import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        // while loop = repeat some code forever while some condition remains true

        Scanner scanner = new Scanner(System.in);

        int age;
        
        // --- while loop ---
        System.out.print("Enter your age: ");
        age = scanner.nextInt();
        
        while(age < 0) {
            System.out.println("Your age can't be negative!");
            System.out.print("Enter your age: ");
            age = scanner.nextInt();
        }
        // ------------------
        
        // --- do while loop ---
        do { 
            if(age < 0) {
                System.out.println("Your age can't be negative!");
            }
            System.out.print("Please enter your age: ");
            age = scanner.nextInt();
        } while (age < 0);
        // ---------------------

        System.out.printf("You are %d years old", age);

        scanner.close();
    }
}
