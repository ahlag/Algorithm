import java.awt.*;
import java.awt.event.*;

public class Sample4 extends Frame {
    private Button bt;
//    private Label lb;
    
    public static void main(String[] args) {
        Sample4 sm = new Sample4();
        //Sample1 sm = new Sample1();
    }
    public Sample4() {
        super("サンプル");
        
        bt = new Button("ようこそ。");
        add(bt);
        
        addWindowListener(new SampleWindowListener());
        bt.addMouseListener(new SampleMouseListener());
        
        setSize(250,200);
        setVisible(true);
    }
    /*
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
    */
    class SampleWindowListener extends WindowAdapter {
        public void WindowClosing(WindowEvent e) {
            System.exit(0);
        }
    }

    class SampleMouseListener implements MouseListener {
        public void mouseClicked(MouseEvent e) {}
        public void mouseReleased(MouseEvent e) {}
        public void mousePressed(MouseEvent e) {
            bt.setLabel("You");
        }
        public void mouseEntered(MouseEvent e) {
            bt.setLabel("いらっしゃいませ。");
        }
        public void mouseExited(MouseEvent e) {
            bt.setLabel("ようこそ。");
        }
    }
}
