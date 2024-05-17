#include <stdio.h>
#include <stdlib.h>

int N; // 实际用户输入的矩阵大小
double** HEAD = NULL; // 用来指向N个double*的指针,原始矩阵的指针
double** L = NULL; // L矩阵的指针
double** U = NULL; // U矩阵的指针


void inputInfo(); // 输入矩阵信息
void showMatrix(); // 展示矩阵
void makeSimple();// 化简矩阵
void changeRow();
void decomposeMatrix();



int main(){
    while(1){
        inputInfo(); // 输入矩阵数据
        showMatrix();
        
        
        
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

// 行变换之交换
void changeRow(int row1,int row2){
    double* tem = *(HEAD+row1);
    *(HEAD+row1) = *(HEAD+row2);
    *(HEAD+row2) = tem;
}

// 化简矩阵
void makeSimple(){
    int ptrCol = 0; // 列指针，初始化指向第一列
    for(int col = 0;col<N;col++){
        if(*(*(HEAD+col)+col) == 0){
            // 主元素是0，行变化解决
            for(int row = col+1;row<N;row++){
                if(*(*(HEAD+row)+col)!=0){
                    // 两行交换
                    changeRow(col,row);
                }
                if(row==N-1 && *(*(HEAD+col)+col) == 0){
                    // 最后一行了还是0
                    printf("不是满秩矩阵");
                    return;
                }
            }
        }
        // 主元更换完毕，可以化简
    }
}

// 将化简之后的矩阵分解为两个矩阵
void decomposeMatrix(){

}