import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;

class Pair
{
    int r;
    int c;
    int depth;
    Pair(int _r, int _c) { r = _r; c = _c; }
    Pair(int _r, int _c, int _depth) { r = _r; c = _c; depth = _depth; }
}

public class Main
{
    static int[][] map = new int[1010][1010];
    static int[][] mark = new int[1010][1010];
    static int N, M, answer;
    static ArrayList<Pair> location = new ArrayList<>();
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};

    static void bfs()
    {
        Queue<Pair> q = new LinkedList<>();
        for(Pair x : location)
        {
            q.add(new Pair(x.r, x.c, 1));
            mark[x.r][x.c] = 1;
        }

        while(!q.isEmpty())
        {
            Pair front = q.poll();
            int r = front.r;
            int c = front.c;
            int depth = front.depth;

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                if(map[nr][nc] == -1 || mark[nr][nc] > 0) continue;
                mark[nr][nc] = depth+1;
                q.add(new Pair(nr, nc, depth+1));
                answer = Math.max(answer, depth+1);
            }
        }
    }

    public static void main(String[] args) throws IOException
    {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt(); N = sc.nextInt();
        int numOfZero = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                map[i][j] = sc.nextInt();
                if(map[i][j] == 1) location.add(new Pair(i, j));
                if(map[i][j] == -1) mark[i][j] = -1;
                if(map[i][j] == 0) numOfZero++;
            }
        }
        if(numOfZero == 0) { System.out.print(0); return; }

        bfs();

        boolean success = true;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(mark[i][j] == 0) {success = false; break;}
            }
        }

        if(!success) System.out.print(-1);
        else System.out.print(answer-1);
    }

}
