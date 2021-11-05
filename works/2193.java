import java.util.*;

public class Main {	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		long[][] d = new long[100][2];
		int n = sc.nextInt();
		
		d[1][0] = 0;
		d[1][1] = 1;
		
		for(int i = 2; i <= n; i++)
		{
			d[i][0] = d[i-1][0] + d[i-1][1];
			d[i][1] = d[i-1][0];
		}
		
		System.out.println(d[n][0] + d[n][1]);		
	}
}
