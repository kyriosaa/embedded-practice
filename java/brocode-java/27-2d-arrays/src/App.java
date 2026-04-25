public class App {
    public static void main(String[] args) throws Exception {
        
        // 2D array = An array where each element is an array.
        //            Useful for storing a matrix of data.

        String[] fruits = {"apple", "orange", "banana"};
        String[] vegetables = {"potato", "onion", "carrot"};
        String[] meats = {"chicken", "pork", "beef", "fish"};

        String[][] groceries = {fruits, vegetables, meats};

        groceries[0][0] = "pineapple";
        groceries[1][2] = "celery";
        groceries[2][3] = "lamb";

        for(String[] foods : groceries) {
            for (String food : foods) {
                System.out.print(food + " ");
            }
            System.out.println();
        }

        // --------------------------------------------------
        System.out.println();
        // --------------------------------------------------

        char[][] telephone = {{'1', '2', '3'},
                              {'4', '5', '6'},
                              {'7', '8', '9'},
                              {'*', '0', '#'}};

        for(char[] row : telephone) {
            for(char number : row) {
                System.out.print(number + " ");
            }
            System.out.println();
        }
    }
}
