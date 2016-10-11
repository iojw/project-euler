/*A unit fraction contains 1 in the numerator.

Where 0.16‾ means 0.1666… and has a 1-digit recurring cycle. It can be seen that 17 has a 6-digit recurring cycle.

Find the value of d<1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.*/

#include <iostream>
#include <ttmath/ttmath.h>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

bool isPrime(int a){
	if (a==2||a==3)
		return true;
	if (a%2==0||a==1)
		return false;
		bool prime=true;
	for (int i=3;i<=sqrt(a);i+=2){
		if (a%i==0)
			prime=false;
	}
	if (prime==true)
		return true;
	else
		return false ;
		
}

ttmath::UInt<1> data(int y){
	if (y==5){
		return 0;
	}
	else{
	ttmath::UInt<100> denom;
		denom=9;
		bool divi=false;
		while (divi==false){
			if (denom%y==0)
				divi=true;
			else
				{denom=denom*10+9;}
		}
		return denom.ToString().size();
}}


int main(){
	vector<int> storage;
	int size=-1;

	for (int a=3;a<1000;a++){
		if (isPrime(a))
			{storage.push_back(a);size++;}
			
	}
	
	//BRUTE FORCE METHOD FROM 1
	/*ttmath::UInt<100> maxlength=1;
	int max;
	for (int i=0;i<size;i++){
		if (data(storage[i])>maxlength)
			{max=storage[i];maxlength=data(storage[i]);}
		if (data(storage[i])==(storage[i]-1)&&i!=0&&i!=1)
			cout<<storage[i]<<" "<<data(storage[i])<<endl;
	}*/
	
	//STARTS FROM TOP DOWN UNTIL IT FINDS A PERIOD OF i-1
	for (int i=size;;i--){
		if (data(storage[i])==(storage[i]-1)&&i!=0&&i!=1)
		{cout<<"1/"<<storage[i]<<" gives you a cycle length of "<<data(storage[i])<<"."<<endl;break;}
	}
	
	//cout<<storage[size];
	cin.ignore();
	cin.get();
	return 0;
}