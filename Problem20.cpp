//n! means n  (n  1)  ...  3  2  1

//For example, 10! = 10  9  ...  3  2  1 = 3628800,
//and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

//Find the sum of the digits in the number 100!

#include <iostream>
#include <ttmath/ttmath.h>
using namespace std;
typedef ttmath::UInt<9> bigint;

int main(){
	bigint ans=1,sum=0;
	//bigint sum=0;
	for (int i=2;i<=100;i++)
		ans*=i;
	cout<<ans<<endl;
	while (ans!=0)
		{sum+=ans%10;ans/=10;}
	cout<<sum;
}