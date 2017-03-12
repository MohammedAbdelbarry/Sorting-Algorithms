function a = merge(a, first, mid, last)
	low = first;
	high = mid + 1;
	ind = 1;
	temp = zeros(1, last - first + 1);
	while(low <= mid && high <= last)
		if a(low) < a(high)
			temp(ind++) = a(low++);
		elseif a(high) < a(low)
			temp(ind++) = a(high++);
		else
			temp(ind++) = a(low++);
			temp(ind++) = a(high++);
		endif;
	endwhile;
	while(low <= mid)
		temp(ind++) = a(low++);
	endwhile;
	while(high <= last)
		temp(ind++) = a(high++);
	endwhile;
	for i = first:last
		a(i) = temp(i - first + 1);
		refreshdata(gcf, 'caller');
		drawnow;
	endfor;