#include "sortings.hpp"

void ule::sortings::shell_sort(int* const arr, const int size) {
	int interval = 1;
	while (3 * interval + 1 <= (size + 2) / 3){
		interval = 3 * interval + 1;
	}
	
	for (; interval > 0; interval /= 3){
		for (int i = interval; i < size; i++){
			const int temp = arr[i];
			int j = i;
			for(; j >= interval && arr[j - interval] > temp; j -= interval){
				arr[j] = arr[j - interval];
			}
			arr[j] = temp;
		}
	}
}