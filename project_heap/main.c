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
	int i = ++(h->heap_size);//맨마지막 노드에 들어가있다고 가정하고 시작 

	while (item.key > h->heap[i/2].key &&  i !=1) {//부모노드랑 비교

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
	temp = h->heap[(h->heap_size)--];//마지막거가 위로 올라가야 하니까 마지막 꺼놓고 heapsize를 줄인다

	parent = 1;
	child = 2;


	while(child <= h->heap_size) {//추후 보는걸로
		//둘중에 더 큰거랑 바꾸려고 (맨위에 가있는 가장 작은값과 바꾸려면 둘중에 더 큰값이 위에 가있어야함 
		if (child < h->heap_size && (h->heap[child].key) < (h->heap[child+1].key)) {
			child++;
		}
		if (temp.key > h->heap[child].key) break;//밑에서 온값이 아까전에 두 차일드 중에 비교한값중에 더 큰값과 비교해도 더크면
													//그냥 둔다 ->나중에 parent값에다가 temp넣을거라서 그냥 두면 됨

		h->heap[parent] = h->heap[child];// temp값이 차일드 값 보다 작은경우 위치를 바꾼다 아랫값을 위로 올린다.
		parent = child ;//이제 기준을 아까 차일드값으로 옮긴다
		child *= 2;

	}

	h->heap[parent] = temp;//추후  밑에것을 끌어올렸으니까 차일드 값에다가 temp값 넣어주면 됨
	print_heap(h);
	return item;//heap에 있는 하나의 값 
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
	printf("디버깅 \n");

	element a[17] = { 34,12,76,59,32,55,88,26,16,79,34,85,29,78,41,56,86 };
	heap_sort(a, 17);
	
	for (int i = 0; i < 17; i++) {
		printf("%d ", a[i].key);
	}
	printf("\n end \n");


}