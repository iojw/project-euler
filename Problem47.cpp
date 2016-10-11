/*The first two consecutive numbers to have two distinct prime factors are:

14 = 2  7
15 = 3  5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2²  7  23
645 = 3  5  43
646 = 2  17  19.

Find the first four consecutive integers to have four distinct primes factors. What is the first of these numbers?*/

#include <iostream>
#include <cmath>
using namespace std;

bool distinct(int num){
	int count=0;
	for (int n=2;num!=1;n++){
		//cout<<num<<endl;
		if (num%n==0){
			count++;
			while (num%n==0)
				num/=n;
		}
	}
	if (count==4)
		return true;
	else
		return false;
}

int main(){
	bool found=false;
	for (int i=4;found!=true;i++){
		if (distinct(i)&&distinct(i-1)&&distinct(i-2)&&distinct(i-3))
			{cout<<i-3;found=true;break;}
	}
	return 0;
}