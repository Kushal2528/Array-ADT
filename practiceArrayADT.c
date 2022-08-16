#include <stdio.h>
#include <stdlib.h>
typedef struct Array
{
	int len;
	int size;
	int* item;
}Arr;

Arr* create(int usize);
int get(Arr* ptr, int idx);
void set(Arr* ptr, int idx, int value);
void del(Arr* ptr, int idx);
int len(Arr* ptr);
void update(Arr* ptr, int idx, int value);

int main() 
{
/******************************************************/
	Arr* myArr = create(5);
	for(int i=0; i<5; i++)
	{
		set(myArr, i, i+71);
	}
	for(int i=0; i<len(myArr); i++)
	{
		printf("%d ", get(myArr, i));
	}
/******************************************************/
	del(myArr, 2);
	del(myArr, 3);

	puts("\nAfter deleting items from index 2 and 3:");
	for(int i=0; i<len(myArr); i++)
	{
		printf("%d ", get(myArr, i));
	}

/******************************************************/

	for(int i=0; i<len(myArr); i++)
	{
		update(myArr, i, i+91);
	}	
	puts("\nAfter updating:");

	for(int i=0; i<len(myArr); i++)
	{
		printf("%d ", get(myArr, i));
	}

/******************************************************/
	return 0;
}




Arr* create(int usize)
{
	Arr* ptr= (Arr*)malloc(sizeof(Arr));
	ptr->size=usize;
	ptr->len=0;
	ptr->item=(int* )calloc(usize, sizeof(int));
	printf("Array of size %d created..\n", usize);
	return ptr;
}

int get(Arr* ptr, int idx)
{
	if(idx<0 || idx>ptr->len)
	{
		printf("get(): Invalid index(%d)..\n", idx);
		return -1;
	}
	else
	{
		return ptr->item[idx];
	}
}

void set(Arr* ptr, int idx, int value)
{
	if(ptr->len == ptr->size)
	{
		printf("set(): Array is full..\n");
		return;
	}
	else if(idx<0 || idx>ptr->len)
	{
		printf("set(): Invalid index(%d)..\n",idx);
		return;
	}
	else
	{
		ptr->len++;
		for(int i=ptr->len-1; i>idx; i--)
		{
			ptr->item[i]=ptr->item[i-1];
		}
		ptr->item[idx]=value;
	}
}

void del(Arr* ptr, int idx)
{

	if(idx<0 || idx >= ptr->len)
	{
		printf("del(): Invalid index(%d)..\n",idx);
		return;
	}
	else
	{
		for(int i=idx; i<ptr->len-1; i++)
		{
			ptr->item[i]=ptr->item[i+1];
		}
		ptr->len--;
		return;
	}	
}

void update(Arr* ptr, int idx, int value)
{
	if(idx<0 || idx>=ptr->len)
	{
		printf("update(): Invalid index(%d)..\n", idx);
		return;
	}
	else
	{
		ptr->item[idx]=value;
		return;
	}
}

int len(Arr* ptr)
{
	return ptr->len;
}
