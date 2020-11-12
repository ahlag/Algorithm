import java.io.*;

class Sample7 {
    public static void main(String[] args) {
        
        try {
            PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("test1.txt")));
            
            pw.println("Hellow");
            pw.println("Goodbye!");
            System.out.println("ファイルに書き込みました。");
            
            pw.close();
        } catch(IOException e) {
            System.out.println("入出力エラーです。");
        }
    }
}
