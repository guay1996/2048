// 2048 (Ongoing).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>   
#include<string>
using namespace std;
using std::string;

int square[4][4] = {0};
int score;

string leftspace(int a, int b) {
	if (square[a][b] == 0 || square[a][b] == 2 || square[a][b] == 4 || square[a][b] == 8) {
		return "|   ";
		}
	else if (square[a][b] == 16 || square[a][b] == 32 || square[a][b] == 64) {
		return "|  ";
		}
	else if (square[a][b] == 128 || square[a][b] == 256 || square[a][b] == 512) {
		return "|  ";
	}
	else if (square[a][b] == 1024 || square[a][b] == 2048 || square[a][b] == 4096 || square[a][b] == 8192) {
		return "| ";
	}
	else if (square[a][b] == 16384 || square[a][b] == 32768) {
		return "| ";
	}
}
string rightspace(int a, int b) {
	if (square[a][b] == 0 || square[a][b] == 2 || square[a][b] == 4 || square[a][b] == 8) {
		return "  ";
	}
	else if (square[a][b] == 16 || square[a][b] == 32 || square[a][b] == 64) {
		return "  ";
	}
	else if (square[a][b] == 128 || square[a][b] == 256 || square[a][b] == 512) {
		return " ";
	}
	else if (square[a][b] == 16384 || square[a][b] == 32768) {
		return "";
	}
	else if (square[a][b] == 1024 || square[a][b] == 2048 || square[a][b] == 4096 || square[a][b] == 8192) {
		return " ";
	}
}



void gameboard()
{
	system("cls");


	cout << "Make the number 2048!" << endl;
	cout << endl;
	cout << "Slide the panels using W (Up), A (Left), S (Down), D(Right)";
	cout << endl;
	cout << endl;

	cout << "_____________________________" << endl;
	cout << "|      |      |      |      |" << endl;
	cout << leftspace(0,0) << square[0][0] << rightspace(0,0)<< leftspace(0,1) << square[0][1] << rightspace(0,1) << leftspace(0,2)<< square[0][2] << rightspace(0,2)<< leftspace(0,3) << square[0][3] << rightspace(0,3)<<"|" << endl;
	cout << "|______|______|______|______|" << endl;
	cout << "|      |      |      |      |" << endl;
	cout << leftspace(1, 0) << square[1][0] << rightspace(1, 0) << leftspace(1, 1) << square[1][1] << rightspace(1, 1) << leftspace(1, 2) << square[1][2] << rightspace(1, 2) << leftspace(1, 3) << square[1][3] << rightspace(1, 3) << "|" << endl;
	cout << "|______|______|______|______|" << endl;
	cout << "|      |      |      |      |" << endl;
	cout << leftspace(2, 0) << square[2][0] << rightspace(2, 0) << leftspace(2, 1) << square[2][1] << rightspace(2, 1) << leftspace(2, 2) << square[2][2] << rightspace(2, 2) << leftspace(2, 3) << square[2][3] << rightspace(2, 3) << "|" << endl;
	cout << "|______|______|______|______|" << endl;
	cout << "|      |      |      |      |" << endl;
	cout << leftspace(3, 0) << square[3][0] << rightspace(3, 0) << leftspace(3, 1) << square[3][1] << rightspace(3, 1) << leftspace(3, 2) << square[3][2] << rightspace(3, 2) << leftspace(3, 3) << square[3][3] << rightspace(3, 3) << "|" << endl;
	cout << "|______|______|______|______|" << endl;

	cout << "Total Score: " << score << endl;
	}
	
void wingame() {
	if (square[0][0] == 2048 || square[0][1] == 2048 || square[0][2] == 2048 || square[0][3] == 2048 || square[1][0] == 2048 || square[1][1] == 2048 || square[1][2] == 2048 || square[1][3] == 2048 || square[2][0] == 2048 || square[2][1] == 2048 || square[2][2] == 2048 || square[2][3] == 2048 || square[3][0] == 2048 || square[3][1] == 2048 || square[3][2] == 2048 || square[3][3] == 2048) {
		cout << "Congratulations! You formed the number 2048!" << endl;
	}
}

void alignright(int arr[4][4]) {
	for (int i = 0; i < 4; i++) {
		if (arr[i][1] == 0) {
			arr[i][1] = arr[i][0];
			arr[i][0] = 0;
		}
		if (arr[i][2] == 0) {
			arr[i][2] = arr[i][1];
			arr[i][1] = arr[i][0];
			arr[i][0] = 0;
		}
		if (arr[i][3] == 0) {
			arr[i][3] = arr[i][2];
			arr[i][2] = arr[i][1];
			arr[i][1] = arr[i][0];
			arr[i][0] = 0;
		}
	}

	for (int k = 0; k < 4; k++) {
		if (arr[k][3] == arr[k][2]) {
			arr[k][3] = 2 * arr[k][2];
			score = score + 2 * arr[k][2];
			arr[k][2] = arr[k][1];
			arr[k][1] = arr[k][0]; 
			arr[k][0] = 0;
			
			if (arr[k][2] == arr[k][1]) {
				arr[k][2] = 2 * arr[k][1];
				score = score + 2 * arr[k][1];
				arr[k][1] = 0;
				arr[k][0] = 0;
				
			}
		}
		else if (arr[k][2] == arr[k][1]) {
			arr[k][2] = 2 * arr[k][1];
			score = score + 2 * arr[k][1];
			arr[k][1] = arr[k][0];
			arr[k][0] = 0;
			
		}
		else if (arr[k][1] == arr[k][0]) {
			arr[k][1] = 2 * arr[k][0];
			score = score + 2 * arr[k][0];
			arr[k][0] = 0;
			
		}
	}

}
void alignleft(int arr[4][4]) {
	for (int i = 0; i < 4; i++) {
		if (arr[i][2] == 0) {
			arr[i][2] = arr[i][3];
			arr[i][3] = 0;
		}
		if (arr[i][1] == 0) {
			arr[i][1] = arr[i][2];
			arr[i][2] = arr[i][3];
			arr[i][3] = 0;
		}
		if (arr[i][0] == 0) {
			arr[i][0] = arr[i][1];
			arr[i][1] = arr[i][2];
			arr[i][2] = arr[i][3];
			arr[i][3] = 0;
		}
	}

	for (int k = 0; k < 4; k++) {
		if (arr[k][0] == arr[k][1]) {
			arr[k][0] = 2 * arr[k][1];
			score = score + 2 * arr[k][1];
			arr[k][1] = arr[k][2];
			arr[k][2] = arr[k][3];
			arr[k][3] = 0;
			if (arr[k][1] == arr[k][2]) {
				arr[k][1] = 2 * arr[k][2];
				score = score + 2 * arr[k][2];
				arr[k][2] = 0;
				arr[k][3] = 0;
			}
		}
		else if (arr[k][1] == arr[k][2]) {
			arr[k][1] = 2 * arr[k][2];
			score = score + 2 * arr[k][2];
			arr[k][2] = arr[k][3];
			arr[k][3] = 0;
		}
		else if (arr[k][2] == arr[k][3]) {
			arr[k][2] = 2 * arr[k][3];
			score = score + 2 * arr[k][3];
			arr[k][3] = 0;
		}
	}

}
void aligndown(int arr[4][4]) {
	for (int i = 0; i < 4; i++) {
		if (arr[1][i] == 0) {
			arr[1][i] = arr[0][i];
			arr[0][i] = 0;
		}
		if (arr[2][i] == 0) {
			arr[2][i] = arr[1][i];
			arr[1][i] = arr[0][i];
			arr[0][i] = 0;
		}
		if (arr[3][i] == 0) {
			arr[3][i] = arr[2][i];
			arr[2][i] = arr[1][i];
			arr[1][i] = arr[0][i];
			arr[0][i] = 0;
		}
	}

	for (int k = 0; k < 4; k++) {
		if (arr[3][k] == arr[2][k]) {
			arr[3][k] = 2 * arr[2][k];
			score = score + 2 * arr[2][k];
			arr[2][k] = arr[1][k];
			arr[1][k] = arr[0][k];
			arr[0][k] = 0;
			if (arr[2][k] == arr[1][k]) {
				arr[2][k] = 2 * arr[1][k];
				score = score + 2 * arr[1][k];
				arr[1][k] = 0;
				arr[0][k] = 0;
			}
		}
		else if (arr[2][k] == arr[1][k]) {
			arr[2][k] = 2 * arr[1][k];
			score = score + 2 * arr[1][k];
			arr[1][k] = arr[0][k];
			arr[0][k] = 0;
		}
		else if (arr[1][k] == arr[0][k]) {
			arr[1][k] = 2 * arr[0][k];
			score = score + 2 * arr[0][k];
			arr[0][k] = 0;
		}
	}

}
void alignup(int arr[4][4]) {
	for (int i = 0; i < 4; i++) {
		if (arr[2][i] == 0) {
			arr[2][i] = arr[3][i];
			arr[3][i] = 0;
		}
		if (arr[1][i] == 0) {
			arr[1][i] = arr[2][i];
			arr[2][i] = arr[3][i];
			arr[3][i] = 0;
		}
		if (arr[0][i] == 0) {
			arr[0][i] = arr[1][i];
			arr[1][i] = arr[2][i];
			arr[2][i] = arr[3][i];
			arr[3][i] = 0;
		}
	}

	for (int k = 0; k < 4; k++) {
		if (arr[0][k] == arr[1][k]) {
			arr[0][k] = 2 * arr[1][k];
			score = score + 2 * arr[1][k];
			arr[1][k] = arr[2][k];
			arr[2][k] = arr[3][k];
			arr[3][k] = 0;
			if (arr[1][k] == arr[2][k]) {
				arr[1][k] = 2 * arr[2][k];
				score = score + 2 * arr[2][k];
				arr[2][k] = 0;
				arr[3][k] = 0;
			}
		}
		else if (arr[1][k] == arr[2][k]) {
			arr[1][k] = 2 * arr[2][k];
			score = score + 2 * arr[2][k];
			arr[2][k] = arr[3][k];
			arr[3][k] = 0;
		}
		else if (arr[2][k] == arr[3][k]) {
			arr[2][k] = 2 * arr[3][k];
			score = score + 2 * arr[3][k];
			arr[3][k] = 0;
		}
	}

}

char choice;
int main()
{
	int score = 0;
	
	gameboard();
	
	srand(time(NULL));
	int z = rand() % 10;
	int x = rand() % 4;
	int y = rand() % 4;

	if (z == 0) {
		square[x][y] = 4;
	}
	else {
		square[x][y] = 2;
	}
	
	gameboard();
	

	LOOP:
	cout << "Choose your direction" << endl;
	cin >> choice;
	if (choice == 'd') {
		alignright(square);
		
	}
	if (choice == 'a') {
		alignleft(square);
	}
	if (choice == 'w') {
		alignup(square);	
	}
	if (choice == 's') {
		aligndown(square);	
	}
	

	RANDOM:
	int a = rand() % 4;
	int b = rand() % 4;
	int c = rand() % 10;
	if (square[a][b] == 0) {
		if (c == 0) {
			square[a][b] = 4;
		}
		else {
			square[a][b] = 2;
		}
	}
	else {
		goto RANDOM;
	}
	
	gameboard();
	goto LOOP;
    return 0;
}

