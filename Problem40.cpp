/*An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dxn represents the nth digit of the fractional part, find the value of the following expression.

dx1  dx10 dx100  dx1000  dx10000  dx100000  dx1000000*/

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

string toString(int num){
	stringstream ss;
	ss<<num;
	return ss.str();
}

int toInt (string str){
	int num;
	stringstream ss(str);
	ss>>num;
	return num;
}
int main(){
	//generate freaking long string
	string list;
	int digits=0;
	int product=1;
	for (int i=1;digits<=1000000;i++){
		list.append(toString(i));
		digits+=toString(i).size();
	}
	for (int i=0;i<=6;i++){
		int current=toInt(list.substr(pow((double)10,i)-1,1));
		product*=current;
		cout<<current<<endl;
	}
	cout<<product;
}