#include "Utils.h"


// 解下三角矩阵方程组
double* lowerTriangularMatrix(double** L,double* b,int N){
    double* y = (double*)malloc(N * sizeof(double));// 存储y
    for(int row = 0;row < N;row++){
        // 先做减法
        for(int col = 0;col < row;col++){
            *(b+row) -= (*(*(L+row)+col)) * (*(y+col));
        }
        // 做除法
        *(y+row) = *(b+row) / (*(*(L+row)+row));
    }
    return y;
}

double* upperTriangularMatrix(double** U,double* b,int N){
    double *X = (double*)malloc(N * sizeof(double));
    for(int row = N-1;row >= 0;row--){
        for(int p = row+1;p<N;p++)
            *(b+row) -= *(X+p) * (*(*(U+row)+p));
        *(X+row) = *(b+row) / (*(*(U+row)+row));
    }
    return X;
}

// 行变换之交换
void changeRow(int row1,int row2,double** HEAD){
    double* tem = *(HEAD+row1);
    *(HEAD+row1) = *(HEAD+row2);
    *(HEAD+row2) = tem;
}

double abs_t(double a){
    if(a<0) return -a;
    return a;
}

int needExchange(int N,double** HEAD,int col){// 寻找这个矩阵的col列的主元素的那一行
    int max = col;
    for(int row = col+1;row<N;row++){
        if(abs_t(*(*(HEAD+row)+col)) > abs_t(*(*(HEAD+max)+col)))
            max = row;
    }
    return max;
}
