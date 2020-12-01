#include "head.h"

void Info(int s[SIZE+1][SIZE+1],int m,int n)
{
	int temp[TSIZE][TSIZE];			//����һ�������̣�ʹ����ȫ����סС����
	for(int i=0;i<TSIZE;i++)
		for(int j=0;j<TSIZE;j++)
			temp[i][j]=9;		//��ʼ�������̱߽磬9�Ժ���,������˵����������

	for(int i=0;i<TSIZE;i++)		//�������8Χס
		temp[0][i]=8;

	for(int i=0;i<TSIZE;i++)
		temp[18][i]=8;

	for(int i=0;i<TSIZE;i++)
		temp[i][0]=8;

	for(int i=0;i<TSIZE;i++)
		temp[i][18]=8;


	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
			temp[i+1][j+1]=s[i][j];	//��С���̵�ֵ���Ƶ������������룬ʹ����Χ�����ı߽����
											
	for(int k=0;k<8;k++)	//�������
		for(int l=0;l<2;l++){
			BlackScoreBoard[m][n].info[k].linknum[l]=0;
			BlackScoreBoard[m][n].info[k].oppnum[l]=0;
			BlackScoreBoard[m][n].info[k].nullnum[l]=0;
			WhiteScoreBoard[m][n].info[k].linknum[l]=0;
			WhiteScoreBoard[m][n].info[k].oppnum[l]=0;
			WhiteScoreBoard[m][n].info[k].nullnum[l]=0;
		}

//��¼˫��������Ϣ

		int i,k;

//��¼����������ÿһ�����Ϣ															


	
		for(i=0;temp[m+1][n+1+i]==1;i++)
			BlackScoreBoard[m][n].info[0].linknum[0]++;			//��¼������������
		while(temp[m+1][n+1+i]==0)	{BlackScoreBoard[m][n].info[0].nullnum[0]++;i++;}
		while(temp[m+1][n+1+i]==2 || temp[m+1][n+1+i]==9)	{BlackScoreBoard[m][n].info[0].oppnum[0]++;	i++;}

		while(temp[m+1][n+1+i]==1)	{BlackScoreBoard[m][n].info[0].linknum[1]++;	i++;}
		while(temp[m+1][n+1+i]==0)	{BlackScoreBoard[m][n].info[0].nullnum[1]++;i++;}
		while(temp[m+1][n+1+i]==2 || temp[m+1][n+1+i]==9)	{BlackScoreBoard[m][n].info[0].oppnum[1]++;	i++;}	//��¼���������������
		
	
		for(i=1;temp[m+1][n+1-i]==1;i++)
			BlackScoreBoard[m][n].info[4].linknum[0]++;

		while(temp[m+1][n+1-i]==0)	{BlackScoreBoard[m][n].info[4].nullnum[0]++;i++;}
		while(temp[m+1][n+1-i]==2 || temp[m+1][n+1-i]==9)	{BlackScoreBoard[m][n].info[4].oppnum[0]++;	i++;}

		while(temp[m+1][n+1-i]==1)	{BlackScoreBoard[m][n].info[4].linknum[1]++;	i++;}
		while(temp[m+1][n+1-i]==0)	{BlackScoreBoard[m][n].info[4].nullnum[1]++;i++;}
		while(temp[m+1][n+1-i]==2 || temp[m+1][n+1-i]==9)	{BlackScoreBoard[m][n].info[4].oppnum[1]++;	i++;}	
		
	
										
		for(i=0;temp[m+1+i][n+1+i]==1;i++)
			BlackScoreBoard[m][n].info[1].linknum[0]++;					//��¼ / ��������

		while(temp[m+1+i][n+1+i]==0)	{BlackScoreBoard[m][n].info[1].nullnum[0]++;i++;}
		while(temp[m+1+i][n+1+i]==2 || temp[m+1+i][n+1+i]==9)	{BlackScoreBoard[m][n].info[1].oppnum[0]++;	i++;}

		while(temp[m+1+i][n+1+i]==1)	{BlackScoreBoard[m][n].info[1].linknum[1]++;	i++;}
		while(temp[m+1+i][n+1+i]==0)	{BlackScoreBoard[m][n].info[1].nullnum[1]++;i++;}
		while(temp[m+1+i][n+1+i]==2 || temp[m+1+i][n+1+i]==9)	{BlackScoreBoard[m][n].info[1].oppnum[1]++;	i++;}	

	
		for(i=1;temp[m+1-i][n+1-i]==1;i++)
			BlackScoreBoard[m][n].info[5].linknum[0]++;

		while(temp[m+1-i][n+1-i]==0)	{BlackScoreBoard[m][n].info[5].nullnum[0]++;i++;}
		while(temp[m+1-i][n+1-i]==2 || temp[m+1-i][n+1-i]==9)	{BlackScoreBoard[m][n].info[5].oppnum[0]++;	i++;}

		while(temp[m+1-i][n+1-i]==1)	{BlackScoreBoard[m][n].info[5].linknum[1]++;	i++;}
		while(temp[m+1-i][n+1-i]==0)	{BlackScoreBoard[m][n].info[5].nullnum[1]++;i++;}
		while(temp[m+1-i][n+1-i]==2 || temp[m+1-i][n+1-i]==9)	{BlackScoreBoard[m][n].info[5].oppnum[1]++;	i++;}	

	
		for(i=0;temp[m+1+i][n+1]==1;i++)
			BlackScoreBoard[m][n].info[2].linknum[0]++;					//��¼ | ��������

		while(temp[m+1+i][n+1]==0)	{BlackScoreBoard[m][n].info[2].nullnum[0]++;i++;}
		while(temp[m+1+i][n+1]==2 || temp[m+1+i][n+1]==9)	{BlackScoreBoard[m][n].info[2].oppnum[0]++;	i++;}

		while(temp[m+1+i][n+1]==1)	{BlackScoreBoard[m][n].info[2].linknum[1]++;	i++;}
		while(temp[m+1+i][n+1]==0)	{BlackScoreBoard[m][n].info[2].nullnum[1]++;i++;}
		while(temp[m+1+i][n+1]==2 || temp[m+1+i][n+1]==9)	{BlackScoreBoard[m][n].info[2].oppnum[1]++;	i++;}	


	
		for(i=1;temp[m+1-i][n+1]==1;i++)
			BlackScoreBoard[m][n].info[6].linknum[0]++;

		while(temp[m+1-i][n+1]==0)	{BlackScoreBoard[m][n].info[6].nullnum[0]++;i++;}
		while(temp[m+1-i][n+1]==2 || temp[m+1-i][n+1]==9)	{BlackScoreBoard[m][n].info[6].oppnum[0]++;	i++;}

		while(temp[m+1-i][n+1]==1)	{BlackScoreBoard[m][n].info[6].linknum[1]++;	i++;}
		while(temp[m+1-i][n+1]==0)	{BlackScoreBoard[m][n].info[6].nullnum[1]++;i++;}
		while(temp[m+1-i][n+1]==2 || temp[m+1-i][n+1]==9)	{BlackScoreBoard[m][n].info[6].oppnum[1]++;	i++;}	

	

		for(i=0;temp[m+1+i][n+1-i]==1;i++)
			BlackScoreBoard[m][n].info[3].linknum[0]++;					//��¼ \ ��������

		while(temp[m+1+i][n+1-i]==0)	{BlackScoreBoard[m][n].info[3].nullnum[0]++;i++;}
		while(temp[m+1+i][n+1-i]==2 || temp[m+1+i][n+1-i]==9)	{BlackScoreBoard[m][n].info[3].oppnum[0]++;	i++;}

		while(temp[m+1+i][n+1-i]==1)	{BlackScoreBoard[m][n].info[3].linknum[1]++;	i++;}
		while(temp[m+1+i][n+1-i]==0)	{BlackScoreBoard[m][n].info[3].nullnum[1]++;i++;}
		while(temp[m+1+i][n+1-i]==2 || temp[m+1+i][n+1-i]==9)	{BlackScoreBoard[m][n].info[3].oppnum[1]++;	i++;}	
			

		for(i=1;temp[m+1-i][n+1+i]==1;i++)
			BlackScoreBoard[m][n].info[7].linknum[0]++;

		while(temp[m+1-i][n+1+i]==0)	{BlackScoreBoard[m][n].info[7].nullnum[0]++;i++;}
		while(temp[m+1-i][n+1+i]==2 || temp[m+1-i][n+1+i]==9)	{BlackScoreBoard[m][n].info[7].oppnum[0]++;	i++;}

		while(temp[m+1-i][n+1+i]==1)	{BlackScoreBoard[m][n].info[7].linknum[1]++;	i++;}
		while(temp[m+1-i][n+1+i]==0)	{BlackScoreBoard[m][n].info[7].nullnum[1]++;i++;}
		while(temp[m+1-i][n+1+i]==2 || temp[m+1-i][n+1+i]==9)	{BlackScoreBoard[m][n].info[7].oppnum[1]++;	i++;}	


//��¼����������ÿһ�����Ϣ


	
		for(i=0;temp[m+1][n+1+i]==2;i++)
			WhiteScoreBoard[m][n].info[0].linknum[0]++;			//��¼������������
		while(temp[m+1][n+1+i]==0)	{WhiteScoreBoard[m][n].info[0].nullnum[0]++;i++;}
		while(temp[m+1][n+1+i]==1 || temp[m+1][n+1+i]==9)	{WhiteScoreBoard[m][n].info[0].oppnum[0]++;	i++;}

		while(temp[m+1][n+1+i]==2)	{WhiteScoreBoard[m][n].info[0].linknum[1]++;	i++;}
		while(temp[m+1][n+1+i]==0)	{WhiteScoreBoard[m][n].info[0].nullnum[1]++;i++;}
		while(temp[m+1][n+1+i]==1 || temp[m+1][n+1+i]==9)	{WhiteScoreBoard[m][n].info[0].oppnum[1]++;	i++;}	//��¼���������������
		
	
		for(i=1;temp[m+1][n+1-i]==2;i++)
			WhiteScoreBoard[m][n].info[4].linknum[0]++;

		while(temp[m+1][n+1-i]==0)	{WhiteScoreBoard[m][n].info[4].nullnum[0]++;i++;}
		while(temp[m+1][n+1-i]==1 || temp[m+1][n+1-i]==9)	{WhiteScoreBoard[m][n].info[4].oppnum[0]++;	i++;}

		while(temp[m+1][n+1-i]==2)	{WhiteScoreBoard[m][n].info[4].linknum[1]++;	i++;}
		while(temp[m+1][n+1-i]==0)	{WhiteScoreBoard[m][n].info[4].nullnum[1]++;i++;}
		while(temp[m+1][n+1-i]==1 || temp[m+1][n+1-i]==9)	{WhiteScoreBoard[m][n].info[4].oppnum[1]++;	i++;}	
		
	
										
		for(i=0;temp[m+1+i][n+1+i]==2;i++)
			WhiteScoreBoard[m][n].info[1].linknum[0]++;					//��¼ / ��������

		while(temp[m+1+i][n+1+i]==0)	{WhiteScoreBoard[m][n].info[1].nullnum[0]++;i++;}
		while(temp[m+1+i][n+1+i]==1 || temp[m+1+i][n+1+i]==9)	{WhiteScoreBoard[m][n].info[1].oppnum[0]++;	i++;}

		while(temp[m+1+i][n+1+i]==2)	{WhiteScoreBoard[m][n].info[1].linknum[1]++;	i++;}
		while(temp[m+1+i][n+1+i]==0)	{WhiteScoreBoard[m][n].info[1].nullnum[1]++;i++;}
		while(temp[m+1+i][n+1+i]==1 || temp[m+1+i][n+1+i]==9)	{WhiteScoreBoard[m][n].info[1].oppnum[1]++;	i++;}	

	
		for(i=1;temp[m+1-i][n+1-i]==2;i++)
			WhiteScoreBoard[m][n].info[5].linknum[0]++;

		while(temp[m+1-i][n+1-i]==0)	{WhiteScoreBoard[m][n].info[5].nullnum[0]++;i++;}
		while(temp[m+1-i][n+1-i]==1 || temp[m+1-i][n+1-i]==9)	{WhiteScoreBoard[m][n].info[5].oppnum[0]++;	i++;}

		while(temp[m+1-i][n+1-i]==2)	{WhiteScoreBoard[m][n].info[5].linknum[1]++;	i++;}
		while(temp[m+1-i][n+1-i]==0)	{WhiteScoreBoard[m][n].info[5].nullnum[1]++;i++;}
		while(temp[m+1-i][n+1-i]==1 || temp[m+1-i][n+1-i]==9)	{WhiteScoreBoard[m][n].info[5].oppnum[1]++;	i++;}	

	
		for(i=0;temp[m+1+i][n+1]==2;i++)
			WhiteScoreBoard[m][n].info[2].linknum[0]++;					//��¼ | ��������

		while(temp[m+1+i][n+1]==0)	{WhiteScoreBoard[m][n].info[2].nullnum[0]++;i++;}
		while(temp[m+1+i][n+1]==1 || temp[m+1+i][n+1]==9)	{WhiteScoreBoard[m][n].info[2].oppnum[0]++;	i++;}

		while(temp[m+1+i][n+1]==2)	{WhiteScoreBoard[m][n].info[2].linknum[1]++;	i++;}
		while(temp[m+1+i][n+1]==0)	{WhiteScoreBoard[m][n].info[2].nullnum[1]++;i++;}
		while(temp[m+1+i][n+1]==1 || temp[m+1+i][n+1]==9)	{WhiteScoreBoard[m][n].info[2].oppnum[1]++;	i++;}	


	
		for(i=1;temp[m+1-i][n+1]==2;i++)
			WhiteScoreBoard[m][n].info[6].linknum[0]++;

		while(temp[m+1-i][n+1]==0)	{WhiteScoreBoard[m][n].info[6].nullnum[0]++;i++;}
		while(temp[m+1-i][n+1]==1 || temp[m+1-i][n+1]==9)	{WhiteScoreBoard[m][n].info[6].oppnum[0]++;	i++;}

		while(temp[m+1-i][n+1]==2)	{WhiteScoreBoard[m][n].info[6].linknum[1]++;	i++;}
		while(temp[m+1-i][n+1]==0)	{WhiteScoreBoard[m][n].info[6].nullnum[1]++;i++;}
		while(temp[m+1-i][n+1]==1 || temp[m+1-i][n+1]==9)	{WhiteScoreBoard[m][n].info[6].oppnum[1]++;	i++;}	

	

		for(i=0;temp[m+1+i][n+1-i]==2;i++)
			WhiteScoreBoard[m][n].info[3].linknum[0]++;					//��¼ \ ��������

		while(temp[m+1+i][n+1-i]==0)	{WhiteScoreBoard[m][n].info[3].nullnum[0]++;i++;}
		while(temp[m+1+i][n+1-i]==1 || temp[m+1+i][n+1-i]==9)	{WhiteScoreBoard[m][n].info[3].oppnum[0]++;	i++;}

		while(temp[m+1+i][n+1-i]==2)	{WhiteScoreBoard[m][n].info[3].linknum[1]++;	i++;}
		while(temp[m+1+i][n+1-i]==0)	{WhiteScoreBoard[m][n].info[3].nullnum[1]++;i++;}
		while(temp[m+1+i][n+1-i]==1 || temp[m+1+i][n+1-i]==9)	{WhiteScoreBoard[m][n].info[3].oppnum[1]++;	i++;}	
			

		for(i=1;temp[m+1-i][n+1+i]==2;i++)
			WhiteScoreBoard[m][n].info[7].linknum[0]++;

		while(temp[m+1-i][n+1+i]==0)	{WhiteScoreBoard[m][n].info[7].nullnum[0]++;i++;}
		while(temp[m+1-i][n+1+i]==1 || temp[m+1-i][n+1+i]==9)	{WhiteScoreBoard[m][n].info[7].oppnum[0]++;	i++;}

		while(temp[m+1-i][n+1+i]==2)	{WhiteScoreBoard[m][n].info[7].linknum[1]++;	i++;}
		while(temp[m+1-i][n+1+i]==0)	{WhiteScoreBoard[m][n].info[7].nullnum[1]++;i++;}
		while(temp[m+1-i][n+1+i]==1 || temp[m+1-i][n+1+i]==9)	{WhiteScoreBoard[m][n].info[7].oppnum[1]++;	i++;}	




				
}







