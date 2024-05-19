#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>

// 解下三角矩阵方程组
double* lowerTriangularMatrix(double** L,double* b,int N);
// 上三角矩阵求解
double* upperTriangularMatrix(double** U,double* b,int N);


#endif