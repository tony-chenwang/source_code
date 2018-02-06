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

class Box
{
	public:
		 Box(int h=10,int w=10 ,int len=10);  // 使用默认参数构造函数 
		                                       // 还有一个是初始化参数列表  一定要注意区别
	     int volume();
	private:
       int height;
       int width;
       int length;
	
};

Box::Box(int h,int w ,int len)
{
	height = h;
	width = w;
	length = len;
}


int Box::volume()
{
	return (height*length*width);
}

int main(int argc, char *argv[])
{
	Box box1;
	cout<<"The box1 volume is "<< box1.volume()<<endl; 
	
	Box box2(5);
	cout<<"The box2 volume is "<< box2.volume()<<endl;
	
	Box box3(5,5);
	cout<<"The box3 volume is "<< box3.volume()<<endl;
	
	Box box4(5,5,5);
	cout<<"The box4 volume is "<< box4.volume()<<endl;	
	
	
	return 0;
}


