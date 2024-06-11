#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "HashMap.h"

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {

	// 1. 创建空的哈希表
	HashMap* map = hashmap_create();

	// 2. 添加键值对
	hashmap_put(map, "liuqiangdong", "zhangzetian");
	hashmap_put(map, "wangbaoqiang", "marong");
	hashmap_put(map, "wenzhang", "mayili");
	hashmap_put(map, "jianailiang", "lixiaolu");

	// hashmap_put(map, "wangbaoqiang", "");
	// hashmap_put(map, "wenzhang", "");
	// hashmap_put(map, "jianailiang", "");

	// V val1 = hashmap_get(map, "liuqiangdong");
	// V val2 = hashmap_get(map, "peanut");

	hashmap_delete(map, "liuqiangdong");
	hashmap_delete(map, "peanut");

	// 销毁哈希表
	hashmap_destroy(map);

	return 0;
}