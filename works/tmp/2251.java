import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;

public class Main
{
    static int[] limit = new int[3];
    static int[] bottle = new int[3];
    static boolean[][][] mark = new boolean[210][210][210];
    static ArrayList<Integer> answer = new ArrayList<>();

    static void dfs()
    {
        if(bottle[0] == 0) answer.add(bottle[2]);

        for(int i = 0; i < 3; i++)
        {
            if(bottle[i] == 0) continue;

            for(int j = 0; j < 3; j++)
            {
                if(i == j) continue;
                if(bottle[j] == limit[j]) continue;
                int toPour = limit[j] - bottle[j];
                int i_before = bottle[i], j_before = bottle[j];

                if(bottle[i] - toPour >= 0)
                {
                    bottle[i] -= toPour;
                    bottle[j] += toPour;
                }
                else
                {
                    bottle[j] = bottle[i] + bottle[j];
                    bottle[i] = 0;
                }
                if(mark[bottle[0]][bottle[1]][bottle[2]])
                {
                    bottle[i] = i_before;
                    bottle[j] = j_before;
                    continue;
                }
                mark[bottle[0]][bottle[1]][bottle[2]] = true;
                dfs();
                mark[bottle[0]][bottle[1]][bottle[2]] = false;
                bottle[i] = i_before;
                bottle[j] = j_before;
            }
        }
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        int A = Integer.parseInt(_s[0]);
        int B = Integer.parseInt(_s[1]);
        int C = Integer.parseInt(_s[2]);
        limit[0] = A; limit[1] = B; limit[2] = C;
        bottle[0] = 0; bottle[1] = 0; bottle[2] = C;
        mark[0][0][C] = true;

        dfs();

        Collections.sort(answer);
        ArrayList<Integer> new_answer = new ArrayList<>();
        for(int x : answer)
        {
            if(!new_answer.contains(x)) new_answer.add(x);
        }
        for(int x : new_answer) System.out.print(x + " ");
    }
}
