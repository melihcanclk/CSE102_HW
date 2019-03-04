#include <stdio.h>		/*library for standart functions for instance printf(); or scanf();*/
#include <math.h>		/*Library for mathematical operations*/
#include <time.h>		/*Library for creating random number*/
#include <stdlib.h>		/*library for rand() function*/
#define PI 3			/*It can be exchangeable by 3.1415*/
#define SQUARE 1		/*Predefined square*/
#define RECTANGULAR 2		/*Predefined rectangle*/
#define CIRCULAR 3		/*Predefined Circular*/	
#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4

double CreateBody (int shape);										
int SetColor (int color);										
double LoadMoves(int shape, double size_of_body);							
int SetAttackPower(int lower_bound, int upper_bound);							/*	Preload of The  */ 
void ShowPokemon(int shape, double size_of_body, int color, double move_length, int attack_power);	/*	following functions*/
													
													
int main(){
					/*Main Function of Pokémon Printing program	*/ 		
int shape, color, attack_power;
double size_of_body, move_length;
shape = RECTANGULAR; /* Pick one of them and assign it to shape variable (RECTANGULAR,SQUARE,CIRCULAR)	*/
size_of_body = CreateBody (shape);
color = 568;		/*Choose 1 color between 0 and 1000 . İf you are not pick in that interval, colour of Pokémon will be Yellow */
color = SetColor(color);
move_length = LoadMoves(shape, size_of_body);
attack_power = SetAttackPower (0, 150);	/*Changable Attack Power Range*/
ShowPokemon(shape, size_of_body, color, move_length, attack_power);

return 0;	
}

double CreateBody (int shape){			/*Function that is used tor determine the shape of input 1,2 or 3	*/
	
	int border,radius,border1,border2;
	double area; 
	
	if(shape == 1){

	printf("Enter the one border of square:");
	scanf("%d", &border);
	area = pow(border,2);
		
	}else if(shape == 2){
	
	printf("Enter the first border of the rectangle:");
	scanf("%d",&border1);
	printf("Enter the second border of the rectangle:");
	scanf("%d",&border2);
	area = border1 * border2;	/*Multiplying two border to obtain the area*/

	}else if(shape == 3){
	
	printf("Enter the radius of the circle:");
	scanf("%d",&radius);
	area = PI * radius * radius;				/*The reason why we are multiplying radius by radius, we cant know
								if scanned number is negative or positive*/
	}

return area;
}

int SetColor (int color){				/*Function for determine color of  Pokémon*/

	if(color>=0 && color <=1000){
		return color%5;
		
	}else{
		return 1;				/*It will return 1 (Yellow in current situation)*/
	
	}
}

double LoadMoves(int shape, double size_of_body){	/*Function for calculate move of  Pokémon (Circumference of shape)*/

	double perimeter;
	
	if(shape == 1){		/*Square*/
	
		perimeter = sqrt(size_of_body); 		
		perimeter = perimeter *4;
	
	}else if(shape == 2){		/*Rectangle*/
	
		perimeter = size_of_body / 5 ;		/*We are assuming that one border is 5*/
		perimeter = (2 * perimeter) + 10;
	
	}else if(shape == 3){
	
		perimeter = size_of_body / PI;		/*Circular*/
		perimeter = sqrt(perimeter); 
		perimeter = PI * 2 * perimeter;
	
	}

return perimeter;

}

int SetAttackPower(int lower_bound, int upper_bound){		/*Attack Power of Pokémon (Initiliazed randomly) */

	int power;
	int mod = upper_bound - lower_bound +1;
	srand(time(NULL));
	power = (rand() % mod) +lower_bound;		/* The reason why I'm adding lower_bound is if we change the value, program*/
	return power;					/* can adapt it to our operation. */
}

void ShowPokemon(int shape, double size_of_body, int color, double move_length, int attack_power){/*Printing Pokémon with his shape and 
												  information about  Pokémon*/
	int radius,border,i,j,k,l;
	
	if(shape == 1){				/*Square*/
		
		border = sqrt(size_of_body);
		
		while(i<border){
			j=0;
			while(j<border){
				printf("x");
				j++;
			}
			
			i++;
			printf("\n");
			
		}
		
	printf("Name : Square Pokémon\n");
	printf("Size : %.0f\n",size_of_body);
	printf("Color : ");
	if(color == RED){
		printf("Red\n");
	}else if(color == YELLOW){
		printf("Yellow\n");
	}else if(color == BLUE){
		printf("Blue\n");
	}else if(color == BLACK){
		printf("Black\n");
	}else if(color == WHITE){
		printf("White\n");
	}	
	
	printf("Move : %.2f\n",move_length);
	printf("Attack : %d\n",attack_power);
	
	}else if(shape == 2){			/*Rectagular*/
		
		border = (int)size_of_body / 5;
		while(i<5){
		j=0;
			while(j<border){
				printf("x");
				j++;
			}
			
			i++;
			printf("\n");
		}
		printf("Name : Rectangular Pokémon\n");
		printf("Size : %.0f\n",size_of_body);
		printf("Color : ");
		if(color == RED){
			printf("Red\n");
		}else if(color == YELLOW){
			printf("Yellow\n");
		}else if(color == BLUE){
			printf("Blue\n");
		}else if(color == BLACK){
			printf("Black\n");
		}else if(color == WHITE){
			printf("White\n");
		}		
		
		printf("Move : %.2f\n",move_length);
		printf("Attack : %d\n",attack_power);
		
	}else if(shape = 3){				/*Circular*/
								/*shape =3 size of body = area of circle*/
		size_of_body = size_of_body / PI;
		size_of_body = sqrt(size_of_body);		/*Now size_of_body become radius*/
		
		if(size_of_body == 0){
			printf("%s\n", "A circle can't has zero radius.");
		}
		else if((int)size_of_body%2==1){		/*For Odd numbers and  numbers bigger than 0*/
			for(i=0;i<size_of_body/2;i++){
				for(j=size_of_body/2;j>i;j--){
					printf("\t");
				}
				printf("x");
				for(k=0;k<2*i;k++){
					printf("\t");
				}
				if(i!=0){
					printf("x");
				}
				printf("\n");
			}
			j=0;k=0;
			for(i=1;i<size_of_body/2;i++){

				for(j=0;j<i;j++){
					printf("\t");
				}
				if (i!=(int)size_of_body/2 ){
					printf("x");
				}
				for(k=1;k<(size_of_body/2 - i)*2;k++){
					printf("\t");
				}
				printf("x\n");
				
				
			}
			
		}else if(size_of_body > 0){			/*For even numbers and numbers bigger than 0*/
				
			for(i=0;i<(size_of_body/2)-1;i++){
				printf("\t");
			}
				printf("    x\n");
				
				for(i=0;i<size_of_body/2;i++){
					for(j=(size_of_body/2)-1;j>i;j--){
						printf("\t");
					}
					printf("x");
					for(k=0;k<(2*i)+1;k++){
						printf("\t");
					}
						printf("x");
					
					printf("\n");
				}
				j=0;k=0;
				for(i=1;i<size_of_body/2;i++){

					for(j=0;j<i;j++){
						printf("\t");
					}
					if (i!=(int)size_of_body/2 ){
						printf("x");
					}
					for(k=1;k<(size_of_body/2 - i)*2;k++){
						printf("\t");
					}
					printf("x\n");
					
				
				}
			for(i=0;i<(size_of_body/2)-1;i++){
				printf("\t");
			}
				printf("    x\n");
		}	
		if(size_of_body != 0){
			size_of_body = PI * size_of_body* size_of_body;
			
			printf("Name : Circular Pokémon\n");
			printf("Size : %.2f\n",size_of_body);
			printf("Color : ");
			if(color == RED){
				printf("Red\n");
			}else if(color == YELLOW){
				printf("Yellow\n");
			}else if(color == BLUE){
				printf("Blue\n");
			}else if(color == BLACK){
				printf("Black\n");
			}else if(color == WHITE){
				printf("White\n");
			}	
					
			printf("Move : %.2f\n",move_length);
			printf("Attack : %d\n",attack_power);
		}
	}			
}

