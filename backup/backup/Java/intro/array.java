public class Main {
    public static void main (String[] args) {
        int[] score = new int [5];
        
        int N = score.length;
        
        for( int i = 0; i < N; i++ ) {
            score[i] = i;
        }
        
        System.out.println(score[1]);
    }
}
