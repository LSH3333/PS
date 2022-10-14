import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int A, B, C, X, Y;
        A = sc.nextInt(); B = sc.nextInt(); C = sc.nextInt();
        X = sc.nextInt(); Y = sc.nextInt();
        int cost = 0;
        
        while(true)
        {
            int x=1, y=1;
            if(X <= 0) x = 0;
            if(Y <= 0) y = 0;

            int a = cost + A*x + B*y;
            int b = cost + C * 2;
            cost = Math.min(a,b);

            X--; Y--;
            if(X < 0 && Y < 0) break;
        }
        System.out.print(cost);
    }
}
