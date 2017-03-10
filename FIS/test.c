#include<stdio.h>

char * dispchar()
{
	char *name = "fileName";
	return name;
}
int main()
{
	char *try = "try";
	char *name = dispchar();
	
	printf("%s,%s",name,try);
	return 0;
}
