#include <stdio.h>

int ThirdLittleNums(int *array00, int *array01, int nums00, int nums01)
{
	int i,j,k=0;
	int temp;
	int array[4];
	int count = 2;
	
	while(count!=0){
		for(i=0; i<nums00; i++){
			for(j=0; j<nums01-(i+1); j++){
				if(--count==1){
					if(array00[j]>array00[j+1]){
						temp = array00[j];
						array00[j] = array00[j+1];
						array00[j+1] = temp;
					}
				}else if(--count==0){
					if(array01[j]>array01[j+1]){
						temp = array01[j];
						array01[j] = array01[j+1];
						array01[j+1] = temp;
					}
				}
			}
		}
	}
	
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			if(array00[i]<array01[j]){
				array[k++] = array00[i];
			}else{
				array[k++] = array01[j];
			}
		}
	}
	
	return array[2];
}


void main()
{
	int array00[] = {4,6,1,9,5,2};
	int array01[] = {1,4,6,9,2,5};
	int length00 = sizeof(array00);
	int length01 = sizeof(array01);
	int result;

	result = ThirdLittleNums(array00, array01, length00, length01);

	printf("min three nums is %d\n", result);

	return ;
}


