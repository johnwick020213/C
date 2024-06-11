#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include"BitMap.h"
#include<string.h>
/*×¢ÊÍ*/

void remove_duplicate_and_sort(char* str)
{
	BitMap*map= bitmap_create(26);
	int lenth = strlen(str);
	for(int j=0;j<lenth;j++)
	{
		bitmap_set(map, str[j] - 96);
	}
	
	for (int i = 0; i <26 ; i++)
	{
		if (bitmap_isset(map, i))
		{
			printf("%c", (char)(i + 96));
		}
	}
	bitmap_clear(map);
}
int main(void)
{
	char* s = "sfjkljfsaldjfsldfcdjkjfkkd";
	remove_duplicate_and_sort(s);
	return 0;
}