import org.junit.Test;
import static org.junit.Assert.*;

public class BankTest {
    
    //正常系: "ミヤビ"をセットできるか
    @Test public void setName() {
        Bank b = new Bank();
        b.setName("ミヤビ");
    }
    
    //異常系: nullをセットしようとしたら例外が起きるべき
    @Test public void setNameWithNull() {
        try {
            Bank b = new Bank();
            b.setName(null);
        } catch(NullPointerException e) {
            return;
        }
        fail();
    }
    
    //異常系: 2文字をセットしようとしたら例外が起きるべき
    @Test(expected = IllegalArgumentException.class)
    public void throwExceptionWithTwoCharName() {
        Bank b = new Bank();
        b.setName("ミヤ");
    }
}
