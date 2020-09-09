import java.util.Scanner;
//분할 정복 쿼드 트리
//

public class Main {
	static int[][] arr;
	static int N;
	static String result="";

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
			
		N=sc.nextInt();

		arr = new int[N][N];
		
		for(int i=0; i<N; i++) {
			String t = sc.next();
			for(int j=0;j<N;j++) {
				arr[i][j] = Character.getNumericValue(t.charAt(j));
			}
		}

		quadtree(arr, 0,0,N);
	
		
		System.out.println(result);		
	}
	public static boolean same(int startx, int starty,int size, int arr[][]){
		for(int i=startx;i<startx+size;i++)
			for(int j=starty;j<starty+size;j++){
				if(arr[i][j]!=arr[startx][starty]) return false;}

		return true;
	}

	public static void quadtree(int arr[][],int startx,int starty,int size) {

		int point=arr[startx][starty];
		
		if(same(startx,starty,size,arr)){result=result+point;// System.out.println(point); 
		}
		else 
		{
		result=result+"(";
		//System.out.println("(");
		quadtree(arr,startx,starty,size/2); //1
		quadtree(arr,startx,starty+size/2,size/2); //2
		quadtree(arr,startx+size/2,starty,size/2); //3
		quadtree(arr,startx+size/2,starty+size/2,size/2); //4}
		result=result+")";
		//System.out.println(")");
	}
}
}
 
