#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "html_str.h"

int translate_string(char *dest, const char *src)
{
	int lang = 2;

	char *buffer, *tmp;
	FILE *fp;
	int i = 0,j;

	printf("DEBUG FILE=%s FUNCTION=%s LINE=%d\n",__FILE__,__FUNCTION__,__LINE__);
	fp = fopen("tr.txt", "r");
	if(!fp)
		fprintf(stderr, "what happened here \n");
	memset(dest, 0, MAX_STRING_LEN);
	buffer = (char *)malloc(BUFSIZ);
	for(j = 0; j < total_string; j++) {
		memset(buffer, 0, BUFSIZ);
		if(fgets(buffer, BUFSIZ,fp) == NULL)
			break;
		printf("buffer=%s FUNCTION=%s LINE=%d\n",buffer,__FUNCTION__,__LINE__);
		tmp = strtok(buffer, ",");
		printf("token = %s\n",tmp);
		if(!strcmp(src, tmp)) {
			while(i <= lang) {
				tmp = strtok(NULL, ",");
				i++;
			}
			strcpy(dest, tmp);
			printf("****%s****\n",dest);
			break;
		}
		printf("token=%s FUNCTION=%s LINE=%d\n",tmp,__FUNCTION__,__LINE__);
	}

	printf("DEBUG FILE=%s FUNCTION=%s LINE=%d\n",__FILE__,__FUNCTION__,__LINE__);
	if(!strlen(dest))
		strcpy(dest, src);

	printf("DEBUG FILE=%s FUNCTION=%s LINE=%d\n",__FILE__,__FUNCTION__,__LINE__);
	fclose(fp);
	free(buffer);
	buffer = NULL;

	return 0;
}

int main (void)
{
	int i;
	char buffer[BUFSIZ];
	for (i = 0; i < total_string;i++) {
		memset(buffer, 0, BUFSIZ);
		translate_string(buffer, table_heading_strings[i]);
		printf("%s\n",buffer);
	}
	return 0;
}
