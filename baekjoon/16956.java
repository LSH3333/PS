import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main
{
    //static char[][] d = new char[501][];
    static String[] d = new String[501];
    static int w, h;

    static int mr[] = {0, 1, 0, -1};
    static int mc[] = {1, 0, -1, 0};

    static boolean bfs(int r, int c)
    {
        if(d[r].charAt(c) != 'W') return true;

        for(int i = 0; i < 4; i++)
        {
            int nr = r + mr[i], nc = c + mc[i];
            if(0 <= nr && nr < h && 0 <= nc && nc < w)
            {
                if(d[nr].charAt(nc) == 'S') return false;
                else if (d[nr].charAt(nc) == '.')
                {
                    char[] charArray = d[nr].toCharArray();
                    charArray[nc] = 'D';
                    d[nr] = String.valueOf(charArray);
                }
            }
        }
        return true;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        h = sc.nextInt(); w = sc.nextInt();

        for(int r = 0; r < h; r++) d[r] = sc.next();
        boolean impossible = false;
        for(int r = 0; r < h; r++)
        {
            for(int c = 0; c < w; c++)
            {
                if(!bfs(r, c)) { impossible = true; break; }
            }
            if(impossible) break;
        }

        if(impossible) System.out.print(0);
        else
        {
            System.out.println(1);
            for(int r = 0; r < h; r++)
                System.out.println(d[r]);
        }


    }

}
