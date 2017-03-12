function a = __mergeSort(a, first, last)
	if(first < last)
		mid = floor(first + (last - first)/2);
		a = __mergeSort(a, first, mid);
		a = __mergeSort(a, mid + 1, last);
		a = merge(a, first, mid, last);
	endif;