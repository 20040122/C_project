#include <stdio.h>
#include <stdlib.h>
int setPartiton(int A[],int n){
    int pov,low=0,low0=0,high=n-1,high0=n-1,flag=1,k=n/2,i;
    int s1=0,s2=0;
    while(flag){
        pov=A[low];
        while(low<high){
            while(low<high&&A[high]>=pov)
                high--;
            if(low!=high) {
                A[low] = A[high];
            }
            while(low<high&&A[low]<=pov)
                low++;
            if(low!=high) {
                A[high] = A[low];
            }
        }
        A[low]=pov;
        if(low==k-1){
            flag=0;
        } else{
            if(low<k-1){
                low0=++low;
                high=high0;
            }
            else{
                low=low0;
                high=high0--;
            }
        }
    }
    for(i=0;i<k;i++){
        s1+=A[i];
    }
    for(i=k;i<n;i++){
        s2+=A[i];
    }
    return s2-s1;
}

int main(){
    int A[10]={4,1,12,18,7,13,18,16,5,15};
    int d;
    d=setPartiton(A,10);
    printf("%d",d);
    return 0;
}