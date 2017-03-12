function a = bubbleSort(a)
	n = size(a, 2);
	h = stem(a, 'ydatasource', 'a');
	for i = 1:n
		for j = i + 1:n
			if (a(j) < a(i))
				temp = a(j);
				a(j) = a(i);
				a(i) = temp;
				%pause(0.04);
				refreshdata([gcf], 'caller');
				drawnow;
			end;
		end;
	end;
