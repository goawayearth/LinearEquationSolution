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