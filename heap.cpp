#include<stdio.h>
#include<limits.h>


int heap[1000000],heapSize;
/*Initialize Heap*/
void Init()
{
        heapSize = 0;
        heap[0] = -INT_MAX;
}

/*Insert an element into the heap */
void Insert(int element)
{
	heapSize++;
	heap[heapSize]=element;
	int now=heapSize;
	while(heap[now/2]> element){
		heap[now]=heap[now/2];
		now=now/2;
	}
	heap[now]=element;
	
}

int DeleteMin()
{
	int now, child, min, max;
	min=heap[1];
	max=heap[heapSize--];
	for(now=1;now*2<=heapSize;now=child){
		child=now*2;
		if(child!=heapSize && heap[child+1]<heap[child])
			child++;

		if(max>heap[child])
			heap[now]=heap[child];
		else
			break;
	}
	heap[now]=max;
	return min;
}

int main()
{
        int number_of_elements;
        scanf("%d",&number_of_elements);
        int iter, element;
        Init();
        for(iter = 0;iter < number_of_elements;iter++)
        {
                scanf("%d",&element);
                Insert(element);
        }
        for(iter = 0;iter < number_of_elements;iter++)
        {
                printf("%d ",DeleteMin());
        }
        printf("\n");
        return 0;
}

