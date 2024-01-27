#include <stdio.h>
#define N 7
void Merge(int A[],int low,int mid,int high){
    static int B[N];
    int i,j,k=low;
    for(i=low;i<=high;i++){
            B[i]=A[i];
    }
    for(i=low,j=mid+1;i<=mid&&j<=high; k++){
        if(B[i]<B[j]){
            A[k]=B[i];
            i++;
        }
        else{
            A[k]=B[j];
            j++;
        }
    }
    while(i<=mid){
        A[k]=B[i];
        i++;
        k++;
    }
    while(j<=high){
        A[k]=B[j];
        j++;
        k++;
    }
}
void MergeSort(int A[],int low,int high){
    if(low<high) {
        int mid = (high + low) / 2;
        MergeSort(A, low, mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}
void Print(int A[]){
    for(int i=0;i<7;i++){
        printf("%3d",A[i]);
    }
}
//空间复杂度O(n)
int main(){
    int A[7]={49,38,65,97,76,13,27};
    MergeSort(A,0,6);
    Print(A);
    return 0;
}