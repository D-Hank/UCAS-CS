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
			for(int k=0;k<4;k++){
				MyScoreBoard[i][j].info[k].linknum=0;
				MyScoreBoard[i][j].info[k].oppnum=0;
				OppScoreBoard[i][j].info[k].linknum=0;
				OppScoreBoard[i][j].info[k].oppnum=0;
			}
//��¼˫��������Ϣ

	int m,n,i;

//��¼����������ÿһ�����Ϣ

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m][n+i]==2;i++)	OppScoreBoard[m][n].info[0].linknum++;		//��¼������������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m][n-i]==2;i++)	OppScoreBoard[m][n].info[0].linknum++;
										
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n+i]==2;i++)	OppScoreBoard[m][n].info[1].linknum++;		//��¼ / ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n-i]==2;i++)	OppScoreBoard[m][n].info[1].linknum++;

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n]==2;i++)	OppScoreBoard[m][n].info[2].linknum++;		//��¼ | ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n]==2;i++)	OppScoreBoard[m][n].info[2].linknum++;

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n-i]==2;i++)	OppScoreBoard[m][n].info[3].linknum++;		//��¼ \ ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n+i]==2;i++)	OppScoreBoard[m][n].info[3].linknum++;

	
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n+i]==2;i++)	;	if(temp[m][n+i]==1)	OppScoreBoard[m][n].info[0].oppnum++;		//��¼���������������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n-i]==2;i++)	;	if(temp[m][n-i]==1)	OppScoreBoard[m][n].info[0].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n+i]==2;i++)	;	if(temp[m+i][n+i]==1)	OppScoreBoard[m][n].info[1].oppnum++;		//��¼/�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n-i]==2;i++)	;	if(temp[m-i][n-i]==1)	OppScoreBoard[m][n].info[1].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n]==2;i++)	;	if(temp[m+i][n]==1)	OppScoreBoard[m][n].info[2].oppnum++;		//��¼ | �����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n]==2;i++)	;	if(temp[m-i][n]==1)	OppScoreBoard[m][n].info[2].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n-i]==2;i++)	;	if(temp[m-i][n-i]==1)	OppScoreBoard[m][n].info[3].oppnum++;		//��¼\�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n+i]==2;i++)	;	if(temp[m+i][n+i]==1)	OppScoreBoard[m][n].info[3].oppnum++;

//��¼����������ÿһ�����Ϣ

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m][n+i]==1;i++)	MyScoreBoard[m][n].info[0].linknum++;		//��¼������������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m][n-i]==1;i++)	MyScoreBoard[m][n].info[0].linknum++;
										
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n+i]==1;i++)	MyScoreBoard[m][n].info[1].linknum++;		//��¼ / ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n-i]==1;i++)	MyScoreBoard[m][n].info[1].linknum++;

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n]==1;i++)	MyScoreBoard[m][n].info[2].linknum++;		//��¼ | ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n]==1;i++)	MyScoreBoard[m][n].info[2].linknum++;

	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m+i][n-i]==1;i++)	MyScoreBoard[m][n].info[3].linknum++;		//��¼ \ ��������
	for(int m=1;m<16;m++)	for(int n=1;n<16;n++)	for(int i=1;temp[m-i][n+i]==1;i++)	MyScoreBoard[m][n].info[3].linknum++;

	
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n+i]==1;i++)	;	if(temp[m][n+i]==2)	MyScoreBoard[m][n].info[0].oppnum++;		//��¼���������������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m][n-i]==1;i++)	;	if(temp[m][n-i]==2)	MyScoreBoard[m][n].info[0].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n+i]==1;i++)	;	if(temp[m+i][n+i]==2)	MyScoreBoard[m][n].info[1].oppnum++;		//��¼/�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n-i]==1;i++)	;	if(temp[m-i][n-i]==2)	MyScoreBoard[m][n].info[1].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n]==1;i++)	;	if(temp[m+i][n]==2)	MyScoreBoard[m][n].info[2].oppnum++;		//��¼ | �����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n]==1;i++)	;	if(temp[m-i][n]==2)	MyScoreBoard[m][n].info[2].oppnum++;

	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m+i][n-i]==1;i++)	;	if(temp[m-i][n-i]==2)	MyScoreBoard[m][n].info[3].oppnum++;		//��¼\�����������
	for(m=1;m<16;m++)	for(n=1;n<16;n++)	for(i=1;temp[m-i][n+i]==1;i++)	;	if(temp[m+i][n+i]==2)	MyScoreBoard[m][n].info[3].oppnum++;

/*	for(int i=0;i<4;i++)					//�жϳ�������
	if(MyScoreBoard[m][n].info[i].linknum>4)
		return long_connect;
*/
//33����
//44����



				
}

