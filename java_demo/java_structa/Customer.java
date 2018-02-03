import java.io.*;

public class Customer{
	
String name,adress,telephone;  // 可以不写 修饰符  默认为 public

String getName()   //   <=> public String getName 
{
	return name;
}
	
void setName(String name)
{
	this.name = name;
}	
	
String getAdress()
{
	return adress;
}	
	
void setAdress(String adress)
{
	this.adress = adress;
}
	
String getTelephone()
{
	return telephone;
}
	
void setTelephone(String telephone)
{
	this.telephone = telephone;
}
	
public static void main(String args[])
{
	Customer customer1 = new Customer(); //类的实例化的一般形式
	Customer customer2 = new Customer();	
	
	customer1.setName("tony.chen");
	customer1.setAdress("#1330 beiai road");
	customer1.setTelephone("18516396750");
	
	customer2.setName("tony.zhang");
	customer2.setAdress("#1340 beiai road");
	customer2.setTelephone("15651022367");
	
	System.out.println("customer1 name is "+customer1.getName());
	System.out.println("customer1 Adress is "+customer1.getAdress());	
	System.out.println("customer1 Telephone is "+customer1.getTelephone());	
	
	System.out.println("customer2 name is "+customer2.getName());
	System.out.println("customer2 Adress is "+customer2.getAdress());	
	System.out.println("customer2 Telephone is "+customer2.getTelephone());	
	
}
		
}
