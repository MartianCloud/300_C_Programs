#include<stdio.h>
#include<string.h>

void printDuplicateCharacters(char* input){
    char freq[256]={0};
    for(int i=0;input[i]!='\0';i++){
        freq[input[i]]++;
    }
    for(int i=0;i<256;i++){
        if(freq[i]>1){
            printf("%c",i);
        }
    }
}


int main()
{
    char inputStr[] ="aaAAWWll_wworlDD";
    printDuplicateCharacters(inputStr);
    return 0;
}