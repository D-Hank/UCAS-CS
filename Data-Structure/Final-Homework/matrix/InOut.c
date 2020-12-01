#include "MatrixHead.h"
extern FILE *fin,*fout;

//����һ�м���ʽ
int mygetline(char *str, int lim)
{
    int len=0,c;
    while((--lim>0) && ((c=getc(fin))!=EOF) && (c!='\n'))
        str[len++]=c;
    if(c=='\n')
        str[len++]='\n';
    str[len]='\0';
    return len;
}


int GetRLSMatrix(RLSMatrix *M, char *line, int start)
{
//���ݶ��������ʽline����������ȷ���ľ�����ʼλ��start
//�õ�ϡ�����M��������

    int k;  //k��ʾ��ǰ�ַ���line�е��±�
    int i,j,e,mu,nu,tu;
    int ispositive; //ispositive�ж�ֵ�ķ���
    int s;  //s��ʾ��ǰ�õ���������Ԫ��()��λ��
    int isrpos;
    char c;

    k = start;

    //�õ����������������
    mu = 0; k++;
    while((c=*(line+k)) != ';'){    //mu�������
        if(c>='0' && c<='9') { mu = mu*10+c-'0'; }
        k++;
    }
    nu = 0; k++;
    while((c=*(line+k)) != ';'){    //nu�������
        if(c>='0' && c<='9') { nu = nu*10+c-'0'; }
        k++;
    }

    // �õ��������Ԫ�ĸ�������ϡ������Ԫ�أ����߼����У�
    tu = 0; k = k+2;
    while((c=*(line+k)) != ']'){    //����������
        if(c == '('){           //һ����Ԫ����뿪ʼ����ʼ��
            tu++;
            i = j = e = 0;
            s = 1;
            ispositive = 1;
        }else if(c == '-'){     //����ֵΪ����Ԫ��
            ispositive = -1;
        }else if(c == ','){     //i��j����
            if(s==1)      M->data[tu].i = i;
            else if(s==2) M->data[tu].j = j;
            s++;
        }else if(c == ')'){     //e����
            M->data[tu].e = ispositive*e;
        }else{                  //����i,j,e
            if(s==1)      i = i*10+c-'0';
            else if(s==2) j = j*10+c-'0';
            else if(s==3) e = e*10+c-'0';
        }
        k++;
    }

    //��mu,nu,tu����ϡ�����M��
    M->mu = mu; M->nu = nu; M->tu = tu;

    //�õ�ϡ�����M�е�rpos
    int rposi[MAXRC+1];     //rposi��ʾÿһ���з���Ԫ�ĸ���
    for(k=0; k<=MAXRC; k++) //��ʼ��rposi
        rposi[k] = 0;
    for(k=1; k<=tu; k++)    //����ÿһ���з���Ԫ�ĸ���
        rposi[M->data[k].i]++;

    for(i=1; i<=mu; i++)    //�ҵ���һ������Ԫ���к�
        if(rposi[i]){
            M->rpos[i]=1;
            break;
        }
    for(k=i+1; k<=mu; k++)  //����rposi�ж�֮����rpos
        M->rpos[k] = M->rpos[k-1] + rposi[k-1];

    return OK;
}//GetRLSMatrix


int PrintRLSMatrix(RLSMatrix M)
{
//���ϡ�����
    int i,j,k;
    k = 1;
    //����ϡ�����M��ÿһ�к���
    for(i=1; i<=M.mu; i++){
        for(j=1; j<=M.nu; j++){
            //�жϵ�ǰλ���Ƿ��з���Ԫ
            if(M.data[k].i == i && M.data[k].j == j){
                fprintf(fout, "%d\t", M.data[k].e);
                k++;
            }else
                fprintf(fout, "%d\t", 0);
        }
        fprintf(fout, "\n");
    }

    fprintf(fout, "\n");
    return 0;
}//PrintRLSMatrix
