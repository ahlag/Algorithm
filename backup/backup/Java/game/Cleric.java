import java.util.*;

public class Cleric {
    String name;
    int hp = 50;
    final int MAX_HP = 50;
    int mp = 10;
    final int MAX_MP = 10;
    
    public void selfAid() {
        System.out.println(this.name + "はセルフエイドを唱えた！");
        this.hp = this.MAX_HO;
        this.mp -= 5;
        System.out.println("HPが最大まで回復した。");
    }
    
    Cleric() {
        this.hp = 50;
        this.mp = 10;
    }


}
