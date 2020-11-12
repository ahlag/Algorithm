import java.util.*;

public class Treeset{
    public static void main(String[] args) {
        Map<String, Integer> prefs = new HashMap<String, Integer>();
            prefs.put("Kyoto", 255);
            prefs.put("Tokyo", 1261);
            prefs.put("Kumamoto", 181);
        
            int tokyo = prefs.get("Tokyo");
            System.out.println("The population of Tokyo is " + tokyo);
            prefs.remove("Kyoto");
        
            prefs.put("Kumamoto", 182);
            int kumamoto = prefs.get("Kumamoto");
            System.out.println("The population of Kumamoto is " + kumamoto);
        
            System.out.println();
        
            for(String key : prefs.keySet()) {
                int population = prefs.get(key);
                System.out.println(key + "'s population is " + population);
            }
    }
}
