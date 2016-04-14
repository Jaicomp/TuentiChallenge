#include <stdio.h>
	
	
	
int main(){
	
	int num_sec;
	int i, j;
	int num_leds_on_number[] = {6, 2, 5, 4, 5, 5, 3, 7, 5};
	int actual_time[] = {0,0,0,0,0,0};
	int total_time = 0;
	
	printf("Enter your time in seconds: \n");
	scanf("%d", &num_sec);


	for(i=0; i <= num_sec; i++){
		
		actual_time[0] = i;
		
		for(j = 0; j < (int) (sizeof(actual_time)/sizeof(actual_time[0])); j++){

			//If digit of time is 6, update time
			if (actual_time[j] == 6){
				actual_time[j] = 0;
				actual_time[j+1] += 1;
			}
			

			total_time += num_leds_on_number[actual_time[j]];

		}
	}

	
	printf("\nNumber of leds ON: %d\n", total_time);

	return 0;
}


