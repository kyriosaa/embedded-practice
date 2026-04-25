import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        // nested loop = A loop inside another loop
        //               Used often in matrices or DS&A

        // for(int i = 1; i <= 3; i++) {
        //     for(int j = 1; j <= 9; j++) {
        //         System.out.print(j + " ");
        //     }
        //     System.out.println();
        // }

        Scanner scanner = new Scanner(System.in);

        int rows;
        int columns;
        char symbol;

        System.out.print("How many rows?: ");
        rows = scanner.nextInt();

        System.out.print("How many columns?: ");
        columns = scanner.nextInt();

        System.out.print("Enter a symbol: ");
        symbol = scanner.next().charAt(0);

        for(int i = 0; i < columns; i++) {
            for(int j = 0; j < rows; j++) {
                System.out.print(symbol);
            }
            System.out.println();
        }

        scanner.close();
    }
}
