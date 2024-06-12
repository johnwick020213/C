typedef int E;

typedef struct {
	E* elements;
	int capacity;
	int size;
}Vector;

//���캯��
Vector* vector_create(void);
//��������
void vector_destroy(Vector* v);
//��������һ��Ԫ��
void push_back(Vector* v, E val);
//��ǰ�����һ��Ԫ��
void push_front(Vector* v, E val);
//ɾ�����һ��Ԫ�أ�������
E pop_back(Vector* v);
//ɾ����һ��Ԫ�ء�������
E pop_front(Vector* v);
//����
void grow_capacity(Vector* v);