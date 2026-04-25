public class Test extends Assignment {
    private String testType;

    public Test(String name, String dueDate, double avaliablePoints, double earnedPoints, String testType) {
        super(name, dueDate, avaliablePoints, earnedPoints);
        this.testType = testType;
    }

    public String getTestType() {
        return testType;
    }

    public void setTestType(String type) {
        testType = type;
    }
}
