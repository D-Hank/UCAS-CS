#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#define CHARSIZE 2
void initRecordBorard(void);
void recordtoDisplayArray(void);
void displayBoard(void);


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
int aRecordBoard[SIZE+1][SIZE+1];


int main()

{
	initRecordBorard();
	recordtoDisplayArray();
	displayBoard();
	while(1)
		{
//�жϳ���������л����˳�
		int n,p;
		char a,b,c;
		c=getchar();
		if(c=='q'||c==EOF)
			break;
		else
			;

//�ж����1�������
		printf("player1 input position:\n");
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
			printf("player1 input position:\n");
			scanf("%d",&n);
			scanf("%c",&a);	
			}
		aRecordBoard[n][a-'A'+1]=1;
		recordtoDisplayArray_current(n,a-'A'+1);
    		displayBoard();

//�ж����2�������
		printf("player2 input position:\n");
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
			printf("player2 input position:\n");
			scanf("%d",&p);
			scanf("%c",&b);	
			}
	
//�ɹ����Ӻ��������
		aRecordBoard[p][b-'A'+1]=2;
		recordtoDisplayArray_current(p,b-'A'+1);
    		displayBoard();

		recordtoDisplayArray();

		printf("input q to quit, and others to continue\n");
		c=getchar();
		}





  /*initRecordBorard();
    recordtoDisplayArray();
    displayBoard();
    getchar();

    aRecordBoard[5][8]=1;
    aRecordBoard[5][9]=2;
    recordtoDisplayArray();
    displayBoard();
    getchar();

    aRecordBoard[3][4]=2;
    recordtoDisplayArray();
    displayBoard();
    getchar();

    aRecordBoard[6][1]=1;
    recordtoDisplayArray();
    displayBoard();
    getchar();

    aRecordBoard[9][4]=2;
    recordtoDisplayArray();
    displayBoard();
    getchar();*/
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
















