import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();

        int sum = 0;
        boolean isZero = false;
        for(int i = 0; i < n.length(); i++)
        {
            if(n.charAt(i) == '0') isZero = true;
            sum += n.charAt(i) - '0';
        }

        if(sum % 3 == 0 && isZero)
        {
            String[] array = n.split("");
            Arrays.sort(array, Collections.reverseOrder());
            String descending = String.join("", array);
            System.out.print(descending);
        }
        else
            System.out.print(-1);

    }
}
