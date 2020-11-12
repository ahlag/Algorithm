import java.awt.*;
import java.awt.event.*;

public class Sample1 extends Frame {
    private Label lb;
    
    public static void main(String[] args) {
        Sample1 sm = new Sample1();
    }
    public Sample1() {
        super("サンプル");
        lb = new Label("Welcome!");
        
        add(lb);
        
        lb.setForeground(Color.blue);
        lb.setFont(new Font("Serif",Font.BOLD, 24));
        
        addWindowListener(new SampleWindowListener());
        
        setSize(250,400);
        setVisible(true);
    }
    
    class SampleWindowListener extends WindowAdapter {
        public void WindowClosing(WindowEvent e) {
            System.exit(0);
        }
    }
}
