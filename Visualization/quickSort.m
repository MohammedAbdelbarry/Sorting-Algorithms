function a = quickSort(a, first, last)
	figure = stem(a, 'ydatasource', 'a');
	a = __quickSort(a, first, last);