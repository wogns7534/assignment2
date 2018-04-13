#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);


int main(void)
{
   filestat1();
   filestat2();
   filetime1();
   filetime2();
   sizecmp();
   blockcmp();
   datecmp();
   timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
   stat("text1", &stat1);//text1 size,blocks 크기 저장
   printf("text1 size: %d\n", (int)stat1.st_size);
   printf("text1 blocks : %d\n", (int)stat1.st_blocks);
   return;
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
   stat("text2", &stat2);//text1 size,blocks 크기 저장
   printf("text2 size: %d\n", (int)stat2.st_size);
   printf("text2 blocks : %d\n", (int)stat2.st_blocks);
   return;
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
   struct stat buf;
   struct tm* time;//시간정보가져오기
   
   stat("text1", &buf);
   time = localtime(&buf.st_mtime);//시간정보가져오기
   printf("Time information of text1\n");
   printf("month : %d\n", time->tm_mon+1);
   printf("date : %d\n", time->tm_mday);
   printf("hour : %d\n", time->tm_hour);
   printf("min : %d\n", time->tm_min);
   return;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
   struct stat buf;
   struct tm* time;//시간정보가져오기

   stat("text2", &buf);
   time = localtime(&buf.st_mtime);//시간정보가져오기
   printf("Time information of text2\n");
   printf("month : %d\n", time->tm_mon + 1);
   printf("date : %d\n", time->tm_mday);
   printf("hour : %d\n", time->tm_hour);
   printf("min : %d\n", time->tm_min);
   return;

}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	printf("size compare\n");

	if((int)stat1.st_size > (int)stat2.st_size)
	printf("text1 is bigger\n");
	else
	printf("text2 is bigger\n");

	return;
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	printf("block compare\n");

	if((int)stat1.st_blocks > (int)stat2.st_blocks)
        printf("text1 is bigger\n");
        else
        printf("text2 is bigger\n");

        return;
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
}
