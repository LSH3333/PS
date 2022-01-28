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
    Pair(int _r, int _c, int _depth)
    {
        r = _r;
        c = _c;
        depth = _depth;
    }
}

public class Main
{
    static ArrayList<String> map = new ArrayList<>();
    static boolean[][] mark = new boolean[110][110];
    static int n, m, answer = 2000000000;
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};

    static void bfs()
    {
        Queue<Pair> q = new LinkedList<>();
        mark[0][0] = true;
        q.add(new Pair(0, 0, 1));

        while(!q.isEmpty())
        {
            Pair front = q.poll();
            int r = front.r;
            int c = front.c;
            int depth = front.depth;

            if(r == n-1 && c == m-1)
            {
                answer = Math.min(answer, depth);
                continue;
            }

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(mark[nr][nc] || map.get(nr).charAt(nc) == '0') continue;
                mark[nr][nc] = true;
                q.add(new Pair(nr, nc, depth+1));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
//        n = sc.nextInt(); m = sc.nextInt(); sc.nextLine();
        String[] _s = br.readLine().split(" ");
        n = Integer.parseInt(_s[0]);
        m = Integer.parseInt(_s[1]);
        for(int i = 0; i < n; i++)
        {
            String str = br.readLine();
            map.add(str);
        }

        bfs();

        System.out.print(answer);
    }
}
