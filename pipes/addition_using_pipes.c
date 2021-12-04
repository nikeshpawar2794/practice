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
    int pid2[2];
    pipe(pid1);
    pipe(pid2);

    id = fork();
    
    if(id == 0)
    {
        close(pid1[1]);	    
        
        //read(pid1[0],buff,size);
        read(pid1[0],arr,size);
        printf("%d %d\n",arr[0],arr[1]); 
        printf("Child Process\n"); 
        close(pid1[0]);


        close(pid2[0]);
        sum=arr[0] + arr[1];
        write(pid2[1],&sum,sizeof(sum));
        close(pid2[1]);
    }

    else
    {
        printf("Parent Process \n");
        close(pid1[0]);
        
        
        printf("Enter two integer's : ");
        scanf("%d %d",&arr[0],&arr[1]);
        write(pid1[1],arr,sizeof(arr));
       
        printf("data sent successfully \n");
        close(pid1[1]);


        close(pid2[1]);
        read(pid2[0],&sum,sizeof(sum));
        printf("Additon = %d\n",sum);
        printf("data Received from child successfully \n");

    }
           return 0;
}
