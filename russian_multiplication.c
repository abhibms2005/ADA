#include<stdio.h>
#include<stdlib.h>
void russian_peasent(int a, int b){
    int result=0;
    while(a>0){
    if(a%2 !=0){
        result+=b;
    }
    a=a/2;
    b=b*2;
}
}
int main(){
    int a, b;
    printf("Enter value of a and b: ");
    scanf("%d", &a, &b);
    russian_peasent(a,b);
}