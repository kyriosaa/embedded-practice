public class App {
    public static void main(String[] args) throws Exception {
        
        // overloaded constructors = Allow a class to have multiple constructors
        //                           with different parameter lists.
        //                           Enable objects to be initialized in various ways.

        User user1 = new User("Spongebob");
        User user2 = new User("Patrick", "pstar@aol.com");
        User user3 = new User("Sandy", "scheeks@gmail.com", 27);
        User user4 = new User();

        System.out.printf("%s | %s | %d\n", user1.username, user1.email, user1.age);
        System.out.printf("%s | %s | %d\n", user2.username, user2.email, user2.age);
        System.out.printf("%s | %s | %d\n", user3.username, user3.email, user3.age);
        System.out.printf("%s | %s | %d\n", user4.username, user4.email, user4.age);
    }
}
