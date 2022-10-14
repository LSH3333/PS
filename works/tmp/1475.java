import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        String number = sc.next();
        int[] nums = new int[10];
        for(int i = 0; i < number.length(); i++) nums[number.charAt(i)-'0']++;
        int a = 0, b = 0;
        for(int i = 0; i < 10; i++)
        {
            if(i == 6 || i == 9) continue;
            a = Math.max(a, nums[i]);
        }
        b = nums[6] + nums[9];
        if(b % 2 != 0) b = b / 2 + 1;
        else b = b / 2;
        System.out.print(Math.max(a, b));
    }
}
