#include "head.h"

//玩家对战模式
void playersvs(void)
{	while(1)
	{
//判断程序继续运行还是退出
	int n,p;
	char a,b,c;
	c=getchar();
	if(c=='q'||c=='Q'||c==EOF)
		break;
	else
		;

//判断玩家1落子情况
	printf("---player1 input position:\n");
	scanf("%d",&n);
	scanf("%c",&a);
	for(;IsChessPiece(n,a-'A'+1)||OutChessboard(n,a-'A'+1);)
	{
	if(IsChessPiece(n,a-'A'+1))
		{
		printf("There was a chess piece, please choose other position\n");
		}
	else if(OutChessboard(n,a-'A'+1))
		{
		printf("This position is out of chessboard, please input again\n");
		}
	printf("---player1 input position:\n");
	scanf("%d",&n);
	scanf("%c",&a);	
	}
	
	Info(aRecordBoard);
	
/*	if(Ban_Hand(aRecordBoard,n,a-'A'+1)==1)				//判断禁手
	{
	printf("----break the rule: Long connect !!!----\n");
	break;
	}			
	else if(Ban_Hand(aRecordBoard,n,a-'A'+1)==2)
	{
		printf("----break the rule: Three-ban !!!----\n");
		break;
	}
	else if(Ban_Hand(aRecordBoard,n,a-'A'+1)==3)
	{
		printf("----break the rule: Four-ban !!!----\n");
		break;
	}
*/
	aRecordBoard[n][a-'A'+1]=1;
	
	recordtoDisplayArray_current(n,a-'A'+1);
   	displayBoard();

	for(int i=0;i<4;i++)
		printf("myinfo[%d]=%d ",i,MyScoreBoard[n][a-'A'+1].info[i].linknum);
	printf("\n");

	if(winner_1(n,a-'A'+1))		//判断玩家1是否赢得比赛
	{
		printf("----Player1 Win!!!----\n");
		break;
	}


//判断玩家2落子情况
	printf("---player2 input position:\n");
	scanf("%d",&p);
	scanf("%c",&b);
	for(;IsChessPiece(p,b-'A'+1)||OutChessboard(p,b-'A'+1);)
	{
	if(IsChessPiece(p,b-'A'+1))
	{
		printf("There was a chess piece, please choose other position\n");
	}
	else if(OutChessboard(p,b-'A'+1))
	{
		printf("This position is out of chessboard, please input again\n");
	}
	printf("---player2 input position:\n");
	scanf("%d",&p);
	scanf("%c",&b);	
	}	
	aRecordBoard[p][b-'A'+1]=2;
	recordtoDisplayArray_current(p,b-'A'+1);
   	displayBoard();

	for(int i=0;i<4;i++)
		printf("oppinfo[%d]=%d ",i,OppScoreBoard[p][b-'A'+1].info[i].linknum);
	printf("\n");

	if(winner_2(p,b-'A'+1))		//判断玩家2是否赢得比赛
	{
		printf("----Player2 Win!!!----\n");
		break;
	}

	recordtoDisplayArray();

	printf("input q to quit, and others to continue");
	c=getchar();
	}
}

