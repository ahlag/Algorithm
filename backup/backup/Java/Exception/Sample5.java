class Sample5 {
    public static void main(String[] ags) {
        
        Car car1 = new Car();
        try {
            car1.setCar(1234, -10.0);
        } catch(CarException e) {
            System.out.println(e + "が放出されました。");
        }
        car1.show();
    }
}

class CarException extends Exception {
}


class Car {
    private int num;
    private double gas;
    
    public Car() {
        num = 0;
        gas = 0.0;
        System.out.println("車を作成しました。");
    }
    public void setCar(int n, double g) throws CarException {
        if(g<0) {
            CarException e = new CarException();
            throw e;
        } else {
            num = n;
            gas = g;
            System.out.println("ナンバーを" + num + "ガソリン量を" + gas + "にしました。");
        }
    }
    public void show() {
        System.out.println("車のナンバーは" + num + "です。");
        System.out.println(")ガソリン量は" + gas + "です。");
    }
}
