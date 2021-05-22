#include<stdio.h>

#define MY_SIZEOF(type)	((char *)((type *) 0 + 1) - (char *)((type *)0))

#define MY_SIZEOF_NEW(obj)	((char *)(&obj + 1) - (char *)(&obj))

struct my{
	char a[4];
	int b;
	int c;
};
typedef struct my MY;


int main()
{
	int x;
	float y;
	MY my_obj;
	printf("Size of int = %lu\n",MY_SIZEOF(int));
	printf("Size of char = %lu\n",MY_SIZEOF(char));
	printf("Size of long = %lu\n",MY_SIZEOF(long));
	printf("Size of short = %lu\n",MY_SIZEOF(short));
	printf("Size of pointer int = %lu\n",MY_SIZEOF(int *));
	printf("Size of pointer struct = %lu\n",MY_SIZEOF(MY));
	printf("Size of pointer struct ptr = %lu\n",MY_SIZEOF(MY *));

//Second way, in which need to pass a obj;

	printf("Size of x int = %lu\n",MY_SIZEOF_NEW(x));
	printf("Size of y Float = %lu\n",MY_SIZEOF_NEW(y));
	printf("Size of my_obj Float = %lu\n",MY_SIZEOF_NEW(my_obj));

	return(0);

}
