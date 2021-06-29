public class Main {
    public static void methodA(String name) {
        System.out.println("This is method " + name);
        methodB();
    }
    
    public static void methodB() {
        System.out.println("This is method B");
    }
    
    public static void main(String[] args) {
        methodA("");
    }
}
