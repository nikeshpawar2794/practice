#include<stdio.h>
#include <pthread.h>

void *greed(void *arg)
{
	printf("Hello \n");
}

int main()
{

pthread_t threadid;
printf("Before thread \n");
pthread_create(&threadid, NULL, greed, NULL);
pthread_join(threadid,NULL);
printf("After thread \n");

	return 0;
}
