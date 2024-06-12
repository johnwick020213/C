typedef int E;

typedef struct {
	E* elements;
	int capacity;
	int size;
}Vector;

//构造函数
Vector* vector_create(void);
//析构函数
void vector_destroy(Vector* v);
//最后面添加一个元素
void push_back(Vector* v, E val);
//最前面添加一个元素
void push_front(Vector* v, E val);
//删除最后一个元素，并返回
E pop_back(Vector* v);
//删除第一个元素。并返回
E pop_front(Vector* v);
//扩容
void grow_capacity(Vector* v);