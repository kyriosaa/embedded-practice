import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        // calculate the area of a rectangle
        double width = 0;
        double height = 0;
        double area = 0;
        
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter width: ");
        width = scanner.nextDouble();

        System.out.print("Enter height: ");
        height = scanner.nextDouble();

        area = width * height;

        System.out.println("Area is: " + area + " cm squared");

        // System.out.print("Enter your name: ");
        // String name = scanner.nextLine();

        // System.out.print("Enter your age: ");
        // int age = scanner.nextInt();

        // System.out.print("What is your gpa?: ");
        // double gpa = scanner.nextDouble();

        // System.out.print("Are you a student? (true/false): ");
        // boolean isStudent = scanner.nextBoolean();

        // System.out.println("");
        // System.out.println("Your name is " + name);
        // System.out.println("You are " + age + " years old");
        // System.out.println("Your gpa is: " + gpa);
        // if(isStudent) {
        //     System.out.println("You are enrolled as a student!");
        // } else {
        //     System.out.println("You are not enrolled!");
        // }

        scanner.close();
    }
}
