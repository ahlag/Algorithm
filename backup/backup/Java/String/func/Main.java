public class Main {
    public static void main(String[] args) {
        String s1 = "スッキリJava";
        String s2 = "Java";
        String s3 = "java";
        if(s2.equals(s3)) {
            System.out.println("s2 & s3 matches.");
        }
        if(s2.equalsIgnoreCase(s3)) {
            System.out.println("If the cases of s2 & s3 are not differentiated, it matches.");
        }
        System.out.println("The length of s1 is " + s1.length());
        if(!s1.isEmpty()) {
            System.out.println("s1 is not empty!");
        }
        
        String s4 = "Java and Javascript";
        if(s4.contains("Java")) {
            System.out.println("s4 contains Java");
        }
        
        if(s4.endsWith("Java")) {
            System.out.println("s4 ends with Java");
        }
        
        System.out.println("The index of Java from the front is at " + s4.indexOf("Java"));
        System.out.println("The index of Java from the back is at " + s4.lastIndexOf("Java"));
        
    }
}
