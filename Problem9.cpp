#include <iostream>
using namespace std;

bool isThriplet(int num1,int num2, int num3){
	if (num1*num1+num2*num2==num3*num3)
		return true;
	else
		return false;
}

bool total(int num1,int num2, int num3){
	if (num1+num2+num3==1000)
		return true;
	else
		return false;
}

int main(){
	int a,b,c;
	for (a=1;a<1000;a++){
		for (b=1;b<1000;b++){
			for (c=1;c<1000;c++){
				if (isThriplet(a,b,c)&&total(a,b,c))
					{cout<<a<<" "<<b<<" "<<c<<"="<<a*b*c;
				return 0;}
				
			}
		}
	}
	

	return 0;
}