/*We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?*/

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;
	
bool isPan(int num){
	stringstream ss;
	//cout<<num;
	ss<<num;
	int n=ss.str().size();
	int check[n+1];
	for (int i=0;i<=n;i++)
		check[i]=false;
	while (num!=0){
		check[num%10]=true;
		num/=10;
	}
	for (int i=1;i<=n;i++){
		if (!check[i])
			return false;
	}
	return true;
}

bool isPrime(int num){
	if (num==2||num==3)
		return true;
	if (num==1||num%2==0)
		return false;
	for (int i=3;i<=sqrt(num);i++){
		if (num%i==0)
			return false;
	}
	return true;
}
int main(){
//based on rule that num is divisible by 3 if sum of digits is divisible by 3
//	1+2+3+4+5+6+7+8+9 = 45
//	1+2+3+4+5+6+7+8 = 36
//	1+2+3+4+5+6+7 = 28
//	1+2+3+4+5+6 = 21
//	1+2+3+4+5 = 15
//	1+2+3+4 = 10
//	1+2+3 = 6
//	1+2 = 3
//Only 4&7 aren't divisible by 3. Rest are all non-prime.
	
	int max=1;
	for (int i=7654321;;i-=2){
		if (isPrime(i)&&isPan(i))
		{max=i;break;}
	}
	cout<<max;
}