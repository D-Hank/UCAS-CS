#include "head.h"

int main()
{
	char model,c;
	//��Ϸ��ʼ��
	system("clear");
	//��ʼ������ʾ��Ϸ�Ļ�����Ϣ
	printf("-------welcome to silly gobang---------\n");
	printf("-------Writer: Zhang Lei--------\n");
	printf("-------made in China copyrights @ 2017K8009922027\n\n");
	printf("choose model:\n");
	printf("input 1 : player vs player\n");printf("input 2 : player vs computer(black)\n");printf("input 3 : player vs computer(white)\n");printf("input 4 : test model\n");
	scanf("%c",&model);

	//��ʼ����ʾ������
	initRecordBorard();
	recordtoDisplayArray();
	displayBoard();		
	printf("-----game start-----\n");
	printf("input q to quilt, and others to continue:");	
	c=getchar();
	if(c=='q'||c=='Q'||c==EOF)
		return 0;
	else
		;
	//ѡ����Ϸģʽ
	switch(model)
	{
		case '1': playersvs();break;				//��Ҷ�ս
		case '2': player_vs_computer_black();break;		//�˻���ս������ִ��
		case '3': player_vs_computer_white();break;		//�˼ʶ�ս������ִ��
		case '4': test();break;					//�����ߵ���ģʽ
	}
	

	return 0;
}

