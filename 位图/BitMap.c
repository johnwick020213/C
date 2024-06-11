#include "BitMap.h"
#include<stdlib.h>	
#include <stdio.h>
#include <string.h>

#define BITS_PER_WORD 32//һ�����ĸ��ֽڣ�һ���ֽڰ�λ��ÿ����32λ
#define BITMAP_SHIFT   5 // 2^5 = 32
#define BITMAP_MASK 0x1F
// �洢bitsλ����Ҫ���ٸ�word
#define BITMAP_SIZE(bits) ((bits + BITS_PER_WORD - 1) >> BITMAP_SHIFT)

// bits: λͼ�ĳ���
BitMap* bitmap_create(size_t bits) {
	BitMap* bm = malloc(sizeof(BitMap));

	bm->array = (Word*)calloc(BITMAP_SIZE(bits), sizeof(Word));
	bm->bits = bits;

	return bm;
}

void bitmap_destroy(BitMap* bm) {
	free(bm->array);
	free(bm);
}

// ����λͼ�������ܹ�����bitsλ
void grow_capacity(BitMap* bm, size_t bits) {
	// λͼ���ڴ���յ����ݽṹ��
	// ���ݲ��ԣ���Ҫ��󣬾���������ڴ�ռ�
	uint32_t* new_array = realloc(bm->array, BITMAP_SIZE(bits) * sizeof(Word));
	if (!new_array) {
		printf("Error: realloc failed in grow_capacity\n");
		exit(1);
	}
	bm->array = new_array;
	// �����ݵĲ�����Ϊ0
	int bytes = (BITMAP_SIZE(bits) - BITMAP_SIZE(bm->bits)) * sizeof(Word);
	memset(bm->array + BITMAP_SIZE(bm->bits), 0, bytes);
}

// ��������Ϊn��λ
// 100, 32 * 4 = 128
void bitmap_set(BitMap* bm, size_t n) {
	if (n >= bm->bits) {
		if (BITMAP_SIZE(n + 1) > BITMAP_SIZE(bm->bits)) {
			// ����
			grow_capacity(bm, n + 1);
		}
		bm->bits = n + 1;
	}
	// ���õ�nλ 
	// ��α�ʾ��nλ (word, offset)
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	bm->array[word] |= (0x1 << offset);
}

void bitmap_unset(BitMap* bm, size_t n) {
	if (n >= bm->bits) {
		return;
	}
	// �ҵ���nλ (word, offset)
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	bm->array[word] &= ~(0x1 << offset);
}

bool bitmap_isset(BitMap* bm, size_t n) {
	if (n >= bm->bits) {
		return false;
	}
	// �ҵ���nλ (word, offset)
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	return bm->array[word] & (0x1 << offset);
}

void bitmap_clear(BitMap* bm) {
	size_t bytes = BITMAP_SIZE(bm->bits) * sizeof(Word);
	memset(bm->array, 0, bytes);
}