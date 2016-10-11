//By listing the first six prime numbers:
//2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//What is the 10 001st prime number?

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
	int su=0;
	int primecounter=0;
	for (int c=2;;c++){
		if (isPrime(c)){
			su+=c;
			
		}
	}
	cout<<su;
	return 0;}
