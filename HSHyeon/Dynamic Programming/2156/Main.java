/*2156번
다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 

연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 
 
1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 
가장 많은 양의 포도주를 마실 수 있도록 

예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 
첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.
*/
import java.util.Scanner;
class  Main
{
	static int N=0;
	static int arr[];
	static int check[];
	public static void main(String[] args) 
	{		
		Scanner sc=new Scanner(System.in);

		N=sc.nextInt(); //포도주 잔 개수
		arr = new int[N];
		check = new int[N];

		for(int i=0; i<N; i++) {
				arr[i] = sc.nextInt(); //각 포도주잔의 포도주 양
		}
		solve();
		//System.out.println("Hello World!");
	}
	public static void solve(){
		//3번 연속 선택하지 않고 최댓값 구하기
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				 
				 if(j>1){
					 if(check[j-1]==1&&check[j-2]==1) return;
					 else check[j]=1;
					  }
			}
		}
	}
}

