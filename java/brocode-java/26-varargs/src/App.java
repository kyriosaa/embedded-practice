public class App {
    public static void main(String[] args) throws Exception {
        
        // varargs = Allow a method to accept a varying number of arguments.
        //           Makes methods more flexible, no need for overloaded methods.
        //           Java will pack the arguments into an array
        //           ... (ellipsis)

        System.out.println(add(1, 2, 3, 4));
        System.out.println(average(1, 2, 3, 4));
    }

    static int add(int... numbers) {
        int sum = 0;

        for(int number : numbers) {
            sum += number;
        }

        return sum;
    }

    static double average(double... numbers) {
        double sum = 0;

        if(numbers.length == 0) {
            return 0;
        } else {
            for(double number : numbers) {
                sum += number;
            }
    
            return sum / numbers.length;
        }        
    }
}
