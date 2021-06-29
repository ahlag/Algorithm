public class MemoryEater {
    public static void main(String args[]) {
        System.out.println("eating memory...");
        long[] larray = new long[1280000];
        for(int i = 0; i < larray.length; i++) {
            larray[i] = i;
        }
    }
}
