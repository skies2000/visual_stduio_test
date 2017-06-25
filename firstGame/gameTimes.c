

	static int winCnt = 0;
	static int gameCnt = 0;

	void increGame() {
		gameCnt++;
	}
	void increYourWin() {
		winCnt++;
	}
	int getGame() {
		return gameCnt;
	}
	int getYourWin() {
		return winCnt;
	}
	int winRate(){
	if (gameCnt == 0) {
		return 0;
	}
	return (double)winCnt / gameCnt * 100;
	
}
	void setWinCnt(int winC){
		winCnt = winC;
	}
	void setGameCnt(int gameC) {
		gameCnt = gameC;
	}