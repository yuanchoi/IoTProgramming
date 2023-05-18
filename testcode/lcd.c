//LCD에 hello world 띄우기
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define clcd "/dev/clcd"
int main()
{
    int clcd_d;
    char str[]="Hello team7";

    if((clcd_d = open(clcd,O_RDWR)) < 0)
    {
        perror("open");
        exit(1);
    }
    
    write(clcd_d,str,sizeof(str));
    close(clcd_d);
    return 0;
}
