import java.util.Calendar;
import java.util.Date;

public class Main {
    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        
        //現在の年を表示する
        Date now = new Date();
        Calendar c = Calendar.getInstance();
        c.setTime(now);
        int y = c.get(Calendar.YEAR);
        System.out.println("今年は" + y +"年です");
        //指定した日のDate型の値を得る
        
        c.set(2010,8,22,1,23,45);
        c.set(Calendar.YEAR, 2011);
        
        Date past = new Date(1316622225935L);
        System.out.println(past);
        
        long end   = System.currentTimeMillis();
        System.out.println("Elapsed time :" + (end - start));
    }
}
