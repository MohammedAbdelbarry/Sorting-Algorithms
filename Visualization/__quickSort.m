function a = __quickSort(a, first, last)
	if(first < last)
		[a pivot] = lomuto(a, first, last);
		a = __quickSort(a, first, pivot - 1);
		a = __quickSort(a, pivot + 1, last);	
	endif;