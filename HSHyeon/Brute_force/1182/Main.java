import java.util.Scanner;
//1182 부분수열의 합
//N개의 정수 수열, 양수인 부분수열 중 원소를 다 더한 값이 S가 되는 경우의 수
//입력 N과 S, 수열 N개의 정수
//합이 S가 되는 부분수열의 개수

public class  Main 
{
	static int[] arr;
	static int result;
	static int N,S=0;

	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);

		N=sc.nextInt();
		S=sc.nextInt();
		
		arr = new int[N];
		
		for(int i=0; i<N; i++) {
				arr[i] = sc.nextInt();
		}
		
		Solve(0,0,0);

		System.out.println(result);
	}

	
	public static void Solve(int num,int sum, int length){
		if(num>=N) return; 
		sum=sum+arr[num];
		if(sum==S&& length>0)result++;

		Solve(num+1,sum,length+1);
		Solve(num+1,sum-arr[num],length);
	}
	
} 
