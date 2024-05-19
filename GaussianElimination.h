#ifndef __GAUSSIAN_H__
#define __GAUSSIAN_H__


#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "ColumnPivoting.h"
#include <omp.h>

// 化简矩阵
void g_makeSimple(int N,double** HEAD);

int g_needExchange(int N,double** HEAD,int col);









#endif