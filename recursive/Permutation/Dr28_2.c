/*
 * -------------------------------
 *      順列生成（辞書式順）     *
 * -------------------------------
 */

#include <stdio.h>

#define N 4
int p[N+1];

void perm(int);

void main(void)
{
    int i;

    for (i=1;i<=N;i++)        // 初期設定
        p[i]=i;
        
    p[1]='a';p[2]='c';p[3]='h';p[4]='t';
    perm(1);
}
void perm(int i)
{
    int j,k,t;

    if (i<N){
        for (j=i;j<=N;j++){
            t=p[j];                 // p[i]～p[j]の右ローテイト
            for (k=j;k>i;k--)
                p[k]=p[k-1];
            p[i]=t;

            perm(i+1);              // 再帰呼び出し

            for (k=i;k<j;k++)       // 配列の並びを再帰呼び出し前に戻す
                p[k]=p[k+1];
            p[j]=t;
        }
    }
    else {
        for (j=1;j<=N-1;j++)        // 順列の表示
            printf("%c",p[j]);
        printf("\n");
    }
}
