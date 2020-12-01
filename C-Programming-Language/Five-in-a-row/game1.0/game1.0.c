#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#define CHARSIZE 2
void initRecordBorard(void);
void recordtoDisplayArray(void);
void displayBoard(void);

int winner_1(int s[SIZE+1][SIZE+1]);	//�ж����1��Ӯ
int winner_2(int s[SIZE+1][SIZE+1]);	//�ж����2��Ӯ
int IsChessPiece(int i,int j);		//�жϵ�ǰ���Ӵ��Ƿ�������
int OutChessboard(int i,int j);		//�жϵ�ǰ���Ӵ��Ƿ���������
void recordtoDisplayArray_current(int i,int j);		//����������ʾ��ǰ�������
void playersvs(void);

int Ban_Hand(int s[SIZE+1][SIZE+1],int m,int n);	//�жϽ���

//����ʹ�õ���GBK���룬ÿһ�������ַ�ռ��2���ֽڡ�

//���̻���ģ�� 
char aInitDisplayBoardArray[SIZE][SIZE*CHARSIZE+1+2] = 
{
		"15���өөөөөөөөөөөөө�",
		"14�ĩ��������������",
		"13�ĩ��������������",
		"12�ĩ��������������",
		"11�ĩ��������������",
		"10�ĩ��������������",
		" 9�ĩ��������������",
		" 8�ĩ��������������",
		" 7�ĩ��������������",
		" 6�ĩ��������������",
		" 5�ĩ��������������",
		" 4�ĩ��������������",
		" 3�ĩ��������������",
		" 2�ĩ��������������",
		" 1���۩۩۩۩۩۩۩۩۩۩۩۩۩�"
};
//������������ʾ���� 
char aDisplayBoardArray[SIZE][SIZE*CHARSIZE+1+2];
 
char play1Pic[]="��";//������;
char play1CurrentPic[]="��"; 

char play2Pic[]="��";//������;
char play2CurrentPic[]="��";

//���������ڼ�¼���̸�� 
int aRecordBoard[SIZE+1][SIZE+1];		//1_15������0��0����Ϊ�㣬������


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
	printf("input q to quilt, and others to continue\n");	
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

int winner_1(int s[SIZE+1][SIZE+1]){
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE+1-5;j++)
		{
			if(s[i][j]==1 && s[i][j+1]==1 && s[i][j+2]==1 && s[i][j+3]==1 && s[i][j+4]==1)
				return 1;
		}		
	}
	for(int j=1;j<=SIZE;j++)
	{
		for(int i=1;i<=SIZE+1-5;i++)
		{
			if(s[i][j]==1 && s[i+1][j]==1 && s[i+2][j]==1 && s[i+3][j]==1 && s[i+4][j]==1)
				return 1;
		}
	}
	for(int i=1;i<=SIZE+1-5;i++)
	{
		for(int j=1;j<=SIZE+1-5;j++)
		{
			if(s[i][j]==1 && s[i+1][j+1]==1 && s[i+2][j+2]==1 && s[i+3][j+3]==1 && s[i+4][j+4]==1)
				return 1;
		}
	}
	for(int i=5;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE+1-5;j++)
		{
			if(s[i][j]==1 && s[i-1][j+1]==1 && s[i-2][j+2]==1 && s[i-3][j+3]==1 && s[i-4][j+4]==1)
				return 1;
		}
	}
	return 0;	
}

int winner_2(int s[SIZE+1][SIZE+1]){
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE+1-5;j++)
		{
			if(s[i][j]==2 && s[i][j+1]==2 && s[i][j+2]==2 && s[i][j+3]==2 && s[i][j+4]==2)
				return 1;
		}		
	}
	for(int j=1;j<=SIZE;j++)
	{
		for(int i=1;i<=SIZE+1-5;i++)
		{
			if(s[i][j]==2 && s[i+1][j]==2 && s[i+2][j]==2 && s[i+3][j]==2 && s[i+4][j]==2)
				return 1;
		}
	}
	for(int i=1;i<=SIZE+1-5;i++)
	{
		for(int j=1;j<=SIZE+1-5;j++)
		{
			if(s[i][j]==2 && s[i+1][j+1]==2 && s[i+2][j+2]==2 && s[i+3][j+3]==2 && s[i+4][j+4]==2)
				return 1;
		}
	}
	for(int i=5;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE+1-5;j++)
		{
			if(s[i][j]==2 && s[i-1][j+1]==2 && s[i-2][j+2]==2 && s[i-3][j+3]==2 && s[i-4][j+4]==2)
				return 1;
		}
	}
	return 0;	
}

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
	if(Ban_Hand(aRecordBoard,n,a-'A'+1)==1)				//�жϽ���
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

	aRecordBoard[n][a-'A'+1]=1;
	
	recordtoDisplayArray_current(n,a-'A'+1);
   	displayBoard();

	if(winner_1(aRecordBoard))		//�ж����1�Ƿ�Ӯ�ñ���
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

	if(winner_2(aRecordBoard))		//�ж����2�Ƿ�Ӯ�ñ���
	{
		printf("----Player2 Win!!!----\n");
		break;
	}

	recordtoDisplayArray();

	printf("input q to quit, and others to continue");
	c=getchar();
	}
}





