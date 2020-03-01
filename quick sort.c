#include <stdio.h>

#define MAX_SIZE 8

int arr[MAX_SIZE] = { 4, 3, 2, 10, 12, 1, 5, 6 };

void print_arr(int left, int right)
{
	printf("[%d", arr[left]);
	int i;
	for (i = left + 1; i <= right; i++) printf(", %d", arr[i]);
	printf("]");
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int left, int right)
{
  int pivot = arr[right];
    int i = (left-1);

    for (int j = left; j <= right- 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}
void quick_sort(int left, int right)
{
 if(left < right)
  {
      int partition_index=partition(left,right);
      quick_sort(left,partition_index-1);
      quick_sort(partition_index+1,right);
  }
}

int main()
{
	quick_sort(0, MAX_SIZE - 1);

	print_arr(0, MAX_SIZE - 1);
	printf("\n");

	return 0;
}
