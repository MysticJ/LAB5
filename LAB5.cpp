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
	srand(time(NULL));
	int random=rand()%div+1;
	return random;
}

int Sum(int sum){
	// Generate the first dice
	int dice1=randGen(6);
	// playing
	sleep(1);
	// show result
	// Generate the second dice
	int dice2=randGen(6);
	sleep(1);
	// Generate the third dice
	int dice3=randGen(6);
	sleep(1);
	// Generate the sum of the dices
	sum=sum+dice1+dice2+dice3;
	// to test
	// cout<<"dice1="<<dice1<<"\tdice2="<<dice2<<"\tdice3="<<dice3<<"\nsum="<<sum<<"\n"<<endl;
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
	// first player:
	int sum1=Sum(0);
	int sum2=Sum(0);
	int sum3=Sum(0);
	if ((sum1!=sum2)&&(sum2!=sum3)&&(sum3!=sum1)){
		if (sum1>sum2){
			if (sum1>sum3){
				// player1 wins
			}
			else { // sum1<sum3
				// player3 wins
			}
		}
		else { // sum1<sum2
			if (sum2>sum3) {
				// player2 wins
			}
			else { // sum2<sum3
				// player3 wins
			}
		}
	}
	else if ((sum1==sum2)&&(sum1!=sum3)){
		if (sum1>sum3){
			// player1 and player2 wins
		}
		else { // sum1=sum2<sum3
			// player3 wins
		}
	}
	else if ((sum1==sum3)&&(sum1!=sum2)){
		if (sum1>sum2){
			// player1 and player3 wins
		}
		else { // sum1=sum3<sum2
			// player2 wins
		}
	}
	else if ((sum2==sum3)&&(sum2!=sum1)){
		if (sum2>sum1){
			// player2 and player3 wins
		}
		else { // sum2=sum3<sum1
			// player1 wins
		}
	}
	else { // sum1=sum2=sum3
		// a tie, no one wins
	}

	return 0;
}
