#include "head.h"

//���Ժ���ģʽ
void player_vs_computer_white(void)
{	while(1)
	{
//�жϳ���������л����˳�
	int n,p,a;

	char b,c;
	struct point iposition;
	c=getchar();
	if(c=='q'||c=='Q'||c==EOF)
		break;


//��������
	printf("---player input position:\n");
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
	printf("---player input position:\n");
	scanf("%d",&p);
	scanf("%c",&b);	
	}
	
	aRecordBoard[p][b-'A'+1]=1;
	recordtoDisplayArray_current(p,b-'A'+1);
   	displayBoard();


	Info(aRecordBoard,p,b-'A'+1);

	if(winner_1(p,b-'A'+1))								//�ж�����Ƿ�Ӯ�ñ���
	{
		printf("----Player Win!!!----\n");
		break;
	}

	if(Ban_Hand(p,b-'A'+1)==1)							//�жϽ���
	{
		printf("----Black broke the rule: Long connect !!!----\n");
	}			
	else if(Ban_Hand(p,b-'A'+1)==2)
	{
		printf("----Black broke the rule: Three-ban !!!----\n");
	}
	else if(Ban_Hand(p,b-'A'+1)==3)
	{
		printf("----Black broke the rule: Four-ban !!!----\n");
	}





//��������
	
	iposition=AI_White_1(3);

/*
	for(int i=15;i>0;i--)
	{
		for(int j=1;j<16;j++)
			printf("%-.4d  ",gradestable_white[i][j].score);
		printf("\n");
	}
*/

	printf("iposition.x=%d iposition.y=%d\n",iposition.x,iposition.y);


	aRecordBoard[iposition.x][iposition.y]=2;
	
	recordtoDisplayArray_current(iposition.x,iposition.y);
	displayBoard();
	
	Info(aRecordBoard,iposition.x,iposition.y);
	

	
	if(winner_2(iposition.x,iposition.y))						//�жϵ����Ƿ�Ӯ�ñ���
	{
		printf("----Computer Win!!!----\n");
		break;
	}




	recordtoDisplayArray();

	printf("input q to quit, and others to continue");
	c=getchar();

	}
}

