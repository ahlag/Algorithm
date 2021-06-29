import java.lang.reflect.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Class clazz = RefSample.class;
        //引数1つのコンストラクタを取得し、インスタンスを生成する
        Constructor<?> cons = clazz.getConstructor(int.class);
        RefSample rs = (RefSample) cons.newInstance(256);
        
        //timesフィールドに関するFieldを取得して読み書き
        Field f = clazz.getField("times");
        f.set(rs,2);                            //rsのtimesに代入
        System.out.println(f.get(rs));          //rsのtimesを取得
        
        //引数2つのhelloメソッドを取得して呼び出す
        Method m = clazz.getMethod("hello", String.class, int.class);
        m.invoke(rs, "reflection!", 128);
        
        //クラスやメソッドへの修飾(punlicやfinalの有無)を調べる
        boolean pubc = Modifier.isPublic(clazz.getModifiers());
        boolean finm = Modifier.isFinal(m.getModifiers());
        
        System.out.println(pubc);
        System.out.println(finm);
    }
}

public class RefSample {
    public int times = 0;
    public RefSample(int t) {
        this.times = t;
    }
    public void hello(String msg) {
        this.hello(msg, this.times);
    }
    public void hello(String msg, int t) {
        System.out.println("Hello, " + msg + " x" + t);
    }
}

/*
public class Main {
    public static void main(String[] args) throws IOException {
        
        System.out.println("Calculation stopped");
        ProcessBuilder pb = new ProcessBuilder();
        pb.command("java", "-version");
        
        try {
            
            Process process = pb.start();
            
            // blocked :(
            BufferedReader reader =
            new BufferedReader(new InputStreamReader(process.getInputStream()));
            
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
            
            int exitCode = process.waitFor();
            System.out.println("\nExited with error code : " + exitCode);
            
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
    }
}
*/
