#include<stdio.h>
#include<string.h>
 
int main()
{
    char para[100];
    int kount=0;
    int c;
    while((c=getchar())!=EOF){
        scanf("%s", para);
        kount++;
    }
    printf("%d", kount-1);
    return 0;
}