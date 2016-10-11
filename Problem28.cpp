//What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

#include <iostream>
#include <cmath>
using namespace std;

// From studying the numbers. I have broken the diagonals into four parts. 
// 1. Up-Right 2. Up-Left 3. Down Right 4. Down Left
// The formulas for the respective group is as follows.
// 1. (n+2)^2
// 2. (n+2)^2 - 2n
// 3. (n+2)^2 - 6n
// 4. (n+2)^2 - 4n

//Total number of numbers per group for 1001x1001 = (1001-1)/2 = 500
//PROBLEM OWNED.

int main(){
	int sum=0;
	int count=2;
	int count2=0;
	for (int n=3;n<=1001;n+=2){
		//UpRight
		sum+=pow(double(n),2);count2++;
		//cout<<pow(double(n),2)<<endl;
		//UpLeft
		sum+=pow(double(n),2)-(2*(n-count));
		//DownRight
		sum+=pow(double(n),2)-(6*(n-count));
		//DownLeft
		sum+=pow(double(n),2)-(4*(n-count));
		count++;
	}
	//As easy as that
	cout<<sum+1; //DON'T FORGET THE 1
	//cout<<count2;
}