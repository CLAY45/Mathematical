#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define STACK_LENGTH	180

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	int ret, sp = 0;
	long counter =0;
	char stack[STACK_LENGTH], rec;
	fp = fopen(argv[1], "r");
	
	while((rec = fgetc(fp)) != EOF){
		counter++;
		if(rec == '0'){
			if(sp == STACK_LENGTH - 1){
				printf("count : %ld \n", counter);
				sp = 0;
			}
			stack[sp++] = rec;
		}
		else if(sp <= STACK_LENGTH - 1){
			memset(stack, '0', STACK_LENGTH);
			sp = 0;
		}
	}

	fclose(fp);

	return 0;
}
