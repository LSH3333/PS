import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;

class Pair
{
    int r;
    int c;
    Pair(int _r, int _c) { r = _r; c = _c; }
}

public class Main
{
    static ArrayList<String> map = new ArrayList<>();
    static int[][] mark = new int[30][30];
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};
    static ArrayList<Integer> answer = new ArrayList<>();
    static int N;

    static void bfs(int r, int c, int cnt)
    {
        Queue<Pair> q = new LinkedList<>();
        mark[r][c] = cnt;
        q.add(new Pair(r,c));
        int numberOfHouse = 1;

        while(!q.isEmpty())
        {
            Pair front = q.poll();
            int nr = front.r;
            int nc = front.c;

            for(int i = 0; i < 4; i++)
            {
                int nnr = nr + dr[i];
                int nnc = nc + dc[i];
                if(nnr < 0 || nnr >= N || nnc < 0 || nnc >= N) continue;
                if(mark[nnr][nnc] > 0 || map.get(nnr).charAt(nnc) == '0') continue;
                mark[nnr][nnc] = cnt;
                q.add(new Pair(nnr, nnc));
                numberOfHouse++;
            }
        }
        answer.add(numberOfHouse);
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++)
        {
            String tmp = br.readLine();
            map.add(tmp);
        }

        int cnt = 1;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(map.get(i).charAt(j) == '1' && mark[i][j] == 0)
                {
                    bfs(i, j, cnt);
                    cnt++;
                }
            }
        }

        Collections.sort(answer);
        System.out.println(cnt-1);
        for(int x : answer) System.out.println(x);
    }

}
