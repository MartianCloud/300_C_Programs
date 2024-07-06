#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "Hello World";
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+32;
        }
        else if(str[i]>='a' && str[i]<='z'){
            str[i]=str[i]-32;
        }
      i++;
    }
    printf("%s",str);
    return 0;
}