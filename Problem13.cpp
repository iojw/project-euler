//Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ttmath/ttmath.h>
using namespace std;

int main(){
//getting numbers
	string raw;
	vector<string> vectornum;
	ifstream numfile ("Problem13.txt");
	if (numfile.is_open()){
		while (numfile.good()){
			getline(numfile,raw);
			vectornum.push_back(raw);
			//cout<<raw;
		}
		numfile.close();
	}
	ttmath::UInt<10> accu="0";
	for (int i=0;i<100;i++){
		//cout<<vectornum[i]<<endl;
		accu+=vectornum[i];
	}
	string ans=accu.ToString();
	cout<<ans.substr(0,10);
return 0;

}