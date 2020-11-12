import java.util.Arrays;
import java.util.*;
import java.util.stream.*;
import java.nio.file.*;

interface A {
    void show(int i);
}

public class DemoforEach {
    public static void main(String[] args) {
        
        A obj;
        obj = ( i ) -> System.out.println("Hello" + i);
        
        obj.show(7);
        
        List<Integer> values = Arrays.asList(4,5,6,7);
        
        values.forEach( i -> System.out.println(i));
        
        IntSream
            .range(1,10).forEach(System.out::print);
        System.out.println();
    }
}
