/*Euler published the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

Using computers, the incredible formula  n²  79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, 79 and 1601, is 126479.

Considering quadratics of the form:

n² + an + b, where |a|  1000 and |b|  1000

where |n| is the modulus/absolute value of n
e.g. |11| = 11 and |4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num){
	if (num==2||num==3)
		return true;
	if (num%2==0||num<=1)
		return false;
	bool prime=true;
	for (int i=3;i<=sqrt(num);i+=2){
		if (num%i==0)
			prime=false;
	}
	if (prime==true)
		return true;
	else
		return false;
}

int consecutives(int a,int b){
	int count=0;
	for (int i=0;;i++){
		if (isPrime(pow(double(i),2)+(a*i)+b)==true)
		{count+=1;}
		else
			break;
	}
	return count;
}

int main(){
	int max=1;
	int maxval[2];
	for (int a=-999;a<1000;a++){
		for (int b=-999;b<1000;b++){
			if (consecutives(a,b)>max)
				{max=consecutives(a,b);maxval[0]=a;maxval[1]=b;}
		}
	}
	cout<<max<<endl<<maxval[0]<<" * "<<maxval[1]<<" = "<<maxval[0]*maxval[1];
	//cout<<isPrime(-3);
}