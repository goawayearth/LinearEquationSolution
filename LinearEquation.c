/*
增加错误检测
*/
#include "ColumnPivoting.h"

int N; // 实际用户输入的矩阵大小
double** HEAD = NULL; // 用来指向N个double*的指针,原始矩阵的指针
double** L = NULL; // L矩阵的指针
double** U = NULL; // U矩阵的指针
double* X = NULL; // 方程组的解
double* b = NULL;
int ERROR = 0;//用来处理异常，如果出现异常EROR=1

void inputInfo(); // 输入矩阵信息
void showMatrix(); // 展示矩阵
void pauseBeforeExit();

int main(){
    while(1){
        inputInfo(); // 输入矩阵数据
        printf("初识矩阵是：\n");
        showMatrix(N,N+1,HEAD);
        makeSimple(N,HEAD);
        printf("化简之后的矩阵是：\n");
        showMatrix(N,N+1,HEAD);
        int type = detectType(HEAD,N);
        if(type == 2) printf("该方程组没有解！！！\n");
        else if(type == 3) printf("该方程组有无穷多解！！！\n");
        else{ // 有唯一解
            printf("该矩阵有唯一解！！！\n");
            b = getFinalRes(HEAD,N);
            for(int i=0;i<N;i++){
                printf("%lf ",*(b+i));
            }
            printf("\n");
        }

    }
}


void inputInfo(){
    printf("请输入矩阵的大小N(输入0退出程序):");
    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "输入错误！程序退出。\n");
        pauseBeforeExit();
        exit(EXIT_FAILURE); // 输入格式错误，退出程序
    }
    
    if (N == 0) {
        printf("程序退出成功！\n");
        pauseBeforeExit();
        exit(0); // 用户输入0，退出程序
    } 
    
    // 开辟N个double*的指针
    HEAD = (double**)malloc(N * sizeof(double*));
    if (HEAD == NULL) {
        fprintf(stderr, "内存分配失败！程序退出。\n");
        pauseBeforeExit();
        exit(EXIT_FAILURE); // 内存分配失败，退出程序
    }

    // 解的空间
    X = (double*)malloc(N * sizeof(double));
    if (X == NULL) {
        fprintf(stderr, "内存分配失败！程序退出。\n");
        pauseBeforeExit();
        free(HEAD); // 释放已分配的HEAD指针
        exit(EXIT_FAILURE); // 内存分配失败，退出程序
    }

    // 开辟矩阵的存储空间
    for (int i = 0; i < N; i++) {
        HEAD[i] = (double*)malloc((N + 1) * sizeof(double));
        if (HEAD[i] == NULL) {
            fprintf(stderr, "内存分配失败！程序退出。\n");
            pauseBeforeExit();
            // 释放之前分配的内存
            for (int j = 0; j < i; j++) {
                free(HEAD[j]);
            }
            free(HEAD);
            free(X);
            exit(EXIT_FAILURE); // 内存分配失败，退出程序
        }
    }

    printf("请输入方程组的增广矩阵:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            if (scanf("%lf", &HEAD[i][j]) != 1) {
                fprintf(stderr, "输入错误！程序退出。\n");
                pauseBeforeExit();
                // 释放已分配的内存
                for (int k = 0; k < N; k++) {
                    free(HEAD[k]);
                }
                free(HEAD);
                free(X);
                exit(EXIT_FAILURE); // 输入格式错误，退出程序
            }
        }
    }
}


// 输出矩阵
void showMatrix(int row,int col,double** HEAD){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%lf ",*(*(HEAD+i)+j));
        }
        printf("\n");
    }
}

void pauseBeforeExit() {
    printf("按任意键退出程序...\n");
    getchar(); // 读取一个字符
    getchar(); // 等待用户按任意键（包括Enter键）
    getchar();
}