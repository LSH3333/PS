import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        if(N <= 1)
        {
            System.out.print(1);
            return;
        }
        if(N <= 2)
        {
            if(M >= 9) System.out.print(4);
            else System.out.print((M-1)/2+1);
            return;
        }

        if(M < 5)
        {
            System.out.print(M);
            return;
        }

        if(M <= 5)
        {
            System.out.print(M-1);
            return;
        }

        // 일단 오른쪽으로 1칸씩 끝까지 갔을때, 5칸이상 이라면
        // 4가지 방법 모두 사용해야 하므로, 2칸씩 이동하는 2,3번 방법도 한번씩 사용
        // 즉 2칸 빼줘야함
        if(M > 5)
        {
            System.out.print(M-2);
        }
    }

}
