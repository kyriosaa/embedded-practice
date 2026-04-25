public class App {

    static int y = 3;  // GLOBAL

    public static void main(String[] args) throws Exception {
        
        // variable scope = where a variable can be accessed

        int x = 1;  // LOCAL
        
        System.out.println("main(x) = " + x);
        System.out.println("main(y) = " + y);
        doSomething();
    }
    
    static void doSomething() {
        int x = 2;  // LOCAL

        System.out.println("doSomething(x) = " + x);
        System.out.println("doSomething(y) = " + y);
    }
}
