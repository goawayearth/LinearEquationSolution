
#include "ColumnPivoting.h"

double abs_t(double a){
    if(a<0) return -a;
    return a;
}

// 行变换之交换
void changeRow(int row1,int row2,double** HEAD){
    double* tem = *(HEAD+row1);
    *(HEAD+row1) = *(HEAD+row2);
    *(HEAD+row2) = tem;
}

int needExchange(int N,double** HEAD,int col){// 寻找这个矩阵的col列的主元素的那一行
    int max = col;
    for(int row = col+1;row<N;row++){
        if(abs_t(*(*(HEAD+row)+col)) > abs_t(*(*(HEAD+max)+col)))
            max = row;
    }
    return max;
}



void nextCalculate(int N,double** HEAD,int col){
    // 换完主元之后，需要将主元下面的数据变为0
    for(int row = col+1;row<N;row++){
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
    double *b = (double*)malloc(N * sizeof(double));
    for(int row = N-1;row >= 0;row--){
        for(int p = row+1;p<N;p++)
            *(*(HEAD+row)+N) -= *(b+p) * (*(*(HEAD+row)+p));
        *(b+row) = *(*(HEAD+row)+N) / (*(*(HEAD+row)+row));
    }
    return b;

}