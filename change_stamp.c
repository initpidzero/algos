#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char cmd[BUFSIZ];

	struct stat sb,bs;
struct tm *tm;
tm = localtime(&bs.st_mtime);
	printf("%d\n",stat(argv[1], &sb));
	printf("%d\n",stat(argv[2], &bs));
	printf("%s\n",argv[1]);
	printf("%s\n",argv[2]);
	printf("Last file modification:   %s\n", ctime(&sb.st_mtime));
	printf("Last file localtime:   %d:%d:%d\n", tm->tm_year,tm->tm_mon,tm->tm_mday);
	printf("Last file modification:   %ld\n", bs.st_mtime);
//	sprintf(cmd, "touch -d\"%s\" %s",ctime(&sb.st_mtime),argv[2]);
//	system(cmd);
	return 0;
}
