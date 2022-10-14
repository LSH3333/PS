import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    static int n;
    static int[][] ans = new int[110][110];
    static ArrayList<Integer>[] list;

    static void dfs(int i, ArrayList<Boolean> mark, ArrayList<Integer> canVisit)
    {
        for(int x : list[i])
        {
            if(mark.get(x)) continue;
            mark.set(x, true);
            canVisit.add(x);
            dfs(x, mark, canVisit);
        }
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        list = new ArrayList[n];
        for(int i = 0; i < n; i++) list[i] = new ArrayList<>();
        for(int i = 0; i < n; i++)
        {
            String[] _s = br.readLine().split(" ");
            for(int j = 0; j < n; j++)
            {
                if(_s[j].equals("1")) list[i].add(j);
            }
        }

        for(int i = 0; i < n; i++)
        {
            ArrayList<Boolean> mark = new ArrayList<>();
            for(int j = 0; j < n; j++) mark.add(false);
            ArrayList<Integer> canVisit = new ArrayList<>();
            dfs(i, mark, canVisit);
            for(int j : canVisit) ans[i][j] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                System.out.print(ans[i][j] + " ");
            } System.out.println();
        }
    }

}
