#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(void)
{

	struct dirent **namelist;
	int n;
	const char *targetdirectory = ".";

	n = scandir(targetdirectory, &namelist, 0, alphasort);
	struct stat buf;
	if (n < 0) {
		perror("scandir");
	} else {
		while (n--) {
			stat(namelist[n]->d_name, &buf);
			printf("entry number = %d %-23s  %10ld \t %s \n", n, namelist[n]->d_name,
			       buf.st_mtime, ctime(&buf.st_mtime));
			free(namelist[n]);
        }
        free(namelist);
    }

    return 0;
}
