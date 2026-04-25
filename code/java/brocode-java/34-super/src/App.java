public class App {
    public static void main(String[] args) throws Exception {

        // super = Refers to the parent class (subclass <- superclass).
        //         Used in constructors and method overriding.
        //         Calls the parent constructor to initialize attributes.

        Person person = new Person("Harry", "Potter");
        Student student = new Student("Ron", "Weasley", 3.5);
        Employee employee = new Employee("Rubeus", "Hagrid", 50000);

        person.showName();

        student.showGPA();

        employee.showSalary();
    }
}
