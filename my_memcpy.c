#include<stdio.h>
#include<malloc.h>

void my_strcpy(char *dest,char *src)
{
	while(*src){
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}

void my_memcpy(char *dest,char *src,int size)
{
	while(size-->0){
		*dest = *src;
		dest++;
		src++;
	}
}

int main()
{
	char *src = (char *)malloc(sizeof(char)*20);
	my_strcpy(src,"ABCDEFGHIJKLM");
	char *dest = (char *)malloc(sizeof(char)*20);
	my_memcpy(dest,src,5);
	printf("src =  %s\n",src);
	printf("dest = %s\n",dest);

// Behaviour in overlap case
	char *p1 = (char *)malloc(sizeof(char)*20);
	char *p2;
	my_strcpy(p1,"ABCDEFGHIJ");
	p2 = p1 + 2;
	printf("BEFORE src =  [%s]\n",p1);
	printf("BEFORE dest = [%s]\n",p2);

	my_memcpy(p2,p1,5);
	printf("AFTER src =  [%s]\n",p1);
	printf("AFTER dest = [%s]\n",p2);
/*
BEFORE src =  [ABCDEFGHIJ]
BEFORE dest = [CDEFGHIJ]
AFTER src =  [ABABABAHIJ]
AFTER dest = [ABABAHIJ]
*/
// Behaviour in non overlap case
	printf("Non overlap case\n");
	my_strcpy(p1,"ABCDEFGHIJ");
	p2 = p1 + 5;
	printf("BEFORE src =  [%s]\n",p1);
	printf("BEFORE dest = [%s]\n",p2);

	my_memcpy(p2,p1,3);
	printf("AFTER src =  [%s]\n",p1);
	printf("AFTER dest = [%s]\n",p2);
	/*  
Non overlap case
BEFORE src =  [ABCDEFGHIJ]
BEFORE dest = [FGHIJ]
AFTER src =  [ABCDEABCIJ]
AFTER dest = [ABCIJ]
*/
	return 0;
}