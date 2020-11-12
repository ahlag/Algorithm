import java.awt.*;
import java.awt.event.*;

public class Sample3 extends Frame {
    private Button bt;
//    private Label lb;
    
    public static void main(String[] args) {
        Sample3 sm = new Sample3();
        //Sample1 sm = new Sample1();
    }
    public Sample3() {
        super("サンプル");
        
        bt = new Button("ようこそ。");
        add(bt);
        
        addWindowListener(new SampleWindowListener());
        bt.addActionListener(new SampleActionListener());
        
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

    class SampleActionListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            bt.setLabel("こんにちは。");
        }
    }
}
