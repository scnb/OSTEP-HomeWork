#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int pipefd[2];
	int BUF_SIZ = 10;
	char buf[4];
    int rc1 = fork();
	if (rc1 < 0)
	{
		fprintf(stderr,"fork failed\n");
		exit(1);
	}	
	else if (rc1 == 0)
	{
		close(pipefd[0]);			     //子进程1向管道写入数据，关闭管道的读端
		write(pipefd[1],"test",4);
		exit(0);
	}
	int rc2 = fork();
	if (rc2 < 0)
	{
		fprintf(stderr,"fork failed\n");
		exit(1);
	}
	else if (rc2 == 0)
	{
		close(pipefd[1]);				//子进程2从管道读取数据，关闭管道的写端
		int len = read(STDIN_FILENO,buf,BUF_SIZ);
		for (int i = 0;i < len;i++)
		{
			printf("%c",buf[i]);
		}
		printf("\n");
		exit(0);
	}
	return 0;
}
