/*			There are some problems about my homework										*/
/*	1)	However A User Pokemon Doesn't Move, Stamina Become Directly 0						 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY -1

typedef enum{quadratic,linear}attack_type;
typedef enum{Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby}pokemon;


int length_of_pokemon(char name[][11],int i){

	int j=0;
	
	while(j!=10 && name[i][j]!='\0' ){
		j++;
	}
	return j;

}

int length_of_input(char name[]){

	int i=0;
	
	while(name[i]!='\0'){
		i++;
	}
	return i;

}

int comp_pokemon(char input[],char Pokemon_name[][11]){

	int j,i,length_input,length_pokemon,counter=0,temp=-1;
	char carry;
	
	length_input = length_of_input(input);					/*Length Of Input*/
	
	for(i=0;i<10;i++){	
		carry = ' ';
		j=0;
		counter=0;
		length_pokemon = length_of_pokemon(Pokemon_name,i);
		
		if(length_input==length_pokemon){
			while(input[j+2]!='\0'){
				if(Pokemon_name[i][j] == input[j]){
					counter++;
				}
				j++;
			}
			if(counter == length_pokemon-2){
				temp=i;
				i=10;
			}	
		}
	}		
	return temp;
		
}

char *deciding_type(attack_type type[10],int comp){			/*Deciding If The Type is Quadratic Or Linear*/

	if(type[comp]==0){
		return "Quadratic";
	}else if(type[comp] == 1){
		return "Linear";
	}
	
}

void print_pokemon(int comp,char Pokemon_name[][11], int range[], attack_type type[],int attack_power[], int stamina[]){
	
	char *type1= deciding_type(type,comp);
	
	if(comp==-1){
		printf("%s","You Entered Wrong Pokemon Name...\n");
	}
	else{
		printf("Name		: %s\n",Pokemon_name[comp]);
		printf("Attack Type	: %s\n",type1);
		printf("Range		: %d\n",range[comp]);
		printf("Attack Power	: %d\n",attack_power[comp]);
		printf("Stamina		: %d\n",stamina[comp]);
	}

}

void decider(pokemon Pokemons[],int i){						/*Function For Printing The names Of Pokemon*/
	
	if(Pokemons[i]==Charmander){
		printf("Charmander\n");
	}else if(Pokemons[i]==Pikachu){
		printf("Pikachu\n");
	}else if(Pokemons[i]==Squirtle){
		printf("Squirtle\n");
	}else if(Pokemons[i]==Bulbasaur){
		printf("Bulbasaur\n");
	}else if(Pokemons[i]==Pidgeotto){
		printf("Pidgeotto\n");
	}else if(Pokemons[i]==Ratata){
		printf("Ratata\n");
	}else if(Pokemons[i]==Mug){
		printf("Mug\n");
	}else if(Pokemons[i]==Caterpie){
		printf("Caterpie\n");
	}else if(Pokemons[i]==Zubat){
		printf("Zubat\n");
	}else if(Pokemons[i]==Krabby){
		printf("Krabby\n");
	}else if(Pokemons[i]==-1){
		printf("\n");
	}
}

void pokedex(char Pokemon_name[][11], int range[], attack_type type[],int attack_power[], int stamina[]){
	char input[11];
	int result;
	
	printf("Please enter name of your pokemon>\n");
	
	scanf("%s",input);
	
	if(input!="exit"){										//exit yazınca menüye geri dön
		result = comp_pokemon(input,Pokemon_name);
		print_pokemon(result,Pokemon_name,range,type,attack_power,stamina);
	}
}
void show_Pokemons(char Pokemon_name[10][11], pokemon Pokemons[],int pokemon_count){			/*Function For Showing Out Pokemons*/

	int i;
	
	for(i=0;i<pokemon_count;i++){
		printf("%d - ",i);
		decider(Pokemons,i);					
	}
}

int control_f(int input,pokemon *my_pokemons){		/*The Function For If There Is Pokemon That Are Choosen Is On My Pocket Of Not*/
	int i=0,flag=1;
	
	while(flag==1 && i<4){
	
		if(my_pokemons[i]==input){
			flag=0;
		}
		i++;
	}
	return flag;

}

void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pokemons	){/*Function For Adding Choosen Pokemon On My Pocket*/
	int i=0,input=0,control,flag=1,counter=0;

	printf("Please Enter The Number Of Pokemon That You Want To Catch>\n");
	scanf("%d",&input);

	control = control_f(input,my_pokemons);
	
	if(input>=0 && input<10 && control==1){
		while(flag==1 && i<4){
			if(*(my_pokemons+i)==-1){
				*(my_pokemons+i)=Pokemons[input];
				flag=0;
				counter++;	
			}
			
			i++;
		}	
		if(counter!=0){
			printf("You Caught Pokemon %d\n",input);
		}
		if(counter==0){
			printf("Your Pocket Is Full.You Can Enter The Battle.\n");
		
		}
		
	}else{
		printf("You Might Tried To Enter A Pokemon That You Have Already Entered Or Wrong Value.\n");
	}
	
}

void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pocket){

	int pokemon_count = 4,poke_number;
	
	show_Pokemons(Pokemon_name,my_pocket,pokemon_count);
	
	printf("Please Enter The Number Of Pokemon That You Want To Release>(Enter 4 To Go Back To Menu)\n");
	
	scanf("%d",&poke_number);
	
	*(my_pocket+poke_number)=-1;

}


void oaks_laboratory(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_Pokemons){

	int pokemon_count=10;
	char choice = '2',decider_char;
	getchar();					/*Getchar(); Function For Keeping \n Character*/
	
	while(choice >'0' && choice<'4'){

		printf("\n%s\n","		*****Welcome To Oak's Laboratory*****\n" );
		printf("%s\n","		1.Show Pokemons\n" );
		printf("%s\n","		2.Catch Pokemon\n" );
		printf("%s\n","		3.Release Pokemon\n" );
		printf("%s\n","		4.Back\n");
		printf("%s","		Choice:" );
	
		do{
			scanf("%c",&choice);
		}while(choice<1 && choice>4);
						
		if(choice == '1'){
			show_Pokemons(Pokemon_name,Pokemons,pokemon_count);
		
		}else if(choice == '2'){
			catch_a_pokemon(Pokemon_name, Pokemons,my_Pokemons);	
		
		}else if(choice == '3'){
			release_a_pokemon(Pokemon_name,Pokemons,my_Pokemons);
		
		}else if(choice == '4'){
			printf("%s","GETTING BACK TO MAIN MENU...\n" );
			break;
		}else{

			printf("%s","You entered wrong value. " );
		}
			getchar();
			choice = '2';

	}
}

void print_shortcut(int area[8][8],int i,int j){ /*Function For Printing Shortcuts Of Pokemons' Names That Are Shown On The Area*/

	if(area[i][j]==0){
		printf("Ch");
	}else if(area[i][j]==1){
		printf("Pik");
	}else if(area[i][j]==2){
		printf("Sq");
	}else if(area[i][j]==3){
		printf("Bu");
	}else if(area[i][j]==4){
		printf("Pid");
	}else if(area[i][j]==5){
		printf("Rat");
	}else if(area[i][j]==6){
		printf("Mu");
	}else if(area[i][j]==7){
		printf("Ca");
	}else if(area[i][j]==8){
		printf("Zu");
	}else if(area[i][j]==9){
		printf("Kr");
	}else{
		printf(" ");
	}
}

void show_area (char Pokemon_name[10][11],int area[8][8],int pokemon_staminas_view[8][8]){/*Function For Print The Area*/

	int j,i;
	printf("\n\n");
		
	for(j=0;j<8;j++){	
		for(i=0;i<8;i++){
			printf("----------------");
		}
		printf("\n|");
		
		for(i=0;i<8;i++){
			printf("\t");
			print_shortcut(area,i,j);
			//printf("%d",area[i][j]);
			printf("\t|");
		}
		printf("\n|");
		for(i=0;i<8;i++){
			printf("\t");
			if(pokemon_staminas_view[i][j]<=-1){/*If Stamina Is Smaller Than Or Equal To 0,Then Replace It By Space Character*/
				printf(" ");
			}else{
				printf("(%d)",pokemon_staminas_view[i][j]);/*Otherwise Print The Stamina Of That Pokemon*/
			}
			printf("\t|");
		}
		printf("\n");
	}
	for(i=0;i<8;i++){
		printf("----------------");
	}

	printf("\n\n");	
}

void move_f(int move,int move_count,int coordinates_User[4][2],int input,int area[8][8],pokemon user_Pokemons[4],int pokemon_staminas_view[8][8],int stamina[8]){
	if(move==2){
		if(coordinates_User[input][0]+move_count<8 && 									/*Condition To Avoid Overhanging The Edges*/
			area[coordinates_User[input][1]][coordinates_User[input][0]+move_count] ==-1){/*Not To Overwrite The Name Of Pokemon*/
			
			coordinates_User[input][0]=coordinates_User[input][0]+move_count;
			area[coordinates_User[input][1]][coordinates_User[input][0]-move_count] =-1;
			area[coordinates_User[input][1]][coordinates_User[input][0]]=user_Pokemons[input];
			pokemon_staminas_view[coordinates_User[input][1]][coordinates_User[input][0]-move_count]=-1;
			pokemon_staminas_view[coordinates_User[input][1]][coordinates_User[input][0]]=stamina[user_Pokemons[input]];
		}
	}else if(move==4){
		if(coordinates_User[input][1]-move_count>=0 && 										/*Condition To Avoid Overhanging The Edges*/
			area[coordinates_User[input][1]-move_count][coordinates_User[input][0]] ==-1){	/*Not To Overwrite The Name Of Pokemon*/
			
			coordinates_User[input][1]=coordinates_User[input][1]-move_count;
			area[coordinates_User[input][1]+move_count][coordinates_User[input][0]] =-1; 
			area[coordinates_User[input][1]][coordinates_User[input][0]]=user_Pokemons[input];
			pokemon_staminas_view[coordinates_User[input][1]+move_count][coordinates_User[input][0]]=-1;
			pokemon_staminas_view[coordinates_User[input][1]][coordinates_User[input][0]]=stamina[user_Pokemons[input]];
		}
	}else if(move==6){
		if(coordinates_User[input][1]+move_count<8 && 										/*Condition To Avoid Overhanging The Edges*/
			area[coordinates_User[input][1]+move_count][coordinates_User[input][0]] ==-1){/*Not To Overwrite The Name Of Pokemon*/
				
			coordinates_User[input][1]=coordinates_User[input][1]+move_count;
			area[coordinates_User[input][1]-move_count][coordinates_User[input][0]] =-1; 
			area[coordinates_User[input][1]][coordinates_User[input][0]]=user_Pokemons[input];
			pokemon_staminas_view[coordinates_User[input][1]-move_count][coordinates_User[input][0]]=-1;
			pokemon_staminas_view[coordinates_User[input][1]][coordinates_User[input][0]]=stamina[user_Pokemons[input]];
		}
	}else if(move==8){
		if(coordinates_User[input][0]-move_count>=0 && 										/*Condition To Avoid Overhanging The Edges*/
			area[coordinates_User[input][1]][coordinates_User[input][0]-move_count] ==-1){	/*Not To Overwrite The Name Of Pokemon*/
			
			coordinates_User[input][0]=coordinates_User[input][0]-move_count;
			area[coordinates_User[input][1]][coordinates_User[input][0]+move_count] =-1;
			area[coordinates_User[input][1]][coordinates_User[input][0]]=user_Pokemons[input];
			pokemon_staminas_view[coordinates_User[input][1]][coordinates_User[input][0]+move_count]=-1;
			pokemon_staminas_view[coordinates_User[input][1]][coordinates_User[input][0]]=stamina[user_Pokemons[input]];
		}
	}
		
}

void check_range(int coordinates_User[4][2],int coordinates_Ai[4][2],int stamina[10],int attack_power[10], attack_type type[10], int range[10],pokemon user_Pokemons[4],pokemon Ai_Pokemons[4],int input_user,int pokemon_staminas_view[8][8],int area[8][8]){//0=y 1=x
	int i,j,k,new_stamina;
		
	if(type[user_Pokemons[input_user]]==linear){					/*If Type Of That Pokemon Is Linear*/
		for(k=1;k<=range[user_Pokemons[input_user]];k++){				/*Range*/			
			for(i=0;i<4;i++){					/*Changing The Pokemon To Control If There Is A Rival Pokemon At Bottom*/ 
				if(coordinates_User[input_user][0]+k==coordinates_Ai[i][0] && coordinates_User[input_user][1]==coordinates_Ai[i][1]){
				stamina[Ai_Pokemons[i]] = stamina[Ai_Pokemons[i]]-attack_power[user_Pokemons[input_user]];
					if(stamina[Ai_Pokemons[i]]<=0){
						pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
						area[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
						Ai_Pokemons[i]=-1;
						coordinates_Ai[i][1]=-1;
						coordinates_Ai[i][0]=-1;
						
					}else{
						pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=stamina[Ai_Pokemons[i]]; 
					}
				i=5;
				}
												/*Changing The Pokemon To Control If There Is A Rival Pokemon At Left*/
				else if(coordinates_User[input_user][0]==coordinates_Ai[i][0] && coordinates_User[input_user][1]+k==coordinates_Ai[i][1]){
				stamina[Ai_Pokemons[i]] = stamina[Ai_Pokemons[i]]-attack_power[user_Pokemons[input_user]];
					if(stamina[Ai_Pokemons[i]]<=0){
						pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
						area[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
						Ai_Pokemons[i]=-1;
						coordinates_Ai[i][1]=-1;
						coordinates_Ai[i][0]=-1;
						
					}else{
						pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=stamina[Ai_Pokemons[i]]; 
					}
				i=5;
				}
												/*Changing The Pokemon To Control If There Is A Rival Pokemon At Right*/
				else if(coordinates_User[input_user][0]-k==coordinates_Ai[i][0] && coordinates_User[input_user][1]==coordinates_Ai[i][1]){
				stamina[Ai_Pokemons[i]] = stamina[Ai_Pokemons[i]]-attack_power[user_Pokemons[input_user]];
					if(stamina[Ai_Pokemons[i]]<=0){
						pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
						area[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
						Ai_Pokemons[i]=-1;
						coordinates_Ai[i][1]=-1;
						coordinates_Ai[i][0]=-1;
					}else{
						pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=stamina[Ai_Pokemons[i]]; 
					}
				i=5;
				}
												/*Changing The Pokemon To Control If There Is A Rival Pokemon At Top*/
				else if(coordinates_User[input_user][0]==coordinates_Ai[i][0] && coordinates_User[input_user][1]-k==coordinates_Ai[i][1]){
				stamina[Ai_Pokemons[i]] = stamina[Ai_Pokemons[i]]-attack_power[user_Pokemons[input_user]];
					if(stamina[Ai_Pokemons[i]]<=0){
						pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
						area[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
						Ai_Pokemons[i]=-1;
						coordinates_Ai[i][1]=-1;
						coordinates_Ai[i][0]=-1;
					}else{
						pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=stamina[Ai_Pokemons[i]]; 
					}
				i=5;
				}
				
			}
		
		}
	}else{
		for(k=-range[user_Pokemons[input_user]];k<=range[user_Pokemons[input_user]];k++){
			for(j=-range[user_Pokemons[input_user]];j<=range[user_Pokemons[input_user]];j++){							/*Range*/
				for(i=0;i<4;i++){					/*Changing The Pokemon To Control If There Is A Rival Pokemon At The Rectangular Area*/
					if((k!=0 || j!=0) && coordinates_User[input_user][0]+k==coordinates_Ai[i][0] && coordinates_User[input_user][1]+j==coordinates_Ai[i][1]){
					stamina[Ai_Pokemons[i]] = stamina[Ai_Pokemons[i]]-attack_power[user_Pokemons[input_user]];
						if(stamina[Ai_Pokemons[i]]<=0){
							pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
							area[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=-1;
							coordinates_Ai[i][1]=-1;
							coordinates_Ai[i][0]=-1;
						}else{
							pokemon_staminas_view[coordinates_Ai[i][1]][coordinates_Ai[i][0]]=stamina[Ai_Pokemons[i]]; 
						}
					i=5;
					}
				}
		
			}
		}
	}	
}

void battle(char Pokemon_name[10][11], int range[10], attack_type type[10], int attack_power[10], int stamina[10], pokemon user_Pokemons[4]){

	int win=0,ctrl,i,a,b,j,k,y,x,Ai_r0,Ai_y,Ai_x,control=1,flag=1,pokemon_count=4,input_user,move_user,move_count_user=0,counter_User=0,counter_Ai=0;
	int input_Ai,move_Ai,move_count_Ai;
	int area[8][8];
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			area[i][j]=EMPTY;
		}
	}
	int pokemon_staminas_view[8][8];
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			 pokemon_staminas_view[i][j]=EMPTY;						/*Assigning The Pokemon Stamina Screen*/
		}
	}
										
	pokemon Ai_Pokemons[4]={-1,-1,-1,-1};
	int coordinates_User[4][2];
	for(i=0;i<4;i++){
		for(j=0;j<2;j++){
			 coordinates_User[i][j]=EMPTY;							/*Assigning The User Pokemon Coordinates*/
		}
	}
	int coordinates_Ai[4][2];
	for(i=0;i<4;i++){
		for(j=0;j<2;j++){
			 coordinates_Ai[i][j]=EMPTY;							/*Assigning The Ai Pokemon Coordinates*/
		}
	}
	srand(time(0));	
	
	for(j=0;j<4;j++){
		flag=1;
		Ai_r0=(rand()%10);
		for(k=0;k<4;k++){
			if(Ai_Pokemons[k]==Ai_r0){				/*We Selected Ai Pokemons*/
				flag=0;
				j--;
			}	
		}
		if(flag==1){
			Ai_Pokemons[j]=Ai_r0;
		}	
	}			
	
	for(i=0;i<4;i++){
			
		Ai_y=(rand()%2)+6;					/*Taking Integer For Y Axis For Placement Of AI Pokemons*/
		Ai_x=rand()%8;						/*Taking Integer For Z Axis For Placement Of AI Pokemons*/
		
		if(area[Ai_x][Ai_y]== EMPTY){			/*If The Area Is Empty*/
			area[Ai_x][Ai_y] = Ai_Pokemons[i];
			coordinates_Ai[i][0] = Ai_y;			/*y*/	
			coordinates_Ai[i][1] = Ai_x;			/*x*/
			pokemon_staminas_view[Ai_x][Ai_y]=stamina[Ai_Pokemons[i]];
		}else{
			i--;
		}
	}
	i=0;
	x=-2;
	y=-2;
	show_area(Pokemon_name,area,pokemon_staminas_view);			/*Showing The Area Before User Enter The Coordinates Of Pokemons On His/Her Pocket*/
	do{
		printf("Please Enter X Coordinates Of %d. Pokemon> ",i);
		scanf("%d",&y);
		
		printf("Please Enter Y Coordinates Of %d. Pokemon> ",i);
		scanf("%d",&x);
		
		while(x<0 || x>=2 || y<0 || y>=8){
			printf("INVALID COORDINATES...\n");
			printf("Please Enter X Coordinates Of %d. Pokemon> ",i);
			scanf("%d",&y);
			printf("Please Enter Y Coordinates Of %d. Pokemon> ",i);
			scanf("%d",&x);
			
			for(j=0;j<4;j++){
				if(coordinates_User[j][1]==y && coordinates_User[j][0]==x){
					printf("You Have Entered This Coordinate Another Pokemon...\n");
					y=-2;
					x=-2;
				}
			}
		}
			
			if(area[y][x]== EMPTY){	/*If The Area Is Empty*/
				area[y][x] = user_Pokemons[i];
				coordinates_User[i][0] = x;		/*y*/
				coordinates_User[i][1] = y;		/*x*/		
				pokemon_staminas_view[y][x]=stamina[user_Pokemons[i]];
				show_area(Pokemon_name,area,pokemon_staminas_view);
				i++;
			}else{
				printf("ARENA HAS ALREADY TAKEN...\n");
				
			}
			
	}while(i<4);

	show_Pokemons(Pokemon_name,user_Pokemons,pokemon_count);		/*Pokemons That Are In My Pocket*/
		
	while(win==0){
		printf("Please Enter The Pokemon That You Want To Move>\n");
		scanf("%d",&input_user);	
		
		ctrl = control_f(user_Pokemons[input_user],user_Pokemons);/*The Function For Controlling If User Enters The Pokemon Number That Is Already Dead Or Not*/
		
		while(ctrl==1){
			printf("Please Enter The Pokemon That You Want To Move>\n");
			scanf("%d",&input_user);
		}
			printf("Please Enter The Move(2,4,5,6,8)>\n");
			scanf("%d",&move_user);
			
		while(move_user!=2 && move_user!=4 && move_user!=5 && move_user!=6 && move_user!=8){
			printf("Please Enter The Move(2,4,5,6,8)>\n");
			scanf("%d",&move_user);
		}
		if(move_user!=5){
			printf("Enter The Move Count(1 Or 2)>\n");
			scanf("%d",&move_count_user);
		
			while(move_count_user<1 || move_count_user>2){
				printf("Enter The Move Count(1 Or 2)>\n");
				scanf("%d",&move_count_user);
			}
		}
		printf("YOUR TURN\n");
		move_f(move_user,move_count_user,coordinates_User,input_user,area,user_Pokemons,pokemon_staminas_view,stamina);
	
		input_Ai=rand()%4;						//Choosing Any Pokemon between 0-3
		do{	
			move_count_Ai=rand()%3;				//Generating How Many Move Will AI Do
										
			
		}while(move_count_Ai==0);					//0 1 2 3
		ctrl = control_f(Ai_Pokemons[input_Ai],Ai_Pokemons);/*The Function For Controlling If User Enters The Pokemon Number That Is Already Dead Or Not*/		
		do{
			move_Ai=rand()%5;			//Generating Move Way
			move_Ai=move_Ai*2;
										//çift sayı
			
		}while(move_Ai==0 && ctrl==1);
	
		for(a=0;a<4;a++){
			printf("Pokemon%d - %d\n",a,Ai_Pokemons[a]);
		}
		
		/*Function For Checking If There Is A Pokemon In The Range Of Chosen Pokemon*/
		check_range(coordinates_User,coordinates_Ai,stamina,attack_power,type, range,user_Pokemons,Ai_Pokemons,input_user,pokemon_staminas_view,area);
		
		printf("ENEMY MOVE\n");
		
		/*Function For Moving AI Pokemon*/
		move_f(move_Ai,move_count_Ai,coordinates_Ai,input_Ai,area,Ai_Pokemons,pokemon_staminas_view,stamina);
		
		/*Function For Checking If There Is A Pokemon In The Range Of Chosen Pokemon*/
		check_range(coordinates_Ai,coordinates_User,stamina,attack_power,type,range,Ai_Pokemons,user_Pokemons,input_Ai,pokemon_staminas_view,area);
		
		/*Function For Showing The Area*/
		show_area(Pokemon_name,area,pokemon_staminas_view);
		
		for(a=0;a<4;a++){
			if(pokemon_staminas_view[coordinates_User[a][1]][coordinates_User[a][0]]<=0){	
				counter_User++;
			}
		}	
		for(a=0;a<4;a++){
			if(pokemon_staminas_view[coordinates_Ai[a][1]][coordinates_Ai[a][0]]<=0){	
				counter_Ai++;
			}
		}	
		if(counter_Ai==4){
			printf("User Wins!!!\n");		/*If All The Pokemons That AI Have Are Dead Then User Wins*/
			win=1;
		}else if(counter_User==4){
			printf("Ai Wins!!!\n");			/*If All The Pokemons That User Have Are Dead Then AI Wins*/
			win=1;
		}
		counter_Ai=0;
		counter_User=0;
	
		if(win!=1){	
			show_Pokemons(Pokemon_name,user_Pokemons,pokemon_count);	
		}
	}	
	
	
}

void menu(){		
		
	int control;
	char Pokemon_name[10][11]={"Charmander","Pikachu","Squirtle","Bulbasaur","Pidgeotto","Ratata","Mug","Caterpie","Zubat","Krabby"};
	int range[10]={1,3,4,3,2,2,1,2,3,2};
	attack_type type[10]={quadratic,linear,linear,linear,quadratic,linear,quadratic,quadratic,linear,linear};
	int attack_power[10]={500,350,300,400,250,250,350,200,350,300};
	int stamina[10]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};
	pokemon my_Pokemons[4]={-1,-1,-1,-1};
	pokemon Pokemons[10]={Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby};

	char decider_char,choice='2';

	while(choice >'0' && choice<'4'){
		printf("%s\n","		*****MENU*****\n" );
		printf("%s\n","		1.Open Pokedex\n" );
		printf("%s\n","		2.Go To Oak's Laboratory\n" );
		printf("%s\n","		3.Enter The Tournament\n" );
		printf("%s\n","		4.Exit\n");
		printf("%s","		Choice:" );

		scanf("%c",&choice);
		
		if(choice == '1'){
		
			pokedex(Pokemon_name,range,type,attack_power,stamina);
		
		}else if(choice == '2'){
			oaks_laboratory(Pokemon_name, Pokemons,my_Pokemons);
		
		}else if(choice == '3'){
			control = control_f(-1,my_Pokemons);
			printf("%d",control);
			if(control == 1){
				battle(Pokemon_name,range,type, attack_power,stamina,my_Pokemons);
				break;
			}else{
				printf("Your Pocket Is Not Full. You Can Not Enter The Battle Without Make Your Pocket Full\n");
			}
		}else if(choice == '4'){
			printf("%s","EXITING...\n" );
			break;
		}else{

			printf("%s","You entered wrong value. Please Enter Any Key\n" );
		}	
			getchar();
			choice = '2';
	}
}

int main(){
menu();

return 0;
}
