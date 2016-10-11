/*The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int digits(int num){
	//returns number of digits
	int count=0;
	while (num!=0){
		count++;
		num/=10;
	}
	return count;
}

bool check(int a,int b,int c,int d,int e,vector<bool> primes){
	//checks if all concantenations are prime
	int nums[5]={a,b,c,d,e};
	//bool all=true;
	for (int i=0;i<5;i++){
		for (int y=0;y<5;y++){
			//cout<<nums[i]*pow((double)10,digits(nums[y]))+nums[y]<<endl;
			if (primes[nums[i]*pow((double)10,digits(nums[y]))+nums[y]]==false&&i!=y)
				{return false;}
		}
	}
		
	return true;
}

int main(){
	//generate primes up to 10,000
	int limit=10000;
	vector<bool> primes(limit+1,true);
	primes[0]=false;
	primes[1]=false;
	for (int i=4;i<=limit;i+=2){
		primes[i]=false;
	}
	for (int n=3;n<=sqrt(limit);n+=2){
		if (primes[n]==true){
			for (int m=n*2;m<=limit;m+=n){
				primes[m]=false;
			}
		}
	}
//	cout<<primes[35]<<endl;
	//prime generation completed;
	//loop through all primes.
	bool found=false;


	for (int a = 0;found!=true; ++a)
	{
		if (primes[a]){
			cout<<a<<endl;
			for (int b=0;found!=true&&b<a;b++){
				if (primes[b]){
					//cout<<b<<endl;
					for (int c=0;found!=true&&c<b;c++){
						if (primes[c]){
						//	cout<<c<<endl;
							for (int d=0;found!=true&&d<c;d++){
								//cout<<endl<<endl<<primes[3]<<endl;
								if (primes[d]){
									for (int e=0;found!=true&&e<d;e++){
									if (a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d){
										if (check(a,b,c,d,e,primes))
											{found=true;cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;break;}
									}
								}
								}
							}
						}
					}
				}
			}
		}

			
	}
		//cout<<check(9,7,5,3,primes);

}