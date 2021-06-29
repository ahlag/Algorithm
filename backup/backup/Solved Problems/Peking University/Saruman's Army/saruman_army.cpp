#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1010
int a[N];

int main( )
{
    int r, n,j=1;
    memset(a, -1, sizeof(a));
    while (scanf("%d%d", &r, &n) && r != -1 && n != -1)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int ans = 0;
        int j = 0;
        while (j<n)
        {
            int temp = a[j];
            while (a[j] - temp <= r) j++;
            temp = a[j - 1];
            while (a[j] - temp <= r) j++;
            ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}