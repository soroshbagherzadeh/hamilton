# hamilton
#include <stdio.h>
#include <stdlib.h>
#define max_size 5
int main(){
    int matris[max_size][max_size]={{0,0,1,1,0},{0,0,0,1,1},{1,0,0,0,1},{1,1,0,0,0},{0,1,1,0,0}};
    int andis[max_size][max_size];
    int k=0;
    // همسایه هر راس
    for(int i=0;i<(sizeof(matris)/sizeof(matris[0]));i++){
        for(int j=0;j<(sizeof(matris[0])/sizeof(matris[0][0]));j++){
            if(matris[i][j]==1){
                andis[i][k]=j;
                k++;
            }
        }
        k=0;
    }
    int stack[10];
    int top=0;
    int sign=0;
    int copy=0;
    stack[top]=0;
    top++;
    //نقطه شروع 
    stack[top]=andis[top-1][1];
    for(int i=0;i<max_size-1;i++){
        for(int j=0;j<2;j++){
            if(andis[stack[top]][j]==stack[top-1]){
                sign=j;
                 break;
            }
        }
        if(sign==0){
            copy=stack[top];
            top++;
            stack[top]=andis[copy][1];
           // sign=0;
        }
        else{
            copy=stack[top];
            top++;
            stack[top]=andis[copy][0];
            sign=0;
        }
    }
    //تشخیص داشتن دور همیلتون
    sign=0;
   for(int i=1;i<max_size+1;i++){
    for(int j=1;j<max_size+1;j++){
        if(stack[i]==stack[j]){
            sign++;
        }
    }
    if(sign>=2){
        printf("dor hamilton nadard ");
        sign=1;
        break;
    }
    sign=0;
   } 
   //نمایش دور در صورت وجود
   if(sign!=1){
    printf("dor hamilton darad \n");
    for (int  i = 0; i <= top; i++)
    {
        printf("%d ",stack[i]);
    }
   }
    return 0;
}
