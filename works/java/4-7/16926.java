import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


public class Main
{
    static int N, M, R;
    static int[][] before = new int[301][301];
    static int[][] after = new int[301][301];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException
    {
        String[] _s = br.readLine().split(" ");
        N = Integer.parseInt(_s[0]);
        M = Integer.parseInt(_s[1]);
        R = Integer.parseInt(_s[2]);

        for(int r = 0; r < N; r++) {
            _s = br.readLine().split(" ");
            for(int c = 0; c < M; c++) {
                before[r][c] = Integer.parseInt(_s[c]);
            }
        }

        int r = 0, c = 0, H = N, W = M;
        while(true) {
            CalOneRec(r, c, H, W);
            r++; c++;
            H-=2; W-=2;
            if(H < 2 || W < 2) break;
        }

        Print();

    }

    static void Print() {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                sb.append(after[i][j]).append(' ');
            }
            sb.append('\n');
        }
        System.out.println(sb);
    }

    static void CalPosition(int r, int c, int idx, int[] v) {
        int num = before[r][c];
        v[(idx + R) % v.length] = num;
    }

    static void CalOneRec(int _r, int _c, int H, int W) {
        int length = (H + W) * 2 - 4;
        int[] v = new int[length];
        int r = _r;
        int c = _c;
        int idx = 0;

        // down
        for(; r < _r+H; r++, idx++)
        {
            CalPosition(r, c, idx, v);
        }
        r--;

        // right
        for(c = c+1; c < _c+W; c++, idx++)
        {
            CalPosition(r, c, idx, v);
        }
        c--;

        // up
        for(r = r-1; r >= _r; r--, idx++)
        {
            CalPosition(r, c, idx, v);
        }
        r++;

        // left
        for(c = c-1; c >= _c; c--, idx++)
        {
            CalPosition(r, c, idx, v);
        }


        //
        r = _r; c = _c;
        idx = 0;
        // down
        for(; r < _r+H; r++, idx++)
        {
            after[r][c] = v[idx];
        }
        r--;

        // right
        for(c = c+1; c < _c+W; c++, idx++)
        {
            after[r][c] = v[idx];
        }
        c--;

        // up
        for(r = r-1; r >= _r; r--, idx++)
        {
            after[r][c] = v[idx];
        }
        r++;

        // left
        for(c = c-1; c >= _c+1; c--, idx++)
        {
            after[r][c] = v[idx];
        }

    }
}

