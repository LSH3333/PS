import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

public class Main
{
    static int N;

    static void Draw(int r, int c, int cnt, int depth, char[][] stars)
    {
        stars[r][c] = '*';
        // up
        for(int i = 0; i < cnt-1; i++)
        {
            r--;
            stars[r][c] = '*';
        }

        // right
        for(int i = 0; i < cnt-1; i++)
        {
            c++;
            if(c >= stars[r].length) break;
            stars[r][c] = '*';
        }

        if(depth == N-1) return;

        // down
        for(int i = 0; i < cnt+2-1; i++)
        {
            r++;
            stars[r][c] = '*';
        }

        // left
        for(int i = 0; i < cnt+2-1; i++)
        {
            c--;
            stars[r][c] = '*';
        }

        Draw(r, c, cnt+4, depth+1, stars);

    }

    static void Print(char[][] stars)
    {
        for(int i = 0; i < stars.length; i++)
        {
            if(i == 1)
                System.out.println('*');
            else
            {
                for(int j = 0; j < stars[i].length; j++)
                    System.out.print(stars[i][j]);
                System.out.println();
            }
        }
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        if(N == 1) { System.out.print('*'); return; }

        char[][] stars = new char[4*N-2+1][4*N-4+1];
        for(int i = 0; i < stars.length; i++)
        {
            for(int j = 0; j < stars[0].length; j++)
            {
                stars[i][j] = ' ';
            }
        }

        Draw(2*N, 2*N-2, 3, 0, stars);
        
        Print(stars);

    }
}
