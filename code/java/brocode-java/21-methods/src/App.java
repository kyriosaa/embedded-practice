public class App {
    public static void main(String[] args) throws Exception {

        // method = a block of reusable code that is executed when called ()

        String name = "Kin";
        int age = 23;
        String fulName = getFullName("Spongebob", "Squarepants");

        happyBirthday(name, age);
        happyBirthday(name, age);
        happyBirthday(name, age);

        System.out.println(square(3));
        System.out.println(cube(3));
        System.out.println(fulName);

        if(ageCheck(age)) {
            System.out.println("You may sign up for a credit card!");
        } else {
            System.out.println("You must be over the age of 18 to sign up!");
        }
    }
    
    static void happyBirthday(String name, int age) {
        System.out.println("Happy birthday to you!");
        System.out.printf("Happy birthday dear %s!\n", name);
        System.out.printf("You are %d years old!\n", age);
        System.out.println("Happy birthday to you!");
        System.out.println();
    }

    static double square(double number) {
        return number * number;
    }

    static double cube(double number) {
        return Math.pow(number, 3);
    }

    static String getFullName(String first, String last) {
        return first + " " + last;
    }

    static boolean ageCheck(int age) {
        if(age >= 18) {
            return true;
        } else {
            return false;
        }
    }
}
