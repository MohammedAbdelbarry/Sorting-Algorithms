function a = selectionSort(a)
	n = size(a, 2);
	h = stem(a, 'ydatasource', 'a');
	for i = 1:n
		min = a(i);
		minInd = i;
		for j = i + 1:n
			if (a(j) < min)
				min = a(j);
				minInd = j;
				%pause(0.04);
			end;
		end;
		a(minInd) = a(i);
		a(i) = min;
		refreshdata([gcf], 'caller');
		drawnow;
	end;