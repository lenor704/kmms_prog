#include "io.hpp"
#include "sortings.hpp"

int main() {
	int arr[] = {1, 8, 2, 5, 3, 11, 7, 6, 5, 3, 9};
	const int size = sizeof(arr) / sizeof(arr[0]);
	
	ule::print_array("Массив до сортировки:", arr, size);
	
    ule::sortings::shell_sort(arr, size);

    ule::print_array("Массив после сортировки:", arr, size);

    return 0;
}