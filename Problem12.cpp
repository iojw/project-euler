//What is the value of the first triangle number to have over five hundred divisors?

#include <iostream>
#include <cmath>
using namespace std;

int factors(int num){
	int count=0;
	
	for (int a=1;a<=sqrt(num);a++){
		if (num%a==0)
			{
				if (num/a==a)
					dwcount++;
				else
					count+=2;
			}
	}
	return count;
	
}

int main(){
	
	int accu=0;
	
	for (int a=1;;a++){
		accu+=a;
		//cout<<accu<<" ";
		
		
		if (factors(accu)>500)
		{cout<<accu<<" "<<factors(accu);break;}
	}

	return 0;
}