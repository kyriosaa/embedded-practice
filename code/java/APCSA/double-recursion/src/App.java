public class App {
    public static int recursion(int n) {
        if(n == 2 || n == 1) {
            return 2 * n;
        } else {
            return recursion(n - 1) - recursion(n - 2);
        }
    }

    public static void main(String[] args) throws Exception {
        int n = 6;
        System.out.println(recursion(n));
    }
}

//  foo(6)
//      foo(5)
//          foo(4)
//              foo(3)
//                  foo(2) -> BASE
//                  foo(1) -> BASE
//              foo(2) -> BASE
//          foo(3)
//              foo(2) -> BASE
//              foo(1) -> BASE
//      foo(4)
//          foo(3)
//              foo(2) -> BASE
//              foo(1) -> BASE
//          foo(2) -> BASE

//  foo(6) =((-4)-(-2))=-2
//      foo(5) =(-2-2)=-4
//          foo(4) =(2-4)=-2
//              foo(3) =(4-2)=2
//                  foo(2) =4
//                  foo(1) =2
//              foo(2) =4
//          foo(3) =(4-2)=2
//              foo(2) =4
//              foo(1) =2
//      foo(4) =(2-4)=-2
//          foo(3) =(4-2)=2
//              foo(2) =4
//              foo(1) =2
//          foo(2) =4
//
//  foo(6) -> return -2
