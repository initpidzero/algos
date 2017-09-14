#include <stdio.h>
int main (void)
{
	int array[] = {-10,9,8,7,6,5,-100,4,3,2,1, 90909, -88888};
	int i;
	int len = sizeof(array)/sizeof(array[0]);
	for(i = 1; i < len; i++) {
		int j = i -1;
		int key =  array[i];
		while(j >=0 && array[j] > key){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}

	for(i = 0; i < len; i++) {
		printf("a[%d]=%d\n",i,array[i]);
	}
	return 0;
}
