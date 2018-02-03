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

// 构造和析构函数一般声明为 public 类型， 一般不允许用户调用。
class Time
{
	public:
	  Time(); // 构造函数 和类的名称同名，没有返回值
	  Time(Time& c); // 构造函数 重载
	  ~Time();// 析构函数 和类的名称同名，没有返回值
          Time(int,int,int);
          void settime();
          void showtime();
	
	private:
          int hour;
	  int minute;
	  int seconds;
	
};  // 定义类的时候末尾需要加分号 

Time::Time():hour(5),minute(3),seconds(3) //初始化参数的列表
{		
} // 具体函数不需要加分号
 

Time::Time(Time& c)
{
   hour = c.hour;
   minute = c.minute; 
   seconds = c.seconds;	
}

Time::Time(int a,int b,int c)
{
	hour = a;
	minute = b;
	seconds = c;		
}

/****************************************************
  * @functionName
  * @brief
  * @param
  * @retval
  析构函数的通常在下面几种情况下调用：
  1. 在函数中创建对象，在函数结束的时候
  2. 使用new 创建 对象 ，使用delete 删除的时候
  3. 某些对象离开作用域的时候。
****************************************************/
Time::~Time()
{
				
}


void Time::settime()
{
    hour = 2;
    minute = 3; 
    seconds = 4;
}

void Time::showtime()
{
	cout<<"hour:"<<hour<<endl;
        cout<<"min:"<<minute<<endl;
        cout<<"seconds:"<<seconds<<endl;
}


int main(int argc,char *argv[])
{
  Time time_t;
  time_t.showtime();
  
  Time time2_t(time_t);  //可以使用另一个对象来构建一个对象
  time2_t.showtime();
  
  // 1.0 对象的创建方法
  Time test;  // 默认调用无参数的构造函数 No 1.1 
  Time testb(1,2,3);  // 调用符合某个构造函数  No 1.2
  testb.showtime();
  
  Time time3_t(time_t); // 2.0 使用拷贝构造函数初始化
  time3_t.showtime(); 
 
  Time t1;
  Time t2 = t1; // 3.0 赋值的方法使用构造函数初始化
  
  Time ta;
  Time tb;
  tb = ta;
  
  Time * ptr = NULL;
  ptr = new Time(1,2,3); // 4.0 使用对象指针进行初始化

  
  return 0;
}
