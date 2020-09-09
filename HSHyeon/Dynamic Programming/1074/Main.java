
/*1074번
분할정복 

한수는 2차원 배열 (항상 2^N * 2^N 크기이다)을 Z모양으로 탐색하려고 한다. 예를 들어, 2*2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
만약, 2차원 배열의 크기가 2^N * 2^N라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 4등분 한 후에 (크기가 같은 2^(N-1)로) 재귀적으로 순서대로 방문한다.
다음 예는 2^2 * 2^2 크기의 배열을 방문한 순서이다.
N이 주어졌을 때, (r, c)를 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.
*/
import java.util.Scanner;
class  Main
{
	static int size;
	static int N,r,c;
	static int result;

	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);

		N=sc.nextInt();
		r=sc.nextInt();
		c=sc.nextInt();

		size=Integer.parseInt(String.valueOf((Math.pow(2,N))));
		int arr[][] = new int[size][size]; //배열

		//System.out.println("Hello World!");
	}

	public static void solve(){
		int count;
	
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				count++;
				if(i==r&&j==c) count=result;
		}
	}
		public static void solve2(int r, int c){
		count++; 
		if(i==r&&j==c) {count=result; return;}
		}
	}
}
