#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define EXIT_NUMBER 9
#define LOOP_NUMBER 2

int make_a_guess(int trial,int min, int max){
	int i=1,j,guess,lucky_number,distance,pow1,pow2,flag=0,ctrl_distance,counter=0,temp,mod;
	srand(time(NULL));
	mod = max - min;
	lucky_number = (rand() % mod)+min ;
	
	printf("%d\n", lucky_number);
	while(i<trial+1){
		printf("(Trial : %d)Make a guess between %d and %d: ",i,min,max);
		scanf("%d",&guess);
		temp = max;

		while(temp>0){
			
			temp = temp / 2;
			counter ++;
		}
		if(guess<=max && guess>=min){			/*If The Guess is between minimum and maximum number, enters this.*/
			distance = lucky_number-guess;
			distance = abs(distance);			/*Function for taking absolute value of distance*/
	
			for(j=0;j<counter -1;j++){

				pow1 = pow(2,j);
				pow2 = pow(2,j+1);
				
				if(distance >= pow1 && distance < pow2 ){
					ctrl_distance = j+1;	
					break;
				}	
			}
				
			if(ctrl_distance<10 && distance>1){
			printf("Distance = %d\n", ctrl_distance);
			
			}else if(distance == 1){
				printf("%s\n","Distance = 1" );
				
			}else if(distance == 0){
				printf("%s\n","Distance = 0. You Win.");
				i=trial+1;
				flag++;
			}	

			if(lucky_number < guess){
				max = guess;

			}else if(lucky_number > guess){
				min = guess;
			}
			
	
		}else{
			if(guess > max){
				printf("Your Guess Is Bigger Than Maximum Number.\n");
			}else if(guess < max){
				printf("Your Guess Is Smaller Than Minimum Number.\n");
			}
		}
			
		i++;
		
		
	}
	
	return flag;

}
void show_scores(int score_human,int score_program){

	char input;

	printf("Your Score: %d Program Score : %d\n",score_human,score_program );	/*Function for print the score. For reset this, 
																					open program again*/
}


void hourglass(int height){

	int i,j,k,l=1;

	if(height%2 != 0){

		for(i=1;i<=(height-1)/2;i++){

			for(j=0;j<i-1;j++){

				printf(" ");
			}
			for(k=0;k<height - (2 * (i-1));k++){

				printf("*");
			}
			printf("\n");
		}
		while(l<i){
			printf(" ");
			l++;
		}
		printf("*\n");

		for(i=1;i<=(height-1)/2;i++){

			for(j=0;j<((height-1)/2)-i;j++){

				printf(" ");
			}
			for(k=0;k<(2*i)+1;k++){

				printf("*");
			}
			printf("\n");
		}
	}else{

		printf("Number you entered is not valid.\n");
	}
}

void draw_mountain_road (int length,int max_radius){

	int i,j,x=0,random_number,counter;
	srand(time(NULL));
	

	while (x<(length+1/2)){
		random_number = (rand() % max_radius)+1;
		counter = max_radius +1;

		for(i=0;i<random_number;i++){

			for(j=0;j<counter;j++){
				printf(" ");	

			}
			printf("/\n");
			counter --;
		}
		
		for (int i = 0; i < counter ; ++i){
			printf(" ");
		}
		printf("|\n");
		counter++;
		x++;

		for (int i = 0; i < random_number; ++i){
			for (int j= 0; j < counter; ++j)
			{
				printf(" ");
			}
			printf("\\");
			printf("\n");
			counter++;
		}
		
		if(x!=length){
			random_number = (rand() % max_radius)+1;
			for (int i = 0; i < random_number; ++i){
				for (int i = 0; i < counter; ++i){
					printf(" ");
				}
				printf("\\");
				printf("\n");
				counter++;
			}
			for (int i = 0; i < counter ; ++i){
				printf(" ");
			}
			printf("|\n");
			counter--;

			for (int i = 0; i < random_number; ++i){
				for (int j = 0; j < counter; ++j){
					printf(" ");
				}
				printf("/\n");
				counter--;
			}
			x++;
		}	

	}
}



void menu(){
	int choice=2,height, flag ,length, max_radius,trial,min,max,score_program = 0,score_human = 0;
	char decider_char;

	while(choice >0 && choice<4){
		printf("\e[2J"); /* This Command Clears The Screen*/
		printf("%s\n","*****MENU*****\n" );
		printf("%s\n","1.Play Lucky Number\n" );
		printf("%s\n","2.Draw Hourglass\n" );
		printf("%s\n","3.Draw Mountain Road\n" );
		printf("%s\n","4.Exit\n");
		printf("%s","Choice:" );

		scanf("%d",&choice);
		
		if(choice == 1){

			printf("Enter Minimum Value:\n");
			scanf("%d",&min);
			printf("Enter Minimum Value:\n");
			scanf("%d",&max);
			printf("Please Enter Your Trials: ");
			scanf("%d",&trial);
			flag = make_a_guess(trial,min,max);
			
			if(flag == 0){
				score_program++;
			}else if(flag == 1){
				score_human++;
			}

			show_scores(score_human,score_program);

		}else if(choice == 2){

			printf("Please Enter A Height For Hourglass : ");
			scanf("%d",&height);

			hourglass(height);

		}else if(choice == 3){
			printf("Please Enter Length Of Mountain : ");
			scanf("%d",&length);
			printf("Please Enter Maximum Radius Of Mountain : ");
			scanf("%d",&max_radius);

			draw_mountain_road (length,max_radius);

		}else if(choice == 4){
			printf("%s","EXITING...\n" );
			break;
		}else{

			printf("%s","You entered wrong value. " );
		}
			printf("Press Any Key To Return To Menu...");
			decider_char = getchar();
			decider_char = getchar();

			if(decider_char == 'Y' || decider_char == 'y'){
				choice = LOOP_NUMBER;
			}else if(decider_char == 'N' || decider_char == 'n'){
				choice = EXIT_NUMBER;
			}
	}
}

int main(){

menu();
return 0;

}