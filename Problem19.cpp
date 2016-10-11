//You are given the following information, but you may prefer to do some research for yourself.
//
//1 Jan 1900 was a Monday.
//Thirty days has September,
//April, June and November.
//All the rest have thirty-one,
//Saving February alone,
//Which has twenty-eight, rain or shine.
//And on leap years, twenty-nine.
//A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
//How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec //2000)?

#include <iostream>
using namespace std;
//Using the Gaussian algorithm
int dayofweek(int date, int month, int year ){
	int q=date;
	int m;
	if (month==1||month==2)
		{m=(month+9)%12+3;year--;}
	else
		{m=(month+9)%12+3;}
	//int m=(month+9)%12+3;
	int k=year%100;
	int j=year/100;
	int product=(q+(13*(m+1)/5)+k+k/4+j/4-(2*j))%7;
		if (product<0)
			return product+7;//computer arithmetic is wrong
		else
			return product;
}

int main(){
	int count=0;
	for (int i=1901;i<=2000;i++){
		for (int x=1;x<=12;x++){
			if (dayofweek(1,x,i)==1)
				{count++;//cout<<"1 "<<x<<" "<<i<<endl;}
		}
		}
	}
	cout<<count;
	return 0;
}
