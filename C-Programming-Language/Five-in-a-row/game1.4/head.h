#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#define CHARSIZE 2

#define TSIZE 17

#define long_connect 1
#define threeban 2
#define fourban 3

struct SingleInfo{		
	int linknum;		//������
	int oppnum;		//���˶�����������
};

struct SingleScore{
	struct SingleInfo info[4];	//��¼4������������Ϣ
	int score;			//��¼�õ�����
};

struct SingleScore BlackScoreBoard[16][16];		//��¼�����Ϻڰ�˫��ÿһ��ĵ÷ֺ���Ϣ
struct SingleScore WhiteScoreBoard[16][16];

int Three_ban(int s[TSIZE][TSIZE]);
int Four_ban(int s[TSIZE][TSIZE]);
void initRecordBorard(void);
void recordtoDisplayArray(void);
void displayBoard(void);

int Ban_Hand(int x,int y);//�жϽ���

int winner_1(int ,int);	//�ж����1��Ӯ
int winner_2(int ,int);	//�ж����2��Ӯ
int IsChessPiece(int i,int j);		//�жϵ�ǰ���Ӵ��Ƿ�������
int OutChessboard(int i,int j);		//�жϵ�ǰ���Ӵ��Ƿ���������
void recordtoDisplayArray_current(int i,int j);		//����������ʾ��ǰ�������
void playersvs(void);

void Info(int s[SIZE+1][SIZE+1]);	//��¼������Ϣ

//���������ڼ�¼���̸�� 
int aRecordBoard[SIZE+1][SIZE+1];		//1_15������0��0����Ϊ�㣬������







