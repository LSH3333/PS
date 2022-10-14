import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        HashMap<Integer, Integer> m = new HashMap<>();
        int num = a, cnt = 1;

        while(true)
        {
            if(m.get(num) != null)
            {
                System.out.print(m.size() - (m.get(num)-1));
                break;
            }
            m.put(num, cnt++);
            num = num * a % b;
        }
    
    }
}
