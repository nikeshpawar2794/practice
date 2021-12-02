#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define size 100
int main(int argc, char *argv[])
{
    pid_t id;
    char buff[size];
    int pid1id[2];
    pipe(pid1id);
    id = fork();
    
    if(id == 0)
    {
	    printf("Child Process\n");
        read(pid1id[0],buff,size);
        printf("%s",buff);  
    }

    else
    {
        printf("Parent Process \n");
        close(pid1id[0]);
        write(pid1id[1],"Buffer Data\0",12);
        printf("data sent sucessfully \n");

    }
           return 0;
}
