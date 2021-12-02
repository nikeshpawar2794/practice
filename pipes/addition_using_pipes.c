#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define size 100
int main(int argc, char *argv[])
{
    int arr[2],sum;
    pid_t id;
    char buff[size];
    int pid1[2];
    pipe(pid1);
    id = fork();
    
    if(id == 0)
    {
	    printf("Child Process\n");
        //read(pid1[0],buff,size);
        read(pid1[0],arr,size);
        printf("%d %d\n",arr[0],arr[1]);  
    }

    else
    {
        printf("Parent Process \n");
        close(pid1[0]);
        
        
        printf("Enter two integer's : ");
        scanf("%d %d",&arr[0],&arr[1]);
        write(pid1[1],(int *)arr,8);
        printf("data sent successfully \n");

    }
           return 0;
}
