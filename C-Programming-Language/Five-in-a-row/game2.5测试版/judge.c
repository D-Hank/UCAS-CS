#include "head.h"

//�ж��Ƿ�������
int IsChessPiece(int i,int j)
{
	if(aRecordBoard[i][j]==1||aRecordBoard[i][j]==2)
		return 1;
	else
		return 0;
}

//�ж��Ƿ���������
int OutChessboard(int i,int j)
{
	if((1<=i&&i<=15)&&(1<=j&&j<=15))
		return 0;
	else
		return 1;
}

//�ж���Ӯ
int winner_1(int m,int n){
	for(int i=0;i<4;i++)
	if(BlackScoreBoard[m][n].info[i].linknum[0]+BlackScoreBoard[m][n].info[i+4].linknum[0]==5)
		return 1;
	return 0;
}

int winner_2(int m,int n){
	for(int i=0;i<4;i++)
	if(WhiteScoreBoard[m][n].info[i].linknum[0]+WhiteScoreBoard[m][n].info[i+4].linknum[0]>4)
		return 1;
	return 0;
}

