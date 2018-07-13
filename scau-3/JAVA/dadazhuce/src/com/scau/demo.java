package com.scau;
import java.util.Scanner;

public class demo {
    public static void main(String[] args) {
        //实例化车
        //用一维数组保存各种车的对象
        Car[] car = new Car[6];
        car[0] = new Audi_A4();
        car[1] = new Mazda6();
        car[2] = new PickupSnow();
        car[3] = new JingLong();
        car[4] = new SongHuaRriver();
        car[5] = new YiWeiKe();

        //实例化Scanner输入对象
        Scanner input = new Scanner(System.in);

        //例行询问
        System.out.println("欢迎使用答答租车系统：");
        System.out.println("您是否要租车： 1是  0 否");

        //判断是否继续
        int choice = input.nextInt();
        if (choice == 0) return;

        //打印车辆类型及其价目表
        System.out.println("您可租车的类型及其价目表");
        System.out.println("序号  汽车名称      租金          容量");
        for (int i = 0; i < car.length; i++) {
            System.out.print(i + 1 + ".   ");
            car[i].showCar();
        }

        //询问客户要租汽车的数量 用int n 接受
        System.out.println("请输入您要租汽车的数量");
        int n = input.nextInt();

        //定义变量保存信息
        int carRent = 0;
        int carManned = 0;
        int carCargo = 0;

        //定义一维数组保存6种汽车的选择状态
        boolean[] choices = {false, false, false, false, false, false};

        //循环n次计算
        for (int i = 1; i <= n; i++) {
            System.out.println("请输入第" + i + "辆车的序号");
            choice = input.nextInt();//利用choice接受用户选择

            //更改选择标记
            choices[choice - 1] = true;

            //计算租金、载人数、载货量
            carRent += car[choice - 1].carRent;
            carManned += car[choice - 1].carManned;
            carCargo += car[choice - 1].carCargo;

        }//end for

        //根据输入天数计算租金 用n接收
        System.out.println("请输入租车天数：");
        n = input.nextInt();
        carRent *= n;

        //打印账单
        System.out.println("您的账单：");
        System.out.println("***可载人的车有：");
        for (int i = 0; i < car.length; i++) {
            if(choices[i] && car[i].carManned != 0) System.out.print("   " + car[i].carName);
        }
        System.out.println("    共载人：" + carManned + "人");
        System.out.println("***可载货的车有：");
        for (int i = 0; i < car.length; i++) {
            if(choices[i] && car[i].carCargo != 0) System.out.print("   " + car[i].carName);
        }
        System.out.println("    共载货：" + carCargo + "吨");
        System.out.println("***租车总价格：" + carRent + "元");
    }
}
