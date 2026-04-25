public class App {
    public static void main(String[] args) throws Exception {
        String name = "   Kin   ";

        int length = name.length();
        char letter = name.charAt(4);
        int index = name.indexOf("i");
        int lastIndex = name.lastIndexOf("n");

        // name = name.toUpperCase();
        // name = name.toLowerCase();
        // name = name.trim();
        name = name.replace("K", "G");
        System.out.println(name);

        System.out.println(length);
        System.out.println(letter);
        System.out.println(index);
        System.out.println(lastIndex);
    }
}
