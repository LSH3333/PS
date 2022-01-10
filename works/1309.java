import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main
{

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int MOD = 9901;
        int[][] d = new int[n+1][3];

        // 세로 길이 n일때 n번 행에 사자가 없는 경우
        d[1][0] = 1;
        // 세로 길이 n일때 n번 행에 왼쪽만 사자가 있는 경우
        d[1][1] = 1;
        // 세로 길이 n일때 n번 행에 오른쪽만 사자가 있는 경우
        d[1][2] = 1;

        for(int i = 2; i <= n; i++)
        {
            d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % MOD;
            d[i][1] = (d[i-1][0] + d[i-1][2]) % MOD;
            d[i][2] = (d[i-1][0] + d[i-1][1]) % MOD;
        }

        System.out.print((d[n][0] + d[n][1] + d[n][2]) % MOD);
    }

}
