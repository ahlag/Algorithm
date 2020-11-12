package calcapp.main;
public class sCalc {
    public static void main(String[] args) {
        int a = 10; int b = 2;
        int total = calcapp.logics.CalcLogic.tasu(a,b);
        int delta = calcapp.logics.CalcLogic.hiku(a,b);
        System.out.println("足すと" + total + "、引くと" + delta);
    }
}
