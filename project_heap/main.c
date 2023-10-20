#include <stdio.h>
#include <stdlib.h>

#define ME 100



typedef struct {
	int key;
}element;

typedef struct {
	element heap[ME];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));

}

void init(HeapType* h) {
	h->heap_size = 0;
}
void print_heap(HeapType *h) {
	if (h->heap_size == 0) return;
	for (int i = 1; i <= h->heap_size;i++) {
		printf("%d ", h->heap[i].key);

	}
	printf("\n");
}
void insert_max_heap(HeapType* h,element item) {
	int i = ++(h->heap_size);//�Ǹ����� ��忡 ���ִٰ� �����ϰ� ���� 

	while (item.key > h->heap[i/2].key &&  i !=1) {//�θ���� ��

		h->heap[i] = h->heap[i/2];
		i /= 2;


	}
	h->heap[i] = item;
	print_heap(h);

}

element  delete_max_heap(HeapType *h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];//�������Ű� ���� �ö󰡾� �ϴϱ� ������ ������ heapsize�� ���δ�

	parent = 1;
	child = 2;


	while(child <= h->heap_size) {//���� ���°ɷ�
		//���߿� �� ū�Ŷ� �ٲٷ��� (������ ���ִ� ���� �������� �ٲٷ��� ���߿� �� ū���� ���� ���־���� 
		if (child < h->heap_size && (h->heap[child].key) < (h->heap[child+1].key)) {
			child++;
		}
		if (temp.key > h->heap[child].key) break;//�ؿ��� �°��� �Ʊ����� �� ���ϵ� �߿� ���Ѱ��߿� �� ū���� ���ص� ��ũ��
													//�׳� �д� ->���߿� parent�����ٰ� temp�����Ŷ� �׳� �θ� ��

		h->heap[parent] = h->heap[child];// temp���� ���ϵ� �� ���� ������� ��ġ�� �ٲ۴� �Ʒ����� ���� �ø���.
		parent = child ;//���� ������ �Ʊ� ���ϵ尪���� �ű��
		child *= 2;

	}

	h->heap[parent] = temp;//����  �ؿ����� ����÷����ϱ� ���ϵ� �����ٰ� temp�� �־��ָ� ��
	print_heap(h);
	return item;//heap�� �ִ� �ϳ��� �� 
}


	
void heap_sort(element a[],int size) {

	int i;
	HeapType* h;

	h = create();
	init(h);

	for (i = 0; i < size; i++) {
		insert_max_heap(h, a[i]);

	}

	for (i = (size - 1); i >= 0;i--) {

		a[i] = delete_max_heap(h);

	}
	free(h);
}



void main() {
	printf("����� \n");

	element a[17] = { 34,12,76,59,32,55,88,26,16,79,34,85,29,78,41,56,86 };
	heap_sort(a, 17);
	
	for (int i = 0; i < 17; i++) {
		printf("%d ", a[i].key);
	}
	printf("\n end \n");


}