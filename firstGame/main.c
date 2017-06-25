// firstGame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"
#include "gameContinue.h"
int main()
{
		

		
		initMoney(0, 1000, 0);
		int com;
		int you;
		int money;
		int gambleMoney;
		int gambleFlag = 0;
		int continueCheck = fileLoadCheck();
		int yesOrNo;

		puts("자 게임을 시작합니다.");
		
		if (continueCheck!= -1) {
			fputs("게임을 이어서 하시겠습니까? (yes 1 no 0): ", stdout);
			scanf_s("%d", &yesOrNo);


		}if (continueCheck == -1 || yesOrNo == 0) {

			fputs("당신의 머니를 입력해 주세요: ", stdout);
			scanf_s("%d", &money);
			while (getchar() != '\n');
			setMyMoney(money);
		}
		else {
			fileLoad();
		}
		

		
		

		printf("게이머 머니 : %d\n", getMyMoney());
		printf("컴퓨터 머니 : %d\n", getComMoney());
		puts("");

	while (1) {
		puts("판돈을 설정합니다.");
		fputs("판돈입력: ", stdout);
		scanf_s("%d", &gambleMoney);
		while (getchar() != '\n');
		gambleFlag=setGambleMoney(gambleMoney);
		puts("");
		if (gambleFlag == 0) {
			puts("소유하고 있는 금액 내에서 거세요!");
			printf("당신의 현재 게임 머니 : %d\n", getMyMoney());
			continue;
		}
		else if (gambleFlag == 1) {
			puts("컴퓨터의 소유 금액 초과입니다!");
			printf("컴퓨터의 현재 게임 머니 : %d\n", getComMoney());
			continue;
		}
		
		puts("######## 대결! ########!!");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		if (you == QUIT) {
			break;
		}

		puts("");

		puts("******* 결과! ********!!");
		WhoIsWinner(com, you);
	

		fputs("|> 컴퓨터의 선택은 ", stdout);
		showRSP(com);
		puts("");

	
		fputs("|> 당신의 선택은 ",stdout);
		showRSP(you);
		puts("");
		printf("승률 : %d %%\n", winRate());
		printf("게이머 머니 : %d\n", getMyMoney());
		printf("컴퓨터 머니 : %d\n", getComMoney());
		puts(""); 
		if (getMyMoney() <= 0 || getComMoney() <= 0) {
			break;
		}
	}

	puts("@@@@@@@@@@최종결과@@@@@@@@@@");
	printf("최종 승률 : %d %%\n", winRate());
	fputs("게임 내용을 저장하시겠습니까? (yes 1, no )", stdout);
	scanf_s("%d", &yesOrNo);
	while (getchar() != '\n');
	if (yesOrNo == 1) fileStore();
	else if(fileLoadCheck()==1)
		system("cd c:/upload && del gameData.dat");
	puts("이용해 주셔서 감사합니다.");
	if (getchar() != '\n')while (getchar() != '\n');
    return 0;
}

