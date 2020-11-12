public class Main {
    
    public static void incArray(int[] array) {
        for(int i = 0; i < array.length; i++ ) {
            array[i]++;
        }
    }
    
    public static void print(int[] array) {
        for(int i = 0; i < array.length; i++ ) {
            System.out.println(array[i]);
        }
    }
    
    public static void main(String[] args) {
        int[] array = {1,2,3};
        incArray(array);
        print(array);
    }
}
