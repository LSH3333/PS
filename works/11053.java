import java.util.*;

class Main
{

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int answer = 1;
        ArrayList<Integer> v = new ArrayList<>();
        int n = sc.nextInt();
        for(int i = 0; i < n; i++)
        {
            int num = sc.nextInt();
            v.add(num);
        }

        int[] d = new int[1010];
        d[0] = 1;
        for(int i = 1; i < n; i++)
        {
            int highest = 0;
            for(int j = 0; j < i; j++)
            {
                if(v.get(j) < v.get(i)) highest = Math.max(highest, d[j]);
            }
            d[i] = highest + 1;
            answer = Math.max(answer, d[i]);
        }
        System.out.print(answer);
    }

}
