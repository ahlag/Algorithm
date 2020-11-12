import java.awt.*;
import java.awt.event.*;

public class Sample7 extends Frame implements Runnable {
    int num;
    
    public static void main(String[] args) {
        Sample7 sm = new Sample7();
    }
    public Sample7() {
        super("サンプル");
        
        addWindowListener(new SampleWindowListener());
        
        Thread th;
        th = new Thread(this);
        th.start();
        
        setSize(250,200);
        setVisible(true);
    }
    public void run() {
        try {
            for(int i = 0; i < 10; i++ ) {
                num = i;
                repaint();
                Thread.sleep(1000);
            }
        }catch(InterruptedException e) {}
    }
    public void paint(Graphics g) {
        String str = num + "です。";
        g.drawString(str,100,100);
    }
    class SampleWindowListener extends WindowAdapter {
        public void WindowClosing(WindowEvent e) {
            System.exit(0);
        }
    }
}
