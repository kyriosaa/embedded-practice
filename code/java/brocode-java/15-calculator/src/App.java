import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        double num1;
        double num2;
        char operator;
        double result = 0;
        boolean validOperation = true;

        System.out.print("Enter first number: ");
        num1 = scanner.nextDouble();

        System.out.print("Enter operation (+ | - | * | / | ^): ");
        operator = scanner.next().charAt(0);

        System.out.print("Enter second number: ");
        num2 = scanner.nextDouble();

        // enhanced switch
        switch(operator) {
            case '+' -> 
                result = num1 + num2;
            case '-' ->
                result = num1 - num2;
            case '*' ->
                result = num1 * num2;
            case '/' ->
                {
                    if(num2 == 0) {
                        System.out.println("Cannot divide by zero!");
                        validOperation = false;
                    } else {
                        result = num1 / num2;
                    }
                }
            case '^' ->
                result = Math.pow(num1, num2);
            default ->
                {
                    System.out.println("Invalid operator!");
                    validOperation = false;
                }
        }

        if(validOperation) {
            System.out.printf("%.2f %c %.2f = %.2f", num1, operator, num2, result);
        } 

        scanner.close();
    }
}
