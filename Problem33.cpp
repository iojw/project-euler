/*The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.*/

#include <iostream>
#include <ttmath/ttmath.h>
#include <vector>
using namespace std;

bool checknum(int a,vector<int> denom);
bool checkdenom(int a,vector<int> num);

int gcd(int a, int b)
{
  int c = a % b;
  while(c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

int main(){
	vector<int> num;
	vector<int> denom;
	for (int i=11;i<=99;i++){
		//cout<<i<<endl;
		for (int b=11;b<=99;b++){
			//cout<<b<<endl;
			if (i%10==b%10&&i%10!=0&&b%10!=0&&b!=i)
				{
					//cout<<"1"<<endl;
					if ((float)(i/10)/(float)(b/10)==(float)i/(float)b&&checknum(i,denom)==false&&checkdenom(b,num)==false)
					{	num.push_back(i);denom.push_back(b);
							//cout<<i<<" "<<b<<endl;
				}}
			
			if (i%10==b/10&&i%10!=0&&b%10!=0&&b!=i)
					{
						//cout<<"2"<<endl;
						if (((float)(i/10))/((float)(b%10))==(float)i/(float)b&&checknum(i,denom)==false&&checkdenom(b,num)==false)
							{cout<<i<<" "<<b<<endl;num.push_back(i);denom.push_back(b);}
					}
			if (i/10==b%10&&i%10!=0&&b%10!=0&&b!=i)
							{
								//cout<<"3"<<endl;
								if (((float)(i%10))/((float)(b/10))==(float)i/(float)b&&checknum(i,denom)==false&&checkdenom(b,num)==false)
									{cout<<i<<" "<<b<<endl;num.push_back(i);denom.push_back(b);}
							}
			if (i/10==b/10&&i%10!=0&&b%10!=0&&b!=i)
									{
									//cout<<"4"<<endl;
									if (((float)(i%10)/(float)(b%10))==(float)i/(float)b&&checknum(i,denom)==false&&checkdenom(b,num)==false)
									{cout<<i<<" "<<b<<endl;num.push_back(i);denom.push_back(b);}
									}
		
		}
	}
	//int product=1;
	int denomtotal=1,numtotal=1;
	for (unsigned i=0;i<num.size();i++){
		numtotal*=num[i];
	}
	for (unsigned i=0;i<denom.size();i++){
		denomtotal*=denom[i];
	}
	cout<<endl<<"Decimal: "<<numtotal/denomtotal<<endl<<"Fraction: "<<numtotal<<"/"<<denomtotal<<" = "<<numtotal/gcd(numtotal,denomtotal)<<"/"<<denomtotal/gcd(numtotal,denomtotal)<<endl<<"Denominator: "<<denomtotal/gcd(numtotal,denomtotal);
	return 0;
}

bool checkdenom(int a,vector<int> num){
	bool found=false;
	for (unsigned i=0;i<num.size();i++){
		if (a==num[i])
			found=true;
	}
	return found;
}

bool checknum(int a,vector<int> denom){
	bool found=false;
	for (unsigned i=0;i<denom.size();i++){
		if (a==denom[i])
			found=true;
	}
	return found;
}






