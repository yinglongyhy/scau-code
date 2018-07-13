package com.scau;

public abstract class Car {
    public String carName;//车名
    public int carRent;//车每天的租金
    public int carManned;//车载人数
    public int carCargo;//车载货量  吨

    public void showCar(){
        System.out.print(carName + "\t      " + carRent + "元/天\t");
        if(carManned != 0) System.out.print("  载人：" + carManned + "人 ");
        if(carCargo != 0) System.out.print("  载货：" + carCargo + "吨");
        System.out.println();
    }

}
