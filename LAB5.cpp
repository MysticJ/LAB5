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
	cout<<"Oh yeeeeesssss! "<<name<<" has won with his luck over the others!"<<endl;
}

void showOfTwo(string name1, string name2){
	// information of two players winning
	cout<<"What a coincident!!! "<<name1<<" and "<<name2<<" has tossed the same number!"<<endl;
}

void showOfThree(){
	// information of tie
	cout<<"No way!!! How can you get the same number all by randomly tossing the dices?!"<<endl;
}

int main() {
	// description;
	cout<<"In this game, three players will be Minion Mel, Carl and Tim!"<<endl;
	cout<<"You are going to have a game of tossing dices."<<endl;
	cout<<"Each of you will randomly toss 3 dices and add up the three numbers of the dices."<<endl;
	cout<<"Specially, if you have tossed one or more than one \"6\", you can dice one more time!"<<endl;
	cout<<"The numbers of three dices in the new toss will be added to your sum of last toss."<<endl;
	cout<<"If anyone has the largest sum, he will be awarded with one day off and lots of bananas!"<<endl;
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
				showOfOne("Mel");// player1 wins
			}
			else { // sum1<sum3
				showOfOne("Tim");// player3 wins
			}
		}
		else { // sum1<sum2
			if (sum2>sum3) {
				showOfOne("Carl");// player2 wins
			}
			else { // sum2<sum3
				showOfOne("Tim")// player3 wins
			}
		}
	}
	else if ((sum1==sum2)&&(sum1!=sum3)){
		if (sum1>sum3){
			showOfTwo("Mel", "Carl");// player1 and player2 wins
		}
		else { // sum1=sum2<sum3
			showOfOne("Tim");// player3 wins
		}
	}
	else if ((sum1==sum3)&&(sum1!=sum2)){
		if (sum1>sum2){
			showOfTwo("Mel", "Tim");// player1 and player3 wins
		}
		else { // sum1=sum3<sum2
			showOfOne("Carl");// player2 wins
		}
	}
	else if ((sum2==sum3)&&(sum2!=sum1)){
		if (sum2>sum1){
			showOfTwo(Tim", "Carl");// player2 and player3 wins
		}
		else { // sum2=sum3<sum1
			showOfOne("Mel");// player1 wins
		}
	}
	else { // sum1=sum2=sum3
		showOfThree();// a tie, no one wins
	}

	return 0;
}
