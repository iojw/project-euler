/*Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13  62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num){
	if (num==2||num==3)
		return true;
	if (num==1||num%2==0)
		return false;
	for (int i=3;i<=sqrt(num);i++){
		if (num%i==0)
			return false;
	}
	return true;
}

int main(){
	//Look at Problem58.txt for formulae
	int count=0;
	int i;
	for (i=1;;i++){
		//calculate bottom right;
		if (isPrime(pow((double)(2*i+1),2)))
			count++;
		//bottom left
		if (isPrime(pow((double)(2*i+1),2)-2*i))
			count++;
		//top left
		if (isPrime(pow((double)(2*i+1),2)-4*i))
			count++;
		//top right
		if (isPrime(pow((double)(2*i+1),2)-6*i))
			count++;
		if (((double)count/(i*4+1))*100<10)
			{cout<<2*i+1<<endl;break;}
	}
}