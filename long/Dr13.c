/*
 * -------------------
 *      �����v�Z     *
 * -------------------
 */

#include <stdio.h>

#define KETA 20             // ����
#define N ((KETA-1)/4+1)    // �z��T�C�Y

void lmul(short *,short,short *);
void ldiv(short *,short,short *);
void print(short *);

int main(void)
{
    short a[N+2]={   0,3050,2508,8080,1233},
          c[N+2];

    lmul(a,101,c); print(c);
    ldiv(a,200,c); print(c);
    return 0;
}
void lmul(short a[],short b,short c[])    // �����O���~�V���[�g��
{
    short i;long d,cy=0;
    for (i=N-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
}
void ldiv(short a[],short b,short c[])    // �����O�����V���[�g��
{
    short i;long d,rem=0;
    for (i=0;i<N;i++){
        d=a[i];
        c[i]=(short)((d+rem)/b);
        rem=((d+rem)%b)*10000;
    }
}
void print(short c[])            // �����O���̕\��
{
    short i;
    for (i=0;i<N;i++)
        printf("%04d ",c[i]);
    printf("\n");
}
