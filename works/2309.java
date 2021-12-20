import java.sql.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[10];
        int sum = 0;
        for(int i = 0; i < 9; i++)
        {
            arr[i] = sc.nextInt();
            sum += arr[i];
        }
        sum -= 100;

        int target1=0, target2=0;
        for(int i = 0; i < 9; i++)
        {
            for(int j = i+1; j < 9; j++)
            {
                if(arr[i] + arr[j] == sum)
                {
                    target1 = i; target2 = j;
                    break;
                }
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = 0; i < 9; i++)
        {
            if(i == target1 || i == target2) continue;
            ans.add(arr[i]);
        }
        Collections.sort(ans);

        for(int x : ans) System.out.println(x);
    }
}
