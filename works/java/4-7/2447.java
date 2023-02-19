import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class Main
{
    static int N;

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        char[][] prev = new char[1][1];
        prev[0][0] = '*';
        recur(3, prev);
    }

    public static void recur(int n, char[][] prev) {
        if(n > N) {
            Print(prev);
            return;
        }

        char[][] board = new char[n][n];
        for(int i = 0; i < n; i++) {
            Arrays.fill(board[i], ' ');
        }


        int r = 0, c = 0;
        for(int cnt = 0; cnt < 9; cnt++) {
            if(cnt != 4) {
                for(int i = r; i < r+n/3; i++) {
                    for(int j = c; j < c+n/3; j++) {
                        board[i][j] = prev[i-r][j-c];
                    }
                }
            }

            if(c+n/3 >= n) {
                r = r + n / 3;
                c = 0;
            }
            else {
                c = c + n / 3;
            }
        }

        recur(n*3, board);
    }

    static void Print(char[][] prev) {
        StringBuilder sb = new StringBuilder();
        for (char[] chars : prev) {
            for (char aChar : chars) {
                sb.append(aChar);
            }
            sb.append('\n');
        }
        System.out.println(sb);
    }

}

