
#include "ColumnPivoting.h"

#include <omp.h>



void nextCalculate(int N,double** HEAD,int col){
    // 换完主元之后，需要将主元下面的数据变为0
    #pragma omp parallel for shared(HEAD, N, col) default(none)
    for(int row = col+1;row<N;row++){
        if(abs_t(*(*(HEAD+col)+col)) < 0.000001) continue;
        double k = (*(*(HEAD+row)+col)) / (*(*(HEAD+col)+col));
        for(int col1 = 0;col1<N+1;col1++)
            *(*(HEAD+row)+col1) -= k * (*(*(HEAD+col)+col1)); 
    }
}


// 化简矩阵
void makeSimple(int N,double** HEAD){
    for(int col = 0;col<N;col++){
        // 这一列的最大的元素
        int max = needExchange(N,HEAD,col);
        if(max != col){
            // 需要进行行变换
            changeRow(col,max,HEAD);            
        }
        /* 行变换之后的计算 */
        nextCalculate(N,HEAD,col);
    }
}

int detectType(double** HEAD,int N){ // 1：有唯一解 2：没有解 3：有无穷多解
    // 输入的是化简之后的矩阵
    if(abs_t(*(*(HEAD+N-1)+N-1)) < 0.000001){
        if(abs_t(*(*(HEAD+N-1)+N)) < 0.000001) return 3;
            else return 2;
    }
    else return 1;
}

double* getFinalRes(double** HEAD,int N){
    double *X = (double*)malloc(N * sizeof(double));
    for(int row = N-1;row >= 0;row--){
        for(int p = row+1;p<N;p++)
            *(*(HEAD+row)+N) -= *(X+p) * (*(*(HEAD+row)+p));
        *(X+row) = *(*(HEAD+row)+N) / (*(*(HEAD+row)+row));
    }
    return X;
}