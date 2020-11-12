public class Computer extends TangibleAsset{
    private String makerName;
    //Constructor
    public Computer (String name, int price, String color, String makerName) {
        super(name, price, color);
        this.makerName = makerName;
    }
    //getter
    public String getMakerName() { return this.makerName; }
}
