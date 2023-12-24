#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

    struct s1
    {
        int a;
        int b[10];
        char c;
        bool d; 
    };

    struct s2
    {
        int e;
        int f[5];
        char g;
        bool h;
    }s2_instance;

    typedef struct
    {
        uint16_t acc;
        uint16_t gyro;
        int8_t mgn;
        bool touch;
    }sensorValue_t;

int main(){
    
    printf("Hello world");
    sensorValue_t hello;
    hello.acc=856;
    s2_instance.h=true;
    struct s1 ss={1,{1,2,3,4,5},'a',0};
    struct s1 *a;
    a=&ss;
    struct s2_instance *b;
    b=&s2_instance;
    memset(b,a,sizeof(s2_instance));
    printf("s2 members value : e : %d f : %d g : %c h : %d",s2_instance.e,s2_instance.f,s2_instance.g,s2_instance.h);


   sensorValue_t sensors =
   {
        .acc=12,
        .gyro=13,
        .mgn=3,
        .touch=0,
    };
    
     return 0;  
    
}