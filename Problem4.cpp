//A palindromic number reads the same both ways. 
//The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.
//Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

bool isPalin(int a)
{
	int temp=a;
	string s;
	stringstream out;
	out<<a;
	s=out.str();
	reverse(s.begin(), s.end());
	stringstream ss(s);
	a=0;
	ss>>a;
	if (a==temp)
		return true;
	else 
		return false;
}

int main(){
	int max=0;
	for (int a=100;a<=999;a++){
		for (int b=100;b<=999;b++){
			if (isPalin(a*b)==true&&a*b>max)
			max=a*b;
		}
	}
	cout<<max<<endl;
}