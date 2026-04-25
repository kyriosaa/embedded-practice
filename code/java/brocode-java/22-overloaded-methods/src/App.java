public class App {
    public static void main(String[] args) throws Exception {
        
        // overloaded methods = methods that share the same name,
        //                      but different parameters
        //                      signature = name + parameters

        String bread = "flatbread";
        String cheese = "cheddar";
        String topping = "pepperoni";

        String pizza = bakePizza(bread, cheese, topping);
        System.out.println(pizza);
    }

    static String bakePizza(String bread) {
        return bread + " pizza";
    }

    static String bakePizza(String bread, String cheese) {
        return bread + " " + cheese + " pizza";
    }

    static String bakePizza(String bread, String cheese, String topping) {
        return bread + " " + cheese + " pizza with " + topping;
    }
}
