/*Take the number 192 and multiply it by each of 1, 2, and 3:

192  1 = 192
192  2 = 384
192  3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n  1?*/

//initial observations (++ represent concantenation)
//-------------------
//integer must contain less than 5 digits. 10000*1 ++ 10000*2 = 10 digits
//integer must be at least 4 digits and >=5000
//2 digit won't be able to make 9 digit number. 
//99*1++99*2++99*3 = 8 digits, 99*1++99*2++99*3++99*4 = 10 digit
//3 digit won't be able to make 9 digit number. 
//999*1++999*2++999*3 = 11 digit, 999*1++999*2 = 7 digit
//min 4 digit num = 9182, as any lower would make it less than the example

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string toString(int num){
	stringstream ss;
	ss<<num;
	return ss.str();
}

int toInt(string str){
	int num;
	stringstream(str)>>num;
	return num;
}

bool isPalin(int num){
	bool check[10];
	//initialise all to false
	for (int i=0;i<10;i++)
		check[i]=false;
	while (num!=0){
		if (num%10>0&&num%10<10)
			{check[num%10]=true;}
		num/=10;
	}
	//check
	for (int i=1;i<=9;i++){
		if (check[i]==false)
			return false;
	}
	return true;
}

bool check(int num, int max){
	string final;
	for (int i=1;i<=max;i++){
		final.append(toString(num*i));
	}
	//cout<<final<<endl;
	if (isPalin(toInt(final)))
		return true;
	else
		return false;
}

int getPalin(int num, int max){
	string final;
	for (int i=1;i<=max;i++){
		final.append(toString(num*i));
	}
	return toInt(final);
}

int main(){
	int max=1;
	for (int i=9182;i<=9999;i++){
		for (int a=1;a<=2;a++){
			if (check(i,a)&&getPalin(i,a)>max)
				max=getPalin(i,a);
		}
	}
	cout<<max<<endl;

}