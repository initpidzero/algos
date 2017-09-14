#include <stdio.h>
void insert(int *array, int len)
{
	int i;
	for(i = 1; i < len; i++) {
		int j = i -1;
		int key =  array[i];
		while(j >=0 && array[j] > key){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	} 
}
void bubble(int *array, int len)
{

	int i ;
	int j;
	for(i = 0; i < len; i++)
		for(j = len - 1; j > i; j--) {
			int temp = array[j];
			if(array[j] < array[j - 1]) {
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
}

int main (void)
{
	int array[] = {-10,9,8,7,6,5,-100,4,3,2,1, 90909, -88888};
	int i;
	int len = sizeof(array)/sizeof(array[0]);
	void (*f)( int*, int);
	//f =  insert;
	f =  bubble;
	f(array, len);

	for(i = 0; i < len; i++) {
		printf("a[%d]=%d\n",i,array[i]);
	}
	return 0;
}
