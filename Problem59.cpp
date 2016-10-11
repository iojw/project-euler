/*Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher1.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int toInt(string str){
	stringstream ss(str);
	int num;
	ss>>num;
	return num;
}
int main()
{
	ifstream file("Problem59.txt");
	vector<string> strings;
	vector<int> nums;
	string raw;
	//get data
	if (file.is_open()){
		while (file.good()){
			getline(file,raw,',');
			strings.push_back(raw);
		}
		file.close();
	}
	//convert strings to ints;
	for (int i=0;i<strings.size();i++){
		nums.push_back(toInt(strings[i]));
	}
	char decrypt[nums.size()];
	int num=0;
	bool found=false;
	string key,current;
	//loop through all possible lowercase letters 26*26*26 as the key. Look the the phrase 'the' each time. 'the' is the most
	//commonly used English word.
	for (int i=(int)'a';i<=(int)'z'&&found!=true;i++){
		for (int b=(int)'a';b<=(int)'z'&&found!=true;b++){
			for (int c=(int)'a';c<=(int)'z'&&found!=true;c++){
				key="";
				 stringstream ss;
				 ss<<(char)i<<(char)b<<(char)c;
				 ss>>key;
				 current="";
				 for (int i = 0; i < nums.size(); ++i)
				 {
				 	decrypt[i]=nums[i]^key.at(i%3);
				 	if (decrypt[i]=='e'&&decrypt[i-1]=='h'&&(decrypt[i-2]=='t'||decrypt[i+2]=='T')&&decrypt[i+1]==' '&&decrypt[i-3]==' ')
				 		{cout<<key<<endl;found=true;break;}
				 }
	
			}
		}
	}
	//add ascii values of XORed ints. prints out in the process.
	int count=0;
	for (int i=0;i<nums.size();++i){
		count+=nums[i]^key.at(i%3);
		char r=nums[i]^key.at(i%3);
		cout<<r;
	}
	cout<<endl<<count<<endl;
	return 0;
}