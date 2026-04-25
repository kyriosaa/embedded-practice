public class Project extends Assignment {

    public boolean groups;
    public boolean presentation;

    public Project(String name, String dueDate, double avaliablePoints, double earnedPoints, boolean hasGroups, boolean hasPresentation) {
        super(name, dueDate, avaliablePoints, earnedPoints);
        groups = hasGroups;
        presentation = hasPresentation;
    }

    public boolean hasGroups() {
        return groups;
    }

    public boolean hasPresentation() {
        return presentation;
    }

    public void setGroups(boolean set) {
        groups = set;
    }

    public void setPresentation(boolean set) {
        presentation = set;
    }
}
