//============================================================================
// Name        : LAB5.cpp
// Author      : QIAN Shiyi & JIN Menghe
// Version     :
// Copyright   : Your copyright notice
// Description : LAB 5 - Minion's Dirty Dice
//============================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;

int randGen(int div){

	int random=rand()%div+1;
	return random;
}

int Sum(int sum){
	cout<<"Dice rolling..."<<endl;
	srand(time(NULL));
	// Generate the first dice
	int dice1=randGen(6);
	cout<<"dice1="<<dice1;
	// playing
	sleep(1);
	// show result
	// Generate the second dice
	int dice2=randGen(6);
	cout<<"\tdice2="<<dice2;
	sleep(1);
	// Generate the third dice
	int dice3=randGen(6);
	cout<<"\tdice3="<<dice3;
	sleep(1);
	// Generate the sum of the dices
	sum=sum+dice1+dice2+dice3;
	cout<<"\nsum="<<sum<<"\n"<<endl;
	// to test
    //cout<<"dice1="<<dice1<<"\tdice2="<<dice2<<"\tdice3="<<dice3<<"\nsum="<<sum<<"\n"<<endl;
	// if any of the dice gives 3
	if ((dice1==6)||(dice2==6)||(dice3==6)){
		sum=Sum(sum);
	}
	return sum;
}

void showOfOne(string name){
	// information of only one player winning
}

void showOfTwo(string name1, string name2){
	// information of two players winning
}

void showOfThree(){
	// information of tie
}

int main() {
	// description;
	// basic function
	int a,b,c;
	int sum1=0;
	int sum2=0;
	int sum3=0;
	// first player:
	cout<<"Player1: Press 1 to roll dice"<<endl;
	cin>>a;

	if(a==1)
		sum1=Sum(0);
	// second player:
	cout<<"Player2: Press 2 to roll dice"<<endl;
	cin>>b;
	//cout<<"Dice rolling"<<endl;
	if(b==2)
		sum2=Sum(0);
	// third player:
	cout<<"Player3: Press 3 to roll dice"<<endl;
	cin>>c;
	//cout<<"Dice rolling"<<endl;
	if(c==3)
		sum3=Sum(0);

	cout<<"Player1: "<<sum1<<endl;
	cout<<"Player2: "<<sum2<<endl;
	cout<<"Player3: "<<sum3<<endl;

	if ((sum1!=sum2)&&(sum2!=sum3)&&(sum3!=sum1)){
		if (sum1>sum2){
			if (sum1>sum3){
				cout<<"Player1 win"<<endl;// player1 wins
			}
			else { // sum1<sum3
				cout<<"Player3 win"<<endl;// player3 wins
			}
		}
		else { // sum1<sum2
			if (sum2>sum3) {
				cout<<"Player2 win"<<endl;// player2 wins
			}
			else { // sum2<sum3
				cout<<"Player3 win"<<endl;// player3 wins
			}
		}
	}
	else if ((sum1==sum2)&&(sum1!=sum3)){
		if (sum1>sum3){
			cout<<"Player1&2 win"<<endl;// player1 and player2 wins
		}
		else { // sum1=sum2<sum3
			cout<<"Player3 win"<<endl;// player3 wins
		}
	}
	else if ((sum1==sum3)&&(sum1!=sum2)){
		if (sum1>sum2){
			cout<<"Player1&3 win"<<endl;// player1 and player3 wins
		}
		else { // sum1=sum3<sum2
			cout<<"Player2 win"<<endl;// player2 wins
		}
	}
	else if ((sum2==sum3)&&(sum2!=sum1)){
		if (sum2>sum1){
			cout<<"Player2&3 win"<<endl;// player2 and player3 wins
		}
		else { // sum2=sum3<sum1
			cout<<"Player1 win"<<endl;// player1 wins
		}
	}
	else { // sum1=sum2=sum3
		cout<<"No one win"<<endl;// a tie, no one wins
	}

	return 0;
}
