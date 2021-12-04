#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
int fd;
char buff[100];
mkfifo("nikfifo",S_IRUSR | S_IWUSR);
fd= open("nikfifo",O_RDONLY);
read(fd,buff,100);
printf("in p2 %s\n",buff);
close(fd);
return 0;
}