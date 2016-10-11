/*A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numserically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012,021,102,120,201,210
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string combine(int one,int two,int three,int four,int five, int six,int seven,int eight, int nine, int ten){
	stringstream final;
	final<<one<<two<<three<<four<<five<<six<<seven<<eight<<nine<<ten;
	//cout<<final.str()<<endl;
	return final.str();
}


int main(){
	cout<<"PROGRAM BOOTING UP...."<<endl;
	vector<string> storage;
	int count=0;
	cout<<"INITIALISATION OF SOFTWARE DONE. GENERATING PERMUTATIONS..."<<endl;
	int nums[10]={0,1,2,3,4,5,6,7,8,9};
	do{
		storage.push_back(combine(nums[0],nums[1],nums[2],nums[3],nums[4],nums[5],nums[6],nums[7],nums[8],nums[9]));count++;
}while (next_permutation(nums,nums+10));
cout<<"GENERATION COMPLETED. SORTING BEGINS..."<<endl;
sort(storage.begin(),storage.end());
cout<<"END OF SORTING"<<endl<<"1 MILLIONTH PERMUTATION --> ";
cout<<storage[999999]<<endl;//1000000-1=99999. Array starts from 0;
cout<<"NUMBER OF PERMUTATIONS FOUND --> "<<count<<endl;
cout<<"PROGRAM EXITED. THANK YOU FOR YOUR TIME.";
return 0;
}