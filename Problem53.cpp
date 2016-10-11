/*here are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,

nCr =	
n!
r!(nr)!
,where r  n, n! = n(n1)...321, and 0! = 1.
It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1  n  100, are greater than one-million?*/

#include <iostream>
#include <ttmath/ttmath.h>
using namespace std;
typedef	ttmath::UInt<9> bigint;

bigint fac(int num){
	if (num==0)
		return 1;
	if (num==1)
		return 1;
	bigint product=num;
	int i;
	for (i=num-1;i>=1;i--)
		{//cout<<product<<endl;
		product*=i;}
	return product;
}

bigint combi(int n,int r){
	return fac(n)/(fac(r)*fac(n-r));
}

int main(){
	int count=0;
	for (int n=1;n<=100;n++){
		for (int r=1;r<=n;r++){
			if (combi(n,r)>1000000)
			{count++;}
		}
	}
	cout<<count<<endl;
		return 0;
}