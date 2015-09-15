import java.util.Scanner;

public class Lab09 {

	public static void main(String []args){
		
		ArrayHelper jeeves = new ArrayHelper();				//creates a new array butler named jeeves
		Scanner io = new Scanner(System.in);
		int dimension1 = 0;
		int dimension2 = 0;
		System.out.print("How many rows?: ");
		dimension1 = io.nextInt();
		System.out.print("How many columns?: ");
		dimension2 = io.nextInt();
		int[][] myArray = new int[dimension1][dimension2];
		
		for(int i = 0; i < myArray.length; i++){			//collects data, populates array, provides feedback
			for(int j = 0; j < myArray[i].length; j++){
				System.out.print("Enter a value for position (" + i + "," + j + "):");
				myArray[i][j] = io.nextInt();
			}
		}
		
		System.out.println("Here is your array:");
		jeeves.print2DArray(myArray);						//commands my butler to do his job.  (use British accent)
		for(int i = 0; i < myArray.length; i++){
			System.out.println("row " + i + " sum = " + jeeves.arraySum(myArray[i]) + ", avg = " + jeeves.arrayAvg(myArray[i]));
		}
		System.out.println("The sum for the entire array is = " + jeeves.arraySum2D(myArray));
		System.out.println("The average for the entire array is = " + jeeves.arrayAvg2D(myArray));
		
	}
	
}
