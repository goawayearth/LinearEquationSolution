#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>

// 解下三角矩阵方程组
double* lowerTriangularMatrix(double** L,double* b,int N);
// 上三角矩阵求解
double* upperTriangularMatrix(double** U,double* b,int N);

// 行变换
void changeRow(int row1,int row2,double** HEAD);

// 绝对值函数
double abs_t(double a);

// 寻找这个矩阵的col列的主元素的那一行 
int needExchange(int N,double** HEAD,int col);

#endif