/*Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938  53 = 49714.

What is the total of all the name scores in the file?*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int letters(char a){
	switch (a){
		case 'A':
		return 1;
		break;
		
		case 'B':
		return 2;
		break;
		
		case 'C':
		return 3;
		break;
		
		case 'D':
		return 4;
		break;
		
		case 'E':
		return 5;
		break;
		
		case 'F':
		return 6;
		break;
		
		case 'G':
		return 7;
		break;
		
		case 'H':
		return 8;
		break;
		
		case 'I':
		return 9;
		break;
		
		case 'J':
		return 10;
		break;
		
		case 'K':
		return 11;
		break;
		
		case 'L':
		return 12;
		break;
		
		case 'M':
		return 13;
		break;
		
		case 'N':
		return 14;
		break;
		
		case 'O':
		return 15;
		break;
		
		case 'P':
		return 16;
		break;
		
		case 'Q':
		return 17;
		break;
		
		case 'R':
		return 18;
		break;
		
		case 'S':
		return 19;
		break;
		
		case 'T':
		return 20;
		break;
		
		case 'U':
		return 21;
		break;
		
		case 'V':
		return 22;
		break;
		
		case 'W':
		return 23;
		break;
		
		case 'X':
		return 24;
		break;
		
		case 'Y':
		return 25;
		break;
		
		case 'Z':
		return 26;
		break;
		
		
	}
	return 0;
}

int alphavalue(string val,int i){
	int sum=0;
	while (val!=""){
		sum+=letters(val.at(0));
	val.erase(0,1);}
	long long int final=sum*(i+1);
	//cout<<sum<<" "<<i+1<<" "<<final<<endl;
	return final;
}


int getdata(string store,vector<string> & individual){
	//vector<string> individual;
	stringstream str(store);
	int max=-1;
	string word;
	while (getline(str,word,','))
		{individual.push_back(word);max++;}
	return max;
}

int main(){
//get correct data into slots
	string whole;
	int max;
	vector<string> individual;
	ifstream file ("Problem22.txt");
	if (file.is_open()){
		while (file.good()==true){
			getline(file,whole);
		}
		file.close();
	}
	max=getdata(whole,individual);
//end of data collection
//removing double quotes from all strings

	for (int i=0;i<=max;i++){
		individual[i].erase(0,1);
		int second=individual[i].size()-1;
		individual[i].erase(second,1);
	}
	
//end of removal of double quotes
	long totalsum=0;
	sort (individual.begin(), individual.end());
	for (int i=0;i<=max;i++){
		totalsum+=alphavalue(individual[i],i);
		//cout<<individual[i]<<" "<<i<<" "<<alphavalue(individual[i],i)<<endl;
	}
	cout<<totalsum;
	//cout<<endl<<individual[141];
	return 0;
}