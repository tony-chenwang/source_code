import java.io.*;

public class Customer{
	
public String name,adress,telephone;

public String getName()
{
	return name;
}
	
public void setName(String name)
{
	this.name = name;
}	
	
public String getAdress()
{
	return adress;
}	
	
public void setAdress(String adress)
{
	this.adress = adress;
}
	
public String getTelephone()
{
	return telephone;
}
	
public void setTelephone(String telephone)
{
	this.telephone = telephone;
}
	
public static void main(String args[])
{
	Customer customer1 = new Customer();
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
