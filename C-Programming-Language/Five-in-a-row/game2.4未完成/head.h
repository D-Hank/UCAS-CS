#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#define CHARSIZE 2

#define TSIZE 19

#define long_connect 1
#define threeban 2
#define fourban 3
struct point{
	int x;
	int y;
};

struct SingleInfo{		
	int linknum[2];		//������
	int oppnum[2];		//���˶�����������
	int nullnum[2];		//�հ�λ������
};

struct SingleScore{
	struct SingleInfo info[8];	//��¼8������������Ϣ
	int score[4];			
};

struct ScoreTableOne{
	int score;			//��¼���̸�������
};

struct ScoreTable{
	struct ScoreTableOne Table[4][16][16];
};

struct pointscore{
	int score;
};

struct ScoreTable BlackTable;				//��¼�����Ϻڰ�˫��ÿһ��ĵ÷���Ϣ
struct ScoreTable WhiteTable;	

struct SingleScore BlackScoreBoard[16][16];		//��¼�����Ϻڰ�˫��ÿһ���������Ϣ
struct SingleScore WhiteScoreBoard[16][16];

struct point BlackGradesMax[225];			//��¼�����Ϻڰ�˫�����ӵ÷���ߵ�
struct point WhiteGradesMax[225];

struct point bestpblack[250];				//��¼�����Ϻڰ�˫��������������λ��
struct point bestpwhite[250];

struct pointscore gradestable_black[16][16];
struct pointscore gradestable_white[16][16];

int Three_ban(int s[TSIZE][TSIZE]);
int Four_ban(int s[TSIZE][TSIZE]);
void initRecordBorard(void);
void recordtoDisplayArray(void);
void displayBoard(void);

int Ban_Hand(int ,int);					//�жϽ���
int Long_Connect(int ,int);
int Three_Ban(int ,int);
int Four_Ban(int ,int);


int winner_1(int ,int);					//�ж����1��Ӯ
int winner_2(int ,int);					//�ж����2��Ӯ
int IsChessPiece(int i,int j);				//�жϵ�ǰ���Ӵ��Ƿ�������
int OutChessboard(int i,int j);				//�жϵ�ǰ���Ӵ��Ƿ���������
void recordtoDisplayArray_current(int i,int j);		//����������ʾ��ǰ�������
				
void playersvs(void);					//��Ϸģʽ
void player_vs_computer_black(void);
void player_vs_computer_white(void);
void test(void);

void Info(int s[SIZE+1][SIZE+1],int m,int n);		//��¼������Ϣ
struct ScoreTable arrange_grades_black(void);		//��������
struct ScoreTable arrange_grades_white(void);

int get_grades_black(int ,int ,int);				//��������
int get_grades_white(int ,int ,int);

struct point AI_Black(void);				//���ԣ����壩
struct point AI_White(void);				//���ԣ����壩
	
//���������ڼ�¼���̸�� 
int aRecordBoard[SIZE+1][SIZE+1];		//1_15������0��0����Ϊ�㣬������



//���±������ڼ���Сֵ�㷨
int balck_score_board[16][16];			//��¼ÿ���ĸ�����ķ���֮��
int white_score_board[16][16];

struct pointlist{
	struct point chess[225];
	int len;
};

struct pointlist black_quene;			//�����ѡ��
struct pointlist white_quene;

struct pointlist black_sure_quene;			//�������ŵ�
struct pointlist white_sure_quene;

void generate_black_point(void);






