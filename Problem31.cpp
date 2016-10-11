/*In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1£1 + 150p + 220p + 15p + 12p + 31p
How many different ways can £2 be made using any number of coins?*/

#include <iostream>
using namespace std;

int main(){
	int ways=0;
	for (int a=0;a*1<=200;a++){
		//cout<<"a "<<a<<endl;
		for (int b=0;b*2+a*1<=200;b++){
			//cout<<"b "<<b<<endl;
			for (int c=0;c*5+b*2+a*1<=200;c++){
				//cout<<"c "<<c<<endl;
				for (int d=0;d*10+c*5+b*2+a*1<=200;d++){
					//cout<<"d "<<d<<endl;
					for (int e=0;e*20+d*10+c*5+b*2+a*1<=200;e++){
						//cout<<"e "<<e<<endl;
						for (int f=0;f*50+e*20+d*10+c*5+b*2+a*1<=200;f+=1){
							//cout<<"f "<<f<<endl;
							for (int g=0;g*100+f*50+e*20+d*10+c*5+b*2+a*1<=200;g++){
								//cout<<"g "<<g<<endl;
								for (int i=0;i*200+g*100+f*50+e*20+d*10+c*5+b*2+a*1<=200;i++){
									//cout<<"i "<<i<<endl;
									if (a*1+b*2+c*5+d*10+e*20+f*50+g*100+i*200==200)
										{ways++;}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ways;
}