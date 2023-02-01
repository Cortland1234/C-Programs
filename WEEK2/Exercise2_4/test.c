int main()
{
    
    int firstArray[7];
    int arraySum[7],i,sum=0;

	printf("Enter the array elements\n");

	for(i=0;i<7;i++)
	{
	    scanf("%lf",&firstArray[i]);
	}
	for(i=0;i<7;i++)
	{
	    sum +=firstArray[i];
	    arraySum[i]=sum;
	}
	for(i=0;i<7;i++)
	    printf("%lf ",arraySum[i]);

    return 0;
}