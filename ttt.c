/*
Title: ttt.c
Author: MotorHead74808
Date: November 10, 2022
*/

#include <stdio.h>
#include <string.h>

char board[3][4] = {
	"   \0",
	"   \0",
	"   \0"
};
int md, win, clock;

void mode(void){
	puts("\x1B[2j");
	printf("Press 1 for single player, 2 for multiplayer: ");
	scanf("%1d", &md);
}

int diags(char in){
		if((board[0][0]==in && board[1][1]==in	&& board[2][2]==in) 
			|| (board[0][2]==in && board[1][1]==in && board[2][0]==in))
			return 0;
		else return 1;
}

int hors(char in){
	if((board[0][0]==in && board[1][0]==in && board[2][0]==in) ||
		(board[0][1]==in && board[1][1]==in && board[2][1]==in) ||
		(board[0][2]==in && board[1][2]==in && board[2][2]==in))
		return 0;
	else return 1;
}

void prnt_brd(void){
	printf("\n\t %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
	printf("\n\t---|---|---");
	printf("\n\t %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
	printf("\n\t---|---|---");
	printf("\n\t %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
	printf("\n\n");
}

void plyr_mov(char in){
	int x ,y;
	printf("Please enter the row number(1-3): ");
	scanf("%1d", &x);
	printf("Please enter the column number(1-3): ");
	scanf("%1d", &y);
	if(board[x-1][y-1]=='x' || board[x-1][y-1]=='o'|| 
			x>3 || y>3 || x<1 || y<1){
		printf("Invalid move!\n");
		--clock;
	}
	else
		board[x-1][y-1]=in;
}

void chk_win(void){
	if(strcmp(board[0], "xxx\0")==0 || strcmp(board[1], "xxx\0")==0 ||
		strcmp(board[2], "xxx\0")==0 || diags('x')==0 || hors('x')==0){
		printf("\nX wins!\n");
		prnt_brd();
		win=1;
	}
	if(strcmp(board[0], "ooo\0")==0 || strcmp(board[1], "ooo\0")==0 ||
		strcmp(board[2], "ooo\0")==0 || diags('o')==0 || hors('o')==0){
		printf("\nO wins!\n");
		prnt_brd();
		win=1;
	}
	if(clock==8 && win==0){
		printf("\nTie!\n");
		win=1;
	}
}

int main(){
	win=clock=0;
	//mode();
	while(win==0){
		prnt_brd();
		if(clock % 2 == 0){
			plyr_mov('x');}
		else{
			plyr_mov('o');}
		chk_win();
		++clock;
	}
	return 0;
}
