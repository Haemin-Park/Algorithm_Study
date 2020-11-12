import java.util.Scanner;
//11401 이항계수3

class  Main 
{ 
static int[] arr; 

	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		long div=1000000007;

		int N=sc.nextInt();
		int S=sc.nextInt();
		
		arr = new int[N];
		
		for(int i=0; i<N; i++) {
				arr[i] = sc.nextInt();
		}
		
		Solve();
		int result=num%div;

		System.out.println(result);
		}

	public static long fac(int num){
		
	}

	public static int Solve(){
		fac(N);//nCr=nCk+n-1Cr

	}	
}

 
