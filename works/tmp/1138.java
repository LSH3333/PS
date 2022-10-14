import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;



public class Main
{
    static int N;
    static boolean fin = false;

    static void Permutation(int[] line, boolean[] mark, ArrayList<Integer> l, int depth, int[] order)
    {
//        if(fin) return;

        if(depth == N)
        {
//            for(Integer x : l)
//            {
//                System.out.print(x + " ");
//            }
//            System.out.println();

            boolean isAnswer = true;
            for(int i = 1; i <= N; i++)
            {
                int cur = l.get(i);
                int taller = order[cur];
                int cnt = 0;
                for(int j = 1; j < i; j++)
                {
                    if(l.get(j) > l.get(i)) cnt++;
                }
                if(cnt != taller) { isAnswer = false; break; }
            }
            if(isAnswer)
            {
                for(int i = 1; i <= N; i++) System.out.print(l.get(i) + " ");
                fin = true;
            }

            return;
        }

        for(int i = 1; i <= N; i++)
        {
            if(mark[i]) continue;
            mark[i] = true;
            l.add(line[i]);
            Permutation(line, mark, l, depth+1, order);
            mark[i] = false;
            l.remove(l.size()-1);
        }
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        int[] line = new int[N+1];
        for(int i = 1; i <= N; i++) line[i] = i;

        String[] _s = br.readLine().split(" ");
        int[] order = new int[N+1];
        for(int i = 1; i <= N; i++) order[i] = Integer.parseInt(_s[i-1]);

        boolean[] mark = new boolean[N+1];

        ArrayList<Integer> l = new ArrayList<>();
        l.add(0);
        Permutation(line, mark, l, 0, order);

    }
}
