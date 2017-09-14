#include <stdio.h>
int main(void)
{
	int secs = 99; 
	int hh = secs / 3600,mm,ss;   
	if(hh == 0)
		mm = secs / 60;
	else
		mm = (secs % 3600) / 60;
	ss = secs % 60; 

	printf("%02d:%02d:%02d",hh,mm,ss);
	return 0;
}
