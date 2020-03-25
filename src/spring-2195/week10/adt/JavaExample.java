public class JavaExample {

    private String name;
    private int age;

    public JavaExample(String name, int age ) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return this.name;
    }

    public static void main(String[] args) {
        JavaExample example = new JavaExample("Bob", 10);

    }
}
