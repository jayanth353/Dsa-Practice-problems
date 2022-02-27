
	while (left <= right)
	{
		if (a[left] == 0 && a[right] == 0) left++;
		else if (a[left] == 0 && a[right] == 1) left++, right--;
		else  if (a[left] == 1 && a[right] == 0)
		{
			swap(a[left], a[right]);
			left++;
			right--;
		}

		if (a[left] == 1 && a[right] == 1) right--;
	}
