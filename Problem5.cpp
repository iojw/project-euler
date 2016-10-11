//2520 is the smallest number 
//that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible by 
//all of the numbers from 1 to 20?

#include <iostream>
using namespace std;

bool check(int b){
	bool divisible=true;
	for (int c=2;c<=20;c++){
		if (b%c==0)
			{}
		else{
			divisible=false;}
		
	}
	if (divisible==true)
		return true;
	else if (divisible==false){
		return false;
	}
}

int main(){
	int num=0;
	for (int a=20;;a++){
		if (check(a)==true){
			num=a;
			break;
		}
		
	}
	cout<<num<<endl;
	return 0;
}