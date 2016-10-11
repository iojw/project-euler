//How many routes are there through a 2020 grid?

#include <iostream>
#include <ttmath/ttmath.h>
using namespace std;
typedef ttmath::UInt<3> bigint;

//ans is 40 choose 20. = n!/k!(n-k)!

bigint fac(int a){
	bigint accu=1;
	for (int i=2;i<=a;i++)
		accu*=i;
	return accu;
	}
	
int main(){	
//=40 choose 20 = n!/k!(n-k)!
	int n= 40;
	int k= 20;
	cout<<fac(n)/(fac(k)*fac((n-k)));
	//cout<<fac(40);
	return 0;
	
}



