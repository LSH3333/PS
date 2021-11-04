import java.util.*;

public class Main 
{
	static int [] d = new int[1000001];
	
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		d[0] = 0;
		d[1] = 0;
		
		for(int i = 2; i <= n; i++)
		{
			int num = d[i-1] + 1;
			if(i % 2 == 0) num = Math.min(d[i/2]+1, num);
			if(i % 3 == 0) num = Math.min(d[i/3]+1, num);
			d[i] = num;
		}
		
		System.out.println(d[n]);
	}

}
