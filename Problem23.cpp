/*A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.*/

#include <iostream>
#include <vector>
using namespace std;

bool abundant(int a){
	int sum=0;
	for (int i=1;i<=a/2;i++){
		if (a%i==0){
			sum+=i;
		}
	}
	if (sum>a)
		return true;
	else 
		return false;
}

void generate(vector<int> storage, bool *sums,int count){
	//int sum=0;
	for (int x=0;x<=count;x++){
		for (int y=0;y<=count;y++){
			if (storage[x]+storage[y]<=28123)
				{sums[storage[x]+storage[y]]=true;}
		}
	}
}

int main(){

//get all abundant numbers below 28123
	vector <int> storage;

	int sum=0,count=0;
	for (int i=1;i<28123;i++){
		if (abundant(i)==true)
			{storage.push_back(i);count++;}
	}
//generate

	bool sums[28123];
	for (int i=0;i<=28123;i++){
		sums[i]=false;
	}
	generate(storage,sums,count);
	for (int i=1;i<=28123;i++){
		//cout<<i<<endl;
		if (sums[i]==false)
			{sum+=i;cout<<i<<endl;}}
	cout<<sum;
	return 0;
}