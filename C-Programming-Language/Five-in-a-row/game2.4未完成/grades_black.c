#include "head.h"


struct ScoreTable arrange_grades_black(void){
	int get_grades_black(int ,int ,int);

	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			for(int k=0;k<4;k++)
				BlackTable.Table[k][i][j].score=get_grades_black(k,i,j);
	return BlackTable;
				
}


int get_grades_black(int i,int x,int y){											//获取最后分数
	int get_my_grades_black(int, int ,int);
	int get_opp_grades_black(int ,int ,int);

	int mygrades=0;
	int oppgrades=0;

	mygrades=get_my_grades_black(i,x,y);
	oppgrades=get_opp_grades_black(i,x,y);

	return mygrades-oppgrades;

}


int get_my_grades_black(int i,int x,int y){
//	int whitedeadpiece(int ,int);
	int s[16][16],t;
	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			s[i][j]=aRecordBoard[i][j];									//复制当前棋局

	if(IsChessPiece(x,y))												//有棋子赋值为0
		return 0;														
	
	t=aRecordBoard[x][y];
	aRecordBoard[x][y]=1;
	Info(aRecordBoard,x,y);
	aRecordBoard[x][y]=t;
	if(Ban_Hand(x,y))												//黑棋禁手或有棋子
		return 0;

	s[x][y]=1;													//填入试探棋子
	
	Info(s,x,y);													//获取落子处棋盘信息
		


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==5)			//黑棋连5
		return 20000;
/*
	if(deadpiece(x,y)==4)												//4个方向死棋
		return 40;

	if(deadpiece(x,y)==3)												//3个方向死棋
		return 100;
*/

	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==4			//黑棋连活4
	&& BlackScoreBoard[x][y].info[i].nullnum[0]>0 && BlackScoreBoard[x][y].info[i+4].nullnum[0]>0)		
		return 4000;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==3			//黑棋连活3
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))		
		return 3800;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+BlackScoreBoard[x][y].info[i].linknum[1]==4 && BlackScoreBoard[x][y].info[i].nullnum[0]==1)			//黑棋跳活4
		return 3000;


	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+BlackScoreBoard[x][y].info[i].linknum[1]==3 && BlackScoreBoard[x][y].info[i].nullnum[0]==1 
	&& BlackScoreBoard[x][y].info[i].nullnum[1]>0 && BlackScoreBoard[x][y].info[(i+4)%8].nullnum[0]>0)		//黑棋跳活3
		return 2700;

	
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==2 
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))		//黑棋连活2
		return 2600;



	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==4 
	&& (BlackScoreBoard[x][y].info[i].oppnum[0]>0 || BlackScoreBoard[x][y].info[i+4].oppnum[0]>0))			//黑棋眠4
		return 2100;

				
	if(BlackScoreBoard[x][y].info[i].linknum[0]+BlackScoreBoard[x][y].info[i+4].linknum[0]==1 
	&& !(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))		//黑棋活1
		return 1500;	
															
	return 40;													//其他情况
}

int get_opp_grades_black(int i,int x,int y){

//	int whitedeadpiece(int ,int);
	int s[16][16];
	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			s[i][j]=aRecordBoard[i][j];									//复制当前棋局

	if(IsChessPiece(x,y))												//有棋子赋值为0
		return 0;
	
	s[x][y]=2;													//填入试探棋子

	Info(s,x,y);													//获取落子处棋盘信息
	
	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]>=5)			//白棋连5
		return -17000;
	

	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==4			//白棋连活4
	&& WhiteScoreBoard[x][y].info[i].nullnum[0]>0 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]>0)		
		return -4500;


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==3			//白棋连活3
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]==1 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]==1))		
		return -4300;


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+WhiteScoreBoard[x][y].info[i].linknum[1]==4 && WhiteScoreBoard[x][y].info[i].nullnum[0]==1)			//白棋跳活4
		return -3500;


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[(i+4)%8].linknum[0]
	+WhiteScoreBoard[x][y].info[i].linknum[1]==3 && WhiteScoreBoard[x][y].info[i].nullnum[0]==1 
	&& WhiteScoreBoard[x][y].info[i].nullnum[1]>0 && WhiteScoreBoard[x][y].info[(i+4)%8].nullnum[0]>0)		//白棋跳活3
		return -2500;


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==2			//白棋连活2
	&& !(WhiteScoreBoard[x][y].info[i].nullnum[0]==1 && WhiteScoreBoard[x][y].info[i+4].nullnum[0]==1))
		return -2400;


	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==4 
	&& (WhiteScoreBoard[x][y].info[i].oppnum[0]>0 || WhiteScoreBoard[x][y].info[i+4].oppnum[0]>0))			//白棋眠4
		return -2300;	
			

	if(WhiteScoreBoard[x][y].info[i].linknum[0]+WhiteScoreBoard[x][y].info[i+4].linknum[0]==3
	&& (WhiteScoreBoard[x][y].info[i].oppnum[0]>0 || WhiteScoreBoard[x][y].info[i+4].linknum[0]>0))			//白棋眠3
		return -1900;

															
	return -40;													//其他情况

}

/*															//判断几个方向死棋
int blackdeadpiece(int x,int y){
	int b=0;
	for(int i=0;i<4;i++)
	if(BlackScoreBoard[x][y].info[i].nullnum[0]==1 && BlackScoreBoard[x][y].info[i+4].nullnum[0]==1))		
		b++;
	return b;				
}


*/









