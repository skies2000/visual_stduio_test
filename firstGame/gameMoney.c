static int myMoney = 0;
static int comMoney = 0;
static int pandon = 0;
int getMyMoney() {
	return myMoney;
}
int getComMoney() {
	return comMoney;
}
int getGambleMoney() {
	return pandon;
}
void initMoney(int you, int com, int pan) {
	myMoney = you;
	comMoney = com;
	pandon = pan;
}
void whoIsGetMoney(int who) {
	if (who == 0) {
		myMoney += pandon;
		comMoney -= pandon;
	}
	else {
		myMoney -= pandon;
		comMoney += pandon;
	}
}
void setMyMoney(int you) {
	if (you <= 0) {
		return;
	}
	myMoney = you;
}
void setComMoney(int com) {
	if (com <= 0) {
		return;
	}
	comMoney = com;
}
int setGambleMoney(int pan) {
	if (myMoney < pan) {
		return 0;
	}
	else if (comMoney < pan) {
		return 1;
	}
	pandon = pan;
	return 2;
}

