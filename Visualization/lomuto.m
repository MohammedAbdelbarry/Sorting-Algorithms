function [a pivotPos] = lomuto(a, first, last)
	pivot = a(last);
	i = first;

	for j = first:last
		if (a(j) < pivot)
			temp = a(i);
			a(i) = a(j);
			a(j) = temp;
			i++;
			%pause(0.1);
			refreshdata(gcf, 'caller');
			drawnow;
		endif;
	endfor;
	a(last) = a(i);
	a(i) = pivot;
	pivotPos = i;