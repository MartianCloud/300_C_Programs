#include<stdio.h>
#include<string.h>

void printDuplicateCharacters(char input[]){
    int freq[256]={0};
    for(int i=0;input[i]!='\0';i++)
    {
        freq[(int)input[i]]++;
    }
    for (size_t i = 0; i < 256; i++)
    {
        if(freq[i]>1)
        {
            printf("%c",(char)i);
        }
    }
}

int main()
{
    char inputStr[] ="hello__world";
    printDuplicateCharacters(inputStr);
    return 0;
}