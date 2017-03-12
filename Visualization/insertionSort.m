function a = insertionSort(a)
	n = size(a, 2);
	h = stem(a, 'ydatasource', 'a');
	for i = 2:n
		j = i;
		while (j > 1 && a(j) < a(j - 1))
			temp = a(j);
			a(j) = a(j - 1);
			a(j - 1) = temp;
			j--;
			%pause(0.04);
			refreshdata([gcf], 'caller');
			drawnow;
		end;
	end;
