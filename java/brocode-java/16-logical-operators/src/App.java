public class App {
    public static void main(String[] args) throws Exception {
        
        // && = AND
        // || = OR
        // !  = NOT

        double temp = 20;

        if(temp <= 30 && temp >= 0) {
            System.out.println("The weather is nice!");
        } else {
            System.out.println("The weather is terrible!");
        }
    }
}
