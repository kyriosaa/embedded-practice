public class App {
    public static void main(String[] args) throws Exception {
        boolean isStudent = true;
        boolean isSenior = true;
        double price = 9.99;

        System.out.printf("The ticket price is: $%.2f\n", price);

        if(isStudent) {
            if(isSenior) {
                System.out.println("You get a student discount of 10%");
                System.out.println("You get a senior discount of 20%");
                price *= 0.7;
                System.out.printf("Updated ticket price: $%.2f\n", price);
            } else {
                System.out.println("You get a student discount of 10%");
                price *= 0.9;
                System.out.printf("Updated ticket price: $%.2f\n", price);
            }
        } else {
            if(isSenior) {
                System.out.println("You get a senior discount of 20%");
                price *= 0.8;
                System.out.printf("Updated ticket price: $%.2f\n", price);
            } else {
                price *= 1.0;
            }
        }

    }
}
