#include "common.h"
#include "gameMoney.h"
#include "gameTimes.h"

int fileStoreCheck() {
	FILE * fp = fopen("C:/upload/gameData.dat", "wb");
	if (fp == NULL) {
		return -1;
	}
	else {
		fclose(fp);
		return 1;
	}
}
int fileLoadCheck() {
	FILE * fp = fopen("C:/upload/gameData.dat", "rb");
	if (fp == NULL) {
		return -1;
	}
	else {
		fclose(fp);
		return 1;
	}
}
void fileStore() {
	FILE * fp = fopen("C:/upload/gameData.dat", "wb");
	
	if (fp == NULL) {
		puts("파일 오픈 실패");
		return;
	}

	int comMoney = getComMoney();
	int myMoney = getMyMoney();
	int gameCnt = getGame();
	int winCnt = getYourWin();

	

	fwrite(&comMoney, 4, 1, fp);
	fwrite(&myMoney, 4, 1, fp);
	fwrite(&gameCnt, 4, 1, fp);
	fwrite(&winCnt, 4, 1, fp);

	fclose(fp);
	return 1;
	
}

void fileLoad() {
	
	FILE * fp = fopen("C:/upload/gameData.dat", "rb");
	if (fp == NULL) {
		puts("파일 오픈 실패");
		return;
	}

	int comMoney = 0;
	int myMoney = 0;
	int gameCnt = 0;
	int winCnt = 0;

	fread(&comMoney, 4, 1, fp);
	fread(&myMoney, 4, 1, fp);
	fread(&gameCnt, 4, 1, fp);
	fread(&winCnt, 4, 1, fp);
	
	setMyMoney(myMoney);
	setComMoney(comMoney);
	setGameCnt(gameCnt);
	setWinCnt(winCnt);
	
	fclose(fp);

	return 1;

}