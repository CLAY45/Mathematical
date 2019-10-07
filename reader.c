#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct element
{
	float speed;
	float acc_x;
	float acc_y;
	float acc_z;
	float longitude;
	float latitude;
	int rotat;
	int torque;
	float fuel;
	float throttle;
	float airfuel;
	int load;
	float airflow;
}parameter;

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char buffer[10] = {0}, rec;
	int i = 0, sp = 0;
	parameter *cache = (parameter *)malloc(sizeof(parameter));

	fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("file %s open failed ! \r\n", argv[1]);
		return -1;
	}

//	printf("address cache :%#x \r\n", cache);

	while((rec = fgetc(fp)) != EOF){
		if(rec == ','){
			buffer[sp] = '\0';
			switch(i)
			{
				case 0:	cache->speed = atof(buffer);break;
				case 1:	cache->acc_x = atof(buffer);break;
				case 2:	cache->acc_y = atof(buffer);break;
				case 3:	cache->acc_z = atof(buffer);break;
				case 4:	cache->longitude = atof(buffer);break;
				case 5:	cache->latitude = atof(buffer);break;
				case 6:	cache->rotat = atoi(buffer);break;
				case 7:	cache->torque = atoi(buffer);break;
				case 8:	cache->fuel = atof(buffer);break;
				case 9:	cache->throttle = atof(buffer);break;
				case 10:	cache->airfuel = atof(buffer);break;
				case 11:	cache->load = atoi(buffer);break;
				case 12:	cache->airflow = atof(buffer);break;
				default:	break;
			}
			memset(buffer, '0', 10);
			sp = 0;
			i++;
			continue;
		}
		else if(rec == '\n'){
			//printf("\n");
			memset(buffer, '0', 10);
			sp = 0;
			i = 0;
			if(cache->speed >= 10)
				printf("%f,%f,%f,%f,%f,%f,%d,%d,%f,%f,%f,%d,%f \r\n", cache->speed, cache->acc_x, cache->acc_y, cache->acc_z, cache->longitude, cache->latitude, cache->rotat, cache->torque, cache->fuel, cache->throttle, cache->airfuel, cache->load, cache->airflow);
		}
		else
			buffer[sp++] = rec;
	}


	free(cache);
	fclose(fp);
	fp = NULL;

	return 0;
}
