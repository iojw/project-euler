/*If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p  1000, is the number of solutions maximised?*/

#include <iostream>
#include <cmath>
using namespace std;

double sum(int a,int b){
	double sum=a+b;
	sum+=sqrt(pow((double)a,2)+pow((double)b,2));
	return sum;
}

int main(){
	double solutions[1001];
	//initiliase
	for (int i=0;i<1001;i++){
		solutions[i]=0;
	}
	//start
	for (int a=1;a<=1000;a++){
		for (int b=2;b<=1000;b++){ 
			if (a<b&&sum(a,b)<=1000){
				if (sum(a,b)==(int)sum(a,b))
					solutions[(int)sum(a,b)]++;
			}
		}
	}
	int maxindex=0;
	int max=1;
	//check
	for (int i=1;i<1001;i++){
		if (solutions[i]>max)
			{maxindex=i;max=solutions[i];}
	}
	cout<<max<<endl<<maxindex;
}