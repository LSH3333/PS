import java.io.IOException;
import java.util.Scanner;


public class Main
{
    static int N, goalR, goalC;



    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        goalR = sc.nextInt();
        goalC = sc.nextInt();

        System.out.println(dfs(N, 0, 0, 0));

    }

    private static int dfs(int n, int startNum, int startR, int startC) {
        if(n == 0) {
            return startNum;
        }

        int length = (int)Math.pow(2, n);
        int cnt = (length / 2) * (length / 2);
        int area = FindArea(length, startR, startC);

        if(area == 0) {
            return dfs(n-1, startNum + (cnt * area), startR, startC);
        }
        else if(area == 1) {
            return dfs(n-1, startNum + (cnt * area), startR, startC + (length / 2));
        }
        else if(area == 2) {
            return dfs(n-1, startNum + (cnt * area), startR + (length / 2), startC);
        }
        else {
            return dfs(n-1, startNum + (cnt * area), startR + (length / 2), startC + (length / 2));
        }
    }

    private static int FindArea(int length, int _r, int _c) {
        // 0 사분면
        if(goalR - _r <= (length / 2)-1 && goalC - _c <= (length / 2) -1) {
            return 0;
        }
        // 1 사분면
        if(goalR - _r <= (length / 2) - 1 && goalC - _c <= length - 1) {
            return 1;
        }
        // 2 사분면
        if(goalR - _r <= length - 1 && goalC - _c <= (length / 2) - 1) {
            return 2;
        }
        // 3 사분면
        else {
            return 3;
        }
    }


}

