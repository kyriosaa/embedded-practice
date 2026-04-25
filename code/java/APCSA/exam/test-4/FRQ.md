> **APCSA - PRACTICE TEST 4**
> 
> **SECTION 2**
> 
> **Time - 1 hour and 30 minutes**
>
> **Number of Questions - 4**
> 
> **Percent of Total Grade - 50%**


# Directions:

SHOW ALL YOUR WORK. REMEMBER THAT PROGRAM SEGMENTS ARE TO BE WRITTEN IN JAVA.


# Notes:

- Assume that the classes listed in the Java Quick Reference have been imported where appropriate.
- Unless otherwise noted in the equation, assume that the parameters in method calls are not null and that methods are ccalled only when their preconditions are satisfied.
- In writing solutions for each question, you may use any of the accessible methods that are listed in classes defined in that question. Writing significant amounts of code that can be replaced by a call to one of these methods will not receive full credit.


# FREE RESPONSE QUESTIONS

1.  A day care has a program to keep track of its employees and which children they care for during the day. An <code>Employee</code> has a minimum and maximum age they can watch. The <code>DayCare</code> also has a maximum ratio that specifies the maximum number of children a single employee can watch. Below is the full <code>DayCare</code> class:

    ```java
    public class DayCare {
        private ArrayList<Employee> employees;
        private ArrayList<Child> children;
        private int maxRatio;
        
        public DayCare(int maxRatio) {
            employees = new ArrayList<Employee>();
            children = new ArrayList<Child>();
            this.maxRatio = maxRatio;
        }

        public boolean findEmployeeForChild(Child c) {
            /* To be completed in part a */
        }

        public boolean runDayCare() {
            /* To be completed in part b */
        }

        public boolean addChild(Child c) {
            /* To be completed in part c */
        }
    }
    ```

    ##
    Questions below
    ##

    (a) **An <code>Employee</code> can only teach children between the employee's minimum age (inclusive) and maximum age (inclusive). They can also only teach children up to the day care's maximum ratio (inclusive). Below is the full <code>Employee</code> class.**

    ```java
    public class Employee {
        /* Instance variables not shown */

        public Employee(String name, String id, int min, int max) {
            /* Implementation not shown */
        }

        // Return the number of children currently assigned to this Employee
        public int childrenAssigned() {
            /* Implementation not shown */
        }

        // Assign a new child to this Employee
        public void assignChild(Child c) {
            /* Implementation not shown */
        }

        // Determine if this Employee can teach a Child based on the child's age
        public boolean canTeach(int age) {
            /* Implementation not shown */
        }
    }
    ```

    **A <code>Child</code> has accessors to get their name and age. While the implementation of <code>Child</code> is not known, you can assume the accessors are called <code>getName</code> and <code>getAge</code>.**

    Complete the <code>findEmployeeForChild</code> method below that assigns a <code>Child</code> to the first <code>Employee</code> who can teach the <code>Child</code> and who has not reached the maximum ratio of the <code>DayCare</code>.

    ```java
    /* Return true if an Employee was found for the Child, false otherwise */
    public boolean findEmployeeForChild(Child c) {

    }
    ```

    ##

    (b) **To run the <code>DayCare</code> for a day, each <code>Child</code> must be assigned to an <code>Employee</code>. If an <code>Employee</code> can not be found for a <code>Child</code>, the <code>DayCare</code> cannot run for the day.**

    Complete the <code>runDayCare</code> method below that finds an <code>Employee</code> for each <code>Child</code> in the <code>children</code> ArrayList.

    ```java
    /* Return true if an Employee was found for each Child, false otherwise */
    public boolean runDayCare(Child c) {

    }
    ```

    ##

    (c) **When a <code>Child</code> is added to the roster of the <code>DayCare</code>, the <code>DayCare</code> should first make sure there could be an <code>Employee</code> available to teach that <code>Child</code>.**

    Complete the <code>addChild</code> method below that adds a <code>Child</code> to the <code>children</code> ArrayList if an <code>Employee</code> is available to teach that <code>Child</code>.

    ```java
    /* Return true if the Child was added to the ArrayList, false otherwise */
    public boolean addChild(Child c) {

    }
    ```

------------------------------------------------------------

2.  A baseball team consists of different people including players, coaches, and people who work in the front office making trades and other transactions. The following <code>Person</code> class is used for all of the people who work for the team.


    Each person has a name and an age.

    ```java
    public class Person {
        private String fullName;
        private int age;

        public Person(String s, int a) {
            fullName = s;
            age = a;
        }

        // Accessors for name and age
        public String getName() {
            return fullName;
        }

        public int getAge() {
            return age;
        }
    }
    ```

    ##
    Question below
    ##

    (a) **A <code>Player</code> has a name and age just like any person on the team, but they also have a <code>position</code>. The position could be something like "catcher," "left fielder," or "infielder." A <code>Player</code> should also be able to change their position using a method called <code>changePosition</code>. Here is an example of a <code>Player</code> object.**

    ```java
    Player p = new Player("Sammy Sosa", 32, "right fielder");
    p.changePosition("outfielder");
    ```

    Write the entire <code>Player</code> class below.

------------------------------------------------------------

3.  A class is designed to store someone's full name. You can assume the name has only one space between the first name and the last name. The class has methods to extract the first name, last name, and number of vowels in the name. You can see an example below.

    ```java
    String fullName = "Katherine Johnson";
    Name.getFirstName(fullName);    // returns "Katherine"
    Name.getLastName(fullName);     // returns "Johnson"
    Name.countVowels(fullName);     // returns 6
    ```

    ##
    Questions below
    ##

    (a) **The <code>getFirstName</code> method returns the first name based on a given full name. You can assume that full name has only one space between the first name and the last name. Write the <code>getFirstName</code> method below.**

    ```java
    public static String getFirstName(String name) {

    }
    ```

    ##

    (b) **The <code>getLastName</code> method returns the last name based on a given full name. You can assume that full name has only one space between the first name and the last name. Write the <code>getLastName</code> method below.**

    ```java
    public static String getLastName(String name) {

    }
    ```

    ##

    (c) **The <code>countVowels</code> method counts the number of vowels in the given name. You can assume we will only count the letters a, e, i, o, and u as vowels. Write the entire <code>countVowels</code> method below.**

    ```java
    public static int countVowels(String name) {

    }
    ```

------------------------------------------------------------

4.  A city parking lot has a sign that keeps track of how many parking spaces are available in the lot. The class for the parking lot is detailed below.

    ```java
    public class ParkingLot {
        private Car[][] lot;

        public ParkingLot(int rows, int cols) {
            lot = new Car[rows][cols];
        }

        public int openSpaces() {
            // Complete in part a
        }

        public boolean parkCar() {
            // Complete in part b
        }
    }
    ```

    ##
    Questions below
    ##

    (a) **Write the <code>openSpaces</code> method that returns how many spaces are available in the parking lot. If a space is empty, it will be equal to null.**

    ```java
    /* Return the number of empty spaces in the parking lot */
    public int openSpaces() {

    }
    ```

    ##

    (b) **Complete the <code>parkCar</code> method that puts a new car in any space in the parking lot and returns <code>true</code> if was able to do so. It should return <code>false</code> if there are no empty spaces. You should use the <code>openSpaces</code> method to receive full credit.**

    ```java
    /* Return true if there is an open spot to park the newCar, false otherwise.
    The car should be added to the lot 2D array is there is an open spot. */
    public boolean parkCar(Car newCar) {

    }
    ```

------------------------------------------------------------
> **END SECTION 2**
------------------------------------------------------------