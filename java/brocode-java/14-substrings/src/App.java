import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        // .substring() = a method used to extract a portion of a string
        //                string.substring(start, end)

        Scanner scanner = new Scanner(System.in);
        
        String email;
        System.out.print("Enter your email: ");
        email = scanner.nextLine();

        if(email.contains("@")) {
            String username = email.substring(0, email.indexOf("@"));
            String domain = email.substring(email.indexOf("@"));
            
            System.out.println();
            System.out.println(username);
            System.out.println(domain);
        } else {
            System.out.println();
            System.out.println("Emails must contain an @ symbol.");
        }


        scanner.close();
    }
}
