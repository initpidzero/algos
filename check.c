#include <stdio.h>

struct check
{
int func(void);
};
int main(void)
{
	const char var2 = 10;
	const int *var1 = (const int *)&var2;
	int *const var = var1;

	printf("%p\n", &var);
	printf("%p\n", var);
	printf("%d\n", *var1);
	printf("%p\n", var1);
	printf("%p\n", &var2);
	return 0;
}
