#include "head.h"

void Info(int s[SIZE+1][SIZE+1],int m,int n)
{
	int temp[TSIZE][TSIZE];			//����һ�������̣�ʹ����ȫ����סС����
	for(int i=0;i<TSIZE;i++)
		for(int j=0;j<TSIZE;j++)
			temp[i][j]=9;		//��ʼ�������̱߽磬9�Ժ���,������˵����������

	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
			temp[i+1][j+1]=s[i][j];	//��С���̵�ֵ���Ƶ������������룬ʹ����Χ�����ı߽����
											
	for(int k=0;k<4;k++)	//�������
		for(int l=0;l<2;l++){
			BlackScoreBoard[m][n].info[k].linknum[l]=0;
			BlackScoreBoard[m][n].info[k].oppnum[l]=0;
			WhiteScoreBoard[m][n].info[k].linknum[l]=0;
			WhiteScoreBoard[m][n].info[k].oppnum[l]=0;
		}

//��¼˫��������Ϣ

		int i;

//��¼����������ÿһ�����Ϣ															


	
		for(i=0;temp[m+1][n+1+i]==1;i++)
			BlackScoreBoard[m][n].info[0].linknum[0]++;			//��¼������������
		if(temp[m+1][n+1+i]==2 || temp[m+1][n+1+i]==9)	BlackScoreBoard[m][n].info[0].oppnum[0]++;	//��¼���������������
		if(temp[m+1][n+1+(i+1)]==1)	BlackScoreBoard[m][n].info[0].linknum[1]++;
		if(temp[m+1][n+1+(i+1)]==2 || temp[m+1][n+1+(i+1)]==9)	BlackScoreBoard[m][n].info[0].oppnum[1]++;		

	
		for(i=1;temp[m+1][n+1-i]==1;i++)
			BlackScoreBoard[m][n].info[0].linknum[0]++;
		if(temp[m+1][n+1-i]==2 || temp[m+1][n+1-i]==9)	BlackScoreBoard[m][n].info[0].oppnum[0]++;
		if(temp[m+1][n+1-(i+1)]==1)	BlackScoreBoard[m][n].info[0].linknum[1]++;
		if(temp[m+1][n+1-(i+1)]==2 || temp[m+1][n+1-(i+1)]==9)	BlackScoreBoard[m][n].info[0].oppnum[1]++;		
	
										
	
		for(i=0;temp[m+1+i][n+1+i]==1;i++)
			BlackScoreBoard[m][n].info[1].linknum[0]++;					//��¼ / ��������
		if(temp[m+1+i][n+1+i]==2 || temp[m+1+i][n+1+i]==9)	BlackScoreBoard[m][n].info[1].oppnum[0]++;		//��¼/�����������
		if(temp[m+1+(i+1)][n+1+(i+1)]==1)	BlackScoreBoard[m][n].info[1].linknum[1]++;
		if(temp[m+1+(i+1)][n+1+(i+1)]==2 || temp[m+1+(i+1)][n+1+(i+1)]==9)	BlackScoreBoard[m][n].info[1].oppnum[1]++;		
	

	
		for(i=1;temp[m+1-i][n+1-i]==1;i++)
			BlackScoreBoard[m][n].info[1].linknum[0]++;
		if(temp[m+1-i][n+1-i]==2 || temp[m+1-i][n+1-i]==9)	BlackScoreBoard[m][n].info[1].oppnum[0]++;			
		if(temp[m+1-(i+1)][n+1-(i+1)]==1)	BlackScoreBoard[m][n].info[1].linknum[1]++;	
		if(temp[m+1-(i+1)][n+1-(i+1)]==2 || temp[m+1-(i+1)][n+1-(i+1)]==9)	BlackScoreBoard[m][n].info[1].oppnum[1]++;

	
		for(i=0;temp[m+1+i][n+1]==1;i++)
			BlackScoreBoard[m][n].info[2].linknum[0]++;					//��¼ | ��������
		if(temp[m+1+i][n+1]==2 || temp[m+1+i][n+1]==9)	BlackScoreBoard[m][n].info[2].oppnum[0]++;			//��¼ | �����������
		if(temp[m+1+(i+1)][n+1]==1)	BlackScoreBoard[m][n].info[2].linknum[1]++;
		if(temp[m+1+(i+1)][n+1]==2 || temp[m+1+(i+1)][n+1]==9)	BlackScoreBoard[m][n].info[2].oppnum[1]++;	
	
	
		for(i=1;temp[m+1-i][n+1]==1;i++)
			BlackScoreBoard[m][n].info[2].linknum[0]++;
		if(temp[m+1-i][n+1]==2 || temp[m+1-i][n+1]==9)	BlackScoreBoard[m][n].info[2].oppnum[0]++;
		if(temp[m+1-(i+1)][n+1]==1)	BlackScoreBoard[m][n].info[2].linknum[1]++;
		if(temp[m+1-(i+1)][n+1]==2 || temp[m+1-(i+1)][n+1]==9)	BlackScoreBoard[m][n].info[2].oppnum[1]++;
	

		for(i=0;temp[m+1+i][n+1-i]==1;i++)
			BlackScoreBoard[m][n].info[3].linknum[0]++;					//��¼ \ ��������
		if(temp[m+1+i][n+1-i]==2 || temp[m+1+i][n+1-i]==9)	BlackScoreBoard[m][n].info[3].oppnum[0]++;		//��¼\�����������
		if(temp[m+1+(i+1)][n+1-(i+1)]==1)	BlackScoreBoard[m][n].info[3].linknum[1]++;
		if(temp[m+1+(i+1)][n+1-(i+1)]==2 || temp[m+1+(i+1)][n+1-(i+1)]==9)	BlackScoreBoard[m][n].info[3].oppnum[1]++;
			

		for(i=1;temp[m+1-i][n+1+i]==1;i++)
			BlackScoreBoard[m][n].info[3].linknum[0]++;
		if(temp[m+1-i][n+1+i]==2 || temp[m+1-i][n+1+i]==9)	BlackScoreBoard[m][n].info[3].oppnum[0]++;
		if(temp[m+1-(i+1)][n+1+(i+1)]==1)	BlackScoreBoard[m][n].info[3].linknum[1]++;
		if(temp[m+1-(i+1)][n+1+(i+1)]==2 || temp[m+1-(i+1)][n+1+(i+1)]==9)	BlackScoreBoard[m][n].info[3].oppnum[1]++;

			

//��¼����������ÿһ�����Ϣ



		for(i=0;temp[m+1][n+1+i]==2;i++)
			WhiteScoreBoard[m][n].info[0].linknum[0]++;			//��¼������������
		if(temp[m+1][n+1+i]==1 || temp[m+1][n+1+i]==9)	WhiteScoreBoard[m][n].info[0].oppnum[0]++;	//��¼���������������
		if(temp[m+1][n+1+(i+1)]==2)	WhiteScoreBoard[m][n].info[0].linknum[1]++;
		if(temp[m+1][n+1+(i+1)]==1 || temp[m+1][n+1+(i+1)]==9)	WhiteScoreBoard[m][n].info[0].oppnum[1]++;		

	
		for(i=1;temp[m+1][n+1-i]==2;i++)
			WhiteScoreBoard[m][n].info[0].linknum[0]++;
		if(temp[m+1][n+1-i]==1 || temp[m+1][n+1-i]==9)	WhiteScoreBoard[m][n].info[0].oppnum[0]++;
		if(temp[m+1][n+1-(i+1)]==2)	WhiteScoreBoard[m][n].info[0].linknum[1]++;
		if(temp[m+1][n+1-(i+1)]==1 || temp[m+1][n+1-(i+1)]==9)	WhiteScoreBoard[m][n].info[0].oppnum[1]++;		
	
										
	
		for(i=0;temp[m+1+i][n+1+i]==2;i++)
			WhiteScoreBoard[m][n].info[1].linknum[0]++;					//��¼ / ��������
		if(temp[m+1+i][n+1+i]==1 || temp[m+1+i][n+1+i]==9)	WhiteScoreBoard[m][n].info[1].oppnum[0]++;		//��¼/�����������
		if(temp[m+1+(i+1)][n+1+(i+1)]==2)	WhiteScoreBoard[m][n].info[1].linknum[1]++;
		if(temp[m+1+(i+1)][n+1+(i+1)]==1 || temp[m+1+(i+1)][n+1+(i+1)]==9)	WhiteScoreBoard[m][n].info[1].oppnum[1]++;		
	

	
		for(i=1;temp[m+1-i][n+1-i]==2;i++)
			WhiteScoreBoard[m][n].info[1].linknum[0]++;
		if(temp[m+1-i][n+1-i]==1 || temp[m+1-i][n+1-i]==9)	WhiteScoreBoard[m][n].info[1].oppnum[0]++;			
		if(temp[m+1-(i+1)][n+1-(i+1)]==2)	WhiteScoreBoard[m][n].info[1].linknum[1]++;	
		if(temp[m+1-(i+1)][n+1-(i+1)]==1 || temp[m+1-(i+1)][n+1-(i+1)]==9)	WhiteScoreBoard[m][n].info[1].oppnum[1]++;

	
		for(i=0;temp[m+1+i][n+1]==2;i++)
			WhiteScoreBoard[m][n].info[2].linknum[0]++;					//��¼ | ��������
		if(temp[m+1+i][n+1]==1 || temp[m+1+i][n+1]==9)	WhiteScoreBoard[m][n].info[2].oppnum[0]++;			//��¼ | �����������
		if(temp[m+1+(i+1)][n+1]==2)	WhiteScoreBoard[m][n].info[2].linknum[1]++;
		if(temp[m+1+(i+1)][n+1]==1 || temp[m+1+(i+1)][n+1]==9)	WhiteScoreBoard[m][n].info[2].oppnum[1]++;	
	
	
		for(i=1;temp[m+1-i][n+1]==2;i++)
			WhiteScoreBoard[m][n].info[2].linknum[0]++;
		if(temp[m+1-i][n+1]==1 || temp[m+1-i][n+1]==9)	WhiteScoreBoard[m][n].info[2].oppnum[0]++;
		if(temp[m+1-(i+1)][n+1]==2)	WhiteScoreBoard[m][n].info[2].linknum[1]++;
		if(temp[m+1-(i+1)][n+1]==1 || temp[m+1-(i+1)][n+1]==9)	WhiteScoreBoard[m][n].info[2].oppnum[1]++;
	

		for(i=0;temp[m+1+i][n+1-i]==2;i++)
			WhiteScoreBoard[m][n].info[3].linknum[0]++;					//��¼ \ ��������
		if(temp[m+1+i][n+1-i]==1 || temp[m+1+i][n+1-i]==9)	WhiteScoreBoard[m][n].info[3].oppnum[0]++;		//��¼\�����������
		if(temp[m+1+(i+1)][n+1-(i+1)]==2)	WhiteScoreBoard[m][n].info[3].linknum[1]++;
		if(temp[m+1+(i+1)][n+1-(i+1)]==1 || temp[m+1+(i+1)][n+1-(i+1)]==9)	WhiteScoreBoard[m][n].info[3].oppnum[1]++;
			

		for(i=1;temp[m+1-i][n+1+i]==2;i++)
			WhiteScoreBoard[m][n].info[3].linknum[0]++;
		if(temp[m+1-i][n+1+i]==1 || temp[m+1-i][n+1+i]==9)	WhiteScoreBoard[m][n].info[3].oppnum[0]++;
		if(temp[m+1-(i+1)][n+1+(i+1)]==2)	WhiteScoreBoard[m][n].info[3].linknum[1]++;
		if(temp[m+1-(i+1)][n+1+(i+1)]==1 || temp[m+1-(i+1)][n+1+(i+1)]==9)	WhiteScoreBoard[m][n].info[3].oppnum[1]++;



				
}







