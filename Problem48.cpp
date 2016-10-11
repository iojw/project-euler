/*The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.*/

#include <iostream>
#include <ttmath/ttmath.h>
#include <string>
#include <sstream>
using namespace std;

//int checksize(ttmath::UInt<80>)

int toInt(string str){
	int num;
	stringstream(str)>>num;
	return num;
}
	
int main(){
	ttmath::UInt<170> huge=0,copy;
	for (ttmath::UInt<1> n=1;n<=1000;n++){
		string temp;
		copy=n;
		copy.Pow(n);
		temp=copy.ToString();
		huge+=copy%10000000000;
	}
	cout<<huge%10000000000<<endl;
	return 0;
}	