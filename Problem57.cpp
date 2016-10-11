#include <iostream>
#include <ttmath/ttmath.h>
using namespace std;
typedef ttmath::UInt<20> bigint;

long int noofdigits(bigint num){
	long int count=0;
	while (num!=0){
		count++;
		num/=10;
	}
	return count;
}

int main(){
	bigint n=3,d=2,temp;
	int count=0;
	for (int i = 1; i <= 1000; ++i)
	{
		//cout<<n<<" "<<d<<endl;
		if (noofdigits(n)>noofdigits(d))
			count++;
		temp=n;
		n=d*2+n;
		d=d+temp;
	}
	cout<<count<<endl;
	return 0;
}