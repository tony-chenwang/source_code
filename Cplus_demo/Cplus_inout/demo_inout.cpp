/********************************************************************************
  * @copyright(C),2017,Mstar semi.co.,Ltd
  * @file Name
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date
  * @brief :  base input $ ouput 2 
  * @History
*******************************************************************************/
#include <iostream>
#include <cmath> 
using namespace std;

int main(int argc, char *argv[])
{
	float a,b,c,s,area;
    //cout<<"Hello C-Free!"<<endl;
     cout<<"请输入三角形的三个边长";
	 cin>>a>>b>>c; 
      
     s = (a+b+c)/2;
     
     if( a > 0 && b >0 && c >0 && (a+b) > c && (a+c) > b && (b+c) > a)
     {
        area =  sqrt(s*(s-a)*(s-b)*(s-c));
	    
	    cout << "三角形的面积为："<<area<< endl; 
      }
      else
      {
      	cout<<"输入错误："<<endl;
      }
       
	return 0;
}
