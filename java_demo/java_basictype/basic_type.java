import java.io.*;
public class basic_type{

public static void main(String args[])
{
     boolean flag; // true /false /on /off 
	 char yeschar;
	 byte findbyte;
	 int intvalue;
	 long longvalue;
	 short shortvalue;
	 float floatvalue;
	 double doublevalue;
	 
	 flag = true; // java 中的true 和 false 都是小写,不能用 0 和 1 代替。
	 yeschar = 'y'; // char 类型占用 16个bit
	 findbyte = 30;  // 表示数的范围 8个bit
	 intvalue = 10000; // 4个字节
	 longvalue = 200L; // 8个字节 定义常量的时候用 L作为后缀
	 shortvalue = 156; // 2个字节
	 floatvalue = 10.0E-5f; // 4个字节
	 doublevalue = floatvalue*floatvalue; // 8个字节
	 
	 System.out.println("The values are:");
	 System.out.println("bool  flag = "+flag);
	 System.out.println("char yeschar= "+yeschar);
	 System.out.println("byte findbyte "+findbyte);
	 System.out.println("int intvalue "+intvalue);
	 System.out.println("long longvalue "+longvalue);
	 System.out.println("short shortvalue "+shortvalue);
	 System.out.println("float floatvalue "+floatvalue);
	 System.out.println("double doublevalue "+doublevalue);
}		
}
