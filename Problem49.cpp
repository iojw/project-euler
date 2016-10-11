/*The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

string toString(int num){
	stringstream ss;
	ss<<num;
	return ss.str();
}

long long int combine(int a,int b,int c){
	stringstream ss;
	ss<<a<<b<<c;
	unsigned long long int num;
	ss>>num;
	return num;
}

bool isPer(int numa,int numb){
	string a=toString(numa);
	string b=toString(numb);
		sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if (a==b)
		return true;
	else 
		return false;
}

int main(){
	vector<int> primes(10000,true);
	primes[0]=false;
	primes[1]=false;
	for (int n=4;n<=9999;n+=2)
		primes[n]=false;
	for (int n=3;n<=9999;n+=2){
	//	cout<<n<<endl;
		if (primes[n]==true){
			for (int b=n*2;b<=9999;b+=n)
				primes[b]=false;
		}
	}
	//cout<<"DONE"<<endl;
	bool found=false;
	for (int i=1001;i<=9999&&found==false;i++){
		//cout<<found<<endl;
		if (primes[i]==true&&i!=1487&&i!=4817&&i!=8147){
		for (int b=1000;b<=i&&found==false;b++){
			if (primes[b]==true){
			if (isPer(i,b)&&i!=b){
				//cout<<i<<" "<<b<<endl;
				if (isPer(i,i+(i-b))&&primes[i+(i-b)]==true)
					{found=true;cout<<b<<endl<<i<<endl<<i+(i-b)<<endl<<i-b<<endl;cout<<combine(b,i,i+(i-b))<<endl;break;}
			}
		}
	}}}
return 0;
}