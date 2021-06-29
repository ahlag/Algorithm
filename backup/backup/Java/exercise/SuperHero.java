public class SuperHero extends Hero {

    private boolean flying;
    
    public void fly() {
        this.flying = true;
        System.out.println("飛び上がったよ!");
    }
    
    public void land() {
        this.flying = false;
        System.out.println("着地したよ!");
    }
}
