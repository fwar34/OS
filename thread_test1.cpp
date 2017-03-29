/*************************************************************************
  > File Name: thread_test1.cpp
  > Author: Feng
  > Created Time: Tue 28 Mar 2017 05:49:44 PM CST
  > Content: 
 ************************************************************************/

#include <iostream>

using namespace std;

/*thread.c*/  
#include <stdio.h>  
#include <pthread.h>  

/*线程一*/  
void* thread_1(void*)  
{  
	int i=0;  
	for(i=0;i<=6;i++)  
	{  
		printf("This is a pthread_1. tid(%lu)\n", pthread_self());  
		if(i==2)  
			pthread_exit(0);  
		//sleep(1);  
	}  
	return NULL;
}  

/*线程二*/  
void* thread_2(void*)  
{  
	int i;  
	for(i=0;i<3;i++)  
		printf("This is a pthread_2. tid(%lu)\n", pthread_self());  
	pthread_exit(0);  
	return NULL;
}  

int main(void)  
{  
	pthread_t id_1,id_2;  
	int i,ret;  
	/*创建线程一*/  
	ret=pthread_create(&id_1,NULL,thread_1,NULL);  
	if(ret!=0)  
	{  
		printf("Create pthread error!\n");  
		return -1;  
	}  
	/*创建线程二*/  
	ret=pthread_create(&id_2,NULL,thread_2,NULL);  
	if(ret!=0)  
	{  
		printf("Create pthread error!\n");  
		return -1;  
	}  
	printf("id_1(%lu), id_2(%lu)\n", id_1, id_2);
	/*等待线程结束*/  
	pthread_join(id_1,NULL);  
	pthread_join(id_2,NULL);  
	return 0;  
}  
