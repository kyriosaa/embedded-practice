public class App {
    public static int powerTwo(int n) {
        if (n == 0) {
            return 1;
        } else {
            System.out.println("Calling powerTwo(" + (n - 1) + ")");
            return 2 * powerTwo(n - 1);
        }
    }

    // 2 * powerTwo(4)
    //      2 * powerTwo(3)
    //          2 * powerTwo(2)
    //              2 * powerTwo(1)
    //                  2 * powerTwo(0)  <- base case = return 1
    //                  2 * 1 = return 2
    //              2 * 2 = return 4
    //          2 * 4 = return 8
    //      2 * 8 = return 16
    // 2 * 16 = return 32

    public static void main(String[] args) {
        int n = 4;
        System.out.println("\nResult: " + powerTwo(n));
    }
}
