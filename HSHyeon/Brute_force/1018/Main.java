import java.util.Scanner;
//맨 위 칸이 흰색이거나 검정색이거나
//입력: 행n, 열m, 각 생의 상태
//출력: 다시 칠해야 하는 정사각형 개수 최솟값
//그냥 검정 개수랑 하양 개수 비율맞추면 되는거아닌교..

public class Main {
	static char[][] arr;
	static int result=100;
	static char[][] black={{'B','W','B','W','B','W','B','W'},
			       {'W','B','W','B','W','B','W','B'},
			       {'B','W','B','W','B','W','B','W'},
			       {'W','B','W','B','W','B','W','B'},
			       {'B','W','B','W','B','W','B','W'},
			       {'W','B','W','B','W','B','W','B'},
			       {'B','W','B','W','B','W','B','W'},
			       {'W','B','W','B','W','B','W','B'}};
	
	static char[][] white={{'W','B','W','B','W','B','W','B'},
			       {'B','W','B','W','B','W','B','W'},
			       {'W','B','W','B','W','B','W','B'},
			       {'B','W','B','W','B','W','B','W'},
			       {'W','B','W','B','W','B','W','B'},
			       {'B','W','B','W','B','W','B','W'},
			       {'W','B','W','B','W','B','W','B'},
			       {'B','W','B','W','B','W','B','W'}}
	static int n,m;

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		//System.out.println("기록의 갯수를 입력하세요");
		
		n=sc.nextInt();
		m=sc.nextInt();
		//m과 n은 8보다 크거나 같고, 50보다 작거나 같다
		arr = new char[n][m];
		
		for(int i=0; i<n; i++) {
			 String t = sc.next();
			for(int j=0;j<m;j++) {
				arr[i][j] = t.charAt(j);
			}
		}
		chess(arr, 0,0);
		System.out.println(result);		
	}

	public static void chess(char arr[][],int startx,int starty) {
		int temp='B';
		int change=0;
		
		if(startx>n-8||starty>m-8) return;

		if(arr[startx][starty]=='W') //흰색으로 시작하는 경우
		{
			for(int i=startx;i<startx+8;i++)
				for(int j=starty;j<starty+8;j++){
					if(i%2==0){
						if(j%2==0)
							temp='W';
						else temp}
					else if(arr[i][j]!=temp)
						change++;
			}
		}
		
		else if (arr[startx][starty]=='B') //검정으로 시작하는 경우
		{
			for(int i=startx;i<startx+8;i++)
				for(int j=starty;j<starty+8;j++){
					if(arr[i][j]!=temp)
						temp='B';
					else if(arr[i][j]==temp)
						change++;
			}
		}

		chess(arr,startx+1,starty);
		chess(arr,startx,starty+1);
		if(change<result) result=change; //더 작은 값이 나왔다면 결과값 수정
		//System.out.println(change);

	}
} 
