import java.util.Set;
import java.util.TreeSet;

public class Treeset{
    public static void main(String[] args) {
        Set<String> words = new TreeSet<String>();
            words.add("Jesus");
            words.add("Car");
            words.add("Moist");
            words.add("Zebra");

            for(String s : words) {
                System.out.print(s + "->");
            }
            System.out.println();
    }
}
