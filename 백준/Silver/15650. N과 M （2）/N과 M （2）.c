#include <stdio.h>
#define false 0
#define true 1
int N, M, arr[8], order[8];
_Bool check[8];
void permutation(int k, int j){
    if(k == j){
        for(int i=0;i<j-1;i++)
            if(arr[order[i]] > arr[order[i+1]])
                return;
        for(int i=0;i<j;i++)    printf("%d ", arr[order[i]]);
        printf("\n");
    }
    else
        for(int i=0;i<N;i++)
            if(check[i] == false){
                order[k] = i;
                check[i] = true;
                permutation(k+1, M);
                check[i] = false;
            }
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++)    arr[i] = i+1;
    permutation(0, M);
}