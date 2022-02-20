#include <stdio.h>

int	den(int	b)
{
	b = 22;
	return(0);
}

int	main()
{
	int	a;
	int	i = 12;
	if (!(a = den(i)))
		printf("Girdi");
	printf("\n%d, %d",a,i);
}
