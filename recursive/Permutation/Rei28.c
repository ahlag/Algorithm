/*
 * -------------------------------------
 *      ���񐶐��i���������łȂ��j     *
 * -------------------------------------
 */

#include <stdio.h>

#define N 4
int p[N+1];

void perm(int);

void main(void)
{
    int i;

    for (i=1;i<=N;i++)        // �����ݒ�
        p[i]=i;
    perm(1);
}
void perm(int i)
{
    int j,t;

    if (i<N){
        for (j=i;j<=N;j++){
            t=p[i]; p[i]=p[j]; p[j]=t;    // p[i]��p[j]�̌���
            perm(i+1);                    // �ċA�Ăяo��
            t=p[i]; p[i]=p[j]; p[j]=t;    // ���ɖ߂�
        }
    }
    else {
        for (j=1;j<=N;j++)                // ����̕\��
            printf("%d ",p[j]);
        printf("\n");
    }
}
