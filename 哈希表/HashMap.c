#include "HashMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define DEFAULT_CAPACITY	8
#define LOAD_FACTOR      0.75

// 创建空的哈希表
HashMap* hashmap_create(void) {
    HashMap* map = malloc(sizeof(HashMap));

    map->table = calloc(DEFAULT_CAPACITY, sizeof(Entry*));
    map->size = 0;
    map->capacity = DEFAULT_CAPACITY;
    map->hashseed = time(NULL);
    return map;
}

// 哈希表的遍历
void hashmap_destroy(HashMap* map) {
    // 1. 释放所有结点
    for (int i = 0; i < map->capacity; i++) {
        Entry* curr = map->table[i];
        while (curr) {
            Entry* next = curr->next;
            free(curr);
            curr = next;
        }
    }
    // 2. 释放table
    free(map->table);
    // 3. 释放map
    free(map);
}

// key: 关键字的地址
// len: 关键字的字节长度
// seed: 哈希种子，避免攻击
uint32_t hash(const void* key, int len, uint32_t seed) {
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    uint32_t h = seed ^ len;
    const unsigned char* data = (const unsigned char*)key;

    while (len >= 4) {
        uint32_t k = *(uint32_t*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len)
    {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
        h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

// 如果key不存在：则添加(key, val)
// 如果key存在，更新key关联的值，并返回原来关联的值。
V hashmap_put(HashMap* map, K key, V val) {
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // map->table[idx]: key所在的链表
    // 遍历链表
    Entry* curr = map->table[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            // 更新curr关联的值
            V oldvalue = curr->val;
            curr->val = val;
            return oldvalue;
        }
        curr = curr->next;
    }   // curr == NULL
    // 不存在key, 添加键值对(key, val)
    Entry* entry = malloc(sizeof(Entry));
    entry->key = key;
    entry->val = val;
    // 头插法
    entry->next = map->table[idx];
    map->table[idx] = entry;
    // 更新哈希表
    map->size++;

    return NULL;
}

V hashmap_get(HashMap* map, K key) {
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // map->table[idx]: key所在的链表
    Entry* curr = map->table[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->val;
        }
        curr = curr->next;
    } // curr == NULL
    return NULL;
}

void hashmap_delete(HashMap* map, K key) {
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // map->table[idx]: key所在的链表
    Entry* prev = NULL;
    Entry* curr = map->table[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            // TODO: 删除curr结点
            if (prev == NULL) {
                map->table[idx] = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            map->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    } // curr == NULL
}

void hashmap_resize(HashMap* map)
{
    int new_capacity = map->capacity << 1;
    Entry** old_table = map->table;
    
    map->table = calloc(new_capacity, sizeof(Entry*));
    map->capacity = new_capacity;
    
    for (int i = 0; i < map->size; i++)
    {
        Entry* curr = old_table[i];
        while (curr)
        {
            Entry* next = curr->next;
            int new_idx = hash(curr->key, strlen(curr->key), map->hashseed) % new_capacity;
            
            curr->next = map->table[new_idx];
            map->table[new_idx] = curr;
            curr = next;
        }
    }
    free(old_table);
    
}