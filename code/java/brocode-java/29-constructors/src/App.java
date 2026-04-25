public class App {
    public static void main(String[] args) throws Exception {
        
        
        // constructor = A special method to initialize objects.
        //               You can pass arguments to a constructor
        //               and set up initial values.

        Student student1 = new Student("Spongebob", 30, 3.2);
        Student student2 = new Student("Patrick", 34, 1.5);
        Student student3 = new Student("Sandy", 27, 4.0);

        System.out.printf("%s | %d | %.2f | %b\n", student1.name, student1.age, student1.gpa, student1.isEnrolled);
        System.out.printf("%s | %d | %.2f | %b\n", student2.name, student2.age, student2.gpa, student2.isEnrolled);
        System.out.printf("%s | %d | %.2f | %b\n", student3.name, student3.age, student3.gpa, student3.isEnrolled);

        student1.study();
        student2.study();
        student3.study();
    }
}
