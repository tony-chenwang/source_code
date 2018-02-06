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
#include<cstring>

using namespace std;

class student
{
	public:
	student(int n,string nam,char s)
	{
		num = n;
		name = nam;
		sex = s;
		
		cout <<"I am the constructor  "<<num<<endl;

	}
	~student()
	{
		cout <<"I am the destructor  "<<num<<endl;
	}
	
	void display()
	{
		cout<<"num :"<<num<<endl;
		cout<<"name :"<<name<<endl;
		cout<<"sex:"<<sex<<endl;
	}
	
	
	private:
		int num;
		string name;
		char sex;
};

student a3(208100512,"tong.li",'m');  //后添加的内容，会有不同的提示信息。

int main(int argc ,char*argv[])  // 
{
	student a1(208100510,"tony.chen",'m');
	a1.display();
	
	student a2(208100511,"thomas.chen",'f');	
	a2.display();
	
	cout<<"end of main function"<<endl;
	return 1;
	
}

