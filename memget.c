#include<stdio.h>

#define GIG 1000000000

int main(int argc, char **argv){
	int *ptr;

	ptr = (int *)malloc(GIG);
	if (ptr == NULL){
		printf("Could not allocate memory!\n");
		return 1;
	}
	while(1){
		sleep(20);
	}
	return 0;
}
