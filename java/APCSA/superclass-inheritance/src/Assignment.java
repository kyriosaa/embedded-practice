public class Assignment {
    private String name;
    private String dueDate;
    private double avaliablePoints;
    private double earnedPoints;

    public Assignment(String name, String dueDate, double avaliablePoints, double earnedPoints) {
        this.name = name;
        this.dueDate = dueDate;
        this.avaliablePoints = avaliablePoints;
        this.earnedPoints = earnedPoints;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDueDate() {
        return dueDate;
    }

    public void setDueDate(String dueDate) {
        this.dueDate = dueDate;
    }

    public double getAvaliablePoints() {
        return avaliablePoints;
    }

    public void setAvaliablePoints(double avaliablePoints) {
        this.avaliablePoints = avaliablePoints;
    }

    public double getEarnedPoints() {
        return earnedPoints;
    }

    public void setEarnedPoints(double earnedPoints) {
        this.earnedPoints = earnedPoints;
    }
}
