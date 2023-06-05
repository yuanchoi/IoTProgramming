#include<termios.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<asm/ioctls.h>

#define tact_d "/dev/tactsw"
#define clcd  "/dev/clcd"

void calc(int *num , char op , int *i);
void PrintFnd(int rst , int k , unsigned char *fnd_data);

int main()
{
	int tact , fnd , sum=0 , i=0;
	char op;
	int num[2];
	unsigned char c;
	
	tact = open(tact_d , O_RDWR);
	
	if(tact < 0)
	{
		printf("tact : open failed!\n");
	}
	
	while(1)
	{
		while(1)
		{
			read(tact , &c , sizeof(c)); //scanf() 처럼 블록상태가 되지 않기 때문에
			usleep(100000);
			if(c) break;
		}	
		
		switch(c)
		{
			case 1: printf("%d입력\n" , c);num[i]=1;i++; break; 
			case 2: printf("%d입력\n" , c);num[i]=2;i++; break; 
			case 3: printf("%d입력\n" , c);num[i]=3;i++; break; 
			case 4: printf("%d입력\n" , c);num[i]=4;i++; break; 
			case 5: printf("%d입력\n" , c);num[i]=5;i++; break; 
			case 6: printf("%d입력\n" , c);num[i]=6;i++; break; 
			case 7: op='+';printf("%c입력\n" , op);break; 
			case 8: op='-';printf("%c입력\n" , op);break; 
			case 9: op='*';printf("%c입력\n" , op);break; 
			case 10: op='/';printf("%c입력\n" , op);break; 
			case 11: calc(num , op , &i); break; 
			case 12: printf("Shutdown!\n"); return;

		}
	}
	close(tact);
	return 0;
	
}

void calc(int *num , char op , int *i)
{
	int clcd_d , rst;
	char data[6];
	clcd_d = open(clcd , O_RDWR);

	if(clcd_d <0)
	{
		printf("디바이스 드라이버가 없습니다.\n");
		return;
	}

	switch(op)
	{
		case '+':rst = num[0]+num[1];break;
		case '-':rst = num[0]-num[1];break;
		case '*':rst = num[0]*num[1];break;
		case '/':rst = num[0]/num[1];break;
	}
	
	data[0] = num[0]+'0';
	data[1] = op;
	data[2] = num[1]+'0';
	data[3] = '=';
	data[4] = (rst/10)+'0';
	data[5] = (rst%10)+'0';	

	write(clcd_d , data , 6);
	*i = 0;
	close(clcd_d);
}
