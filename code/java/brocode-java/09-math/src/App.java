import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner =  new Scanner(System.in);

        System.out.println(Math.PI);
        System.out.println(Math.E);
        System.out.println(Math.pow(2, 3));
        System.out.println(Math.abs(-5));
        System.out.println(Math.sqrt(9));
        System.out.println(Math.round(3.14));
        System.out.println(Math.ceil(3.14));
        System.out.println(Math.floor(3.99));
        System.out.println(Math.max(10, 20));
        System.out.println(Math.min(10, 20));

        System.out.println();

        // HYPOTENUSE c = Math.sqrt((a^2) + (b^2))
        double a;
        double b;
        double c;

        System.out.print("Enter the length of side A: ");
        a = scanner.nextDouble();

        System.out.print("Enter the length of side B: ");
        b = scanner.nextDouble();

        c = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));

        System.out.println("The hypotenuse (C) is: " + c);

        scanner.close();
    }
}
