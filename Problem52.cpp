/*It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.*/

#include <iostream>
#include <string>
#include <sstream>
	using namespace std;

string toString(int num){
	stringstream ss;
	ss<<num;
	return ss.str();
}
bool isPerm(int num){
	string a=toString(num);
	string b=toString(num*2);
	string c=toString(num*3);
	string d=toString(num*4);
	string e=toString(num*5);
	string f=toString(num*6);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	sort(e.begin(), e.end());
	sort(f.begin(), f.end());
	if (a==b&&b==c&&c==d&&d==e&&e==f)
		return true;
	else 
		return false;
}

int main(){
	for (int i=1;;i++){
		if (isPerm(i))
			{cout<<i<<endl;break;}
	}
	return 0;
}