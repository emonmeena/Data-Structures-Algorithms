package Abstraction;

public class RepairShop {
    public static void repairCar(Car car){
        System.out.println(car+" Car has been repaired");
    }
   

    public static void main(String[] args) {
        WagonR objWagonR = new WagonR();
        Audi objAudi = new Audi();
        repairCar(objWagonR);
        repairCar(objAudi);
    }
}