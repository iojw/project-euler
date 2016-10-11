/*The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.*/

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

bool isPrime(int num){
	if (num==2||num==3)
		return true;
	if (num==1||num%2==0)
		return false;
	for (int i=3;i<=sqrt(num);i++)
		{
			if (num%i==0)
				return false;}
			return true;
}

string toStr(int num){
	stringstream ss;
	ss<<num;
	return ss.str();
}

bool correct(int num){
	if (!isPrime(num))
		{return false;}
	int same=num;
//test for left to right truncation
	while (same!=0){
		//cout<<"aad"<<endl;
		if (!isPrime(same))
			return false;
		//cout<<same%(int)pow((double)10,(double)(toStr(same).size()-1))<<endl;
		same=same%(int)pow((double)10,(double)(toStr(same).size()-1));
	}
//test for right to left
	while (num!=0){
		if (!isPrime(num))
			return false;
		//cout<<num<<endl;
		num=num/10;
	}
	return true;
}

int main(){
	unsigned long long sum =0;
	int count=0;
	for (int i=9;;i+=2){
		if (correct(i))
			{sum+=i;cout<<i<<endl;count++;}
		if (count==11)
			break;
	}
	cout<<endl<<sum;
	return 0;
}