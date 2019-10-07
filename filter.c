#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float start[2] = {0}, final[2] = {0};
	float vi[2], cache;
	char rec, buffer[10] = {0};
	FILE *fr = NULL, *fw = NULL;
	int sp = 0, head = 0, tail = 0;

	if((fr = fopen(argv[1], "r")) == NULL){
		printf("Open read file %s failed ! \n", argv[1]);
		return -1;
	}
	/*
	if((fp = fopen(argv[2])) == NULL){
		printf("Open file %s failed ! \n", argv[2]);
		return -1;
	}
	*/

	while((rec = fgetc(fr)) != EOF){
		if(rec == ','){
			buffer[sp] = '\0';
			cache = atof(buffer);
			sp = 0;
			memset(buffer, '0', 10);
			vi[head] = cache;
			if(vi[head] + vi[(head + 1)%2] > 0.0)
				printf("%f,", vi[head]);
				if(vi[head] == 0.0 && vi[(head + 1)%2] != 0.0)
					printf("\n");
			head = (head + 1) % 2;
		}
		else{
			buffer[sp++] = rec;
		}
	}

	fclose(fr);

	return 0;
}
