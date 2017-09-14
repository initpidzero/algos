#include <stdio.h>
#define IMG_SRC "<img src=\"./images/%s.png\"/>"
int main (void)
{
	char subtest[][256] = {"INFO_RT_", "FR_RT_", "UTIL_", "FR_LOSS_"};
	printf("%d\n", sizeof(subtest)/sizeof(subtest[0]));
	printf(IMG_SRC,"bullshit");
	return 0;
}
