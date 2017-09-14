#include <stdio.h>

int main(void)
{
	char string[10];
	int i;
	for(i = 0; i <10; i++) {
		sprintf(string, "%.2d:%.2d:%.2d",i,i+2,i+10);

		printf("%s\n", string);
	}
	return 0;
}
