/********************************************************************************
  * @copyright(C),2017,Mstar semi.co.,Ltd
  * @file Name
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date
  * @brief :   C++ Base element 2
  * @History
*******************************************************************************/
#include<iostream>
using namespace std;

class Complex
{
	public:
		Complex()
		{
			real = 0;
			imag = 0;
		}
		Complex(double r,double i)
		{
			real = r;
			imag = i;
		}
		
		Complex operator +(Complex& c2);   // 注意 应该将  operator + 看出是一个整体    
		                                          
		void display();
		
		
	private:	
		double real;
		double imag;
	
};

Complex Complex::operator +(Complex &c2)
{
	Complex c;
	c.real = real + c2.real;
	c.imag = imag + c2.imag;
	return c;
}

void Complex::display()
{
	cout<<"("<<real<<","<<imag<<"i)"<<endl;
}


int main(int argc, char* argv[])
{
	Complex c1(3,4);
	Complex c2(5,-10);
	Complex c3;
	
	c3 = c1 + c2;
	
	c1.display();
	c2.display();
	c3.display();
   
	return 1;
}

