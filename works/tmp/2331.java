import java.util.*;

public class Main
{
    public static int A, P;

    public static int Cal(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            sum += Math.pow(n%10, P);
            n /= 10;
        }
        return sum;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] str = s.split(" ");
        A = Integer.parseInt(str[0]);
        P = Integer.parseInt(str[1]);

        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
        int cnt = 1;
        m.put(A, cnt++);

        while(true)
        {
            A = Cal(A);
            if(m.containsKey(A)) { System.out.print(m.get(A)-1); break; }
            m.put(A, cnt++);
        }
    }
}
