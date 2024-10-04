#include <stdio.h>
void print_combination(int s, int fg, int td, int td1, int td2){
	printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, s);
}

int main(){
	// Initialize score, max and total variables.
	int score, max, total;

	// We collect our input for the score.
	while (1){
		printf("Enter the NFL score: ");
		scanf("%d", &score);
		getchar(); // Kill the newline.

		if ((score == 0) || (score == 1)){
			printf("Program stopped.\n");
			break;
		}

		// See how many safety's could occur max by floor dividing.
		max = score/2;

		printf("\nPossible combinations of scoring plays if a team's score is %d:\n\n", score);

		// Now we use a VERY brute force method. Where we grab all max^max combinations and see if they equal our score. Print if so.
			// Is there a wayyyy better algorithm for this? Probably!
			// Could I slightly improve this method so I'm not counting way more than necessary? Definitely!
		int i;
		for (i = 0; i < (max+1); i++){
			int j;
			for (j = 0; j < (max+1); j++){
				int k;
				for (k = 0; k < (max+1); k++){
					int l;
					for (l = 0; l < (max+1); l++){
						int m;
						for (m = 0; m < (max+1); m++){
							total = (i*8) + (j*7) + (k*6) + (l*3) + (m*2);
							if (total == score){
								print_combination(m, l, k, j, i);
							}
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
