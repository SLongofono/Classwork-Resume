
public class ArrayHelper {

	public void print2DArray(int[][]array){
		for(int i = 0; i<array.length; i++){
			for(int j=0; j<array[i].length; j++){
				if(j<array[i].length-1){					//per formatting, print a comma, space after each value
					System.out.print(array[i][j] + ", ");
				}
				else{
					System.out.println(array[i][j]);		//skip formatting, newline after last of each row
				}
			}
		}
	}
	
	public int arraySum(int[]array){			//running total of all values
		int sum = 0;
		for(int i = 0; i<array.length; i++){
			sum = sum + array[i];
		}
		return sum;
	}
	
	public double arrayAvg(int[] array){		//average of all values, calls method within the scope
		double mean = (arraySum(array))/1.0; 	//stores a proper double
		mean = mean/array.length;
		return mean;
	}
	
	public int arraySum2D(int[][]array){		
		int sum = 0;
		for(int i = 0; i<array.length; i++){
			for(int j=0; j<array[i].length; j++){
				sum = sum + array[i][j];
			}
		}
		return sum;
	}
	
	public double arrayAvg2D(int[][]array){
		double indexCount = 0.0;
		for(int i = 0; i< array.length; i++){	//counts the length of each array
			indexCount += array[i].length;
		}
		double mean = (arraySum2D(array))/1.0;	//stores a proper double
		mean = mean/indexCount;
		return mean;
	}
	
}
