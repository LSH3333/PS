import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        String n = _s[0];
        String m = _s[1];

        while(n.length() != m.length())
            n = "0" + n;

        int cnt = 0;
        String _n = n;
        String _m = m;
        for(int i = n.length()-1; i >= 0; i--)
        {
            if(n.charAt(i) == '8' && m.charAt(i) == '8')
            {
                n = n.substring(0,i) + '9' + n.substring(i+1);
                if(n.compareTo(m) > 0) cnt++;
                else { n = _n; m = _m; }
            }
        }
        System.out.println(cnt);
    }

}
