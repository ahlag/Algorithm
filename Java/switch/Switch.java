import java.io.*;

class Switch {
    public static void main(String[] args) throws IOException {
        System.out.println("Please type a or b.");
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String str = br.readLine();
        char res = str.charAt(1);
        
        switch(res) {
            case 'a':
                System.out.println("a is typed");
                break;
            case 'b':
                System.out.println("b is typed");
                break;
            default:
                System.out.println("Please type a or b.");
                break;
        }
    }
}
