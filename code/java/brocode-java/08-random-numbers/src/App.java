import java.util.Random;

public class App {
    public static void main(String[] args) throws Exception {
        Random random = new Random();

        int number1;
        double number2;
        boolean number3;

        number1 = random.nextInt(1, 7);      // outer bound is exclusive -> 1-6 in this case
        number2 = random.nextDouble();                    // generates number between 0 and 1
        number3 = random.nextBoolean();                   // true/false

        System.out.println(number1);
        System.out.println(number2);
        System.out.println(number3);
        if(number3) {
            System.out.println("Heads");
        } else {
            System.out.println("Tails");
        }
    }
}
