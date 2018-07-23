package com.scau;


import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

import static com.scau.Card.cards;

public class demo {
    public static void main(String[] args) {
        demo test = new demo();
        Scanner input;
        System.out.println(Arrays.toString(cards));

        int id = 0;
        String name;

        System.out.println("请输入第一位玩家的id");
        while (true) {
            try {
                input = new Scanner(System.in);
                id = input.nextInt();
                break;
            } catch (Exception e) {
                System.out.println("请输入整型id：");
            }
        }
        System.out.println("请输入第一位玩家的姓名");
        name = input.next();
        Card p1 = new Card(id, name);

        System.out.println("请输入第二位玩家的id");
        while (true) {
            try {
                input = new Scanner(System.in);
                id = input.nextInt();
                break;
            } catch (Exception e) {
                System.out.println("请输入整型id：");
            }
        }
        System.out.println("请输入第二位玩家的姓名");
        name = input.next();
        Card p2 = new Card(id, name);

        test.pullCard(p1, p2);
        String p1MaxCard = p1.getMaxCard();
        String p2MaxCard = p2.getMaxCard();
        test.getWinner(p1, p2, p1MaxCard, p2MaxCard);
        System.out.println(p1.name + ":" + Arrays.toString(p1.handcard));
        System.out.println(p2.name + ":" + Arrays.toString(p2.handcard));
    }

    /**
     * 发牌
     */
    public void pullCard(Card p1, Card p2) {
        Random random = new Random();
        int[] flag = {-1, -1, -1, -1};
        for (int i = 0; i < 4; i++) {
            int temp = -1;
            do {
                temp = random.nextInt(52);
            } while (Arrays.binarySearch(flag, temp) >= 0);
            flag[i] = temp;
            if(i % 2 == 0) p1.handcard[i / 2] = cards[temp];
            else p2.handcard[i / 2] = cards[temp];
        }
        System.out.println("发牌结束");
    }

    /**
     * 选出胜者
     */
    public void getWinner(Card p1, Card p2, String card1, String card2) {
        int index1 = Arrays.binarySearch(cards, card1);
        int index2 = Arrays.binarySearch(cards, card2);
        System.out.print("胜者为：");
        if(index1 % 13 > index2 % 13) System.out.println(p1.name);
        else if(index1 % 13 < index2 % 13) System.out.println(p2.name);
        else{
            if(index1 > index2) System.out.println(p1.name);
            else if(index1 < index2) System.out.println(p2.name);
        }
    }
}
