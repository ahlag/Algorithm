import java.awt.*;
import java.awt.event.*;

public class Sample5 extends Frame {
    Image im;
    
    public static void main(String[] args) {
        Sample5 sm = new Sample5();
    }
    public Sample5() {
        super("サンプル");
        
        Toolkit tk = getToolkit();
        im = tk.getImage("tenor.gif");
        
        addWindowListener(new SampleWindowListener());
        
        setSize(250,200);
        setVisible(true);
    }
    public void paint(Graphics g) {
        g.drawImage(im, 100, 100, this);
    }
    class SampleWindowListener extends WindowAdapter {
        public void WindowClosing(WindowEvent e) {
            System.exit(0);
        }
    }
}
