#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int vi[2], cache, i, j;
	char rec, buffer[10] = {0};
	FILE *fr = NULL, *fw = NULL;
	int sp = 0, head = 0, tail = 0;
	int trans[4][4] = {0};
	float Ptrans[4][4] = {0};


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
		if(rec == '\n')
			break;
		if(rec == ','){
			buffer[sp] = '\0';
			cache = atoi(buffer);
			sp = 0;
			memset(buffer, '0', 10);
			vi[head] = cache;
			head = (head + 1) % 2;
			if(vi[(head + 1)%2] != 0){
				if(vi[head] == 1 && vi[(head + 1)%2] == 1)	trans[0][0]++;
				if(vi[head] == 1 && vi[(head + 1)%2] == 2)	trans[0][1]++;
				if(vi[head] == 1 && vi[(head + 1)%2] == 3)	trans[0][2]++;
				if(vi[head] == 1 && vi[(head + 1)%2] == 4)	trans[0][3]++;
				if(vi[head] == 2 && vi[(head + 1)%2] == 1)	trans[1][0]++;
				if(vi[head] == 2 && vi[(head + 1)%2] == 2)	trans[1][1]++;
				if(vi[head] == 2 && vi[(head + 1)%2] == 3)	trans[1][2]++;
				if(vi[head] == 2 && vi[(head + 1)%2] == 4)	trans[1][3]++;
				if(vi[head] == 3 && vi[(head + 1)%2] == 1)	trans[2][0]++;
				if(vi[head] == 3 && vi[(head + 1)%2] == 2)	trans[2][1]++;
				if(vi[head] == 3 && vi[(head + 1)%2] == 3)	trans[2][2]++;
				if(vi[head] == 3 && vi[(head + 1)%2] == 4)	trans[2][3]++;
				if(vi[head] == 4 && vi[(head + 1)%2] == 1)	trans[3][0]++;
				if(vi[head] == 4 && vi[(head + 1)%2] == 2)	trans[3][1]++;
				if(vi[head] == 4 && vi[(head + 1)%2] == 3)	trans[3][2]++;
				if(vi[head] == 4 && vi[(head + 1)%2] == 4)	trans[3][3]++;
			}
			else	continue;
		}
		else{
			buffer[sp++] = rec;
			tail = 0;
		}
	}

	fclose(fr);

	for(i = 0;i < 4;i++){
		for(j = 0;j < 4;j++)
			printf("%d\t", trans[i][j]);
		printf("\n");
	}

	for(i = 0;i < 4;i++){
		for(j = 0;j < 4;j++)
			tail += trans[i][j];
		for(j = 0;j < 4;j++)
			Ptrans[i][j] = (float)trans[i][j] / tail;
		tail = 0;
	}

	for(i = 0;i < 4;i++){
		for(j = 0;j < 4;j++)
			printf("%f\t", Ptrans[i][j]);
		printf("\n");
	}
	return 0;
}
