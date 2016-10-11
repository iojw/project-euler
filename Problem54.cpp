/*In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
High Card: Highest value card.
One Pair: Two cards of the same value.
Two Pairs: Two different pairs.
Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.

The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

//CLUBS=14;
//SPADES=15;
//HEARTS=16;
//DIAMONDS=17;
int value(char str){
	switch (str){
		case 'A':
		return 1;
		break;
		case '2':
		return 2;
		break;
		case '3':
		return 3;
		break;
		case '4':
		return 4;
		break;
		case '5':
		return 5;
		break;
		case '6':
		return 6;
		break;
		case '7':
		return 7;
		break;
		case '8':
		return 8;
		break;
		case '9':
		return 9;
		break;
		case 'T':
		return 10;
		break;
		case 'J':
		return 11;
		break;
		case 'Q':
		return 12;
		break;
		case 'K':
		return 13;
		break;
		case 'C':
		return 14;
		break;
		case 'S':
		return 15;
		break;
		case 'H':
		return 16;
		break;
		case 'D':
		return 17;
		break;
		default:
		return 0;
		break;
	}
	return 0;
}

bool royal(string str){
	int check[18];
	for (int a=0;a<18;a++)
		check[a]=0;
	for (int i=0;i<10;i++){
		check[value(str.at(i))]++;
	}
	if (check[10]==1&&check[11]==1&&check[12]==1&&check[13]==1&&check[1]==1&&(check[14]==5||check[15]==5||check[16]==5||check[17]==5))
		return true;
	else 
		return false;
}

int straightf(string str){
	int check[18];
	for (int a=0;a<18;a++)
		check[a]=0;
	for (int i=0;i<10;i++){
		check[value(str.at(i))]++;
	}
	for (int i=0;i+4<=13;i++){
		if (check[i]==1&&check[i+1]==1&&check[i+2]==1&&check[i+3]==1&&check[i+4]==1&&(check[14]==5||check[15]==5||check[16]==5||check[17]==5))
			return i+4;
	}
	return false;
}

int fourkind(string str){
	int check[18];
	for (int a=0;a<18;a++)
		check[a]=0;
	for (int i=0;i<10;i+=2){
		check[value(str.at(i))]++;
	}
	for (int i=0;i<=13;i++){
		if (check[i]==4&&i==1)
			return 14;
		else if (check[i]==4)
		{return i;}
	}
	return false;
}

int threekind(string str){
	int check[18];
	for (int a=0;a<18;a++)
		check[a]=0;
	for (int i=0;i<10;i+=2){
		check[value(str.at(i))]++;
	}
	for (int i=0;i<=13;i++){
		if (check[i]==3&&i==1)
			return 14;
		else if (check[i]==3)
			return i;
	}
	return false;
}

bool flush(string str){
	int check[18];
	for (int a=0;a<18;a++)
		check[a]=0;
	for (int i=1;i<10;i+=2){
		check[value(str.at(i))]++;
	}
	if (check[14]==5||check[15]==5||check[16]==5||check[17]==5)
		return true;
	else
		return false;
}

int onepair(string str){
	int check[18];
	for (int a=0;a<18;a++)
		check[a]=0;
	for (int i=0;i<10;i+=2){
		check[value(str.at(i))]++;
	}
	//cout<<check[1]<<endl;
	for (int i=0;i<=13;i++){
		//cout<<i<<endl;
		if (check[i]==2&&i==1)
			{return 14;}
		if (check[i]==2)
			return i;
	}
	//cout<<"aaaa"<<endl;
	return false;
}

int twopair(string str){
	int check[18];
	int count=0;
	for (int a=0;a<18;a++)
		check[a]=0;
	for (int i=0;i<10;i+=2){
		check[value(str.at(i))]++;
	}
	vector<int> pairs;
	for (int i=0;i<=13;i++){
		if (check[i]==2)
			{count++;pairs.push_back(i);}
		if (pairs.size()==2){
			if (pairs[0]==1||pairs[1]==1)
				return 14;
			else if (pairs[0]>pairs[1])
				return pairs[0];
			else
				return pairs[1];
		}
	}
	return false;
}

int straight(string str){
	int check[18];
	for (int a=0;a<18;a++)
		check[a]=0;
	for (int i=0;i<10;i+=2){
		check[value(str.at(i))]++;
	}
	if (check[10]==1&&check[11]==1&&check[12]==1&&check[13]==1&&check[1]==1)
		return 14;
	for (int i=0;i+4<=13;i++){
		if (check[i]==true&&check[i+1]==true&&check[i+2]==true&&check[i+3]==true&&check[i+4]==true)
			return i+4;
	}
	return false;
}

int fullh(string str){
	if (onepair(str)!=0&&threekind(str)==1)
		return 14;
	else if (onepair(str)!=0&&threekind(str)>0)
		return threekind(str);
	else
		return false;
}

int high(string str,int rank){
 	vector<int> max;
	for (int i=0;i<9;i+=2){
	if (value(str.at(i))==1)
		{max.push_back(14);}
	else
		{max.push_back(value(str.at(i)));}
	}
	sort(max.begin(), max.end());
	return max[max.size()-1-rank+1];
}

bool todeath(string str){
	int i=1;
	string one=str.substr(0,10);
	string two=str.substr(10,10);
	for(i=1;;i++){
		if (high(one,i)>high(two,i))
			return 0;
		else if (high(one,i)<high(two,i))
			return 1;
	}
	return 0;
}
bool win(string str){
	//Different hands ranked from 0 to 9
	int rank1,rank2;
	string one=str.substr(0,10);
	string two=str.substr(10,10);
	//give ranking for one.
	if (royal(one))
		rank1=9;
	else if (straightf(one)>0)
		rank1=8;
	else if (fourkind(one)>0)
		rank1=7;
	else if (fullh(one)>0)
		rank1=6;
	else if (flush(one)>0)
		rank1=5;
	else if (straight(one)>0)
		rank1=4;
	else if (threekind(one)>0)
		rank1=3;
	else if (twopair(one)>0)
		rank1=2;
	else if (onepair(one)>0)
		rank1=1;
	else
		rank1=0;
	//give ranking for two.
	if (royal(two))
		rank2=9;
	else if (straightf(two)>0)
		rank2=8;
	else if (fourkind(two)>0)
		rank2=7;
	else if (fullh(two)>0)
		rank2=6;
	else if (flush(two)>0)
		rank2=5;
	else if (straight(two)>0)
		rank2=4;
	else if (threekind(two)>0)
		rank2=3;
	else if (twopair(two)>0)
		rank2=2;
	else if (onepair(two)>0)
		rank2=1;
	else
		rank2=0;
	// cout<<rank1<<" "<<rank2<<" "<<str<<endl;
	if (rank1>rank2)
		return 0;
	else if (rank2>rank1)
		return 1;
	else if (rank1==rank2){
		if (rank1==8){
			if (straightf(one)>straightf(two))
				return 0;
			else if (straightf(one)<straightf(two))
				return 1;
			else
				return todeath(str);
		}
		else if (rank1==7){
			if (fourkind(one)>fourkind(two))
				return 0;
			else if (fourkind(two)>fourkind(one))
				return 1;
			else 
				return todeath(str);
		}
		else if (rank1==6){
			if (fullh(one)>fullh(two))
				return 0;
			else if (fullh(one)>fullh(two))
				return 1;
			else
				return todeath(str);
		}
		else if (rank1==5)
			return todeath(str);
		else if (rank1==4){
			if (straight(one)>straight(two))
				return 0;
			else if (straight(one)<straight(two))
				return 1;
			else 
				return todeath(str);}
		else if (rank1==3){
			if (threekind(one)>threekind(two))
				return 0;
			else if (threekind(one)<threekind(two))
				return 1;
			else 
				return todeath(str);
		}
		else if (rank1==2){
			if (twopair(one)>twopair(two))
				return 0;
			else if (twopair(one)<twopair(two))
				return 1;
			else
				return todeath(str);
		}
		else if (rank1==1){
			if (onepair(one)>onepair(two))
				return 0;
			else if (onepair(one)<onepair(two))
				return 1;
			else
				return todeath(str);
		}
		else if (rank1==0)
			return todeath(str);
	}
	return 0;
}

int main(){
	vector<string> raw;	
	string temp;
	//get data
	ifstream file ("Problem54.txt");
	if (file.is_open()){
		while(file.good()){
			getline(file,temp);
			raw.push_back(temp);
		}
		file.close();
	}
	vector<string> second(raw.size(),"");
	//remove spaces from everything
	for (unsigned i=0;i<raw.size()-1;i++){
		string a;
		stringstream ss(raw[i]);
		while (getline(ss,a,' ')){
			second[i].append(a);
		}}
		int count=0,count2=0;
		for (unsigned i=0;i<second.size()-1;i++){
			if (win(second[i])==0 )
				count++;
		}
		cout<<count<<endl;
	}