#ifndef __COLUMN_H__
#define __COLUMN_H__

#include <stdio.h>
#include <stdlib.h>



// 化简矩阵
void makeSimple(int N,double** HEAD);

// 行变换
void changeRow(int row1,int row2,double** HEAD);
//分解为两个矩阵
double** decomposeMatrix_L(int N,double** HEAD);
double** decomposeMatrix_U(int N,double** HEAD);
double* decomposeMatrix_b(int N,double** HEAD);
//比较大小之前的计算
void preCalculate(int N,double** HEAD,int col); 
    
// 除以列主元素
void nextCalculate(int N,double** HEAD,int col);

// 寻找这个矩阵的col列的主元素的那一行 
int needExchange(int N,double** HEAD,int col);

// 换主元之前的计算
void preCalculate(int N,double** HEAD,int col);

// 换完主元之后的计算
void nextCalculate(int N,double** HEAD,int col);





#endif