#include <stdint.h>

typedef char* K;
typedef char* V;

// ����������
typedef struct entry {
	K key;
	V val;
	struct entry* next;
} Entry;

typedef struct {
	Entry** table;
	int size;		// ��ֵ�Եĸ���
	int capacity;
	uint32_t hashseed;
} HashMap;

HashMap* hashmap_create(void);
void hashmap_destroy(HashMap* map);

V hashmap_put(HashMap* map, K key, V val);
V hashmap_get(HashMap* map, K key);
void hashmap_delete(HashMap* map, K key);
void hashmap_resize(HashMap* map);