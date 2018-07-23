package com.scau;

import java.util.Arrays;

public class Card {
    public final static String[] cards = {
            "方块2", "方块3", "方块4", "方块5", "方块6", "方块7", "方块8", "方块9", "方块10", "方块J", "方块Q", "方块K", "方块A",
            "梅花2", "梅花3", "梅花4", "梅花5", "梅花6", "梅花7", "梅花8", "梅花9", "梅花10", "梅花J", "梅花Q", "梅花K", "梅花A",
            "红桃2", "红桃3", "红桃4", "红桃5", "红桃6", "红桃7", "红桃8", "红桃9", "红桃10", "红桃J", "红桃Q", "红桃K", "红桃A",
            "黑桃2", "黑桃3", "黑桃4", "黑桃5", "黑桃6", "黑桃7", "黑桃8", "黑桃9", "黑桃10", "黑桃J", "黑桃Q", "黑桃K", "黑桃A",
    };
    public int id;
    public String name;
    public String[] handcard;

    public Card(int id, String name) {
        handcard = new String[2];
        this.id = id;
        this.name = name;
    }

    /**
     * 选择最大的手牌
     */
    public String getMaxCard() {
        int index1 = Arrays.binarySearch(cards, handcard[0]);
        int index2 = Arrays.binarySearch(cards, handcard[1]);
        System.out.print(this.name + "最大的手牌为:");
        if(index1 % 13 > index2 % 13) {
            System.out.println(handcard[0]);
            return handcard[0];
        }
        else if(index1 % 13 < index2 % 13) {
            System.out.println(handcard[1]);
            return handcard[1];
        }
        else{
            if(index1 > index2) {
                System.out.println(handcard[0]);
                return handcard[0];
            }
            else if(index1 < index2) {
                System.out.println(handcard[1]);
                return handcard[1];
            }
        }
        return null;
    }
}
