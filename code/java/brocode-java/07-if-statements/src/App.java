
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        // if statement = performs a block of code if its condition is true

        Scanner scanner = new Scanner(System.in);

        String name;
        int age;
        boolean isStudent;

        System.out.print("Enter your name: ");
        name = scanner.nextLine();
        System.out.print("Enter your age: ");
        age = scanner.nextInt();
        System.out.print("Are you a student? (true/false): ");
        isStudent = scanner.nextBoolean();

        // GROUP 1
        if(name.isEmpty()) {
            System.out.println("You didn't enter your name! ❌");
        } else {
            System.out.println("Hello " + name + "! 👋");
        }

        // GROUP 2
        if(age >= 65) {
            System.out.println("You are a senior. 🧓🏽");
        } else if(age >= 18) {
            System.out.println("You are an adult. 🧑🏽");
        } else if(age < 0) {
            System.out.println("You are not alive! 💀");
        } else if(age == 0) {
            System.out.println("You are a baby. 👶🏽");
        } else {
            System.out.println("You are a child. 🧒🏽");
        }

        // GROUP 3
        if(isStudent) {
            System.out.println("You are enrolled as a student! 🧑🏽‍🎓");
        } else {
            System.out.println("You are not enrolled! ❌");
        }
    }
}
