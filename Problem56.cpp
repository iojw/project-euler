/*A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b  100, what is the maximum digital sum?*/

#include <iostream>
#include <ttmath/ttmath.h>
using namespace std;
typedef ttmath::UInt<11> bigint;

bigint digitsum(bigint num){
	bigint sum=0;
	while (num!=0){
		sum=sum+num%10;
		num/=10;
	}
	return sum;
}

int main(){
	bigint max=1,maxnum;
	for (bigint i = 1; i < 100; ++i)
	{
		for (bigint a = 1; a < 100; ++a)
		{
			bigint b=i;
			b.Pow(a);
			if (digitsum(b)>max)
				{max=digitsum(b);maxnum=b;}
		}
	}
	cout<<max<<endl<<maxnum;
	return 0;
}