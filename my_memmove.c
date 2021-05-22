#include<stdio.h>
#include<string.h>
#include<malloc.h>

void my_memmove(char *dest,char *src,int size)
{
	char *p1 = dest;
	char *p2 = src;
	p2 = p2 + size;
	//need to check overlap;
	while(p2!=src && --p2!=dest);
		//p2--;

	if(p2!=src) { //means ovelap copy from back;
		printf("OVERLAP CASE\n");
		p2 = src;
		p1 = p1 + size;// -1;
		p2 = p2 + size;// -1;
		while(size-- != 0) {
			*--p1 = *--p2;
			// *p1 = *p2;
			// p1--;
			// p2--;
		}
	}else {  // Overlap from front or no ovelap case
		printf("NON OVERLAP CASE\n");
		while(size-- != 0) {
			*p1++ = *p2++;
			// p1++;
			// p2++;
		}
	}
}


int main()
{
	char *src = (char *)calloc(20,sizeof(char));
	char *dest;
	strcpy(src,"ABCDEFGHIJK");
	dest = src + 2;
	printf("BEFORE src =  [%s]\n",src);
	printf("BEFORE dest = [%s]\n",dest);
	
	my_memmove(dest,src,5);

	printf("AFTER src =  [%s]\n",src);
	printf("AFTER dest = [%s]\n",dest);
	return(0);

}