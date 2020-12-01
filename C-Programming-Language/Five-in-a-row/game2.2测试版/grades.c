#include "head.h"


struct ScoreTable arrange_grades(void){
	int get_grades_black(int ,int);

	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			BlackTable.Table[i][j].score=get_grades_black(i,j);
	return BlackTable;
				
}


int get_grades_black(int x,int y){											//��ȡ������
	int get_my_grades(int ,int);
	int get_opp_grades(int ,int);

	int mygrades=0;
	int oppgrades=0;

	mygrades=get_my_grades(x,y);
	oppgrades=get_opp_grades(x,y);

	return (mygrades>oppgrades)?mygrades:oppgrades;

}


int get_my_grades(int x,int y){
	int s[16][16];
	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			s[i][j]=aRecordBoard[i][j];									//���Ƶ�ǰ���

	if(IsChessPiece(x,y))												//�����Ӹ�ֵΪ0
		return 0;
	
	s[x][y]=1;													//������̽����

	Info(s,x,y);													//��ȡ���Ӵ�������Ϣ
		
	if(Long_Connect(x,y) || Three_Ban(x,y) || Four_Ban(x,y))							//������ֻ�������
		return 0;

	for(int i=0;i<4;i++)
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==5)			//������5
		return 5000;

	for(int i=0;i<4;i++)
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==4			//��������4
	&& BlackScoreBoard[x][y].info[i].nullnum[0]>0 && BlackScoreBoard[x][y].info[i+4].nullnum[0]>0)		
		return 4000;


	for(int i=0;i<4;i++)
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==4 
	&& (BlackScoreBoard[x][y].info[i].oppnum[0]>0 || BlackScoreBoard[x][y].info[i+4].oppnum[0]>0))			//������4
		return 3800;

	for(int i=0;i<4;i++)
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==3			//��������3
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))		
		return 3000;

	for(int i=0;i<8;i++)
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+BlackScoreBoard[x][y].info[i].linknum[1]==4 && BlackScoreBoard[x][y].info[i].nullnum[0]==1)			//��������4
		return 2700;

	for(int i=0;i<8;i++)
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+BlackScoreBoard[x][y].info[i].linknum[1]==3 && BlackScoreBoard[x][y].info[i].nullnum[0]==1 
	&& BlackScoreBoard[x][y].info[i].nullnum[1]>0 && BlackScoreBoard[x][y].info[(i+4)%8].nullnum[0]>0)		//��������3
		return 2600;			

	for(int i=0;i<4;i++)	
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==2 
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))		//��������2
		return 2100;

	for(int i=0;i<4;i++)	
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==1 
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))		//�����1
		return 1500;	
															
	return 40;													//�������
}

int get_opp_grades(int x,int y){
	int s[16][16];
	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			s[i][j]=aRecordBoard[i][j];									//���Ƶ�ǰ���

	if(IsChessPiece(x,y))												//�����Ӹ�ֵΪ0
		return 0;
	
	s[x][y]=2;													//������̽����

	Info(s,x,y);													//��ȡ���Ӵ�������Ϣ
	
	for(int i=0;i<4;i++)
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]>=5)			//������5
		return 4700;
	
	for(int i=0;i<4;i++)
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==4			//��������4
	&& WhiteScoreBoard[x][y].info[i].nullnum[0]>0 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]>0)		
		return 4500;

	for(int i=0;i<4;i++)
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==4 
	&& (WhiteScoreBoard[x][y].info[i].oppnum[0]>0 || WhiteScoreBoard[x][y].info[i+4].oppnum[0]>0))			//������4
		return 4300;	

	for(int i=0;i<4;i++)
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==3			//��������3
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]==1 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]==1))		
		return 3500;

	for(int i=0;i<8;i++)
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+WhiteScoreBoard[x][y].info[i].linknum[1]==4 && WhiteScoreBoard[x][y].info[i].nullnum[0]==1)			//��������4
		return 2500;

	for(int i=0;i<8;i++)
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+WhiteScoreBoard[x][y].info[i].linknum[1]==3 && WhiteScoreBoard[x][y].info[i].nullnum[0]==1 
	&& WhiteScoreBoard[x][y].info[i].nullnum[1]>0 && WhiteScoreBoard[x][y].info[(i+4)%8].nullnum[0]>0)		//��������3
		return 2400;			


	for(int i=0;i<4;i++)
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==3
	&& (WhiteScoreBoard[x][y].info[i].oppnum[0]>0 || WhiteScoreBoard[x][y].info[i+4].linknum[0]>0))			//������3
		return 2300;

	for(int i=0;i<4;i++)
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==2			//��������2
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]==1 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]==1))
		return 1900;
															
	return 40;													//�������

}











