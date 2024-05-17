
#include "ColumnPivoting.h"

int N; // 实际用户输入的矩阵大小
double** HEAD = NULL; // 用来指向N个double*的指针,原始矩阵的指针
double** L = NULL; // L矩阵的指针
double** U = NULL; // U矩阵的指针
double* X = NULL; // 方程组的解


void inputInfo(); // 输入矩阵信息
void showMatrix(); // 展示矩阵


int main(){
    while(1){
        inputInfo(); // 输入矩阵数据
        detectType(double** HEAD,int N);
        
        
    }
}


// 输入矩阵信息
void inputInfo(){
    printf("请输入矩阵的大小N(输入0退出程序):");
    scanf("%d",&N); // 矩阵的大小存到A
    if(N == 0) {
        printf("程序退出成功！\n");
        exit(0);// 退出程序 
    }       
        
    //开辟N个double*的指针
    HEAD = (double**)malloc(N * sizeof(double*));
    // 解的空间
    X = (double*)malloc(N * sizeof(double));
        
    //开辟矩阵的存储空间
    for(int i=0;i<N;i++)
        *(HEAD+i) = (double*)malloc((N+1)*sizeof(double));
        
    printf("请输入方程组的增广矩阵:\n");
    for(int i=0;i<N;i++)
        for(int j=0;j<N+1;j++)
            scanf("%lf",(*(HEAD+i)+j)); // 增广矩阵输入完成
}

// 输出矩阵
void showMatrix(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N+1;j++){
            printf("%lf ",*(*(HEAD+i)+j));
        }
        printf("\n");
    }
}

