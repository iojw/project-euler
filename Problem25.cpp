/*The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?*/

#include <iostream>
#include <ttmath/ttmath.h>
using namespace std;

int noofdigits(ttmath::UInt<100> num){
	int count=0;
	while (num!=0){
		num/=10;
		count++;
	}
	return count;
}

int main(){
	ttmath::UInt<100> x=1,y=1,tmp, fibocount=1;
	for (int i=1;;i++)
		{
			if (noofdigits(x)>=1000)
				{cout<<x<<endl<<fibocount;break;}
			tmp=y;
			y+=x;
			x=tmp;
			fibocount++;
		}
		return 0;
}



