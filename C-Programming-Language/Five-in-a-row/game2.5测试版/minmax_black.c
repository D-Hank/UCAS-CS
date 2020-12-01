#include "head.h"
#include  <stdlib.h>

struct point AI_minmax_Black(int n){
	struct point zl;
	long long int pmax=0;

	int distance=0;
	int dmin=225;


	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			gradestable_black[i][j].score=get_grades_black(i,j);
																	//�ҳ���ߵķ�
	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			if(pmax<gradestable_black[i][j].score)
				pmax=gradestable_black[i][j].score;

	for(int i=0;i<250;i++)
		{
			BlackGradesMax[i].x=0;
			BlackGradesMax[i].y=0;	
		}

	for(int i=0;i<250;i++)
		{
			bestpblack[i].x=0;
			bestpblack[i].y=0;	
		}


	int l=0;																//�ҵ��ķ���ߵ�λ��

	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			if(pmax==gradestable_black[i][j].score)
			{
				BlackGradesMax[l].x=i;
				BlackGradesMax[l].y=j;
				l++;
			}


	int s=0,w;
	struct point val;//������¼ÿһ�����Ӻ󣬶��ַ��ص����ӵ�λ�ú���ߵķ�
	int x,y;//������ʱ��¼������������ӵ�λ��
	long long int tempmax=34867844010*4;//������¼��̽һ�������ߵķ֣���ʼ��һ�����ֵ
	if(n>0)
	{
		for(int i=0;i<l;i++)													//��ÿһ���÷���ߵ��Ӷ���һ��
		{
			x=BlackGradesMax[i].x;
			y=BlackGradesMax[i].y;
			aRecordBoard[x][y]=1;//����һ������

			if(winner_1(x,y))
			{
				aRecordBoard[x][y]=0;//��ԭ����
				zl.x=x;
				zl.y=y;
				zl.score=34867844010;
				return zl;
			}

			val=AI_White(n-1);
			
			if(val.score==tempmax)//����ҵ��͵�ǰ��߷���һ���ĵ�ͱ�������
			{
				bestpblack[s].x=x;
				bestpblack[s].y=y;
				s++;	
			}

			if(val.score<tempmax)//����ҵ��ȵ�ǰ��ߵķֵ͵ķ������Ͱ�֮ǰ�����;
			{
				s=0;
				tempmax=val.score;
				bestpblack[s].x=x;
				bestpblack[s].y=y;
				s++;	
			}
			aRecordBoard[x][y]=0;//��ԭ����
			
		}
		w=(rand()%s);				

		zl.x=bestpblack[w].x;
		zl.y=bestpblack[w].y;
		zl.score=tempmax;	
	
		return zl;
		
	}	



/*
	for(int l=0;l<250;l++)
		if((distance = (BlackGradesMax[l].x-8)*(BlackGradesMax[l].x-8)+(BlackGradesMax[l].y-8)*(BlackGradesMax[l].y-8)) < dmin)		//�����ĵľ���	
			dmin=distance;

	for(int l=0;l<250;l++)
		if((distance = (BlackGradesMax[l].x-8)*(BlackGradesMax[l].x-8)+(BlackGradesMax[l].y-8)*(BlackGradesMax[l].y-8)) == dmin)
			{
				bestpblack[l].x=BlackGradesMax[l].x;
				bestpblack[l].y=BlackGradesMax[l].y;
			}
*/
			
	int z;
	z=(rand()%l);				//����ж�����ŵĵ�������һ��

	zl.x=BlackGradesMax[z].x;
	zl.y=BlackGradesMax[z].y;
	zl.score=pmax;	
	
	return zl;
		
}


struct point AI_White(int n){

	struct point zl;
	long long int pmax=0;

	int distance=0;
	int dmin=225;


	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			gradestable_white[i][j].score=get_grades_white(i,j);

																		//�ҳ���ߵķ�
	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			if(pmax<gradestable_white[i][j].score)
				pmax=gradestable_white[i][j].score;

	for(int i=0;i<250;i++)
		{
			WhiteGradesMax[i].x=0;
			WhiteGradesMax[i].y=0;	
		}

	for(int i=0;i<250;i++)
		{
			bestpwhite[i].x=0;
			bestpwhite[i].y=0;	
		}



	int l=0;																//ѡ���÷���ߵ�λ��

	for(int i=1;i<16;i++)
		for(int j=1;j<16;j++)
			if(pmax==gradestable_white[i][j].score)
			{
				WhiteGradesMax[l].x=i;
				WhiteGradesMax[l].y=j;
				l++;
			}

	int s=0,w;
	struct point val;//������¼ÿһ�����Ӻ󣬶��ַ��ص����ӵ�λ�ú���ߵķ�
	int x,y;//������ʱ��¼������������ӵ�λ��
	long long int tempmax=-34867844010*4;//������¼��̽һ�������ߵķ֣���ʼ��һ����Сֵ
	if(n>0)
	{
		for(int i=0;i<l;i++)													//��ÿһ���÷���ߵ��Ӷ���һ��
		{
			x=WhiteGradesMax[i].x;
			y=WhiteGradesMax[i].y;
			aRecordBoard[x][y]=2;//����һ������
/*
			if(winner_2(x,y))
			{
				aRecordBoard[x][y]=0;//��ԭ����
				zl.x=x;
				zl.y=y;
				zl.score=34867844010;
				return zl;
			}
*/
			val=AI_Black(n-1);
			
			if(val.score==tempmax)//����ҵ��͵�ǰ��߷���һ���ĵ�ͱ�������
			{
				bestpwhite[s].x=x;
				bestpwhite[s].y=y;
				s++;	
			}

			if(val.score>tempmax)//����ҵ��ȵ�ǰ��ߵķֵ͵ķ������Ͱ�֮ǰ�����;
			{
				s=0;
				tempmax=val.score;
				bestpwhite[s].x=x;
				bestpwhite[s].y=y;
				s++;	
			}
			aRecordBoard[x][y]=0;//��ԭ����
			
		}
		w=(rand()%s);					

		zl.x=bestpwhite[w].x;
		zl.y=bestpwhite[w].y;
		zl.score=tempmax;	

		return zl;
	
	}	


/*
	for(int l=0;l<250;l++)
		if((distance = (WhiteGradesMax[l].x-8)*(WhiteGradesMax[l].x-8)+(WhiteGradesMax[l].y-8)*(WhiteGradesMax[l].y-8)) < dmin)		//�����ĵľ���	
			dmin=distance;

	for(int l=0;l<250;l++)
		if((distance = (WhiteGradesMax[l].x-8)*(WhiteGradesMax[l].x-8)+(WhiteGradesMax[l].y-8)*(WhiteGradesMax[l].y-8)) == dmin)
			{
				bestpwhite[l].x=WhiteGradesMax[l].x;
				bestpwhite[l].y=WhiteGradesMax[l].y;
			}
*/
			
	int z;
	z=(rand()%l);					//����ж�����ŵĵ�������һ��

	zl.x=WhiteGradesMax[z].x;
	zl.y=WhiteGradesMax[z].y;
	zl.score=pmax;	

	return zl;
		
}







