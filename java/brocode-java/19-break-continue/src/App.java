public class App {
    public static void main(String[] args) throws Exception {
        
        
        // break    = break out of a loop (STOP)
        // continue = skip current iteration of a loop (SKIP)

        for(int i = 1; i <= 10; i++) {
            if(i == 5) {
                continue;
            } else if(i == 9) {
                break;
            }
            System.out.println(i);
            Thread.sleep(100);
        }
    }
}
