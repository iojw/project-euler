/*145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.*/

#include <iostream>
using namespace std;


int factorial(int a){
	if (a==0)
		return 1;
	int fac=1;
	int i;
	for (i=1;i<=a;i++)
	{fac*=i;}
	return fac;
}

int main(){
	int totalsum;
	for (unsigned long long int i=10;i<=9999999;i++){
		//cout<<i<<endl;
		unsigned long long int sum=0;
		unsigned long long int tmp=i;
		while (tmp!=0){
			sum+=factorial(tmp%10);tmp/=10;
		}
	if (sum==i)
		{totalsum+=i;cout<<i<<endl;}
		}
		cout<<totalsum;
}

