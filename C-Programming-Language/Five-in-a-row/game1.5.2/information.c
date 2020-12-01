#include "head.h"

void Info(int s[SIZE+1][SIZE+1])
{
//	s[x][y] = 1;			//��������

	int temp[TSIZE][TSIZE];			//����һ�������̣�ʹ����ȫ����סС����
	for(int i=0;i<TSIZE;i++)
		for(int j=0;j<TSIZE;j++)
			temp[i][j]=8;		//��ʼ�������̱߽磬8�Ժ���,������˵���൱��߽�

	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
			temp[i][j]=s[i][j];	//��С���̵�ֵ���Ƶ������������룬ʹ����Χ�����ı߽����
											
	for(int i=0;i<16;i++)			//�������
		for(int j=0;j<16;j++)
			for(int k=0;k<4;k++)
				for(int l=0;l<2;l++){
					BlackScoreBoard[i][j].info[k].linknum[l]=0;
					BlackScoreBoard[i][j].info[k].oppnum[l]=0;
					WhiteScoreBoard[i][j].info[k].linknum[l]=0;
					WhiteScoreBoard[i][j].info[k].oppnum[l]=0;
				}
//��¼˫��������Ϣ

	int m,n,i;

//��¼����������ÿһ�����Ϣ															
/*
	for(m=1;m<16;m++)
	{								//��¼������������
		for(n=1;n<16;n++)
			{	
				for(i=0;temp[m+1][n+1+i]==1;i++)	
					BlackScoreBoard[m][n].info[0].linknum[0]++;
//				if(temp[m+1][n+1+i]==2 || temp[m+1][n+1+i]==8)	
//					BlackScoreBoard[m][n].info[0].oppnum[0]++;
//				if(temp[m+1][n+1+i+1]==1)	
//					BlackScoreBoard[m][n].info[0].linknum[1]++;
//				if(temp[m+1][n+1+i+1]==2 || temp[m+1][n+1+i+1]==8)	
//					BlackScoreBoard[m][n].info[0].oppnum[1]++;			
			}
	}

	for(m=1;m<16;m++)
	{
		for(n=1;n<16;n++)
			{
				for(i=1;temp[m+1][n+1-i]==1;i++)	
					BlackScoreBoard[m][n].info[0].linknum[0]++;
//				if(temp[m+1][n+1-i]==2 || temp[m+1][n+1-i]==8)	
//					BlackScoreBoard[m][n].info[0].oppnum[0]++;
//				if(temp[m+1][n+1-i-1]==1)	
//					BlackScoreBoard[m][n].info[0].linknum[1]++;
//				if(temp[m+1][n+1-i-1]==2 || temp[m+1][n+1-i-1]==8)	
//					BlackScoreBoard[m][n].info[0].oppnum[1]++;
			}
	}

	for(m=1;m<16;m++)								//��¼ / ��������					
	{
		for(n=1;n<16;n++)
			{	
				for(i=0;temp[m+1+i][n+1+i]==1;i++)	
					BlackScoreBoard[m][n].info[1].linknum[0]++;
/*				if(temp[m+1+i][n+1+i]==2 || temp[m+1+i][n+1+i]==8)	
					BlackScoreBoard[m][n].info[1].oppnum[0]++;
				if(temp[m+1+i+1][n+1+i+1]==1)	
					BlackScoreBoard[m][n].info[1].linknum[1]++;
				if(temp[m+1+i+1][n+1+i+1]==2 || temp[m+1+i+1][n+1+i+1]==8)	
					BlackScoreBoard[m][n].info[1].oppnum[1]++;			
			}
	}
		
	for(m=1;m<16;m++)
	{
		for(n=1;n<16;n++)
			{
				for(i=1;temp[m+1-i][n+1-i]==1;i++)	
					BlackScoreBoard[m][n].info[1].linknum[0]++;
/*				if(temp[m+1-i][n+1-i]==2 || temp[m+1-i][n+1-i]==8)	
					BlackScoreBoard[m][n].info[1].oppnum[0]++;
				if(temp[m+1-i-1][n+1-i-1]==1)	
					BlackScoreBoard[m][n].info[1].linknum[1]++;
				if(temp[m+1-i-1][n+1-i-1]==2 || temp[m+1-i-1][n+1-i-1]==8)	
					BlackScoreBoard[m][n].info[1].oppnum[1]++;
			}
	}

	for(m=1;m<16;m++)
	{								//��¼ | ��������
		for(n=1;n<16;n++)
			{	
				for(i=0;temp[m+1+i][n+1]==1;i++)	
					BlackScoreBoard[m][n].info[2].linknum[0]++;
/*				if(temp[m+1+i][n+1]==2 || temp[m+1+i][n+1]==8)	
					BlackScoreBoard[m][n].info[2].oppnum[0]++;
				if(temp[m+1+i+1][n+1]==1)	
					BlackScoreBoard[m][n].info[2].linknum[1]++;
				if(temp[m+1+i+1][n+1]==2 || temp[m+1+i+1][n+1]==8)	
					BlackScoreBoard[m][n].info[2].oppnum[1]++;			
			}
	}
		
	for(m=1;m<16;m++)
	{
		for(n=1;n<16;n++)
			{
				for(i=1;temp[m+1-i][n+1]==1;i++)	
					BlackScoreBoard[m][n].info[2].linknum[0]++;
/*				if(temp[m+1-i][n+1]==2 || temp[m+1-i][n+1]==8)	
					BlackScoreBoard[m][n].info[2].oppnum[0]++;
				if(temp[m+1-i-1][n+1]==1)	
					BlackScoreBoard[m][n].info[2].linknum[1]++;
				if(temp[m+1-i-1][n+1]==2 || temp[m+1-i-1][n+1]==8)	
					BlackScoreBoard[m][n].info[2].oppnum[1]++;
			}
	}

	for(m=1;m<16;m++)								//��¼ \ ��������					
	{
		for(n=1;n<16;n++)
			{	
				for(i=0;temp[m+1+i][n+1-i]==1;i++)	
					BlackScoreBoard[m][n].info[0].linknum[0]++;
/*				if(temp[m+1+i][n+1-i]==2 || temp[m+1+i][n+1-i]==8)	
					BlackScoreBoard[m][n].info[0].oppnum[0]++;
				if(temp[m+1+i+1][n+1-i-1]==1)	
					BlackScoreBoard[m][n].info[0].linknum[1]++;
				if(temp[m+1+i+1][n+1-i-1]==2 || temp[m+1+i+1][n+1-i-1]==8)	
					BlackScoreBoard[m][n].info[0].oppnum[1]++;			
			}
	}
	
	for(m=1;m<16;m++)
	{	
		for(n=1;n<16;n++)
			{
				for(i=1;temp[m+1-i][n+1+i]==1;i++)	
					BlackScoreBoard[m][n].info[0].linknum[0]++;
/*				if(temp[m+1-i][n+1+i]==2 || temp[m+1-i][n+1+i]==8)	
					BlackScoreBoard[m][n].info[0].oppnum[0]++;
				if(temp[m+1-i-1][n+1+i+1]==1)	
					BlackScoreBoard[m][n].info[0].linknum[1]++;
				if(temp[m+1-i-1][n+1+i+1]==2 || temp[m+1-i-1][n+1+i+1]==8)	
					BlackScoreBoard[m][n].info[0].oppnum[1]++;
			}
	}
*/
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m][n+i]==1;i++)	BlackScoreBoard[m][n].info[0].linknum[0]++;		//��¼������������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n-i]==1;i++)	BlackScoreBoard[m][n].info[0].linknum[0]++;
							
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n+i]==1;i++)	BlackScoreBoard[m][n].info[1].linknum[0]++;		//��¼ / ��������	
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n-i]==1;i++)	BlackScoreBoard[m][n].info[1].linknum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n]==1;i++)	BlackScoreBoard[m][n].info[2].linknum[0]++;		//��¼ | ��������	
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n]==1;i++)	BlackScoreBoard[m][n].info[2].linknum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n-i]==1;i++)	BlackScoreBoard[m][n].info[3].linknum[0]++;		//��¼ \ ��������	
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n+i]==1;i++)	BlackScoreBoard[m][n].info[3].linknum[0]++;

	
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m][n+i]==1;i++)	;	if(temp[m][n+i]==2)	BlackScoreBoard[m][n].info[0].oppnum[0]++;		//��¼���������������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n-i]==1;i++)	;	if(temp[m][n-i]==2)	BlackScoreBoard[m][n].info[0].oppnum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n+i]==1;i++)	;	if(temp[m+i][n+i]==2)	BlackScoreBoard[m][n].info[1].oppnum[0]++;		//��¼/�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n-i]==1;i++)	;	if(temp[m-i][n-i]==2)	BlackScoreBoard[m][n].info[1].oppnum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n]==1;i++)	;	if(temp[m+i][n]==2)	BlackScoreBoard[m][n].info[2].oppnum[0]++;		//��¼ | �����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n]==1;i++)	;	if(temp[m-i][n]==2)	BlackScoreBoard[m][n].info[2].oppnum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n-i]==1;i++)	;	if(temp[m-i][n-i]==2)	BlackScoreBoard[m][n].info[3].oppnum[0]++;		//��¼\�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n+i]==1;i++)	;	if(temp[m+i][n+i]==2)	BlackScoreBoard[m][n].info[3].oppnum[0]++;



//��¼����������ÿһ�����Ϣ
/*
	for(m=1;m<16;m++)								//��¼������������
		for(n=1;n<16;n++)
			{	
				for(i=0;temp[m+1][n+1+i]==1;i++)	
					WhiteScoreBoard[m][n].info[0].linknum[0]++;
				if(temp[m+1][n+1+i]==2 || temp[m+1][n+1+i]==8)	
					WhiteScoreBoard[m][n].info[0].oppnum[0]++;
				if(temp[m+1][n+1+i+1]==1)	
					WhiteScoreBoard[m][n].info[0].linknum[1]++;
				if(temp[m+1][n+1+i+1]==2 || temp[m+1][n+1+i+1]==8)	
					WhiteScoreBoard[m][n].info[0].oppnum[1]++;			
			}
		
	for(m=1;m<16;m++)
		for(n=1;n<16;n++)
			{
				for(i=1;temp[m+1][n+1-i]==1;i++)	
					WhiteScoreBoard[m][n].info[0].linknum[0]++;
				if(temp[m+1][n+1-i]==2 || temp[m+1][n+1-i]==8)	
					WhiteScoreBoard[m][n].info[0].oppnum[0]++;
				if(temp[m+1][n+1-i-1]==1)	
					WhiteScoreBoard[m][n].info[0].linknum[1]++;
				if(temp[m+1][n+1-i-1]==2 || temp[m+1][n+1-i-1]==8)	
					WhiteScoreBoard[m][n].info[0].oppnum[1]++;
			}

	for(m=1;m<16;m++)								//��¼ / ��������					
		for(n=1;n<16;n++)
			{	
				for(i=0;temp[m+1+i][n+1+i]==1;i++)	
					WhiteScoreBoard[m][n].info[1].linknum[0]++;
				if(temp[m+1+i][n+1+i]==2 || temp[m+1+i][n+1+i]==8)	
					WhiteScoreBoard[m][n].info[1].oppnum[0]++;
				if(temp[m+1+i+1][n+1+i+1]==1)	
					WhiteScoreBoard[m][n].info[1].linknum[1]++;
				if(temp[m+1+i+1][n+1+i+1]==2 || temp[m+1+i+1][n+1+i+1]==8)	
					WhiteScoreBoard[m][n].info[1].oppnum[1]++;			
			}
		
	for(m=1;m<16;m++)
		for(n=1;n<16;n++)
			{
				for(i=1;temp[m+1-i][n+1-i]==1;i++)	
					WhiteScoreBoard[m][n].info[1].linknum[0]++;
				if(temp[m+1-i][n+1-i]==2 || temp[m+1-i][n+1-i]==8)	
					WhiteScoreBoard[m][n].info[1].oppnum[0]++;
				if(temp[m+1-i-1][n+1-i-1]==1)	
					WhiteScoreBoard[m][n].info[1].linknum[1]++;
				if(temp[m+1-i-1][n+1-i-1]==2 || temp[m+1-i-1][n+1-i-1]==8)	
					WhiteScoreBoard[m][n].info[1].oppnum[1]++;
			}

	for(m=1;m<16;m++)								//��¼ | ��������
		for(n=1;n<16;n++)
			{	
				for(i=0;temp[m+1+i][n+1]==1;i++)	
					WhiteScoreBoard[m][n].info[2].linknum[0]++;
				if(temp[m+1+i][n+1]==2 || temp[m+1+i][n+1]==8)	
					WhiteScoreBoard[m][n].info[2].oppnum[0]++;
				if(temp[m+1+i+1][n+1]==1)	
					WhiteScoreBoard[m][n].info[2].linknum[1]++;
				if(temp[m+1+i+1][n+1]==2 || temp[m+1+i+1][n+1]==8)	
					WhiteScoreBoard[m][n].info[2].oppnum[1]++;			
			}
		
	for(m=1;m<16;m++)
		for(n=1;n<16;n++)
			{
				for(i=1;temp[m+1-i][n+1]==1;i++)	
					WhiteScoreBoard[m][n].info[2].linknum[0]++;
				if(temp[m+1-i][n+1]==2 || temp[m+1-i][n+1]==8)	
					WhiteScoreBoard[m][n].info[2].oppnum[0]++;
				if(temp[m+1-i-1][n+1]==1)	
					WhiteScoreBoard[m][n].info[2].linknum[1]++;
				if(temp[m+1-i-1][n+1]==2 || temp[m+1-i-1][n+1]==8)	
					WhiteScoreBoard[m][n].info[2].oppnum[1]++;
			}

	for(m=1;m<16;m++)								//��¼ \ ��������					
		for(n=1;n<16;n++)
			{	
				for(i=0;temp[m+1+i][n+1-i]==1;i++)	
					WhiteScoreBoard[m][n].info[0].linknum[0]++;
				if(temp[m+1+i][n+1-i]==2 || temp[m+1+i][n+1-i]==8)	
					WhiteScoreBoard[m][n].info[0].oppnum[0]++;
				if(temp[m+1+i+1][n+1-i-1]==1)	
					WhiteScoreBoard[m][n].info[0].linknum[1]++;
				if(temp[m+1+i+1][n+1-i-1]==2 || temp[m+1+i+1][n+1-i-1]==8)	
					WhiteScoreBoard[m][n].info[0].oppnum[1]++;			
			}
		
	for(m=1;m<16;m++)
		for(n=1;n<16;n++)
			{
				for(i=1;temp[m+1-i][n+1+i]==1;i++)	
					WhiteScoreBoard[m][n].info[0].linknum[0]++;
				if(temp[m+1-i][n+1+i]==2 || temp[m+1-i][n+1+i]==8)	
					WhiteScoreBoard[m][n].info[0].oppnum[0]++;
				if(temp[m+1-i-1][n+1+i+1]==1)	
					WhiteScoreBoard[m][n].info[0].linknum[1]++;
				if(temp[m+1-i-1][n+1+i+1]==2 || temp[m+1-i-1][n+1+i+1]==8)	
					WhiteScoreBoard[m][n].info[0].oppnum[1]++;
			}

*/


	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m][n+i]==2;i++)	WhiteScoreBoard[m][n].info[0].linknum[0]++;		//��¼������������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n-i]==2;i++)	WhiteScoreBoard[m][n].info[0].linknum[0]++;
										
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n+i]==2;i++)	WhiteScoreBoard[m][n].info[1].linknum[0]++;		//��¼ / ��������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n-i]==2;i++)	WhiteScoreBoard[m][n].info[1].linknum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n]==2;i++)	WhiteScoreBoard[m][n].info[2].linknum[0]++;		//��¼ | ��������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n]==2;i++)	WhiteScoreBoard[m][n].info[2].linknum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n-i]==2;i++)	WhiteScoreBoard[m][n].info[3].linknum[0]++;		//��¼ \ ��������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n+i]==2;i++)	WhiteScoreBoard[m][n].info[3].linknum[0]++;

	
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m][n+i]==2;i++)	;	if(temp[m][n+i]==1)	WhiteScoreBoard[m][n].info[0].oppnum[0]++;		//��¼���������������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n-i]==2;i++)	;	if(temp[m][n-i]==1)	WhiteScoreBoard[m][n].info[0].oppnum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n+i]==2;i++)	;	if(temp[m+i][n+i]==1)	WhiteScoreBoard[m][n].info[1].oppnum[0]++;		//��¼/�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n-i]==2;i++)	;	if(temp[m-i][n-i]==1)	WhiteScoreBoard[m][n].info[1].oppnum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n]==2;i++)	;	if(temp[m+i][n]==1)	WhiteScoreBoard[m][n].info[2].oppnum[0]++;		//��¼ | �����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n]==2;i++)	;	if(temp[m-i][n]==1)	WhiteScoreBoard[m][n].info[2].oppnum[0]++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=0;temp[m+i][n-i]==2;i++)	;	if(temp[m-i][n-i]==1)	WhiteScoreBoard[m][n].info[3].oppnum[0]++;		//��¼\�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n+i]==2;i++)	;	if(temp[m+i][n+i]==1)	WhiteScoreBoard[m][n].info[3].oppnum[0]++;


				
}

