#ifndef __COLUMN__
#define __COLUMN__

#include <stdio.h>
#include <stdlib.h>


// 化简矩阵
void makeSimple(int N,double** HEAD);
// 行变换
void changeRow(int row1,int row2,double** HEAD);
//分解为两个矩阵
void decomposeMatrix(int N,double** HEAD);


//比较大小之前的计算
void preCalculate(int N,double** HEAD,int col); 
    
// 除以列主元素
void nextCalculate(int N,double** HEAD,int col);
    



#endif