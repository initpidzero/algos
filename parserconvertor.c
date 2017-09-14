#include <stdio.h>
#include <string.h>
#define HTML_HEADER "<html> <head> </head> <body>"
#define HTML_FOOTER "</body> </html>" 
#define HTML_FILE "SignalTEK-II_report.html"
struct {
	char content[256];
} element;
struct {
	char caption[256];
	int rows;
	int col;
	int r_bold;
	int c_bold;
	struct element *e_data[12];
} table_html;
void whatever(char what[][256])
{
 printf("%s",what[0]);
}
int main (void)

{
char what[][256] = {"what", "not"};
whatever(what);
	FILE *fp = fopen(HTML_FILE, "w");
	fprintf(fp,"%s\n %s\n", HTML_HEADER, HTML_FOOTER);
	fclose(fp);
}
