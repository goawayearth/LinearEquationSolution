
#include "GaussianElimination.h"


// 化简矩阵
void g_makeSimple(int N,double** HEAD){
    for(int col = 0;col<N;col++){
        // 这一列的最大的元素
        if(*(*(HEAD+col)+col) == 0.0){
            int max = g_needExchange(N,HEAD,col);
            if(max != col){
                // 需要进行行变换
                changeRow(col,max,HEAD);            
            }
        }
        /* 行变换之后的计算 */
        nextCalculate(N,HEAD,col);
    }
}

int g_needExchange(int N,double** HEAD,int col){// 寻找这个矩阵的col列的主元素的那一行
    for(int row = col+1;row<N;row++){
        if(abs_t(*(*(HEAD+row)+col)) > 0)
            return row;
    }
    return col;
}
