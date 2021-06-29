public class Wizard {
    private String name;
    private Wand wand;
    private int hp;
    private int mp
    
    public void heal(Hero h) {
        int basePoint = 10;  //基本回復ポイント
        int recovPoint = (int) (basePoint * this.wand.power); //杖による増幅
        h.setHp(h.getHP() + recovPoint);
        System.out.println(h.getName() + "のHPを" + recovPoint + "回復した!");
    }
}
