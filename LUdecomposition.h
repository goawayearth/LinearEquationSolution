#ifndef __LUDECOMPOSITION_H__
#define __LUDECOMPOSITION_H__

#include <stdio.h>
#include <stdlib.h>



// 化简矩阵
int lu_makeSimple(int N,double** HEAD);


//分解为两个矩阵
double** decomposeMatrix_L(int N,double** HEAD);
double** decomposeMatrix_U(int N,double** HEAD);
double* decomposeMatrix_b(int N,double** HEAD);
//比较大小之前的计算
void lu_preCalculate(int N,double** HEAD,int col); 
    
// 除以列主元素
void lu_nextCalculate(int N,double** HEAD,int col);

// 寻找这个矩阵的col列的主元素的那一行 
int lu_needExchange(int N,double** HEAD,int col);

// 换主元之前的计算
void lu_preCalculate(int N,double** HEAD,int col);

// 换完主元之后的计算
void lu_nextCalculate(int N,double** HEAD,int col);

double* lu_getFinalRes(double** L,double** U,double* b,int N);




#endif