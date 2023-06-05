#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define fnd "/dev/fnd"

int main()
{
	int fnd_d;
  unsigned char fnd_data[4];

  fnd_d = open(fnd , O_RDWR); //해당 드라이버 열기
  //0값을 넣어본다.
  fnd_data[0]=~0x06;
  fnd_data[1]=~0x4B;
  fnd_data[2]=~0x4F;
  fnd_data[3]=~0x66;
  write(fnd_d , fnd_data , sizeof(fnd_data));
  sleep(1);

  fnd_data[0]=~0x6D;
  fnd_data[1]=~0x7D;
  fnd_data[2]=~0x07;
  fnd_data[3]=~0x7F;
  write(fnd_d , &fnd_data , sizeof(fnd_data)); //배열이름에 &를 붙이면 메모리가 충돌나는 것을 방지 시킨다.

	sleep(1);
  close(fnd_d);
  return 0;

}

