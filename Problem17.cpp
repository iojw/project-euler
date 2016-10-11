/*If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.*/

#include <iostream>
using namespace std;

int basic(int x){
	switch (x){
		case 1://one
		return 3;
		break;
		
		case 2://two
		return 3;
		break;
		
		case 3://three
		return 5;
		break;
		
		case 4://four
		return 4;
		break;
		
		case 5://five
		return 4;
		break;
		
		case 6://six
		return 3;
		break;
		
		case 7:
		return 5;
		break;
		
		case 8:
		return 5;
		break;
		
		case 9:
		return 4;
		break;
		
		case 10:
		return 3;
		break;
		
		case 11:
		return 6;
		break;
		
		case 12:
		return 6;
		break;
		
		case 13:
		return 8;
		break;
		
		case 14:
		return 8;
		break;
		
		case 15:
		return 7;
		break;
		
		case 16:
		return 7;
		break;
		
		case 17:
		return 9;
		break;
		
		case 18:
		return 8;
		break;
		
		case 19:
		return 8;
		break;
		
		case 20:
		return 6;
		break;
		
		case 30:
		return 6;
		break;
		
		case 40:
		return 5;
		break;
		
		case 50:
		return 5;
		break;
		
		case 60:
		return 5;
		break;
		
		case 70:
		return 7;
		break;
		
		case 80:
		return 6;
		break;
		
		case 90:
		return 6;
		break;
		
		
		default:
			if (x>10&&x<100)
				{int sum=(basic(x%10)+basic(x-x%10));return sum;}
			else if (x%100==0&&x<1000)
				{int sum=basic(x/100)+7;return sum;}
			else if (x>100&&x<1000)
				{int sum=basic(x%100)+basic(x-x%100)+3;return sum;}
			else if (x%1000==0)
				{int sum=basic(x/1000)+8;return sum;}
				
		break;
		
	}
	//xreturn ;	
}

int main(){
	int accu=0;
	for (int i=1;i<=1000;i++)
		accu+=basic(i);
	cout<<accu;
	//cout<<basic(1000);
	return 0;
}