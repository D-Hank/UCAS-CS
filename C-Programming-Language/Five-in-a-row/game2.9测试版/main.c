#include "head.h"

int main()
{
	char model,c;
	//��Ϸ��ʼ��
	system("clear");
	printf("-------welcome to silly gobang---------\n");
	printf("-------Writer:James Zhang--------\n");
	printf("-------made in China copyrights @ 2017K8009922027\n\n");
	printf("choose model:\n");
	printf("input 1 : player vs player\n");printf("input 2 : player vs computer(black)\n");printf("input 3 : player vs computer(white)\n");printf("input 4 : test model\n");
	scanf("%c",&model);

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
	switch(model)
	{
		case '1': playersvs();break;
		case '2': player_vs_computer_black();break;
		case '3': player_vs_computer_white();break;
		case '4': test();break;
	}
	

	return 0;
}

