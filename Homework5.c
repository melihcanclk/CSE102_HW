/*																																			*/
/*																PUZZLE GAME																	*/
/*											Melihcan Çilek - Gebze Technical University - 1801042092										*/
/*			  		This code is for 15x15 puzzle that includes some words	in word_hunter.dat file and if you want to change 				*/
/*			the coordinates reverse (For example [7,10] and [10,13] coordinates can be converted reverse so it will give reversed word)		*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18
#define FALSE -1
#define EXIT -2

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}

void print_area(char *dict[DICT_SIZE], int coord[DICT_SIZE][4],char area[DICT_SIZE][DICT_SIZE]){
	
	int x,y,i,j,k,flag,number;
	
	for(y=0;y<DICT_SIZE;y++){				/*For Loop For Increasing Y Coordinates*/
		for(x=0;x<DICT_SIZE;x++){			/*For Loop For Increaseing X Coordinates*/
		flag=0;		
		number=0;	
			for(i=0;i<DICT_SIZE;i++){											/*Checking All The Words	*/
				if(coord[i][0]==x && coord[i][1]==y){							/*Checking if x coordinates and y coordinates are equal at the same time*/
					if(coord[i][0]==coord[i][2]){										/*If that word goes to x direction*/
						if(coord[i][1]>coord[i][3]){									/*If coordinates explains that this word is reverse*/
							for(j=coord[i][3];j<=coord[i][1];j++){						/*Starting x position*/
								area[x][coord[i][1]-number] = dict[i][number];
								number++;
							}
						}else{															/*If coordinates explains that this word is not reverse*/
							for(j=coord[i][1];j<=coord[i][3];j++){						/*Starting x position*/
								area[x][j] = dict[i][number];
								number++;
							}
						}
					}else if(coord[i][1]==coord[i][3]){									/*If that word goes to y direction*/
						if(coord[i][0]>coord[i][2]){									/*If coordinates explains that this word is reverse*/
							for(j=coord[i][2];j<=coord[i][0];j++){						/*Starting y position*/
								area[coord[i][0]-number][y] = dict[i][number];
								number++;
							}
						
						}else{															/*If coordinates explains that this word is not reverse*/
							for(j=coord[i][0];j<=coord[i][2];j++){						/*Starting y position*/
								area[j][y] = dict[i][number];
								number++;
							}
						}
						
					}else{																/*If that word goes diagonal*/
						if(coord[i][1] > coord[i][3] && coord[i][0]>coord[i][2]){		
							k=coord[i][2];												/*Starting y position*/
							for(j=coord[i][3];j<=coord[i][1];j++){						/*If coordinates explains that this word is reverse*/
								area[coord[i][0]-number][coord[i][1]-number] = dict[i][number];
								number++;
								k++;
							}
						}else{
							k=coord[i][0];												/*Starting y position*/
							for(j=coord[i][1];j<=coord[i][3];j++){						/*If coordinates explains that this word is not reverse*/
								area[k][j] = dict[i][number];
								number++;
								k++;
							}
						}
					}
					flag++;
				}
			}
		}
	}	
	for(x=0;x<DICT_SIZE;x++){									
		for(y=0;y<DICT_SIZE;y++){
			printf("%c ",area[x][y]);													/*Filling The Area*/
		}
		printf("\n");
	}
	
}

int string_compare(char word[10],char comparisant[10],int size){						/*String Comparing Function*/

	int i;
	
	for(i=0;i<size;i++){
		if(word[i]!=comparisant[i]){
			return 1;
		}
	}
	return -1;
}

int user_part(char *dict[DICT_SIZE], int coord[DICT_SIZE][4],char area[DICT_SIZE][DICT_SIZE],char word[10],int size){

	int column,row,i,j;												/*Function For Taking Rows And Columns And Making Comparision*/
	do{
		printf("Please Enter Column(Left To Right From 0 To 14):");//x
		scanf("%d",&column);
	}while(column>15 || column<0);
	
	do{
		printf("Please Enter Raw(Up To Down From 0 To 14):");//y
		scanf("%d",&row);
	}while(row>15 || row<0);
	
	for(i=0;i<DICT_SIZE;i++){
		if(area[row][column]>=65 && area[row][column]<=90){					/*If That Word Has Already Entered*/
			return -2;
		}else if((coord[i][0]==column || coord[i][2]==column) && (coord[i][1]==row || coord[i][3]==row) && string_compare(word,dict[i],size)==-1){
			return i;														/*-1 Means The Word That User Entered And String That Match With Is The Same*/
		}
	}
	return FALSE;		/*If Its Equal Nothing*/
	
	
}

int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4],x,y,result,result_string,i,finish_counter=0,count=0;    
    char line[LINE_LEN];
    char area[DICT_SIZE][DICT_SIZE];
    char word[10];
    char random_char;
   	char comparisant[10]="exit game";												/*To Control "exit game"*/
	srand(time(0));

	for(y=0;y<DICT_SIZE;y++){
		for(x=0;x<DICT_SIZE;x++){
			random_char=(rand()%25)+98;										/*Numbers Between 98 and 122 Because Lower Latters Corresponds To These Numbers*/
			area[y][x]=random_char;											/*Filling All Area With Random Numbers*/
			
		}
	}
	FILE *fp = fopen("word_hunter.dat", "r");								/*Opening word_hunter.dat File*/
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);/*x coordinate of first or last word*/
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);/*y coordinate of first or last word*/
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);/*x coordinate of last or first word*/
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);/*y coordinate of last or first word*/
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	
	
	//print_dictionary(dict);
	//print_coord(coord);
	
	print_area(dict,coord,area);
	while(finish_counter<DICT_SIZE){									/*Game Continue Until All Secret Words Are Found*/	
		
		printf("Enter word that you want to find.If you want to exit from the game, please write \"exit game\" \n");
		gets(word);															/*Taking Word Until User Enters '\n' Character*/
		count=get_line_size(word);											/*Size Of Word "word"*/
		result_string=string_compare(word,comparisant,WORD_LEN);				/*Comparing The Strings*/
		
		if(result_string==1){												/*If String Is Not "exit game"*/
			result=user_part(dict,coord,area,word,count);					/*Taking Rows And Columns*/
			if(result==-2){													/*Controlling If Number Has Already Entered Or Not*/
				printf("This word has already solved...\n");
			}
			else if(result!= FALSE){								/*If Rows And Columns Are Equal To Any Word's Beginning Or End of X And Y Coordinates*/ 
				for(i=0;i<get_line_size(dict[result]);i++){
					dict[result][i]=dict[result][i]-32;						/*Making Words Uppercase*/
				}
				finish_counter++;
			}else{															/*If Word Or Coordinates Are False*/
				printf("Entered False Coordinates Or Word. Please Try Again...\n");		 
			}
			print_area(dict,coord,area);									/*Printing The Area*/
			getchar();															/*To Reset Word That Taken From The User*/
		}else{																/*If Word Is "exit game"*/
			finish_counter=DICT_SIZE+2;		
			printf("EXITING...\n");
		}
		
	}
	if(finish_counter==DICT_SIZE){
		printf("Congratulations. You Can End The Game\n");			
	}
		
	return 0;
}






