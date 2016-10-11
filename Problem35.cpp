/*The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

string toString(int num){
	stringstream ss;
	ss<<num;
	return ss.str();
}

int toInt(string str){
	int ans;
	istringstream(str)>>ans;
	return ans;
}

bool isPrime(int num){
	if (num==2||num==3)
		return true;
	if (num==1||num%2==0)
		return false;
	for (int i=3;i<=sqrt(num);i+=2){
		if (num%i==0)
			return false;
	}
	return true;
}

bool circular(int num,vector<bool> list){
	string str=toString(num);
	bool prime=true;
	for (unsigned i=1;i<=str.length();i++){		
		if (list[num]==false)
			{prime=false;}
		int tmp=num/pow((double)10,(double)str.size()-1);
		num=(num%(int)(pow((double)10,(double)str.size()-1)))*10+tmp;
	}
	
	if (prime==false)
		{return false;}
	else
		{return true;}
}

int main(){
	//sieve out all primes below 10^6;
	vector<long int> store;
	vector <bool> list(1000001,true);
	vector <int> circulars;
	list[0]=false;
	list[1]=false;
	for (int i=4;i<=1000000;i+=2)
		{list[i]=false;}
	
	for (int n=3;n<=sqrt(1000000);n++){
		if (list[n]==true){
			
			for (int m=n+n;m<1000000;m+=n)
				{list[m]=false;}
			}
		}

	//end of sieving.
		for (unsigned i=2;i<list.size();i++){
			//cout<<i<<endl;
			if (list[i]==true){
				//cout<<i<<endl;
				if (circular(i,list)==true){
					circulars.push_back(i);}}
		}
		sort(circulars.begin(),circulars.end());
		for (unsigned i=0;i<circulars.size();i++)
			{cout<<circulars[i]<<endl;
				}
				cout<<endl<<endl<<circulars.size()<<endl;
	return 0;}
	