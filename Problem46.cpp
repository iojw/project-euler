/*It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2*1^2
15 = 7 + 2*2^2
21 = 3 + 2*3^2
25 = 7 + 2*3^2
27 = 19 + 2*2^2
33 = 31 + 2*1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int num){
	if (num==2||num==3)
		return true;
	if (num==1||num%2==0)
		return false;
	for (int i=3;i<=sqrt(num);++i){
		if (num%i==0)
			return false;
	}
	return true;
}

void generate(int max,vector<unsigned long long int> &squares){
	for(int i = 1; i <= max; ++i)
	{
		squares.push_back(pow((double)i,2));
		//cout<<squares[i-1]<<endl;
	}
}
int main()
{
	vector<unsigned long long int> squares;
	bool found=false;
	generate(10000,squares);
	for (int i=3;;i+=2){
		//cout<<i<<endl;
		found=false;
		for (int a=0;2*squares[a]<i;a++){
			//cout<<squares[a]<<" ";
			if (!isPrime(i)&&isPrime(i-(2*squares[a])))
				{found=true;}
		}
		if (found==false&&!isPrime(i))
			{cout<<i<<endl;break;}
	}
	return 0;
}