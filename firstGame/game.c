
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
		fputs("����(1) ����(2) ��(3) ����(4)����? ", stdout);
		scanf_s("%d", &n);
		while (getchar() != '\n');
		
		if (n == 1 || n == 2 || n == 3 || n == 4) {
			break;
		}
		else {
			puts("�Է� ������ ������ϴ�.");
		}
	}

	return n;

}
void WhoIsWinner(int com, int you) {
	int win = you-com;
		increGame();
	switch(win){
	case 0:
		puts("�����ϴ�.");
		
		break;
	case 1: case -2:
		whoIsGetMoney(0);
		puts("����� �����Դϴ�!");
		
		increYourWin();
		break;
	case -1: case 2:
		whoIsGetMoney(1);
		puts("��ǻ�Ͱ� �����̱���.");
		
		break;
	}
}
void showRSP(int rsp) {
	switch(rsp){
	case GAWI:
		fputs("����", stdout);
		break;
	case ROCK:
		fputs("����", stdout);
		break;
	case BO:
		fputs("��", stdout);
		break;

	}
	

}