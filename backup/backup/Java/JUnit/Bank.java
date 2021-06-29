

public class Bank {
    private String name;
    public String getName() {
        return this.name;
    }
    public void setName(String newName) {
        if(newName.length() <= 3) {
            throw new IllegalArgumentException("名前が不正です");
        }
        this.name = newName;
    }
}
