import java.io.*;

class sample {
    public static void main(String[] args) throws IOException{
        System.out.println("文字列を入力してください.");
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String str = br.readLine();
        
        int num = Integer.parseInt(str);
        
        System.out.println(num + "が入力されました");
    }
}
