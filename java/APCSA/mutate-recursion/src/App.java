public class App {
    public static int recursion(int n) {
        if(n <= 0) {
            return 2;
        } else {
            return 2 + recursion(n - 2);
        }
    }

    public static void main(String[] args) throws Exception {
        int n = 5;
        System.out.println(recursion(n));
    }
}

//  foo(5)
//      foo(4)
//          foo(3)
//              foo(2) base = return 4
//          return 8
//      return 16
//  return 32