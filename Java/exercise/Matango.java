public class Matango {
    int hp = 50;
    private char suffix;
    public void run() {
        System.out.println("お化けキノコ" + this.suffix + "は逃げ出したよ!");
    }
    
    public Matango(char suffix) {
        this.suffix = suffix;
    }
    
    public void attack(Hero h) {
        System.out.println("キノコ" + this.suffix + "の攻撃");
        System.out.println("10のダメージ");
        h.setHp(h.getHp() - 10);
    }
}
