#ifndef _MATRIXHEAD_H_
#define _MATRIXHEAD_H_


#include <stdio.h>
#include <stdlib.h>


//�ļ��������
FILE *fin,*fout;

//�����Ƿ�����
#define OK 1
#define ERROR 0

//�������
#define ADD_ERROR  1
#define SUB_ERROR  2
#define MULT_ERROR 3


//����Ԫ������
typedef int ElemType;


#define MAXSIZE 400 //ϡ��������Ԫ��������
#define MAXRC 20    //ϡ�������������
typedef struct Triple{
    int i,j;    //�÷���Ԫ�����±�����±�
    ElemType e; //�÷���Ԫ��ֵ
}Triple;
typedef struct{
    Triple data[MAXSIZE+1]; //����Ԫ��Ԫ���
    int rpos[MAXRC];        //���е�һ������Ԫ��λ�ñ�
    int mu,nu,tu;           //����������������ͷ���Ԫ����
}RLSMatrix;


//������ļ��ж���һ�м���ʽ
#define MAXLINE 10000
int mygetline(char *str, int lim);


//����ϡ������������
//��ʼ��
int InitRLSMatrix(RLSMatrix *M);
//�������봦��
int GetRLSMatrix(RLSMatrix *M, char *line, int start);
//�����������
int PrintRLSMatrix(RLSMatrix M);
//��������+-*
RLSMatrix addMatrix(RLSMatrix M, RLSMatrix N, int *error);
RLSMatrix subMatrix(RLSMatrix M, RLSMatrix N, int *error);
RLSMatrix multiplyMatrix(RLSMatrix M, RLSMatrix N, int *error);


#endif

