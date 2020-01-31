void main()
{
	int a;
	a = 0;
	while(1)
	{
		//拨码开关关联到LED灯
		int sw;
		sw=$0xfffffc70;
		$0xfffffc60=sw;
		//延迟显示
		int j;
		j=1000000;
		while(j>0)
		{
			j=j-1;
		}
	}
}