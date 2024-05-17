
#include "ColumnPivoting.h"



// 行变换之交换
void changeRow(int row1,int row2,double** HEAD){
    double* tem = *(HEAD+row1);
    *(HEAD+row1) = *(HEAD+row2);
    *(HEAD+row2) = tem;
}

int needExchange(int N,double** HEAD,col){// 寻找这个矩阵的col列的主元素的那一行
    int max = col;
    for(int row = col+1;row<N;row++){
        if((*(*(HEAD+row)+col)) > (*(*(HEAD+max)+col)))
            max = row;
    }
    return max;
}

// 化简矩阵
void makeSimple(int N,double** HEAD){
    int ptrCol = 0; // 列指针，初始化指向第一列
    for(int col = 0;col<N;col++){

        /* 先进行计算 */
        preCalculate(N,HEAD,col);
        int max = needExchange(N,HEAD,col);
        if(max != col){
            // 需要进行行变换
            changeRow(col,max);            
        }
        /* 行变换之后的计算 */
        nextCalculate(N,HEAD,col);
    }
}

// 将化简之后的矩阵分解为两个矩阵
void decomposeMatrix(int N,double** HEAD){

}

void preCalculate(int N,double** HEAD,int col){ // 比较大小之前的计算
    //第一列特殊处理
    // 其他减去左数乘以右数
}

void nextCalculate(int N,double** HEAD,int col){
    // 除以列主元素
}