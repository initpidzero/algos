#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void Munge32( void *data, uint32_t size ) 
{
	int i = 0;
	uint32_t *data32 = (uint32_t*) data;
	uint32_t *data32End = data32 + (size >> 2); /* Divide size by 4. */
	uint8_t *data8 = (uint8_t*) data32End;
	uint8_t *data8End = data8 + (size & 0x00000003); /* Strip upper 30 bits. */

	printf("\n\n data32 begining %p data32 end %p\n", data32, data32End);
	printf("data8 begining %p data8 end %p\n", data8, data8End);
	while( data32 != data32End ) {
		printf("%dth iteration = %p \n",i++, data32);
		*data32++ = -*data32;
	}
	i = 0;
	while( data8 != data8End ) {
		printf("%dth iteration = %p \n",i++, data8);
		*data8++ = -*data8;
	}
}


void Munge16( void *data, uint32_t size ) 
{
	int i = 0;

	uint16_t *data16 = (uint16_t*) data;
	uint16_t *data16End = data16 + (size >> 1); /* Divide size by 2. */
	uint8_t *data8 = (uint8_t*) data16End;
	uint8_t *data8End = data8 + (size & 0x00000001); /* Strip upper 31 bits. */

	printf("\n\n data16 begining %p data16 end %p\n", data16, data16End);
	printf("data8 begining %p data8 end %p\n", data8, data8End);

	while( data16 != data16End ) {
		printf("%dth iteration = %p \n",i++, data16);
		*data16++ = -*data16;
	}

	i = 0;
	while( data8 != data8End ) {
		printf("%dth iteration = %p \n",i++, data8);
		*data8++ = -*data8;
	}
}

void Munge8( void *data, uint32_t size ) 
{
	int i = 0;

	uint8_t *data8 = (uint8_t*) data;
	uint8_t *data8End = data8 + size;

	printf("\n\n data8 begining %p data8 end %p\n", data8, data8End);
	while( data8 != data8End ) {
		printf("%dth iteration = %p \n",i++, data8);
		*data8++ = -*data8;
	}
}

int main (void)
{
	void *something;
	size_t size = 0xff;
	time_t t, t1;
	something = malloc(size);
	time(&t);
	Munge8(something, size); 
	time(&t1);
	printf("%f\n", difftime(t1,t));
	Munge16(something, size); 
	time(&t);
	printf("%f\n", difftime(t,t1));
	Munge32(something, size); 
	time(&t1);
	printf("%f\n", difftime(t1,t));

}
