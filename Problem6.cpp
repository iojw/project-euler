//Hence the difference between the sum of the squares of 
//the first ten natural numbers and the square of the sum is 3025  385 = 2640.
//Find the difference between the sum of the squares 
//of the first one hundred natural numbers and the square of the sum.

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	unsigned long long int sumofsquares,squareofsum;
	
	for (int count=1;count<=100;count++){
		sumofsquares+=pow((double)count,2);
	}
	squareofsum=pow((double)(100*101)/2,2);
	cout<<squareofsum-sumofsquares;
}