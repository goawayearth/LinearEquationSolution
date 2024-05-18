
#include "LUdecomposition.h"
#include "ColumnPivoting.h"


// 化简矩阵
void lu_makeSimple(int N,double** HEAD){
    for(int col = 0;col<N;col++){
        /* 先进行计算 */
        lu_preCalculate(N,HEAD,col);
        
        int max = needExchange(N,HEAD,col);

        if(max != col){
            // 需要进行行变换
            changeRow(col,max,HEAD);            
        }
        /* 行变换之后的计算 */
        lu_nextCalculate(N,HEAD,col);
    }
}

// 将化简之后的矩阵分解为两个矩阵
double** decomposeMatrix_L(int N,double** HEAD){
    double** L;
    L = (double**)malloc(N * sizeof(double*)); // 开辟N个向量
    //开辟矩阵的存储空间
    for(int i=0;i<N;i++)
        *(L+i) = (double*)malloc((N)*sizeof(double));

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            *(*(L+i)+j) = 0.0;
    for(int row = 0;row < N;row++)
        for(int col = 0;col <= row;col++)
            if(col == row) *(*(L+row)+col) = 1;
            else *(*(L+row)+col) = *(*(HEAD+row)+col);
        
    return L;
}

double* decomposeMatrix_b(int N,double** HEAD){
    double *b;
    b = (double*)malloc(N * sizeof(double));
    for(int row = 0;row<N;row++)
        *(b+row) = *(*(HEAD+row)+N);

    return b;
}


double** decomposeMatrix_U(int N,double** HEAD){
    double** U;
    U = (double**)malloc(N * sizeof(double*)); // 开辟N个向量
    //开辟矩阵的存储空间
    for(int i=0;i<N;i++)
        *(U+i) = (double*)malloc((N)*sizeof(double));

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            *(*(U+i)+j) = 0.0;

    for(int row = 0;row<N;row++)
        for(int col = row;col<N;col++)
            *(*(U+row)+col) = *(*(HEAD+row)+col);

    return U;
}

void lu_preCalculate(int N,double** HEAD,int col){ // 比较大小之前的计算
    // 计算主元素之前做减法
    if(col == 0) return; // 第一行和最后一行不需要做减法
    for(int row = col;row<N;row++){
        // 做减法
        for(int col1 = 0;col1<col;col1++){
            *(*(HEAD+row)+col) -= (*(*(HEAD+row)+col1)) * (*(*(HEAD+col1)+col));
        }
    }
}

void lu_nextCalculate(int N,double** HEAD,int col){
    // 换完主元之后，列做除法，行做减法
    if(col == N-1) return; // 最后一行不需要处理
    for(int row = col+1;row<N;row++)
        *(*(HEAD+row)+col) /= (*(*(HEAD+col)+col));
    // 计算行元素
    for(int col1 = col+1;col1<N;col1++)
        for(int p = 0;p < col;p++)
            *(*(HEAD+col)+col1) -= (*(*(HEAD+p)+col1)) * (*(*(HEAD+col)+p));

}