class Sample1 {
    public static void main(String[] ags) {
        
        try {
            int[] test = new int[5];
        
            System.out.println("test[10]に値を代入します。");
            test[10] = 80;
            System.out.println("test[10]に80を値を代入します。");
            System.out.println("無事に終了しました。");
        } catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("配列数の要素をこえています。");
            System.out.println(e + "という例外が発生しました。");
        } finally {
            System.out.println("最後に必ずこの処理を行う。");
        }
        System.out.println("無事に終了しました");
    }
}
