/*We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39  186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int merge4(int a, int b, int c, int d){
	return (((10*a)+b)*10+c)*10+d;
}

int merge2(int a, int b){
	return a*10+b;
}

int merge3(int a , int b, int c){
	return (a*10+b)*10+c;
}

int main(){
	vector<int> products;
	int sum=0;
	int nums[]={1,2,3,4,5,6,7,8,9};
	do {
		if (merge2(nums[0],nums[1])*merge3(nums[2],nums[3],nums[4])==merge4(nums[5],nums[6],nums[7],nums[8]))
			{products.push_back(merge2(nums[0],nums[1])*merge3(nums[2],nums[3],nums[4]));
				//int a=(merge2(nums[0],nums[1])*merge3(nums[2],nums[3],nums[4]));
				//cout<<merge2(nums[0],nums[1])<<" "<<merge3(nums[2],nums[3],nums[4])<<" "<<a<<endl;
				}
		if (nums[0]*merge4(nums[1],nums[2],nums[3],nums[4])==merge4(nums[5],nums[6],nums[7],nums[8]))
			{products.push_back(nums[0]*merge4(nums[1],nums[2],nums[3],nums[4]));
				//int a=(nums[0]*merge4(nums[1],nums[2],nums[3],nums[4]));
				//cout<<nums[0]<<" "<<merge4(nums[1],nums[2],nums[3],nums[4])<<" "<<a<<endl;
				}
	}while (next_permutation(nums,nums+9));
	//cout<<endl<<endl<<endl;
	sort(products.begin(),products.end());
	products.erase(unique(products.begin(),products.end()),products.end());
	for (unsigned i=0;i<products.size();i++){
		sum+=products[i];
		//cout<<products[i]<<endl;
	}
	cout<<sum;
}