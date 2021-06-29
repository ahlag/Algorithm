public class Main {
    public static void main(String[] args) {
        StringBuilder ab = new StringBuilder();
        for( int i = 0; i < 10000; i++ ) {
            ab.append("Java");
        }
        String s = ab.toString();
        System.out.println(s);
    }
}
