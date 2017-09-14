#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[16] = "string1,string2";
	char *string2 = string;
	char *string1 = strsep(&string2, ",");
	char new[10], old[10];
	printf("string 1 = %s, string 2 = %s\n", string1, string2);
	strcpy(new, string1);
	strcpy(old, string2);
	printf("string 1 = %s, string 2 = %s\n", new, old);
	return 0;
}
