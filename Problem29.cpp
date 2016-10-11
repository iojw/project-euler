/*Consider all integer combinations of ab for 2  a  5 and 2  b  5:

If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:

4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

How many distinct terms are in the sequence generated by ab for 2  a  100 and 2  b  100?*/

#include <iostream>
#include <vector>
#include <ttmath/ttmath.h>
#include <algorithm>
using namespace std;
typedef ttmath::UInt<11> bigint;

bigint power(bigint a,bigint b){
	bigint product=1;
	for (bigint i=1;i<=b;i++){
		product=product*a;
		//cout<<a<<endl;
	}
	return product;
}

int main(){
	int size=1;
	bigint tmp;
	vector<bigint> storage;
	//store all teh values
	for (int a=2;a<=100;a++){
		//cout<<a<<endl;
		for (int b=2;b<=100;b++){
			storage.push_back(power(a,b));
			cout<<(power(a,b))<<endl;
			size++;
			}
	}
	//sort teh vector
	sort(storage.begin(),storage.end());
	//check for duplicates
		storage.erase(unique(storage.begin(),storage.end()),storage.end());
	
		cout<<storage.size();
	return 0;
	
}