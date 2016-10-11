//Find the maximum total from top to bottom of the triangle below:

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void getdata(int n,string raw,int conv[15][15]){
	int b=0;
	stringstream str(raw);
	string word;
	//cout<<raw<<endl;
	while (getline(str,word,' '))
		{conv[n][b]=atoi(word.c_str());b++;}
	
}

int main(){
	int conv[15][15];
//init

	vector<string> num;
//getting string data from .txt
	string a;
	ifstream file("Problem18.txt");
	if (file.is_open()==true){
		//int n=0;
		while (file.good()==true){
			getline(file,a);
			num.push_back(a);
			//n++;
		}
		file.close();	
	}
//end of data collection
	for (int i=0;i<15;i++)
		getdata(i,num[i],conv);
	for (int n=14;n>0;n--){
		for (int i=1;i<=n;i++){
			if (conv[n][i]>conv[n][i-1])
				conv[n-1][i-1]+=conv[n][i];
			else if (conv[n][i-1]>conv[n][i]||conv[n][i-1]==conv[n][i])
				conv[n-1][i-1]+=conv[n][i-1];
		}
	}
	cout<<conv[0][0];
	
}
/*
There was a young man from London
Who dreamt that he was Poseidon
He*/