public class Hero {
    private int hp;
    private String name;
    Sword sword;
    static int money;
    
    void bye() {
        System.out.println("勇者は別れを告げた!");
    }
    
    private void die() {
        System.out.println(this.name + "は死んでしまった!");
        System.out.println("GAME OVERです！");
    }
    
    /*
    public void attack(Matango m) {
        System.out.println(this.name + "の攻撃!");
        System.out.println("お化けキノコ" + m.suffix + "から2ポイントの反撃を受けた!");
        this.hp -= 2;
        if(this.hp <= 0) {
            this.die();
        }
        System.out.println("敵に5ポイントのダメージを与えた!");
    }
     */
    
    void sleep() {
        this.hp = 100;
        System.out.println(this.name + "は、眠って回復した!");
    }
    
    void sit(int sec) {
        this.hp += sec;
        System.out.println(this.name + "は、" + sec + "秒座った!");
        System.out.println("HPが" + sec + "ポイント回復した。");
    }

    void slip() {
        this.hp -= 5;
        System.out.println(this.name + "は、転んだ!");
        System.out.println("5のダメージ!");
    }
    
    void run() {
        System.out.println(this.name + "は、逃げ出した!");
        System.out.println("GAMEOVER");
        System.out.println("最終HPは" + this.hp + "でし出したた。");
    }
    
    public int getHP() {
        return this.hp;
    }
    
    public int setHP(int val) {
        this.hp = val;
    }
    
    public String getName() {
        return this.name;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    Hero(String name) {
        this.hp = 100;
        this.name = name;
    }
    
    Hero() {
        this("dummy");
    }
}
