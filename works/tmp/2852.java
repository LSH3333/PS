import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

class Pair
{
    int first, second;
    public Pair(int _first, int _second) {first=_first; second=_second;}
}

class Tuple
{
    int x, y, z;
    public Tuple(int _x, int _y, int _z) {x=_x; y=_y; z=_z;}
}

public class Main
{
    static int ChangeToSec(String time)
    {
        String m = time.substring(0, 2);
        String s = time.substring(3);
        int m_int = Integer.parseInt(m);
        int s_int = Integer.parseInt(s);
        return m_int * 60 + s_int;
    }

    static String ChangeToMin(int time)
    {
        int m = time / 60;
        int s = time % 60;
        String m_str = Integer.toString(m);
        String s_str = Integer.toString(s);
        if(m_str.length() == 1) m_str = "0" + m_str;
        if(s_str.length() == 1) s_str = "0" + s_str;
        return m_str + ":" + s_str;
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<Pair> goal = new ArrayList<>();
        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++)
        {
            String[] _s = br.readLine().split(" ");
            int team = Integer.parseInt(_s[0]);
            String time = _s[1];
            goal.add(new Pair(team, ChangeToSec(time)));
        }
        goal.add(new Pair(0, 60*48));

        int t1 = 0, t2 = 0;
        ArrayList<Tuple> v = new ArrayList<>();
        for(int i = 0; i < N; i++)
        {
            if(goal.get(i).first == 1) t1++; else t2++;
            if(t1 == t2) continue;
            int winning = t1 > t2 ? 1 : 2;
            v.add(new Tuple(goal.get(i).second, goal.get(i+1).second, winning));
        }

        int t1Time = 0;
        int t2Time = 0;
        for (Tuple tuple : v)
        {
            if (tuple.z == 1) t1Time += tuple.y - tuple.x;
            else t2Time += tuple.y - tuple.x;
        }
        
        System.out.println(ChangeToMin(t1Time));
        System.out.println(ChangeToMin(t2Time));
    }
}
