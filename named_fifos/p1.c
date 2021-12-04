#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
int fd;
mkfifo("nikfifo",S_IRUSR | S_IWUSR);
fd= open("nikfifo",O_WRONLY);
write(fd,"Hello World\n",12);
close(fd);
return 0;
}