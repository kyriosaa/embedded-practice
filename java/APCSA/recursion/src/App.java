// Fibonacci Sequence using Recursion
// Fn = Fn-1 + Fn-2
// 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

import java.util.Scanner;

public class App {
    public static int fibonacci(int n) {
        // Base case:    F(0) = 0      F(1) = 1
        if(n <= 1) {
            return n;
        }
        
        // Recursive case:
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    public static void printFibonacci(int n, int current) {
        // Stop when we've printed out all required terms
        if(current >= n) {
            return;
        }
        System.out.println(fibonacci(current));
        printFibonacci(n, current + 1);
    }
    
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter a number: ");
        int numberOfTerms = scanner.nextInt();
        
        System.out.println("\nFibonacci sequence up to " + numberOfTerms + " terms:");
        printFibonacci(numberOfTerms, 0);
        
        scanner.close();
    }
}

// fibonacci(5) = f(4) + f(3)
// fibonacci(4) = f(3) + f(2)
// fibonacci(3) = f(2) + f(1)
// fibonacci(2) = f(1) + f(0)
// fibonacci(1) = 1
// fibonacci(0) = 0
// therefore...
// fibonacci(2) = 1 + 0 = 1
// fibonacci(3) = 1 + 1 = 2
// fibonacci(4) = 2 + 1 = 3
// fibonacci(5) = 3 + 2 = 5