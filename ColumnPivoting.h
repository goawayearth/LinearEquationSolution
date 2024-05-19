#ifndef __COLUMN_H__
#define __COLUMN_H__

#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"

// // 绝对值函数
// double abs_t(double a);

// 化简矩阵
void makeSimple(int N,double** HEAD);

// // 行变换
// void changeRow(int row1,int row2,double** HEAD);
    
// 除以列主元素
void nextCalculate(int N,double** HEAD,int col);

// // 寻找这个矩阵的col列的主元素的那一行 
// int needExchange(int N,double** HEAD,int col);

// 换主元之前的计算
void preCalculate(int N,double** HEAD,int col);

// 换完主元之后的计算
void nextCalculate(int N,double** HEAD,int col);

// 检测矩阵类型
int detectType(double** HEAD,int N);

// 得出方程组的解
double* getFinalRes(double** HEAD,int N);




#endif