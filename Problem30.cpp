/*Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.*/

#include <iostream>
#include <cmath>
using namespace std;

//maximum of 7 digit = only 6 digit
//Hence, we only need to loop from 2 to (9^5)*6 = 354294

int sum(int num){
	int sum=0;
	while (num!=0){
		sum+=pow(double(num%10),5);
		num/=10;
	}
	return sum;
}

int main(){
	int totalsum=0;
	for (int i=2;i<pow(double(9),5)*6;i++){
		if (sum(i)==i)
		{totalsum+=i;cout<<i<<endl;}
	}
	cout<<endl<<totalsum;
	return 0;
}