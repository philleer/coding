#include <iostream>
#include <vector>
#include <cstdio>

class Sort {
public:
	// Quick sort works as follows: The algorithm selects an element,
	// called the pivot, in the array. It divides the array into two
	// parts,  so that all the elements  in the first part  are less
	// than or equal to the pivot and all the elements in the second
	// part are greater than the pivot.  The quick sort algorithm is
	// then  recursively applied to  the first part and second  part.
	struct QuickSort {
		QuickSort();
		~QuickSort();

		// @param list	The given array to be sorted
		// @param first	The first position index to sort
		// @param last	The last position index to sort
		int partition(std::vector<int> &list, int first, int last);
		void quickSort(std::vector<int> &list, int first, int last);
		void quickSort(std::vector<int> &list);

		void quickSortOnce(std::vector<int> &list, int first, int last);
	};

public:
	Sort();
	~Sort();

	void BubbleSort(std::vector<int> &src_vec);
	void InsertSort(std::vector<int> &src_vec);
	void SelectSort(std::vector<int> &src_vec);
	void BinarySelectSort(std::vector<int> &src_vec);
	void QuickSort(std::vector<int> &src_vec);
};

Sort::QuickSort::QuickSort() {

}

Sort::QuickSort::~QuickSort() {

}

void Sort::QuickSort::quickSort(std::vector<int> &list) {
	quickSort(list, 0, list.size() - 1);
}

void Sort::QuickSort::quickSort(std::vector<int> &list, int first, int last) {
	if (last > first) {
		int pivotIndex = partition(list, first, last);
		quickSort(list, first, pivotIndex - 1);
		quickSort(list, pivotIndex + 1, last);
	}
}

int Sort::QuickSort::partition(std::vector<int> &list, int first, int last) {
	int pivot = list[first];
	int low	= first + 1;
	int high = last;

	while (high > low) {
		while (low <= high && list[low] <= pivot) {
			++low;
		}

		while (low <= high && list[high] > pivot) {
			--high;
		}

		if (high > low) {
			int tmp = list[high];
			list[high] = list[low];
			list[low] = tmp;
		}
	}
	
	while (high > first && list[high] >= pivot) {
		--high;
	}

	if (pivot > list[high]) {
		list[first] = list[high];
		list[high] = pivot;
		return high;
	}
	
	return first;	
}

void Sort::QuickSort::quickSortOnce(std::vector<int> &list, int first, int last) {
	int pivot = list[first];
	int low = first + 1;
	int high = last;
	if (high > low) {
		while (high > low) {
			while (low <= high && list[low] <= pivot) {
				++low;
			}
			while (low <= high && list[high] > pivot) {
				--high;
			}
			if (high > low) {
				int tmp = list[high];
				list[high] = list[low];
				list[low] = tmp;
			}
		}

		list[first] = list[high];
		list[high] = pivot;
		quickSort(list, first, high-1);
		quickSort(list, high+1, last);
	}
}

Sort::Sort() {

}

Sort::~Sort() {

}

void Sort::BubbleSort(std::vector<int> &src_vec) {
	int length = src_vec.size();
	if (length == 0) {
		return;
	}
	
	bool needNextThrough = true;
	for (int i = 0; needNextThrough && i < length - 1; i++) {
		needNextThrough = false;
		for (int j = 1; j < length - i; j++) {
			if (src_vec[j-1] > src_vec[j]) {
				int tmp = src_vec[j];
				src_vec[j] = src_vec[j-1];
				src_vec[j-1] = tmp;
				needNextThrough = true;
			}
		}
	}
}

void Sort::InsertSort(std::vector<int> &src_vec) {
	int length = src_vec.size();
	if (length == 0) {
		return ;
	}

	for (int i = 1; i < length; i++) {
		int current_value = src_vec[i];
		int j;
		for (j = i-1; j >= 0 && src_vec[j] > current_value; j--) {
			src_vec[j+1] = src_vec[j];
		}
		src_vec[j+1] = current_value;
	}
}

void Sort::SelectSort(std::vector<int> &src_vec) {
	int length = src_vec.size();
	if (length == 0) {
		return;
	}

	for (int i = 0; i < length - 1; i++) {
		int min = i;
		for (int j = i+1; j < length; j++) {
			if (src_vec[min] > src_vec[j]) {
				min = j;
			}
		}
		if (min != i) {
			int tmp = src_vec[i];
			src_vec[i] = src_vec[min];
			src_vec[min] = tmp;
		}
	}
}

void Sort::BinarySelectSort(std::vector<int> &src_vec) {
	int length = src_vec.size();
	if (length == 0 ) {
		return;
	}

	for (int i = 0; i < length / 2; i++) {
		int max = length - i - 1;
		int min = i;
		for (int j = i; j < length-i; j++) {
			if (src_vec[min] > src_vec[j]) {
				min = j;
			}
			if (src_vec[max] < src_vec[j]) {
				max = j;
			}
			 std::cout << std::endl;
		}

		int tmp;
		if (min != i) {
			tmp = src_vec[i];
			src_vec[i] = src_vec[min];
			src_vec[min] = tmp;
			if (max == i) {
				max = min;
			}
		}
		if (max != length - i - 1) {
			tmp = src_vec[length - i - 1];
			src_vec[length - i - 1] = src_vec[max];
			src_vec[max] = tmp;
		}
	}
}

void Sort::QuickSort(std::vector<int> &src_vec) {
	QuickSort qs;
	qs.quickSort(src_vec);
	// qs.quickSortOnce(src_vec, 0, src_vec.size() - 1);
}