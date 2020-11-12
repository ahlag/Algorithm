public class King {
    void talk(Hero h) {
        System.out.println("王様：ようこそ我が国へ、勇者" + h.getName() + "よ。");
    }

    void name(Hero h, String name) {
        h.setName(name);
        System.out.println("This is your new name," + name);
    }
}
