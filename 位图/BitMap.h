// BitMap.h
#include <stdbool.h>
#include <stdint.h>

typedef uint32_t Word;   // uint32_t: 1.��Сȷ�� (32bits);  2.�޷�������

typedef struct {
    Word* array;
    size_t bits;	    // λ����ĳ���
} BitMap;

BitMap* bitmap_create(size_t bits);
void bitmap_destroy(BitMap* bm);

void bitmap_set(BitMap* bm, size_t n);	// n is a bit index
void bitmap_unset(BitMap* bm, size_t n);
bool bitmap_isset(BitMap* bm, size_t n);
void bitmap_clear(BitMap* bm);
