#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

#define MAX_WORDS 1000

sem_t sem;

char words[MAX_WORDS][50];
int wordCount = 0;	
		

void *readWord(void *a) {
	FILE *fp;
	char word[50];
	
	fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        printf("ERROR: File Not Found\n");
        exit(1);
    }	
    else 
    {
        while(fscanf(fp, "%s", word) != EOF)
        {
            sem_wait(&sem);			
            strcpy(words[wordCount], word);	
            wordCount++;					
            sem_post(&sem);			
        }

        fclose(fp);							

        return NULL;
    }
}

void *printWord(void *a) 
{
    
	while(1) 
    { 
		sem_wait(&sem);		
		if(wordCount > 0) 
        {	
            printf("%s\n", words[wordCount-1]); 
            wordCount--;		
		}
		sem_post(&sem);			
		sleep(1);						
	}
    return NULL;
}

int main(int argc, char *argv[]) 
{
	pthread_t thread1;
    pthread_t thread2;
	
	sem_init(&sem, 0, 1);
	
	pthread_create(&thread1, NULL, readWord, NULL);
	pthread_create(&thread2, NULL, printWord, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	sem_close(&sem);
	
	return 0;
}