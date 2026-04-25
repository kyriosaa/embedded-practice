import java.util.*;

public class AssignmentRunner {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Assignment> assignments = new ArrayList<Assignment>();

        while(true) {
            System.out.print("Enter the assignment's name (exit to quit): ");
            String name = input.nextLine();
            
            if(name.equals("exit")) {
                printSummary(assignments);
                break;
            }
            System.out.print("Enter the due date: ");
            String dueDate = input.nextLine();

            System.out.print("How many points is the assignment worth?: ");
            double avaliablePoints = input.nextDouble();
            input.nextLine();
            
            System.out.print("How many points were earned?: ");
            double earnedPoints = input.nextDouble();
            input.nextLine();

            System.out.print("Is this a (T)est or a (P)roject?: ");
            String assignmentType = input.nextLine();

            if(assignmentType.equals("T")) {
                System.out.print("What type of test is it?: ");
                String type = input.nextLine();
                Test test1 = new Test(name, dueDate, avaliablePoints, earnedPoints, type);
                assignments.add(test1);
                System.out.println();
            } else {
                System.out.println("Does this project require (true/false) ...");
                System.out.print("Groups?" );
                boolean group = input.nextBoolean();
                System.out.print("A presentation?: ");
                boolean presentation = input.nextBoolean();
                Project project1 = new Project(name, dueDate, avaliablePoints, earnedPoints, group, presentation);
                assignments.add(project1);
                System.out.println();
            }
        }
    }

    // Print due date and score percentage on the assignment
    public static void printSummary(ArrayList<Assignment> assignments) {
        for(int i = 0; i < assignments.size(); i++) {
            double earnedPoints = assignments.get(i).getEarnedPoints();
            double avaliablePoints = assignments.get(i).getAvaliablePoints();
            double score = (earnedPoints / avaliablePoints) * 100;
            System.out.println(assignments.get(i).getName() + " - " + score);
        }
    }
}
