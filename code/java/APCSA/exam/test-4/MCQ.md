> **APCSA - PRACTICE TEST 4**
> 
> **SECTION 1**
> 
> **Time - 1 hour and 30 minutes**
>
> **Number of Questions - 40**
> 
> **Percent of Total Grade - 50%**


# Directions:

Determine the answer to each of the following questions or incomplete statements, using the available space for any necessary scratchwork. Then decide which is the best of the choices given and fill in the corresponding oval on the answer sheet. No credit will be given for anything written in the examination booklet. Do not spend too much time on any one problem.


# Notes:

- Assume that the classes listed in the Quick Reference have been imported where appropriate.
- Assume that declarations of variables and methods appear within the context of an enclosing class.
- Assume that method calls that are not prefixed with an object or class name and are not shown within a complete class definition appear within the context of an enclosing class.
- Unless otherwise noted in the question, assume that parameters in the method calls are not *null* and that methods are called only when their preconditions are satisfied.


# MULTIPLE CHOICE QUESTIONS

1.  **Consider the following code segment:**

    ```java
    (int) (5 / 2)
    ```

    What will be the result of the code above?
    - (A) 2
    - (B) 2.5
    - (C) 3
    - (D) 5
    - (E) The statement would generate an error
##
2.  **Consider the following code segment:**

    ```java
    num += 1
    ```

    Which of the following statements is equivalent to the code above?
    - (A)
    ```java
    num = 1
    ```
    - (B)
    ```java
    num + 1
    ```
    - (C)
    ```java
    num++1
    ```
    - (D)
    ```java
    1 += num
    ```
    - (E)
    ```java
    num = num + 1
    ```
##
3. **Which of the following would correctly generate a random number between 5 and 25 (inclusive)?**

    - (A)
    ```java
    (int) (Math.random() * (20))
    ```
    - (B)
    ```java
    (int) (Math.random() * (21))
    ```
    - (C)
    ```java
    (int) (Math.random() * (21) + 5)
    ```
    - (D)
    ```java
    (int) (Math.random() * (25))
    ```
    - (E)
    ```java
    (int) (Math.random() * (25) + 5)
    ```
##
4. **Consider the following code segment:**

    ```java
    String city1 = "Chicago";
    String city2 = "London";
    int difference = city1.compareTo(city2);
    ```

    What would be stored in the difference variable based on the code above?
    - (A) 0
    - (B) 1
    - (C) A number less than 0
    - (D) A number greater than 0
    - (E) The code would generate an error
##
5. **Consider the following code segment:**

    ```java
    String city1 = // Get input from user
    String city2 = // Get input from user
    if(city1.compareTo(city2) > 0)
        print(city1);
    else
        print(city2);
    ```

    What would be stored in the difference variable based on the code above?
    - (A) The city that comes first alphabetically
    - (B) The city that comes second alphabetically
    - (C) Both cities
    - (D) The city that comes first alphabetically, or a <code>NullPointerException</code> if nothing was input for one of the cities
    - (E) The city that comes second alphabetically, or a <code>NullPointerException</code> if nothing was input for one of the cities
##
6. **Consider the following code segment:**

    ```java
    !(x < 5 && y > 10)
    ```

    Which of the following expressions is equivalent to the code above?
    - (A)
    ```java
    x >= 5 && y <= 10
    ```
    - (B)
    ```java
    x <= 5 && y >= 10
    ```
    - (C)
    ```java
    x >= 5 || y <= 10
    ```
    - (D)
    ```java
    x <= 5 || y >= 10
    ```
    - (E)
    ```java
    !x < 5 && !y > 10
    ```
##
7. **Consider the following code segment:**

    ```java
    int num = 0;
    boolean result = (num == 0) || (10 / num < 5);
    ```

    What is the variable result equal to after the execution of the code above?
    - (A) 0
    - (B) <code>true</code>
    - (C) <code>false</code>
    - (D) 10
    - (E) The code would generate an error
##
8. **Consider the following code segment:**

    ```java
    String president = "Lincoln";
    String city = "Lincoln";

    if(city == president)
        // Statement 1
    else if(city.equals(president))
        // Statement 2
    else
        // Statement 3
    ```

    Which of the following if statement will run?
    - (A) Statement 1
    - (B) Statement 2
    - (C) Statement 3
    - (D) Statement 1 and Statement 2
    - (E) Statement 1, Statement 2, and Statement 3
##
9. **Consider the following code segment:**

    ```java
    int num = 0;
    if(num < 10)
        num++;
    else if(num == 1)
        num++;
    else
        num = 10;
    ```

    What will num equal after the execution of the code above?
    - (A) 0
    - (B) 1
    - (C) 2
    - (D) 3
    - (E) 10
##
10. **Consider the following code segment:**

    ```java
    int num = 0;
    if(num < 10)
        num++;
    if(num == 1)
        num++;
    else
        num = 10;
    ```

    What will num equal after the execution of the code above?
    - (A) 0
    - (B) 1
    - (C) 2
    - (D) 3
    - (E) 10
##
11. **Consider the following code segment:**

    ```java
    int num = 0;
    if(num < 10)
        num++;
    else if(num == 1)
        num++;
    if(num == 2)
        num++;
    else
        num = 10;
    ```

    What will num equal after the execution of the code above?
    - (A) 0
    - (B) 1
    - (C) 2
    - (D) 3
    - (E) 10
##
12. **Consider the following code segment:**

    ```java
    int num = 0;
    while(num < 10)
        num++;
    ```

    What will num equal after the execution of the code above?
    - (A) 0
    - (B) 1
    - (C) 9
    - (D) 10
    - (E) 11
##
13. **Consider the following code segment:**

    ```java
    int num = 0;
    while(num < 10)
        if(num % 2 == 0)
            num++;
        else
            num *= 2;
    ```

    What will num equal after the execution of the code above?
    - (A) 9
    - (B) 10
    - (C) 14
    - (D) 20
    - (E) An infinite loop occurs
##
14. **Consider the following code segment:**

    ```java
    int num = 1;
    while(/* Condition Here */)
        num *= 2;
    ```

    What condition could replace <code>/* Condition Here */</code> to ensure num equals 4 after the execution of the code above?
    - (A)
    ```java
    num == 4
    ```
    - (B)
    ```java
    num < 4
    ```
    - (C)
    ```java
    num <= 4
    ```
    - (D)
    ```java
    num > 4
    ```
    - (E)
    ```java
    num >= 4
    ```
##
15. **Consider the following code segment:**

    ```java
    int num = 0;
    for(int i = 0; /* Condition Here */; i++)
        num += 2;
    ```

    What condition could replace <code>/* Condition Here */</code> to ensure num equals 10 after the execution of the code above?
    - (A)
    ```java
    i < 10
    ```
    - (B)
    ```java
    i <= 10
    ```
    - (C)
    ```java
    num < 10
    ```
    - (D)
    ```java
    num <= 10
    ```
    - (E)
    ```java
    i == num
    ```
##
16. **Consider the following code segment:**

    ```java
    for(int i = 0; i <= 10; i += 2)
        // for Loop Body
    ```

    How many times will the for loop body execute in the code above
    - (A) 0
    - (B) 5
    - (C) 6
    - (D) 10
    - (E) 11
##
17. **Consider the following code segment:**

    ```java
    for(int i = 1000; i > 0; i--)
        // for Loop Body
    ```

    How many times will the for loop body execute in the code above?
    - (A) 0
    - (B) 999
    - (C) 1000
    - (D) 1001
    - (E) An infinite loop will occur
##
18. **Consider the following code segment:**

    ```java
    int num = 0;
    for(int i = 0; i < 5; i++)
        for(int k = 0; k < 2; k++)
            num++;
    ```

    What will the variable num equal after the execution of the code above?
    - (A) 0
    - (B) 2
    - (C) 5
    - (D) 7
    - (E) 10
##
19. **Consider the following code segment:**

    ```java
    String firstString = "mississippi";
    String secondString = "";
    for(int i = 0; i < 5; i++)
        secondString += firstString.substring(i, i+1);
    ```

    What will <code>secondString</code> be equal to after the execution of the code above?
    - (A) ""
    - (B) "miss"
    - (C) "missi"
    - (D) "msisipi"
    - (E) "mississippi"
##
20. **Consider the following code segment:**

    ```java
    String[] cities = {"Chicago", "London", "Tokyo", "Manila"};
    for(String city : cities)
        System.out.println(city);
    ```

    What will be printed by the code above?
    - (A) 
    ```java
    Chicago
    ```
    - (B)
    ```java
    ChicagoLondonTokyoManila
    ```
    - (C)
    ```java
    Chicago
    London
    Tokyo
    Manila
    ```
    - (D)
    ```java
    Manila
    Tokyo
    London
    ```
    - (E)
    ```java
    // Nothing will be printed
    ```
##
**The following class will be used for questions 21-23**

```java
public class BaseballPlayer {
    String firstName;
    String lastName;
    int number;
    String position;

    public BaseballPlayer(String first, String last, int num) {
        // Constructor
    }

    public void setPosition(String pos) {
        // Implementation not shown
    }
}
```

21. **Question:**

    The constructor needs to initialize the <code>firstName</code>, <code>lastName</code>, and <code>number</code> variables. What code would be used to complete the constructor?
    - (A)
    ```java
    first = firstName;
    last = lastName;
    num = number;
    ```
    - (B)
    ```java
    firstName = first;
    lastName = last;
    number = num;
    ```
    - (C)
    ```java
    String first = firstName;
    String last = lastName;
    int num = number;
    ```
    - (D)
    ```java
    String firstName = first;
    String lastName = last;
    int number = num;
    ```
    - (E)
    ```java
    String first = String firstName;
    String last = String lastName;
    int num = int number;
    ```

22. **Question:**

    How would you implement the <code>setPosition</code> mutator to set the <code>position</code> variable of a <code>BaseballPlayer</code>?
    - (A)
    ```java
    return pos;
    ```
    - (B)
    ```java
    return position;
    ```
    - (C)
    ```java
    pos = position;
    ```
    - (D)
    ```java
    position = pos;
    ```
    - (E)
    ```java
    String pos = position;
    ```

23. **Question:**

    If the parameters of the constructor were called <code>firstName</code>, <code>lastName</code>, and <code>number</code>, what could you do to initialize the class-level variables?
    - (A) Change the names of the parameters
    - (B) Change the names of the class-level variables
    - (C) Use the <code>this</code> keyword in front of the parameters within the constructor
    - (D) Use the <code>this</code> keyword in front of the class-level variables within the constructor
    - (E) It isn't possible to initialize the class-level variables if the parameters have the same name
##
24. **Which of the following correctly creates a String array of length 10?**

    - (A)
    ```java
    String myArray = new String[10];
    ```
    - (B)
    ```java
    myArray String = new String[10];
    ```
    - (C)
    ```java
    String myArray = new array[10];
    ```
    - (D)
    ```java
    String[] myArray = new array[10];
    ```
    - (E)
    ```java
    String[] myArray = new String[10];
    ```
##
25. **Consider the following code segment:**

    ```java
    String temp = players[0];
    for(int i = 1; i < players.length; i++)
        if(players[i].compareTo(temp) < 0)
            temp = players[i];
    ```

    What does the code above do, assuming players is an array of Strings?
    - (A) Find Strings in the array that are equal to <code>temp</code>
    - (B) Find the String in the array that comes first alphabetically and store it in <code>temp</code>
    - (C) Find the String in the array that comes last alphabetically and store it in <code>temp</code>
    - (D) Find the first String in the array that comes before <code>temp</code> alphabetically and store it in <code>temp</code>
    - (E) Find the first String in the array that comes after <code>temp</code> alphabetically and store it in <code>temp</code>
##
26. **Consider the following code segment:**

    ```java
    int x = 0;
    for(int i = 0; i < nums.length; i++)
        if(nums[i] % 2 == 0)
            x++;
    ```

    What does the code above do, assuming <code>nums</code> is an array of integers?
    - (A) Count the number of items in <code>nums</code>
    - (B) Get the total of all the numbers in <code>nums</code>
    - (C) Get the total of all the even numbers in <code>nums</code>
    - (D) Count the number of even numbers in <code>nums</code>
    - (E) Count the number of odd numbers in <code>nums</code>
##
27. **How would you access the 10th element of an array called <code>myArray</code>?**

    - (A)
    ```java
    myArray[9]
    ```
    - (B)
    ```java
    myArray[10]
    ```
    - (C)
    ```java
    myArray = 9
    ```
    - (D)
    ```java
    myArray = 10
    ```
    - (E)
    ```java
    [10]myArray
    ```
##
28. **Which of the following is required to use binary search?**

    - (A) The data must be stored in an array
    - (B) The data must be stored in an <code>ArrayList</code>
    - (C) The data must be stored
    - (D) The data must be integers
    - (E) Both A and C are required to use binary search
##
29. **An <code>ArrayList</code> has the following elements with each step of sorting shown:**

        Original List:      42 25 10 20 09
        Step 1:             09 25 10 20 42
        Step 2:             09 10 25 20 42
        Step 3:             09 10 20 25 42
        Step 4:             09 10 20 25 42

    What sorting method is being used?
    - (A) Bubble Sort
    - (B) Insertion Sort
    - (C) Merge Sort
    - (D) Quick Sort
    - (E) Selection Sort
##
30. **Consider the following code segment:**

    ```java
    int x = 0;
    for(String temp: myList)
        if(temp.substring(0, 1).equals("s"))
            x++;
    ```

    What will be stored in the variable <code>x</code> after the code above is executed (assuming <code>myList</code> is an <code>ArrayList</code> of Strings)?
    - (A) The number of elements in <code>myList</code> equal to "s"
    - (B) The number of elements in <code>myList</code> that start with "s"
    - (C) The number of elements in <code>myList</code> that end with "s"
    - (D) The total number of elements in <code>myList</code>
    - (E) <code>x</code> will remain equal to 0
##
31. **What is the correct way to declare and initialize a 2D array of Strings with 5 rows and 10 columns?**

    - (A)
    ```java
    String myArray = new array[10][5];
    ```
    - (B)
    ```java
    String myArray = new String[5][10];
    ```
    - (C)
    ```java
    String[] myArray = new String[10][5];
    ```
    - (D)
    ```java
    String[][] myArray = new String[5][10];
    ```
    - (E)
    ```java
    String[][] myArray = new String[10][5];
    ```
##
32. **Consider the following code segment:**

    ```java
    int x = 0;
    for(int[] row: myArray)
        for(int temp: row)
            x += temp;
    ```

    What will be stored in the variable <code>x</code> after the code above executes assuming <code>myArray</code> is a 2D array of integers?
    - (A) The total number of elements in the 2D array
    - (B) The total number of rows in the 2D array
    - (C) The total number of columns in the 2D array
    - (D) The sum of all the elements in the 2D array
    - (E) The sum of the elements in the first row of the 2D array
##
33. **Consider the following code segment:**

    ```java
    for(int row = 0; row <= myArray.length; row++)
        for(int col = 0; col <= /* CONDITION */; col++)
    ```

    - (A)
    ```java
    myArray.length
    ```
    - (B)
    ```java
    myArray.length - 1
    ```
    - (C)
    ```java
    myArray[0].length
    ```
    - (D)
    ```java
    myArray[0].length - 1
    ```
    - (E)
    ```java
    myArray[length - 1]
    ```
##
34. **What would the class header look like for a class called <code>Teacher</code> that is a subclass of <code>Employee</code>?**

    - (A)
    ```java
    public class Teacher
    ```
    - (B)
    ```java
    public class Teacher extends Employee
    ```
    - (C)
    ```java
    public class Teacher implements Employee
    ```
    - (D)
    ```java
    public class Employee extends Teacher
    ```
    - (E)
    ```java
    public class Employee implements Teacher
    ```
##
35. **Consider the following code segment:**

    ```java
    1.  public void Teacher(String name, int salary) {
    2.      super(name);
    3.      this.salary = salary;    
    4.  }
    ```

    The constructor above has an error. Which line contains the error?
    - (A) Line 1
    - (B) Line 2
    - (C) Line 3
    - (D) Lines 1 and 2
    - (E) Lines 2 and 3
##
36. **If you create a class that has a method called <code>calculatePerimeter</code> that overrides a superclass method of the same name, what object-oriented programming concept is this an example of?**

    - (A) Abstraction
    - (B) Class Design
    - (C) Encapsulation
    - (D) Inheritance
    - (E) Polymorphism
##
37. **Which of the following is the superclass for all classes in Java?**

    - (A) Class
    - (B) Comparable
    - (C) Java
    - (D) Object
    - (E) String
##
38. **Consider the following code segment:**

    ```java
    1.  public int sum(int sum) {
    2.      int total;
    3.      if(num == 1)
    4.          total = 1;
    5.      else
    6.          total = num + sum(num - 1)
    7.      return total;
    8.  }
    ```

    Which line contains the base case in the recursive code above?
    - (A) Line 2
    - (B) Line 3
    - (C) Line 4
    - (D) Line 6
    - (E) Line 7
##
39. **Consider the following code segment:**

    ```java
    public int sum(int sum) {
        int total;
        if(num == 1) 
            total = 1;
        else
            total = num + sum(num - 1)
        return total;
    }
    ```

    What would be the result of the call <code>sum(5)</code>?
    - (A) 4
    - (B) 5
    - (C) 10
    - (D) 14
    - (E) 15
##
40. **Consider the following code segment:**

    ```java
    public int fib(int num) {
        if(num <= 1)
            return n;
        else
            return fib(n - 1) + fib(n - 2)
    }
    ```

    How many recursive calls would occur with the call <code>fib(5)</code>?
    - (A) 0
    - (B) 1
    - (C) 5
    - (D) 10
    - (E) 15

------------------------------------------------------------
> **END SECTION 1**
------------------------------------------------------------