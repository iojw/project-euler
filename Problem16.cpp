//What is the sum of the digits of the number 2^100?

#include <iostream>
#include <ttmath/ttmath.h>
//#include <cmath>
using namespace std;

int main(){
	ttmath::UInt<16> a,b;
	a=2;
	b=1000;
	a.Pow(b);
	ttmath::UInt<1> accu=0;
	int size=a.ToString().size();
	for (int i=0;i<size;i++){
		accu+=a.ToString().substr(i,1);
	}
	cout<<accu;
	return 0;
}