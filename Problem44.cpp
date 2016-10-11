/*Pentagonal numbers are generated by the formula, Pn=n(3n-1)/2. The first ten pentagonal numbers are:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70  22 = 48, is not pentagonal.

Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference is pentagonal and D = |Pk  Pj| is minimised; what is the value of D?*/

#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

bool isPenta(int num){
	double ans=(sqrt(24*num+1)+1)/6;
	//cout<<ans<<endl;
	if (floor(ans)==ans)
		return true;
	else
		return false;
}

int main()
{
	clock_t startTime = clock();
	bool found=false;
	for (int i = 1;found!=true; ++i)
	{
		int j=i*(3*i-1)/2;
		for (int b = 1; b < i; ++b)
		{
		int k=b*(3*b-1)/2;
		if (isPenta(j+k)&&isPenta(j-k))
			{cout<<j<<" "<<k<<endl<<j-k<<endl;found=true;break;}
		}
	}
	cout << "Execution Time: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	return 0;
}