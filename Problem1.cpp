//Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
using namespace std;

int main(){
int a,accu=0;
for (a=1;3*a<1000;a++)
{

	if (a%5!=0)
		accu+=3*a;
	
}
for (a=1;5*a<1000;a++)
{
	if (5*a<1000&&5*a!=3*a)
		accu+=5*a;
}
cout<<accu<<endl;
cin.ignore();
cin.get();
return 0;
}
