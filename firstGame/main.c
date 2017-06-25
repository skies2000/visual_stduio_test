// firstGame.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

		puts("�� ������ �����մϴ�.");
		
		if (continueCheck!= -1) {
			fputs("������ �̾ �Ͻðڽ��ϱ�? (yes 1 no 0): ", stdout);
			scanf_s("%d", &yesOrNo);


		}if (continueCheck == -1 || yesOrNo == 0) {

			fputs("����� �Ӵϸ� �Է��� �ּ���: ", stdout);
			scanf_s("%d", &money);
			while (getchar() != '\n');
			setMyMoney(money);
		}
		else {
			fileLoad();
		}
		

		
		

		printf("���̸� �Ӵ� : %d\n", getMyMoney());
		printf("��ǻ�� �Ӵ� : %d\n", getComMoney());
		puts("");

	while (1) {
		puts("�ǵ��� �����մϴ�.");
		fputs("�ǵ��Է�: ", stdout);
		scanf_s("%d", &gambleMoney);
		while (getchar() != '\n');
		gambleFlag=setGambleMoney(gambleMoney);
		puts("");
		if (gambleFlag == 0) {
			puts("�����ϰ� �ִ� �ݾ� ������ �ż���!");
			printf("����� ���� ���� �Ӵ� : %d\n", getMyMoney());
			continue;
		}
		else if (gambleFlag == 1) {
			puts("��ǻ���� ���� �ݾ� �ʰ��Դϴ�!");
			printf("��ǻ���� ���� ���� �Ӵ� : %d\n", getComMoney());
			continue;
		}
		
		puts("######## ���! ########!!");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		if (you == QUIT) {
			break;
		}

		puts("");

		puts("******* ���! ********!!");
		WhoIsWinner(com, you);
	

		fputs("|> ��ǻ���� ������ ", stdout);
		showRSP(com);
		puts("");

	
		fputs("|> ����� ������ ",stdout);
		showRSP(you);
		puts("");
		printf("�·� : %d %%\n", winRate());
		printf("���̸� �Ӵ� : %d\n", getMyMoney());
		printf("��ǻ�� �Ӵ� : %d\n", getComMoney());
		puts(""); 
		if (getMyMoney() <= 0 || getComMoney() <= 0) {
			break;
		}
	}

	puts("@@@@@@@@@@�������@@@@@@@@@@");
	printf("���� �·� : %d %%\n", winRate());
	fputs("���� ������ �����Ͻðڽ��ϱ�? (yes 1, no )", stdout);
	scanf_s("%d", &yesOrNo);
	while (getchar() != '\n');
	if (yesOrNo == 1) fileStore();
	else if(fileLoadCheck()==1)
		system("cd c:/upload && del gameData.dat");
	puts("�̿��� �ּż� �����մϴ�.");
	if (getchar() != '\n')while (getchar() != '\n');
    return 0;
}

