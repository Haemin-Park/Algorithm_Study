//블랙잭 규칙
//n개의 카드 중에서 3장의 카드를 뽑아서
//뽑은 카드의 수의 합 중 M보다 작은 값을 구해 출력
//입력: n카드수, m기준값, 카드 숫자
//출력: 최대합
import java.util.Scanner;

public class Main {
//	int total;
	static int m,n=0;
	static int[] arr,picked;
	static int result;

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		n=sc.nextInt();
		m=sc.nextInt();
		
		arr=new int[n];
		picked=new int[n];
		for(int i=0;i<arr.length;i++) {
			arr[i]=sc.nextInt();
		}
		
		blackjack(0,0);
		System.out.println(result);
	}

	public static void blackjack(int start, int num) {
		//재귀 사용 카드 세 장 뽑기  
		if(num == 3) {
			int sum =0; 
			
			for(int i=0; i<3; i++) {
				sum += picked[i];
			}
			
			if(sum <= m) result = Math.max(result, sum);			
			return;
		}

		for(int i=start; i<n; i++) {
			picked[num] = arr[i];
			blackjack(i+1, num+1);
		}}
}
