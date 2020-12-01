#include "head.h"

//��Ҷ�սģʽ
void playersvs(void)
{	while(1)
	{
//�жϳ���������л����˳�
	int n,p;
	char a,b,c;
	c=getchar();
	if(c=='q'||c=='Q'||c==EOF)
		break;
	else
		;

//�ж����1�������
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

	aRecordBoard[n][a-'A'+1]=1;
	
	recordtoDisplayArray_current(n,a-'A'+1);
   	displayBoard();
	
	Info(aRecordBoard,n,a-'A'+1);


	for(int j=0;j<2;j++)
	{	
		for(int i=0;i<4;i++)
			printf("black_info[%d]link[%d]=%d  ",i,j,BlackScoreBoard[n][a-'A'+1].info[i].linknum[j]);
		printf("\n");
	}

	for(int j=0;j<2;j++)
	{
		for(int i=0;i<4;i++)
			printf("black_info[%d]opp[%d]=%d  ",i,j,BlackScoreBoard[n][a-'A'+1].info[i].oppnum[j]);
		printf("\n");
	}

	if(winner_1(n,a-'A'+1))		//�ж����1�Ƿ�Ӯ�ñ���
	{
		printf("----Player1 Win!!!----\n");
		break;
	}

	
	if(Ban_Hand(n,a-'A'+1)==1)				//�жϽ���
	{
	printf("----Black broke the rule: Long connect !!!----\n");
	break;
	}			
	else if(Ban_Hand(n,a-'A'+1)==2)
	{
		printf("----Black broke the rule: Three-ban !!!----\n");
		break;
	}
	else if(Ban_Hand(n,a-'A'+1)==3)
	{
		printf("----Black broke the rule: Four-ban !!!----\n");
		break;
	}



//�ж����2�������
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

	Info(aRecordBoard,p,b-'A'+1);

	for(int j=0;j<2;j++)
	{	
		for(int i=0;i<4;i++)
			printf("white_info[%d]link[%d]=%d  ",i,j,WhiteScoreBoard[p][b-'A'+1].info[i].linknum[j]);
		printf("\n");
	}

	for(int j=0;j<2;j++)
	{
		for(int i=0;i<4;i++)
			printf("white_info[%d]opp[%d]=%d  ",i,j,WhiteScoreBoard[p][b-'A'+1].info[i].oppnum[j]);
		printf("\n");
	}
	if(winner_2(p,b-'A'+1))		//�ж����2�Ƿ�Ӯ�ñ���
	{
		printf("----Player2 Win!!!----\n");
		break;
	}


	recordtoDisplayArray();

	printf("input q to quit, and others to continue");
	c=getchar();
	}
}

