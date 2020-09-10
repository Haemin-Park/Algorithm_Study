/*1149번

RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다. 
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 
집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.
*/
import java.util.Scanner;
class  Main
{
	static int N;
	static char result[];
	static int[] red;
	static int[] green;
	static int[] blue;
	//static char red='R',blue='B',green='G';

	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		
		N=sc.nextInt();
		
		for(int i=0; i<N; i++) red[i] = sc.next().charAt(0);
		for(int i=0; i<N; i++) green[i] = sc.next().charAt(0);
		for(int i=0; i<N; i++) blue[i] = sc.next().charAt(0);
		
		solve();
		//System.out.println("Hello World!");
		
	}

	public static void solve(){
		//양옆의 색이 다르면서 비용의 최솟값 구하기
		for(int i=0;i<N;i++)
			if(result[i]=='G') {result[i-1]!='G'; result[i+1]!='G';}
			//n-1과 n+1 
			
	}
}

