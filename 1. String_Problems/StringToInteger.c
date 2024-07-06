#include<stdio.h>
#include<string.h>

char *str = "-52.23";

int main()
{
    // double val=atof(str);
    // printf("%f",val);
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>=0 && str[i]<=9){
            printf("%d",str[i]-0);
        }
        printf("%c",str[i]);

    }
    return 0;
    
}