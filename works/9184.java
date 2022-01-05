import java.util.*;

class Main
{
    static int[][][] d = new int[51][51][51];

    static int w(int a, int b, int c)
    {
        if(a <= 0 || b <= 0 || c <= 0) return 1;
        if(a > 20 || b > 20 || c > 20) return d[20][20][20];

        if(d[a][b][c] > 0) return d[a][b][c]; // memoization
        if(a < b && b < c)
        {
            d[a][b][c-1] = w(a,b,c-1);
            d[a][b-1][c-1] = w(a,b-1,c-1);
            d[a][b-1][c] = w(a,b-1,c);
            return d[a][b][c-1] + d[a][b-1][c-1] - d[a][b-1][c];
        }

        d[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
        return d[a][b][c];
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        d[0][0][0] = 1;
        d[20][20][20] = 1048576;

        while(true)
        {
            int a, b, c;
            a = sc.nextInt(); b = sc.nextInt(); c = sc.nextInt();
            if(a == -1 && b == -1 && c == -1) break;

            int ans = w(a,b,c);
            String answer = "w(";
            answer += Integer.toString(a);
            answer += ", ";
            answer += Integer.toString(b);
            answer += ", ";
            answer += Integer.toString(c);
            answer += ") = ";
            answer += Integer.toString(ans) + '\n';
            System.out.print(answer);
        }

    }

}
