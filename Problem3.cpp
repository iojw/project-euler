//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	bool prime=true;
	unsigned long long int num=600851475143,max=0;
	for (unsigned long long int factor=1;factor<=num;factor++){
		if (num%factor==0){
			for (unsigned long long int primer=2;primer<sqrt(factor);primer++){
				if (factor%primer==0)
					prime=false;
				
			}
		if (prime==true){
			max=factor;cout<<factor<<endl;}
		}
		prime=true;
	}
	cout<<max<<endl;
	return 0;
	}