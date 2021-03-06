#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 512
    
// 자식 저장소
// child는 서브모둘입니다.
// 엄마 100원 주세요.

int main()
{
    char msg[SIZE];
    int filedes[2];
    int i;

    if(pipe(filedes) == -1)
    {
        printf("fail to call pipe()\n");
        exit(1);
    }

    for(i = 0; i < 3; i++)
    {
        printf("input a message (%d)\n", i);
        fgets(msg, SIZE, stdin);
        write(filedes[1], msg, SIZE);
    }

    printf("\n");
    for(i = 0; i < 3; i++)
    {
        read(filedes[0], msg, SIZE);
        printf("%s", msg);
    }
    return 0;
}