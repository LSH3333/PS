import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main
{
    static boolean[] mark = new boolean[10];
    static int[] arr = {1,2,3,4,5,6,7,8,9};
    static ArrayList<Integer> v = new ArrayList<>();
    static ArrayList<Integer> nums = new ArrayList<>();
    static int answer = 999999;

    static boolean IsItMagicS()
    {
        if(v.get(0) + v.get(1) + v.get(2) != 15) return false;
        if(v.get(3) + v.get(4) + v.get(5) != 15) return false;
        if(v.get(6) + v.get(7) + v.get(8) != 15) return false;

        if(v.get(0) + v.get(3) + v.get(6) != 15) return false;
        if(v.get(1) + v.get(4) + v.get(7) != 15) return false;
        if(v.get(2) + v.get(5) + v.get(8) != 15) return false;

        if(v.get(0) + v.get(4) + v.get(8) != 15) return false;
        if(v.get(2) + v.get(4) + v.get(6) != 15) return false;

        return true;
    }

    static void DFS(int depth)
    {
        if(depth == 9)
        {
            if(IsItMagicS())
            {
                int sum = 0;
                for(int i = 0; i < 9; i++) sum += Math.abs(nums.get(i) - v.get(i));
                answer = Math.min(answer, sum);
            }
            return;
        }

        for(int i = 0; i < 9; i++)
        {
            if(mark[i]) continue;
            mark[i] = true;
            v.add(arr[i]);
            DFS(depth+1);
            v.remove(v.size()-1);
            mark[i] = false;
        }
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 9; i++)
        {
            int n = Integer.parseInt(sc.next());
            nums.add(n);
        }

        DFS(0);

        System.out.print(answer);
    }

}
