import java.io.*;
import java.util.*;

public class Main
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        boolean[] S = new boolean[21];
        int m = Integer.parseInt(br.readLine());

        while(m-- > 0)
        {
            String order = br.readLine();
            String op; int num =0;

            int idx = order.indexOf(' ');
            if(idx != -1)
            {
                op = order.substring(0, idx);
                num = Integer.parseInt(order.substring(idx+1));
            }
            else
                op = order;

            if(op.equals("add"))
            {
                S[num] = true;
            }
            else if(op.equals("remove"))
            {
                S[num] = false;
            }
            else if(op.equals("check"))
            {
                if(S[num]) bw.write("1\n");
                else bw.write("0\n");
            }
            else if(op.equals("toggle"))
            {
                S[num] = !S[num];
            }
            else if(op.equals("all"))
            {
                Arrays.fill(S, true);
            }
            else if(op.equals("empty"))
            {
                Arrays.fill(S, false);
            }
        }

        bw.flush();
        bw.close();
    }

}
