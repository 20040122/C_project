#include <stdio.h>
int MidSearch(int A[],int B[],int len){
    int s1=0,d1=len-1,m1;
    int s2=0,d2=len-1,m2;
    while(s1!=d1||s2!=d2){
        m1=(s1+d1)/2;
        m2=(s2+d2)/2;
        if(A[m1]==B[m2]){
            return A[m1];
        }else if(A[m1]<B[m2]){
            if((s1+d1)%2==0){
                s1=m1;
                d2=m2;
            }else{
                s1=m1+1;
                d2=m2;
            }
        }
        else{
            if((s1+d1)%2==0){
                d1=m1;
                s2=m2;
            }else{
                d1=m1;
                s2=m2+1;
            }
        }
    }
    return A[s1]<B[s2]?A[s1]:B[s2];
}
int main(){
    int A[]={11,13,15,17,19};
    int B[]={2,4,6,8,20};
    int mid=MidSearch(A,B,5);
    printf("%d",mid);
    return 0;
}