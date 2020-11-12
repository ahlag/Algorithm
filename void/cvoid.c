#include <stdio.h>

int main() {
    
    double x = 3.14, *fp;
    void *vp;
    
    vp = &x;
    fp = vp;
    
    printf("ポインタ変数fpのアドレスは%pです\n",fp);
    printf("ポインタ変数vpのアドレスは%pです\n",vp);
    printf("ポインタ変数fpが指す内容は%fです\n",*fp);
    
    /*間接参照する場合はキャストが必要 */
    printf("ポインタ変数vpが指す内容は%fです\n",*(double *)vp);
    
    printf("ポインタ変数vpが指す内容は%fです\n",*vp);
    
    return 0;
}
