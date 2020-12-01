#include "MatrixHead.h"

int InitRLSMatrix(RLSMatrix *M)
{
// ��ʼ���ԡ����߼����ӵ�˳�����ʾ��ϡ�����M
    int i;
    Triple init;                //init��ʾ�С��С�ֵ��Ϊ0��Ԫ��
    init.i = init.j = 0;
    init.e = 0;
    if(!M) return ERROR;        //��û����ռ䣬����ERROR
    for(i=0; i<MAXSIZE+1; i++){ //MԪ��ȫ����ʼ��Ϊ��Ԫ
        M->data[i] = init;
    }
    for(i=0; i<MAXRC+1; i++){   //���е�һ������Ԫλ�ñ��ʼ��Ϊ0
        M->rpos[i] = 0;
    }
    M->mu = M->nu = M->tu = 0;  //��������������������Ԫ����ʼ��0

    return OK;
}//InitRLSMatrix

//�������ĺ�
RLSMatrix addMatrix(RLSMatrix M, RLSMatrix N, int *error)
{
	int m=1, n=1, c=1, i;
	RLSMatrix Q;
	InitRLSMatrix(&Q);

	//�ж��Ƿ���ϼӷ�Ҫ��
	if(M.mu!=N.mu || M.nu!=N.nu)
		error=ADD_ERROR;

	Q.mu=M.mu;
	Q.nu=M.nu;
	//����M��N�з���Ԫ���Ƚ����кź��к�
	//�ж�M��ǰԪ��N��ǰԪ�Ƿ���ͬһλ��
	//����ͬ����M��N�п�ǰ��Ԫ�ظ�ֵ��Q
	//����ͬ������мӷ�����
	while(m<=M.tu){
		while(n<=N.tu){
			if(M.data[m].i<N.data[n].i){
				Q.data[c].i = M.data[m].i;
				Q.data[c].j = M.data[m].j;
				Q.data[c].e = M.data[m].e;
				c++;m++;
				break;
			}else if(M.data[m].i>N.data[n].i){
				Q.data[c].i = N.data[n].i;
				Q.data[c].j = N.data[n].j;
				Q.data[c].e = N.data[n].e;
				c++;n++;
			}else{
				if(M.data[m].j<N.data[n].j){
					Q.data[c].i = M.data[m].i;
					Q.data[c].j = M.data[m].j;
					Q.data[c].e = M.data[m].e;
					c++;m++;
					break;
				}else if(M.data[m].j>N.data[n].j){
					Q.data[c].i = N.data[n].i;
					Q.data[c].j = N.data[n].j;
					Q.data[c].e = N.data[n].e;
					c++;n++;
				}else{
                    //����Ӧλ���ϵ�����ӣ����������ֵ��Q
					Q.data[c].i = N.data[n].i;
					Q.data[c].j = N.data[n].j;
					Q.data[c].e = M.data[m].e+N.data[n].e;
					//�жϵõ������Ƿ�Ϊ0������Ϊ0�����¼
					if(Q.data[c].e!=0){
						c++;
					}
					m++;n++;
					break;
				}
			}
		}
	}

    //��M��N����ʣ���Ԫ�أ�����ȫ����Q
	if(m>M.tu&&n<=N.tu){
		for(i=n;i<=N.tu;i++){
			Q.data[c].i = N.data[n].i;
			Q.data[c].j = N.data[n].j;
			Q.data[c].e = N.data[n].e;
			c++;
		}
	}
	if(n>N.tu&&m<=M.tu){
		for(i=m;m<=M.tu;i++){
			Q.data[c].i = M.data[m].i;
			Q.data[c].j = M.data[m].j;
			Q.data[c].e = M.data[m].e;
			c++;
		}
	}

    //����Q��Ԫ�صĸ���
    Q.tu = c-1;

    return Q;
}

//�������Ĳ�
RLSMatrix subMatrix(RLSMatrix M, RLSMatrix N, int *error)
{
	int m=1;
	int n=1;
	int c=1;
	int i;
	RLSMatrix Q;
	InitRLSMatrix(&Q);

	if(M.mu!=N.mu || M.nu!=N.nu)
		error=ADD_ERROR;//�ж��Ƿ���ϼӷ�Ҫ��

	Q.mu=M.mu;
	Q.nu=M.nu;
	while(m<=M.tu){
		while(n<=N.tu){
			if(M.data[m].i<N.data[n].i){
				Q.data[c].i = M.data[m].i;
				Q.data[c].j = M.data[m].j;
				Q.data[c].e = M.data[m].e;
				c++;m++;break;
			}
			else if(M.data[m].i>N.data[n].i){
				Q.data[c].i = N.data[n].i;
				Q.data[c].j = N.data[n].j;
				Q.data[c].e = N.data[n].e;
				c++;n++;
			}
			else{
				if(M.data[m].j<N.data[n].j){
					Q.data[c].i = M.data[m].i;
					Q.data[c].j = M.data[m].j;
					Q.data[c].e = M.data[m].e;
					c++;m++;break;
				}
				else if(M.data[m].j>N.data[n].j){
					Q.data[c].i = N.data[n].i;
					Q.data[c].j = N.data[n].j;
					Q.data[c].e = N.data[n].e;
					c++;n++;
				}
				else{
					Q.data[c].i = N.data[n].i;
					Q.data[c].j = N.data[n].j;
					Q.data[c].e = M.data[m].e-N.data[n].e;//����Ӧλ���ϵ�����ӣ����������ֵ��Q
					if(Q.data[c].e!=0){
						c++;//�жϵõ������Ƿ�Ϊ0������Ϊ0�����¼
					}
					m++;n++;break;
				}
			}
		}
	}

	if(m>M.tu&&n<=N.tu){
		for(i=n;i<=N.tu;i++){
			Q.data[c].i = N.data[n].i;
			Q.data[c].j = N.data[n].j;
			Q.data[c].e = -N.data[n].e;
			c++;
		}
	}
	if(n>N.tu&&m<=M.tu){
		for(i=m;m<=M.tu;i++){
			Q.data[c].i = M.data[m].i;
			Q.data[c].j = M.data[m].j;
			Q.data[c].e = M.data[m].e;
			c++;
		}
	}
//printf("%d",c);
Q.tu=c-1;//���������Ԫ�صĸ���
return Q;
}

//�������ĳɻ�
RLSMatrix multiplyMatrix(RLSMatrix M, RLSMatrix N, int *error)
{
	RLSMatrix Q;
				//���в�����Ҫ�󣬷��ش���
	if(M.nu != N.mu)
    {
		error = MULT_ERROR;
		return Q;
	}
				//Q�ĳ�ʼ��
	Q.mu = M.mu;
	Q.nu = N.nu;
	Q.tu = 0;

	int ctemp[Q.nu];
	int tp,t,p,q,arow,brow,ccol;

	if(M.tu * N.tu != 0)//Q���Ƿ������
	{
		for(arow = 1;arow <= M.mu;++arow)//����M��ÿһ��
		{
			for(int i = 0;i <= Q.nu;i++)//��ǰ����Ԫ���ۼ�������
				ctemp[i]=0;

			Q.rpos[arow] = Q.tu + 1;

			if(arow < M.mu)//���ÿһ�з���Ԫ�ظ������Ͻ�
				tp = M.rpos[arow + 1];
			else
				tp = M.tu+1;

			for(p = M.rpos[arow];p < tp;++p)//�Ե�ǰ����ÿһ������Ԫ�ҵ���ӦԪ��N�е��к�
			{
				brow = M.data[p].j;

				if(brow < N.mu)//�������N�е�brow�з���Ԫ�ظ������Ͻ�
					t = N.rpos[brow + 1];
				else
					t = N.tu+1;

				for(q = N.rpos[brow];q < t;++q)
				{
					ccol = N.data[q].j;//�˻�Ԫ����Q�е��к�

					ctemp[ccol] += M.data[p].e * N.data[q].e;
				}//for q

			}//���Q�е�crow(=arow)�еķ���Ԫ

			for(ccol = 1;ccol < Q.nu;++ccol)//ѹ���洢���з���Ԫ
			{
				if(ctemp[ccol])
				{
					if(++Q.tu > MAXSIZE)//���Q�з���Ԫ��������MASIZE�������
					{
						error = MULT_ERROR;
						return Q;
					}

					Q.data[Q.tu].i = arow;
					Q.data[Q.tu].j = ccol;
					Q.data[Q.tu].e = ctemp[ccol];

				}//if
			}
		}//for arow
	}//if
	return Q;
}//matrix_mult
