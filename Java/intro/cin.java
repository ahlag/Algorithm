public class Main {
    public static void main(String[] args) {
        System.out.println("What is your name?");
        String name = new java.util.Scanner(System.in).nextLine();
        System.out.println("What is your age");
        int age = new java.util.Scanner(System.in).nextInt();
        System.out.println("Welcome " + name + " who is " + age + " years old.");
    }
}
