import java.util.Arrays;
import java.util.Random;

public class PokerGame {
    private int[] poker;
    private int[][] players;
    private int playersOfNum;
    private int pokerOfNum;

    public PokerGame(int pokerOfNum, int playersOfNum) {
        this.playersOfNum = playersOfNum;
        this.players = new int[playersOfNum][pokerOfNum * 52 / playersOfNum + 3];
        for (int i = 0; i < playersOfNum; i++) {
            players[i][0] = 0;
        }
        this.pokerOfNum = pokerOfNum;
        this.poker = new int[52];
        /*
        黑桃为52-40
         */
        for (int i = 1; i <= 52; i++) {
            this.poker[i - 1] = i;
        }
    }

    public void Shuffle() {
        Random random = new Random();
        for (int i = 0; i < 500; i++) {
            int j = random.nextInt(42);
            int a = poker[j];
            poker[j] = poker[j + 10];
            poker[j + 10] = a;
        }
    }

    public void pullPoker() {
        int playerOfIndex = 0;
        for (int i = 0; i < pokerOfNum; i++) {
            Shuffle();
//            for (Integer anEachPoker : eachPoker) {
            for (Integer anEachPoker : poker) {
//                System.out.print(anEachPoker + " ");
                int k = players[playerOfIndex][0] + 1;
                players[playerOfIndex][k] = anEachPoker;
                players[playerOfIndex][0]++;
                playerOfIndex = (playerOfIndex + 1) % playersOfNum;
            }
        }
    }

    private String print(int onePoker) {
        String a = "";
//        if (onePoker >= 1 && onePoker <= 13) {
//            a = a + "方块";
//        } else if (onePoker >= 14 && onePoker <= 26) {
//            a = a + "草花";
//        } else if (onePoker >= 27 && onePoker <= 39) {
//            a = a + "红心";
//        } else if (onePoker >= 40 && onePoker <= 52) {
//            a = a + "黑桃";
//        }

        String b = null;

        switch (onePoker % 13) {
            case 1: b = "A"; break;
            case 11: b = "J"; break;
            case 12: b = "Q"; break;
            case 0: b = "K"; break;
            default:
                b = String.valueOf(onePoker % 13);
        }

        return a + b;
    }

    public void show() {

        for (int i = 0; i < playersOfNum; i++) {
            System.out.println("第" + (i + 1) + "个人：");
            Arrays.sort(players[i], 1, players[i][0] + 1);
            int j = 0;
            System.out.print("黑桃：");
            for (j = players[i][0]; j > 0; j--) {
                if (players[i][j] < 40) {
                    System.out.println();
                    break;
                }
                System.out.print(print(players[i][j]) + " ");
            }

            System.out.print("红心：");
            for (; j > 0; j--) {
                if (players[i][j] < 27) {
                    System.out.println();
                    break;
                }
                System.out.print(print(players[i][j]) + " ");
            }

            System.out.print("草花：");
            for (; j > 0; j--) {
                if (players[i][j] < 14) {
                    System.out.println();
                    break;
                }
                System.out.print(print(players[i][j]) + " ");
            }

            System.out.print("方块：");
            for (; j > 0; j--) {
                System.out.print(print(players[i][j]) + " ");
            }
            System.out.println();
        }
    }

}
