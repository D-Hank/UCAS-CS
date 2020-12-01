#include "head.h"

int main()
{
	char model,c;
	//��Ϸ��ʼ��
	system("clear");
	printf("choose model:\n");
	printf("input 1 : player vs player\n");printf("input 2 : player vs computer(black)\n");printf("input 3 : player vs computer(white)\n");
	scanf("%c",&model);

	initRecordBorard();
	recordtoDisplayArray();
	displayBoard();		
	printf("-----game start-----\n");
	printf("input q to quilt, and others to continue:");	
	c=getchar();
	if(c=='q'||c=='Q'||c==EOF)
		return 0;
	else
		;
	switch(model)
	{
		case '1': playersvs();break;
//		case '2': player_vs_computer_black();break;
//		case '3': player_vs_computer_white();break; 
	}
	

	return 0;
}

//��ʼ�����̸�� 
void initRecordBorard(void){
//ͨ��˫��ѭ������aRecordBoard��0
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			aRecordBoard[i][j]=0;
}

//��aRecordBoard�м�¼������λ�ã�ת����aDisplayBoardArray��
void recordtoDisplayArray(void){
//��һ������aInitDisplayBoardArray�м�¼�Ŀ����̣����Ƶ�aDisplayBoardArray��
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE*CHARSIZE+1+2;j++)
			aDisplayBoardArray[i][j]=aInitDisplayBoardArray[i][j];
//�ڶ�����ɨ��aRecordBoard����������0��Ԫ�أ�������ߡ��Ƶ�aDisplayBoardArray����Ӧλ����
	for(int i=1;i<SIZE+1;i++)
		for(int j=1;j<SIZE+1;j++)
			if(aRecordBoard[i][j]==1)
				{
				for(int k=0;k<2;k++)
						{						
					aDisplayBoardArray[15-i][j*2+k]=play1Pic[k];
							}
				}
			else if(aRecordBoard[i][j]==2)
				{
				for(int k=0;k<2;k++)
						{						
					aDisplayBoardArray[15-i][j*2+k]=play2Pic[k];
							}
				}
//ע�⣺aDisplayBoardArray����¼���ַ��������ַ���ÿ���ַ�ռ2���ֽڡ���͡�Ҳ�������ַ���ÿ��Ҳռ2���ֽڡ�
}


void recordtoDisplayArray_current(int i,int j){
//��һ����ɨ�������뵽aRecordBoard��Ԫ�أ���������0��Ԫ�أ��������ߡ����Ƶ�aDisplayBoardArray����Ӧλ����
			if(aRecordBoard[i][j]==1)
				{
				for(int k=0;k<2;k++)
						{						
					aDisplayBoardArray[15-i][j*2+k]=play1CurrentPic[k];
							}
				}
			else if(aRecordBoard[i][j]==2)
				{
				for(int k=0;k<2;k++)
						{						
					aDisplayBoardArray[15-i][j*2+k]=play2CurrentPic[k];
							}
				}
//ע�⣺aDisplayBoardArray����¼���ַ��������ַ���ÿ���ַ�ռ2���ֽڡ����͡�Ҳ�������ַ���ÿ��Ҳռ2���ֽڡ�
}

//��ʾ���̸�� 
void displayBoard(void){
	int i;
	//��һ��������
	system("clear");   //����  
	//�ڶ�������aDisplayBoardArray�������Ļ��
	for(int i=0;i<SIZE;i++)
		{
		for(int j=0;j<SIZE*CHARSIZE+1+2;j++)
			printf("%c",aDisplayBoardArray[i][j]);
		printf("\n");		
		}
	
	//������������������һ����ĸA B .... 
	printf("  %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O');
} 

int IsChessPiece(int i,int j)
{
	if(aRecordBoard[i][j]==1||aRecordBoard[i][j]==2)
		return 1;
	else
		return 0;
}

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
	if(MyScoreBoard[m][n].info[i].linknum==4)
		return 1;
	return 0;
}

int winner_2(int m,int n){
	for(int i=0;i<4;i++)
	if(OppScoreBoard[m][n].info[i].linknum==4)
		return 1;
	return 0;
}

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
	
	Info(aRecordBoard);
	
/*	if(Ban_Hand(aRecordBoard,n,a-'A'+1)==1)				//�жϽ���
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

	if(winner_1(n,a-'A'+1))		//�ж����1�Ƿ�Ӯ�ñ���
	{
		printf("----Player1 Win!!!----\n");
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

	for(int i=0;i<4;i++)
		printf("oppinfo[%d]=%d ",i,OppScoreBoard[p][b-'A'+1].info[i].linknum);
	printf("\n");

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

void Info(int s[SIZE+1][SIZE+1])
{
//	s[x][y] = 1;			//��������

	int temp[TSIZE][TSIZE];			//����һ�������̣�ʹ����ȫ����סС����
	for(int i=0;i<TSIZE;i++)
		for(int j=0;j<TSIZE;j++)
			temp[i][j]=8;		//��ʼ�������̱߽磬8�Ժ���,������˵���൱��߽�

	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
			temp[i][j]=s[i][j];	//��С���̵�ֵ���Ƶ������������룬ʹ����Χ�����ı߽����
											
	for(int i=0;i<16;i++)			//�������
		for(int j=0;j<16;j++)
			for(int k=0;k<4;k++){
				MyScoreBoard[i][j].info[k].linknum=0;
				MyScoreBoard[i][j].info[k].oppnum=0;
				OppScoreBoard[i][j].info[k].linknum=0;
				OppScoreBoard[i][j].info[k].oppnum=0;
			}
//��¼˫��������Ϣ

	int m,n,i;

//��¼����������ÿһ�����Ϣ

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m][n+i]==2;i++)	OppScoreBoard[m][n].info[0].linknum++;		//��¼������������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m][n-i]==2;i++)	OppScoreBoard[m][n].info[0].linknum++;
										
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n+i]==2;i++)	OppScoreBoard[m][n].info[1].linknum++;		//��¼ / ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n-i]==2;i++)	OppScoreBoard[m][n].info[1].linknum++;

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n]==2;i++)	OppScoreBoard[m][n].info[2].linknum++;		//��¼ | ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n]==2;i++)	OppScoreBoard[m][n].info[2].linknum++;

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n-i]==2;i++)	OppScoreBoard[m][n].info[3].linknum++;		//��¼ \ ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n+i]==2;i++)	OppScoreBoard[m][n].info[3].linknum++;

	
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n+i]==2;i++)	;	if(temp[m][n+i]==1)	OppScoreBoard[m][n].info[0].oppnum++;		//��¼���������������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n-i]==2;i++)	;	if(temp[m][n-i]==1)	OppScoreBoard[m][n].info[0].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n+i]==2;i++)	;	if(temp[m+i][n+i]==1)	OppScoreBoard[m][n].info[1].oppnum++;		//��¼/�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n-i]==2;i++)	;	if(temp[m-i][n-i]==1)	OppScoreBoard[m][n].info[1].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n]==2;i++)	;	if(temp[m+i][n]==1)	OppScoreBoard[m][n].info[2].oppnum++;		//��¼ | �����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n]==2;i++)	;	if(temp[m-i][n]==1)	OppScoreBoard[m][n].info[2].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n-i]==2;i++)	;	if(temp[m-i][n-i]==1)	OppScoreBoard[m][n].info[3].oppnum++;		//��¼\�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n+i]==2;i++)	;	if(temp[m+i][n+i]==1)	OppScoreBoard[m][n].info[3].oppnum++;

//��¼����������ÿһ�����Ϣ

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m][n+i]==1;i++)	MyScoreBoard[m][n].info[0].linknum++;		//��¼������������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m][n-i]==1;i++)	MyScoreBoard[m][n].info[0].linknum++;
										
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n+i]==1;i++)	MyScoreBoard[m][n].info[1].linknum++;		//��¼ / ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n-i]==1;i++)	MyScoreBoard[m][n].info[1].linknum++;

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n]==1;i++)	MyScoreBoard[m][n].info[2].linknum++;		//��¼ | ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n]==1;i++)	MyScoreBoard[m][n].info[2].linknum++;

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n-i]==1;i++)	MyScoreBoard[m][n].info[3].linknum++;		//��¼ \ ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n+i]==1;i++)	MyScoreBoard[m][n].info[3].linknum++;

	
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n+i]==1;i++)	;	if(temp[m][n+i]==2)	MyScoreBoard[m][n].info[0].oppnum++;		//��¼���������������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n-i]==1;i++)	;	if(temp[m][n-i]==2)	MyScoreBoard[m][n].info[0].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n+i]==1;i++)	;	if(temp[m+i][n+i]==2)	MyScoreBoard[m][n].info[1].oppnum++;		//��¼/�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n-i]==1;i++)	;	if(temp[m-i][n-i]==2)	MyScoreBoard[m][n].info[1].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n]==1;i++)	;	if(temp[m+i][n]==2)	MyScoreBoard[m][n].info[2].oppnum++;		//��¼ | �����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n]==1;i++)	;	if(temp[m-i][n]==2)	MyScoreBoard[m][n].info[2].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n-i]==1;i++)	;	if(temp[m-i][n-i]==2)	MyScoreBoard[m][n].info[3].oppnum++;		//��¼\�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n+i]==1;i++)	;	if(temp[m+i][n+i]==2)	MyScoreBoard[m][n].info[3].oppnum++;

/*	for(int i=0;i<4;i++)					//�жϳ�������
	if(MyScoreBoard[m][n].info[i].linknum>4)
		return long_connect;
*/
//33����
//44����



				
}






