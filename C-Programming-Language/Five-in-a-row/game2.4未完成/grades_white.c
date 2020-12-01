#include "head.h"


struct ScoreTable arrange_grades_white(void){
	int get_grades_white(int ,int);

	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			for(int k=0;k<4;k++)
				WhiteTable.Table[k][i][j].score=get_grades_white(k,i,j);
	return WhiteTable;
				
}


int get_grades_white(int i,int x,int y){											//��ȡ������
	int get_my_grades_white(int ,int ,int);
	int get_opp_grades_white(int ,int ,int);

	int mygrades=0;
	int oppgrades=0;

	mygrades=get_my_grades_white(i,x,y);
	oppgrades=get_opp_grades_white(i,x,y);

	return mygrades-oppgrades;

}


int get_my_grades_white(int i,int x,int y){
//	int whitedeadpiece(int ,int);
	int s[16][16];
	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			s[i][j]=aRecordBoard[i][j];									//���Ƶ�ǰ���

	if(IsChessPiece(x,y))												//�����Ӹ�ֵΪ0
		return 0;
	
	s[x][y]=1;													//������̽����

	Info(s,x,y);													//��ȡ���Ӵ�������Ϣ
		
	if(Long_Connect(x,y) || Three_Ban(x,y) || Four_Ban(x,y))							//�������
		return 0;


	s[x][y]=2;

	Info(s,x,y);

	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==5)			//������5
		return 5000;

/*	if(deadpiece(x,y)==4)												//4����������
		return 40;

	if(deadpiece(x,y)==3)												//3����������
		return 100;
*/

	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==4			//��������4
	&& WhiteScoreBoard[x][y].info[i].nullnum[0]>0 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]>0)		
		return 4000;


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==3			//��������3
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]==1 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]==1))		
		return 3800;


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+WhiteScoreBoard[x][y].info[i].linknum[1]==4 && WhiteScoreBoard[x][y].info[i].nullnum[0]==1)			//��������4
		return 3000;


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+WhiteScoreBoard[x][y].info[i].linknum[1]==3 && WhiteScoreBoard[x][y].info[i].nullnum[0]==1 
	&& WhiteScoreBoard[x][y].info[i].nullnum[1]>0 && WhiteScoreBoard[x][y].info[(i+4)%8].nullnum[0]>0)		//��������3
		return 2700;

	
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==2 
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]==1 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]==1))		//��������2
		return 2600;


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==4 
	&& (WhiteScoreBoard[x][y].info[i].oppnum[0]>0 || WhiteScoreBoard[x][y].info[i+4].oppnum[0]>0))			//������4
		return 2100;

	
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==1 
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]==1 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]==1))		//�����1
		return 1500;	
															
	return 40;													//�������
}

int get_opp_grades_white(int i,int x,int y){

//	int whitedeadpiece(int ,int);
	int s[16][16];
	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			s[i][j]=aRecordBoard[i][j];									//���Ƶ�ǰ���

	if(IsChessPiece(x,y))												//�����Ӹ�ֵΪ0
		return 0;
	
	s[x][y]=1;													//������̽����

	Info(s,x,y);													//��ȡ���Ӵ�������Ϣ
	

	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]>=5)			//������5
		return -4700;
	

	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==4			//��������4
	&& BlackScoreBoard[x][y].info[i].nullnum[0]>0 && BlackScoreBoard[x][y].info[i+4].nullnum[0]>0)		
		return -4500;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==3			//��������3
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))		
		return -4300;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+BlackScoreBoard[x][y].info[i].linknum[1]==4 && BlackScoreBoard[x][y].info[i].nullnum[0]==1)			//��������4
		return -3500;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+BlackScoreBoard[x][y].info[i].linknum[1]==3 && BlackScoreBoard[x][y].info[i].nullnum[0]==1 
	&& BlackScoreBoard[x][y].info[i].nullnum[1]>0 && BlackScoreBoard[x][y].info[(i+4)%8].nullnum[0]>0)		//��������3
		return -2500;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==2			//��������2
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))
		return -2400;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==4 
	&& (BlackScoreBoard[x][y].info[i].oppnum[0]>0 || BlackScoreBoard[x][y].info[i+4].oppnum[0]>0))			//������4
		return -2300;			


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==3
	&& (BlackScoreBoard[x][y].info[i].oppnum[0]>0 || BlackScoreBoard[x][y].info[i+4].linknum[0]>0))			//������3
		return -1900;
															
	return -40;													//�������

}

/*															//�жϼ�����������
int blackdeadpiece(int x,int y){
	int b=0;
	for(int i=0;i<4;i++)
	if(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))		
		b++;
	return b;				
}

*/











