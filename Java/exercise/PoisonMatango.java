public class PoisonMatango extends Matango {
    private int poisonAtk = 5;
    
    public PoisonMatango(char suffix) {
        super(suffix);
    }
    
    public void attack(Hero h) {
        super.attack(h);
        if(poisonAtk != 0) {
            System.out.println("さらに毒の胞子をばらまいた!");
            int dmg = h.getHp()/5;
            h.setHp(dmg);
            System.out.println(dmg + "ポイントのダメージ");
            this.poisonAtk--;
        }
    }
}
