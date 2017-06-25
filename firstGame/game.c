
#include <time.h>
#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"
int ChoiceOfCom() {

	srand((unsigned int)time(NULL));
	return rand()%3+1;

}
int ChoiceOfMe() {
	int n;
	while (1) {
		fputs("가위(1) 바위(2) 보(3) 종료(4)선택? ", stdout);
		scanf_s("%d", &n);
		while (getchar() != '\n');
		
		if (n == 1 || n == 2 || n == 3 || n == 4) {
			break;
		}
		else {
			puts("입력 범위를 벗어났습니다.");
		}
	}

	return n;

}
void WhoIsWinner(int com, int you) {
	int win = you-com;
		increGame();
	switch(win){
	case 0:
		puts("비겼습니다.");
		
		break;
	case 1: case -2:
		whoIsGetMoney(0);
		puts("당신이 승자입니다!");
		
		increYourWin();
		break;
	case -1: case 2:
		whoIsGetMoney(1);
		puts("컴퓨터가 승자이군요.");
		
		break;
	}
}
void showRSP(int rsp) {
	switch(rsp){
	case GAWI:
		fputs("가위", stdout);
		break;
	case ROCK:
		fputs("바위", stdout);
		break;
	case BO:
		fputs("보", stdout);
		break;

	}
	

}