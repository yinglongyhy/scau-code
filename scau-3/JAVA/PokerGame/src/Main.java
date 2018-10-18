import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int pokerNum, playersNum;
        Scanner scanner = new Scanner(System.in);
        System.out.print("输入扑克牌幅数：");
        pokerNum = scanner.nextInt();
        System.out.print("输入人数：");
        playersNum = scanner.nextInt();
        PokerGame pokerGame = new PokerGame(pokerNum, playersNum);
        pokerGame.pullPoker();
        pokerGame.show();
    }

}
