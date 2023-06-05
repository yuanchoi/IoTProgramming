#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define dot "/dev/dot"

int main()
{
  int dot_d, i;
  unsigned char smile[8] = {0x7E, 0x81, 0xA5, 0xDB, 0x81, 0xA5, 0x99, 0x7E};
  dot_d = open(dot, O_RDWR);
  if(dot_d<0)
  {
    printf("Error\n");
    return 0;
  }
  
  write(dot_d, &smile, sizeof(smile));
  sleep(2);
  
  close(dot_d);
  return 0;
}
