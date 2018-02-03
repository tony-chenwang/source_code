/********************************************************************************
  * @copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date
  * @brief :   C++ Base element
  * @History
*******************************************************************************/
#include <iostream>  // we must remove .h in C++
using namespace std;

//class or struct  声明一个类 不可以在类中进行初始化
//OOP 对象的组成： 描述对象状态或者属性的数据 和 描述对象行为和功能的函数
class Rect
{
	public:      // 封装的特性 将数据和函数结合在一起 
		int Area_int();
		double Area_double();
		Rect();   // 多态性的体现   不同的状态下 具有不同的行为和能力 构造函数
		          // 构造函数在对象被创建的时候调用 注意构造函数 和 析构 函数都没有返回值
		Rect(double l,double w);
		Rect(int l, int w); 
	        virtual ~Rect(); //析构函数 没有返回值 不接受任何形式的参数
		int nLength;  //数据
		int nwidth;
		double dLength;
		double dwidth;	
	private:
	protected:	
};

Rect::Rect():nLength(10),nwidth(10)   //使用初始化参数列表初始化数据
                                      // 初始化属性的一种方法
{ 
}


Rect::Rect(double l,double w)         //注意构造函数和析构函数是没有返回值的
{
	dLength = l;                      // 初始化属性的另一种方法
	dwidth = w;	
}

Rect::Rect(int l, int w)
{
	nLength = l;
	nwidth = w;	
}

Rect::~Rect()
{
	cout<<"I am the descontructor"<<endl;
}


int Rect::Area_int()
{
	cout << "The INT area is :" << nLength*nwidth <<endl;
	return nLength*nwidth;
}


double Rect::Area_double()
{
	cout<<"The double area is :"<<dLength*dwidth <<endl;
	return dLength*dwidth;
}



int main(int argc, char *argv[])
{
    Rect r; 
    r.Area_int();
    
    Rect *ptr;
    ptr = new Rect(2.0,1.333);  // 指针的 new 的用法

    ptr->Area_double();
   
    return 0;
}
