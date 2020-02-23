int leftSum = 0x80000000;
	int sum = 0;
	for (int i = mid; i >= low; --i)
	{
		sum += arr[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			crossLow = i;
		}
	}
	int rightSum = 0x80000000;
	sum = 0;
	for (int j = mid + 1; j <= high; ++j)
	{
		sum += arr[j];
		if (sum > rightSum)
		{
			rightSum = sum;
			crossHigh = j;
		}
	}
	crossSum = leftSum + rightSum;
