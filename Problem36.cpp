/*The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

string toString(int num){
	stringstream ss;
	ss<<num;
	return ss.str();
}

bool isPalin(string stri){
	string tmp=stri;
	reverse(stri.begin(),stri.end());
	if (stri==tmp)
		return true;
	else
		return false;
}

string toBinary(int num){
	vector<int> pows;
	string bina;
	int sizea=-1;;
	for (int i=0;pow((double)2,i)<=num;i++){
		pows.push_back(pow((double)2,i));
		//cout<<pow((double)2,i)<<endl;
		sizea++;
	}
	int current=sizea;
	//cout<<sizea;
	while (current>=0){
		bina.append(toString(num/pows[current]));
		//cout<<current<<endl;
		num=num-((num/pows[current])*(pows[current]));
		current--;
	}
	return bina;
}

int main(){
	unsigned long long int sum=0;
	for (int i=1;i<1000000;i++){
		if (isPalin(toString(i))&&isPalin(toBinary(i)))
		{sum+=i; cout<<toBinary(i)<<endl;}
	}
	cout<<sum;
}