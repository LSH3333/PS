import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Set;
import java.util.HashSet;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        ArrayList<ArrayList<Integer>> v = new ArrayList<>();
        for(int i = 1; i <= 12; i++)
        {
            if(i == 1 || i == 3 || i == 5 || i == 7 || i ==8 || i==10 || i==12)
            {
                ArrayList<Integer> al = new ArrayList<>();
                for(int j = 0; j < 31; j++) al.add(0);
                v.add(al);
            }
            else if(i==4 || i==6 || i ==9 || i==11)
            {
                ArrayList<Integer> al = new ArrayList<>(30);
                for(int j = 0; j < 30; j++) al.add(0);
                v.add(al);
            }
            else
            {
                ArrayList<Integer> al = new ArrayList<>(28);
                for(int j = 0; j < 28; j++) al.add(0);
                v.add(al);
            }
        }

        int n = 0;
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v.get(i).size(); j++)
            {
                v.get(i).set(j, n);
                n = (n + 1) % 7;
            }
        }

        int x = sc.nextInt(); int y = sc.nextInt();
        String[] day = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
        System.out.println(day[v.get(x-1).get(y-1)]);
    }
}
