#include "head.h"


struct ScoreTable arrange_grades_black(void){
	long long int get_grades_black(int ,int);

	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			BlackTable.Table[i][j].score=get_grades_black(i,j);
	return BlackTable;
				
}


long long int get_grades_black(int x,int y){											//��ȡ������
	long long int get_my_grades_black(int ,int ,int);
	long long int get_opp_grades_black(int ,int ,int);

	long long int mygrades=0;
	long long int oppgrades=0;

	mygrades=get_my_grades_black(0,x,y)+get_my_grades_black(1,x,y)+get_my_grades_black(2,x,y)+get_my_grades_black(3,x,y);
	oppgrades=get_opp_grades_black(0,x,y)+get_opp_grades_black(1,x,y)+get_opp_grades_black(2,x,y)+get_opp_grades_black(3,x,y);

	return mygrades+oppgrades;

}


long long int get_my_grades_black(int i,int x,int y){
//	int whitedeadpiece(int ,int);
	int s[16][16],t;

	if(IsChessPiece(x,y))												//�����Ӹ�ֵΪ0
		return 0;														
	

	if(Ban_Hand(x,y)>0)												//�������
		return 0;


	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			s[i][j]=aRecordBoard[i][j];									//���Ƶ�ǰ���

	s[x][y]=1;													//������̽����
	
	Info(s,x,y);													//��ȡ���Ӵ�������Ϣ
		



	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==5)			//������5
		return 549755813888;
/*
	if(deadpiece(x,y)==4)												//4����������
		return 40;

	if(deadpiece(x,y)==3)												//3����������
		return 100;
*/


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==4			//��������4
	&& (BlackScoreBoard[x][y].info[i].nullnum[0]>0 && BlackScoreBoard[x][y].info[i+4].nullnum[0]>0))		
		return 8589934592;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==3			//��������3
	&& (BlackScoreBoard[x][y].info[i].nullnum[0]>0 && BlackScoreBoard[x][y].info[i+4].nullnum[0]>0)
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[(i+4)%8].nullnum[0]==1
	&& BlackScoreBoard[x][y].info[i].oppnum[0]>0 && BlackScoreBoard[x][y].info[(i+4)%8].oppnum[0]>0))		
		return 134217728;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==2 
	&& BlackScoreBoard[x][y].info[i].nullnum[0]>0 && BlackScoreBoard[x][y].info[i+4].nullnum[0]>0			//��������2
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]+BlackScoreBoard[x][y].info[(i+4)%8].nullnum[0]==3
	&& BlackScoreBoard[x][y].info[i].oppnum[0]>0 && BlackScoreBoard[x][y].info[(i+4)%8].oppnum[0]>0))			
		return 2097152;



	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==4 
	&& (BlackScoreBoard[x][y].info[i].oppnum[0]>0 ^ BlackScoreBoard[x][y].info[i+4].oppnum[0]>0))			//������4
		return 32768;

/*	
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+BlackScoreBoard[x][y].info[i].linknum[1]==4 && BlackScoreBoard[x][y].info[i].nullnum[0]==1)			//��������4
		return 590490;
*/


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==3
	&& (BlackScoreBoard[x][y].info[i].oppnum[0]>0 ^ BlackScoreBoard[x][y].info[i+4].linknum[0]>0))			//������3
		return 512;

/*
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+BlackScoreBoard[x][y].info[i].linknum[1]==3 && BlackScoreBoard[x][y].info[i].nullnum[0]==1 
	&& BlackScoreBoard[x][y].info[i].nullnum[1]>0 && BlackScoreBoard[x][y].info[(i+4)%8].nullnum[0]>0)		//��������3
		return 7290;
*/			

	
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==1 
	&& BlackScoreBoard[x][y].info[i].nullnum[0]>0 && BlackScoreBoard[x][y].info[i+4].nullnum[0]>0
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]+BlackScoreBoard[x][y].info[(i+4)%8].nullnum[0]==4
	&& BlackScoreBoard[x][y].info[i].oppnum[0]>0 && BlackScoreBoard[x][y].info[(i+4)%8].oppnum[0]>0))			//�����1
		return 8;	
															
	return 40;													//�������
}

long long int get_opp_grades_black(int i,int x,int y){

//	int whitedeadpiece(int ,int);
	int s[16][16];
	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			s[i][j]=aRecordBoard[i][j];									//���Ƶ�ǰ���

	if(IsChessPiece(x,y))												//�����Ӹ�ֵΪ0
		return 0;
	
	s[x][y]=2;													//������̽����

	Info(s,x,y);													//��ȡ���Ӵ�������Ϣ
	
	
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]>4)			//������5
		return 68719476736;
	
	
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==4			//��������4
	&& WhiteScoreBoard[x][y].info[i].nullnum[0]>0 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]>0)		
		return 1073741824;

	
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==3			//��������3
	&& WhiteScoreBoard[x][y].info[i].nullnum[0]>0 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]>0
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]==1 && WhiteScoreBoard[x][y].info[(i+4)%8].nullnum[0]==1
	&& WhiteScoreBoard[x][y].info[i].oppnum[0]>0 && WhiteScoreBoard[x][y].info[(i+4)%8].oppnum[0]>0))
		return 16777216;

	
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==4 
	&& (WhiteScoreBoard[x][y].info[i].oppnum[0]>0 ^ WhiteScoreBoard[x][y].info[i+4].oppnum[0]>0))			//������4
		return 262144;

/*
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+WhiteScoreBoard[x][y].info[i].linknum[1]==4 && WhiteScoreBoard[x][y].info[i].nullnum[0]==1)			//��������4
		return 1771470;	
*/


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==3
	&& (WhiteScoreBoard[x][y].info[i].oppnum[0]>0 ^ WhiteScoreBoard[x][y].info[i+4].linknum[0]>0))			//������3
		return 4096;

/*
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+WhiteScoreBoard[x][y].info[i].linknum[1]==3 && WhiteScoreBoard[x][y].info[i].nullnum[0]==1 
	&& WhiteScoreBoard[x][y].info[i].nullnum[1]>0 && WhiteScoreBoard[x][y].info[(i+4)%8].nullnum[0]>0)		//��������3
		return 21870;
*/


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==2			//��������2
	&& (WhiteScoreBoard[x][y].info[i].nullnum[0]>0 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]>0)
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].nullnum[0]==3
	&& WhiteScoreBoard[x][y].info[i].oppnum[0]>0 && WhiteScoreBoard[x][y].info[(i+4)%8].oppnum[0]>0))
		return 64;

		
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==1 
	&& WhiteScoreBoard[x][y].info[i].nullnum[0]>0 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]>0
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].nullnum[0]==4
	&& WhiteScoreBoard[x][y].info[i].oppnum[0]>0 && WhiteScoreBoard[x][y].info[(i+4)%8].oppnum[0]>0))		//�����1
		return 8;	

															
	return 40;													//�������

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









