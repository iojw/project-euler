//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//Find the sum of all the primes below two million.

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int a){
	if (a==2||a==3){
		return true;
	}
	if (a%2==0){
		return false;
	}

	bool prime=true;
	for (int b=3;b<=sqrt(a);b+=2){
		if (a%b==0)
			prime=false;
		
	}
	if (prime==true)
		return true;
	else 
		return false;
}

int main(){
	unsigned long sum=0;
	for (long int c=2;c<2000000;c++){
		if (isPrime(c)==true)
		{sum+=c;}
	}
	cout<<sum<<endl;
		return 0;
}