/*By replacing the 1st digit of *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.*/

//3 recurring digits as at least one of the 8 variations is divisble by 3
//I DO NOT UNDERSTAND HOW YOU WOULD ESTABLISH THIS. BUT I DON'T CARE.
//And people so called 'GUESS' that it would be six digit.
//So take it that I tried 5 digit numbers, then found an answer at 6.
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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

bool test(int num,vector<int> primes){
	int count=0;
	int temp=num;
		int list[10];
		for (int i=0;i<10;i++)
			list[i]=0;
		while (num!=0){
			list[num%10]+=1;
			num/=10;
		}
	for(size_t i = 0; i <= 9; ++i)
	{
		string str=toString(temp);
		if (list[i]==3&&toString(num).substr(toString(num).size(),1)!=toString(i)){
			count=0;
			unsigned one=str.find(toString(i));
			unsigned two=str.find(toString(i),one+1);
			unsigned three=str.find(toString(i),two+1);
			for (int a=0;a<=9;a++)
			{
				str.replace(one,toString(a).size(),toString(a));
				str.replace(two,toString(a).size(),toString(a));
				str.replace(three,toString(a).size(),toString(a));
				if (primes[toInt(str)]==true&&str.substr(0,1)!="0")
					{count++;}
			}
			if (count==8)
				return true;
		}
	}
	return false;
}



bool check(int num){
	int list[10];
	for (int i=0;i<10;i++)
		list[i]=0;
	while (num!=0){
		list[num%10]+=1;
		num/=10;
	}
	for (int i=0;i<10;i++){
		if (list[i]==3)
			return true;
	}
	return false;
}

int main(){
	vector<int> primes(10000000,true);
	primes[0]=false;
	primes[1]=false;
	for (int i=4;i<=999999;i+=2){
		primes[i]=false;
	}
	for (int i=3;i<=sqrt(999999);i+=2){
		if (primes[i]==true){
		for (int n=i*2;n<=999999;n+=i){
				primes[n]=false;
		}
	}}
		bool found=false;int count=0;
	for (int i=100001;i<=999999&&found!=true;i+=2){
		cout<<i<<endl;
		if (primes[i]==true&&check(i)==true){
			count++;
			if (test(i,primes)==true){
				{cout<<i<<endl;found=true;break;}
			}
		}
			
	}
	cout<<endl<<endl<<count;
	//	cout<<test(111857,primes);
		return 0;
}