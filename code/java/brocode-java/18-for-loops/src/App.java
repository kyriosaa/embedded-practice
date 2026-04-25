public class App {
    public static void main(String[] args) throws Exception {
        
        // for loop = execute some code a CERTAIN amount of times

        int countdownStart = 10;

        for(int i = countdownStart; i > 0; i--) {
            System.out.println(i);
            Thread.sleep(1000);
        }
        
        System.out.println("HAPPY NEW YEAR");
    }
}
