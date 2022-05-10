import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

class Pair
{
    int first, second;
    public Pair(int _f, int _s) { first = _f; second = _s; }
}

public class Main
{
    static int depth = 0;
    static ArrayList<Pair> l = new ArrayList<>();

    static void Hanoi(int num, int from, int by, int to)
    {
        depth++;
        if(num == 1)
        {
            l.add(new Pair(from, to));
            return;
        }

        Hanoi(num-1, from, to, by);
        l.add(new Pair(from, to));
        Hanoi(num-1, by, from, to);
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int n = sc.nextInt();
        Hanoi(n, 1, 2, 3);
        System.out.println(depth);
        for(int i = 0; i < l.size(); i++)
        {
            sb.append(l.get(i).first).append(' ').append(l.get(i).second).append('\n');
        }
        System.out.print(sb);
    }
}
