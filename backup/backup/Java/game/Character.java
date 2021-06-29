public abstract class Character {
    String name;
    int hp;
    public abstract void attack();
    public void run(String name) {
        System.out.println(name + " ran away!");
    }
}
