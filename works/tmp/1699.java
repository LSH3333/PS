import java.util.*;

public class Main {	
	public static void main(String[] args)
	{	
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] d = new int[100001];
		
		d[0] = 0;
		d[1] = 1;
		
		for(int i = 2; i <= n; i++)
		{
			int smallest = 100001;
			int num = 1;
			while(i - num * num >= 0)
			{
				smallest = Math.min(smallest, d[i-num*num]+1);
				num++;
			}
			d[i] = smallest;
		}
		
		System.out.println(d[n]);
	}
}
