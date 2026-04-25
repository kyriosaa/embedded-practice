import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        String item;
        double price;
        double totalPrice;
        int amount;
        char dollarSymbol = '$';

        System.out.print("What would you like to buy?: ");
        item = scanner.nextLine();
        System.out.print("What is the price for each?: ");
        price = scanner.nextDouble();
        System.out.print("How many would you like?: ");
        amount = scanner.nextInt();

        totalPrice = price * amount;

        System.out.println("");
        System.out.println("You have bought " + amount + " " + item + "(s)");
        System.out.println("Your total is " + dollarSymbol + totalPrice);
    }
}
