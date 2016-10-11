/*The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
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

void tokenise(string raw,vector<string> &individual){
	stringstream ss(raw);
	string word;
	while (getline(ss,word,','))
		individual.push_back(word);
}

bool isTri(int num){
	for (int n=1;n<=num;n++){
		if ((0.5*n)*(n+1)==num)
			return true;
	}
	return false;
}

int sumofletters(string str){
	int sum=0;
	for (unsigned  n=0;n<str.size();n++)
		sum+=letters(str.substr(n,1).at(0));
	return sum;
}
int main(){
	string raw;
	vector<string> individual;
	ifstream file ("Problem42.txt");
	if (file.is_open()){
		while (file.good()){
			getline(file,raw);
		}
		file.close();
	}
	cout<<raw;
	tokenise(raw,individual);
	//remove quotes;
	for (unsigned i=0;i<individual.size();i++){
		individual[i].erase(0,1);
		individual[i].erase(individual[i].size()-1,1);
	}
	int tricount=0;
	for (unsigned i=0;i<individual.size();i++){
		if (isTri(sumofletters(individual[i])))
		{tricount++;cout<<individual[i]<<endl;}
	}
	cout<<tricount;
}