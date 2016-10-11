/*The following iterative sequence is defined for the set of positive integers:
n –> n/2 (n is even) 
n –> 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 –> 40 –> 20 –> 10 –> 5 –> 16 –> 8 –>  4 –> 2 –>  1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?*/

#include <iostream>
#include <ttmath/ttmath.h>
using namespace std;
typedef ttmath::UInt<1> bigint;

int chains(int b){
	int count=1;
	bigint a=b;
	while (a>1){
		if (a%2==0)
			{a/=2;count++;/*cout<<a<<"-> ";*/}
		else
			{a=a*3+1;count++;/*cout<<a<<"-> ";*/}
		}
		return count;
}


int main(){
	int max=1,maxnum=1;
	for (long long int i= 1;i<1000000;i++){
		if (chains(i)>max)
			{max=chains(i);maxnum=i;}
		//cout<<i<<endl;
		}
		cout<<"A starting number of "<<maxnum<<" gives you "<<max<<" terms."<<endl;
		cout<<chains(837799)<<" ";
		return 0;
			
}