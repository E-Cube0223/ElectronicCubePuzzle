#include<stdio.h>
#include"make_log.h"

FILE *fp;

void setup_log(const char file_name[]){
	fp = fopen(file_name, "w");
	if(fp==NULL){
		printf("�t�@�C�����J���܂���ł���\n");
	}
}

void endup_log(void){
	fclose(fp);
	printf("�t�@�C������܂���");
}

//fprintf(fp,"%s,%s",ts,te);