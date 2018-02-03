import java.io.*;

public class Calculator
{
	public static double CalculateAverage(int [] number)
	{
	   int sum = 0;
	   for(int i = 0 ; i < number.length; i++ ) // array usage 
	   {
		   sum += number[i];
	   }
		
	   return sum/(double)number.length;
	
	}
	
	public static int CalculateMax(int [] number) //使用数组作为传入参数
	{
	   int max = number[0];
		
	   for(int i = 0 ; i < number.length; i++ )
	   {
		   if( max < number[i] )
			   max = number[i];
	   }
		
		return max;
	}
	
	
	public static void main( String args[])
	{
		 int numbers[] = {0,1,2,3,4,5,6,7,8,9};
		 System.out.println("the average is "+ Calculator.CalculateAverage(numbers));
		 System.out.println("the max value is "+ Calculator.CalculateMax(numbers));
	}
		
}
