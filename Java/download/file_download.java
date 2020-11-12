import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;

public class file {
    public static void main(String[] args) {
        
        try {
            URL url = new URL("http://dokojava.jp/favicon.ico");
            try (
                 InputStream in = url.openStream();
                 FileOutputStream out = new FileOutputStream("dj.ico")) {
                int data;
                while ((data = in.read()) != -1) {
                    out.write((byte) data);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (MalformedURLException mue) {
                mue.printStackTrace(System.err);
        }
    }
}
