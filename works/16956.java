import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        String[] arr = new String[501];

        for(int i = 0; i < R; i++)
            arr[i] = sc.next();


        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                if(arr[i].charAt(j) != 'W') continue;
                boolean flag = false;

                if(i-1 >= 0)
                    if(arr[i-1].charAt(j) == 'S') flag = true;
                if(j+1 < C)
                    if(arr[i].charAt(j+1) == 'S') flag = true;
                if(i+1 < R)
                    if(arr[i+1].charAt(j) == 'S') flag = true;
                if(j-1 >= 0)
                    if(arr[i].charAt(j-1) == 'S') flag = true;

                if(flag)
                {
                    System.out.print(0);
                    return;
                }
            }
        }

        System.out.println(1);
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                if(arr[i].charAt(j) == '.') System.out.print('D');
                else System.out.print(arr[i].charAt(j));
            } System.out.println();
        }
    }
}
