import java.util.ArrayList;
import java.util.Iterator;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> points = new ArrayList<Integer>();
        points.add(19);
        points.add(40);
        points.add(100);
        
        /*
        for( int pnt : points ) {
            System.out.println(pnt);
        }
         */
        Iterator<Integer> it = points.iterator();
        while(it.hasNext()) {
            int e = it.next();
            System.out.println(e);
        }
    }
}
