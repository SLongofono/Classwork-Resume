import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class Letter_Counter {

	public static void main(String args[]){
		String file = "test.txt";					//initializations.
		String outFile = "out.txt";
		String lastLine = "";
		boolean fileExists = true;
		boolean caseSensitive = false;
		Scanner input = new Scanner(System.in);
		int[] letterCount = new int [26];			//will store how many of each letter lowercase
		int[] letterCountUppr = new int[26];		//will store how many of each letter uppercase
		for(int i = 0; i<letterCount.length; i++){	//initialized to zero for each letter
			letterCount[i]=0;
		}
		FileReader fileRead = null;					//allows us to verify creation of an object later
		BufferedReader lineIn = null;				// ditto
		FileWriter lineOut = null;
		BufferedWriter output = null;
		
		
		System.out.println("Please enter the name of your file:");
		file = input.next();
		System.out.println("");
		System.out.println("Enter the name of the output file (no extension): ");
		outFile = input.next();
		
		
		System.out.println("Does case matter? (enter y for yes or n for no):");
		String temp = input.next();
		if(temp.charAt(0)== 121){
			caseSensitive = true;
		}
		
		while(fileExists){
			try{									//in case there is no such file, wrapped in a try/catch block
				fileRead= new FileReader(file);		//creates a filereader object linked to the file argument
				lineIn = new BufferedReader(fileRead);	//Creates a buffered reader (like a scanner) for the filereader
				fileExists = false;  				//if this line is reached, the file exists and we can move on
				
				System.out.println("Here is the file: ");
				
				lastLine = lineIn.readLine();		//consume the next line
				while(lastLine!=null){				//while the buffer has lines left to read (ie the string value is not null)
					if(caseSensitive){
						letterCountUppr = counterBig(lastLine, letterCountUppr);	//counts the upper case letters in this line
						letterCount = counterLittle(lastLine, letterCount);	//counts the lower case letters in this line
					}
					else{
						letterCount = counter(lastLine, letterCount);	//counts the lower case letters in this line
					}
					System.out.println(lastLine);	//print that line to console
					lastLine = lineIn.readLine();	//move the next value of the buffer to the string's reference
				}

				try{
					lineOut = new FileWriter(outFile);				
					output = new BufferedWriter(lineOut);
					output.write("hello world!\n");
				
				if(caseSensitive){
					for(int i = 0; i<26; i++){						//runs through the array
						output.write((char)(i+65) + " = " + letterCountUppr[i]);		//writes the char associated with each array index and the value in that index
						System.out.println((char)(i+65));
						output.write("\n");												//writes a newline to file
					}
					
					for(int i = 0; i<letterCount.length; i++){							//ditto above for lowercase array
						output.write((char)(i+97) + " = " + letterCount[i]);
						output.write("\n");
					}
				}
				else{
					for(int i = 0; i<letterCount.length; i++){							//ditto above for lowercase array
						output.write((char)(i+97) + " = " + letterCount[i]);
						output.write("\n");
					}
				}}catch(Exception e){System.out.println("ERROR");}
			}
			catch(Exception e){
				System.out.println(e.getMessage());	//if something goes wrong, print the associated error message
				System.out.println("It is possible that the file does not exist.  Please verify the name and extension, and try again");
				System.out.println("Enter the filename: ");
				file = input.next();
			}
		}
		for(int i = 0; i<letterCount.length; i++){
			System.out.println(letterCount[i]);
		}
	}
	
	
	public static int [] counterBig(String line, int[] arr){
		
		for(int i = 0; i<line.length(); i++){
			if((line.charAt(i)>64)&&(line.charAt(i)<91)){	//if in the uppercase letters
				arr[(int) line.charAt(i)-65] = arr[(int) line.charAt(i)-65] + 1;					//add one to the count for that letter, adjusted per the beginning of the uppercase alphabet in the ASCII table
			}												// since the uppercase letters start at 65, the corresponding index will be the decimal value of the char less 65 
		}
	
		return arr;
	}
	
	public static int [] counterLittle(String line, int[] arr){
	
		for(int i = 0; i<line.length(); i++){
			if((line.charAt(i)>96)&&(line.charAt(i)<123)){	//if in the lowercase letters
				arr[(int) line.charAt(i)-97] = arr[(int) line.charAt(i)-97] + 1;					//add one to the count for that letter, adjusted per the beginning of the lowercase alphabet in the ASCII table
			}
		}
	
		return arr;
	}
	
	public static int [] counter(String line, int[] arr){
		
		for(int i = 0; i<line.length(); i++){
			if((line.charAt(i)>96)&&(line.charAt(i)<123)){	//if in the lowercase letters
				arr[(int) line.charAt(i)-97] = arr[(int) line.charAt(i)-97] + 1;					//add one to the count for that letter, adjusted per the beginning of the lowercase alphabet in the ASCII table
			}
			if((line.charAt(i)>64)&&(line.charAt(i)<91)){	//if in the uppercase letters
				arr[(int) line.charAt(i)-65] = arr[(int) line.charAt(i)-65] + 1;					//add one to the count for that letter, adjusted per the beginning of the uppercase alphabet in the ASCII table
			}
		}
		
		return arr;
	}
		
}
