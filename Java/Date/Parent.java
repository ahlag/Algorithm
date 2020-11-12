public class Main {
    public static void main(String[] args) {
        Object o1 = new Empty();
        Object o2 = new Hero();
        Object o3 = "Hey!";
        
        printAnything(o1);
        printAnything(o2);
        printAnything(o3);
    }
    
    public void printAnything(Object o) {
        System.out.println(o.toString());
    }
}
