#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>/*EĞER KARŞININ SATIN ALDIĞI Bİ YERE GELDİYSEK PARA AZALSIN*/
#define PLAYERONE 0
#define PLAYERTWO 1

typedef enum {start,property,tax,punish}block_type;

typedef enum {cap,car,noone}player_type;

struct player{

	player_type type;
	int current_block_id;
	int owned_block_ids[11];
	int account;
	int turn_to_wait;
	char *name;

};
struct block{
	
	int block_id;
	char *name;
	int price;
	int rent;
	int rent1;
	int rent2;
	int rent3;
	int house_price;
	int house_count;
	struct player owner;
	block_type type;

};

char *string_cpy_function(char *result, char *source){
    char *start = result;
 
    while(*source != '\0')
    {
        *result = *source;
        result++;
        source++;
    }
 
    *result = '\0'; // add '\0' at the end
    return start;
}

void init_the_board(struct block board[20]){
	int k=0;

	board[0].block_id = 0;
	board[0].name = "Start"; 
	board[0].price = 0;
	board[0].rent = 0;
	board[0].rent1 = 0;
	board[0].rent2 = 0;
	board[0].rent3 = 0;
	board[0].house_price = 0;
	board[0].house_count = 0;
	board[0].owner.type = noone;
	board[0].type = start;

	board[1].block_id = 1;
	board[1].name = "Esenyurt";
	board[1].price = 16000;
	board[1].rent = 800;
	board[1].rent1 = 4000;
	board[1].rent2 = 9000;
	board[1].rent3 = 25000;
	board[1].house_price = 10000;
	board[1].house_count = 0;
	board[1].owner.type = noone;
	board[1].type = property;
	
	board[2].block_id = 2;
	board[2].name = "Car Park";
	board[2].price = 0;
	board[2].rent = 1500;
	board[2].rent1 = 0;
	board[2].rent2 = 0;
	board[2].rent3 = 0;
	board[2].house_price = 0;
	board[2].house_count = 0;
	board[2].owner.type = noone;
	board[2].type = tax;
	
	board[3].block_id = 3;
	board[3].name = "Tuzla";
	board[3].price = 16500;
	board[3].rent = 850;
	board[3].rent1 = 4250;
	board[3].rent2 = 9500;
	board[3].rent3 = 26000;
	board[3].house_price = 12000;
	board[3].house_count = 0;
	board[3].owner.type = noone;
	board[3].type = property;
	
	board[4].block_id = 4;
	board[4].name = "Arnavutkoy";
	board[4].price = 17000;
	board[4].rent = 875;
	board[4].rent1 = 4500;
	board[4].rent2 = 10000;
	board[4].rent3 = 28000;
	board[4].house_price = 12000;
	board[4].house_count = 0;
	board[4].owner.type = noone;
	board[4].type = property;
	
	board[5].block_id = 5;
	board[5].name = "Wait 2 Turn";
	board[5].price = 0;
	board[5].rent = 2;
	board[5].rent1 = 0;
	board[5].rent2 = 0;
	board[5].rent3 = 0;
	board[5].house_price = 0;
	board[5].house_count = 0;
	board[5].owner.type = noone;
	board[5].type = punish;
	
	board[6].block_id = 6;
	board[6].name = "Catalca";
	board[6].price = 20000;
	board[6].rent = 1000;
	board[6].rent1 = 5000;
	board[6].rent2 = 12000;
	board[6].rent3 = 30000;
	board[6].house_price = 13000;
	board[6].house_count = 0;
	board[6].owner.type = noone;
	board[6].type = property;
	
	board[7].block_id = 7;
	board[7].name = "Beykoz";
	board[7].price = 23000;
	board[7].rent = 1100;
	board[7].rent1 = 5500;
	board[7].rent2 = 12500;
	board[7].rent3 = 33000;
	board[7].house_price = 13000;
	board[7].house_count = 0;
	board[7].owner.type = noone;
	board[7].type = property;
	
	board[8].block_id = 8;
	board[8].name = "Car Fix";
	board[8].price = 0;
	board[8].rent = 1750;
	board[8].rent1 = 0;
	board[8].rent2 = 0;
	board[8].rent3 = 0;
	board[8].house_price = 0;
	board[8].house_count = 0;
	board[8].owner.type = noone;
	board[8].type = tax;
	
	board[9].block_id = 9;
	board[9].name = "Maltepe";
	board[9].price = 30000;
	board[9].rent = 1350;
	board[9].rent1 = 7000;
	board[9].rent2 = 15000;
	board[9].rent3 = 40000;
	board[9].house_price = 15000;
	board[9].house_count = 0;
	board[9].owner.type = noone;
	board[9].type = property;
	
	board[10].block_id = 10;
	board[10].name = "Bills";
	board[10].price = 0;
	board[10].rent = 2000;
	board[10].rent1 = 0;
	board[10].rent2 = 0;
	board[10].rent3 = 0;
	board[10].house_price = 0;
	board[10].house_count = 0;
	board[10].owner.type = noone;
	board[10].type = tax;
	
	board[11].block_id = 11;
	board[11].name = "Sisli";
	board[11].price = 33000;
	board[11].rent = 1500;
	board[11].rent1 = 8000;
	board[11].rent2 = 16000;
	board[11].rent3 = 42000;
	board[11].house_price = 16000;
	board[11].house_count = 0;
	board[11].owner.type = noone;
	board[11].type = property;
	
	board[12].block_id = 12;
	board[12].name = "Oil";
	board[12].price = 0;
	board[12].rent = 2250;
	board[12].rent1 = 0;
	board[12].rent2 = 0;
	board[12].rent3 = 0;
	board[12].house_price = 0;
	board[12].house_count = 0;
	board[12].owner.type = noone;
	board[12].type = tax;
	
	board[13].block_id = 13;
	board[13].name = "Atasehir";
	board[13].price = 35000;
	board[13].rent = 1600;
	board[13].rent1 = 8500;
	board[13].rent2 = 17000;
	board[13].rent3 = 45000;
	board[13].house_price = 17000;
	board[13].house_count = 0;
	board[13].owner.type = noone;
	board[13].type = property;
	
	board[14].block_id = 14;
	board[14].name = "Sariyer";
	board[14].price = 40000;
	board[14].rent = 1750;
	board[14].rent1 = 9500;
	board[14].rent2 = 19000;
	board[14].rent3 = 48000;
	board[14].house_price = 19000;
	board[14].house_count = 0;
	board[14].owner.type = noone;
	board[14].type = property;
	
	board[15].block_id = 15;
	board[15].name = "Wait 1 Turn";
	board[15].price = 0;
	board[15].rent = 1;
	board[15].rent1 = 0;
	board[15].rent2 = 0;
	board[15].rent3 = 0;
	board[15].house_price = 0;
	board[15].house_count = 0;
	board[15].owner.type = noone;
	board[15].type = punish;
	
	board[16].block_id = 16;
	board[16].name = "Kadikoy";
	board[16].price = 43000;
	board[16].rent = 1900;
	board[16].rent1 = 11000;
	board[16].rent2 = 21500;
	board[16].rent3 = 55000;
	board[16].house_price = 23000;
	board[16].house_count = 0;
	board[16].owner.type = noone;
	board[16].type = property;
	
	board[17].block_id = 17;
	board[17].name = "Besiktas";
	board[17].price = 60000;
	board[17].rent = 2500;
	board[17].rent1 = 15000;
	board[17].rent2 = 28000;
	board[17].rent3 = 60000;
	board[17].house_price = 30000;
	board[17].house_count = 0;
	board[17].owner.type = noone;
	board[17].type = property;
	
	board[18].block_id = 18;
	board[18].name = "Vocation";
	board[18].price = 0;
	board[18].rent = 5000;
	board[18].rent1 = 0;
	board[18].rent2 = 0;
	board[18].rent3 = 0;
	board[18].house_price = 0;
	board[18].house_count = 0;
	board[18].owner.type = noone;
	board[18].type = tax;
	
	board[19].block_id = 19;
	board[19].name = "Bebek";
	board[19].price = 70000;
	board[19].rent = 3500;
	board[19].rent1 = 20000;
	board[19].rent2 = 35500;
	board[19].rent3 = 65000;
	board[19].house_price = 35000;
	board[19].house_count = 0;
	board[19].owner.type = noone;
	board[19].type = property;
	
}

void init_player(struct player *player_one,struct player *player_two){

	int i;
	
	player_one->type = cap;
	player_one->current_block_id = 0;
	for(i=0;i<11;i++){
		player_one->owned_block_ids[i]= -1;
	}
	player_one->account = 1000;
	player_one->turn_to_wait=0;
	player_one->name = "Cap";
	
	player_two->type = car;
	player_two->current_block_id = 0;
	for(i=0;i<11;i++){
		player_two->owned_block_ids[i]= -1;
	}
	player_two->account = 1000;
	player_two->turn_to_wait=0;
	player_two->name = "Car";

}

int char_counter(char *string){
	
	int k=0,counter=0;
	while(*(string+k)!='\0'){
	
		counter++;	
		k++;
	}
	return counter;
}

int int_counter(int number){
	int counter=0;
	
	while(number!=0){
		number = number/10;
		counter++;
	}

	return counter;
}


void show_board(struct block board[20],struct player player_one, struct player player_two){

	int i,j=0;
	int point1=19,point2=6;
	for(i=0;i<145;i++){
		printf("-");
	}
	printf("\n");
	
	for(i=0;i<6;i++){
		printf("|\t");
		printf("%s",board[i].name);
		if(char_counter(board[i].name)<8){
			printf("\t\t");
		}else if(char_counter(board[i].name)<12){
			printf("\t");
		}
	}
	printf("|\n");
	for(i=0;i<6;i++){
		printf("|\t");
		if(board[i].type == property){
			printf("%d$",board[i].price);
		}else if(board[i].type == tax){
			printf("%d$",board[i].rent);
		}
		if(int_counter(board[i].price)<8){
			printf("\t\t");
		}else if(int_counter(board[i].price)<12){
			printf("\t");
		}
	}
	printf("|\n");
	for(i=0;i<6;i++){
		printf("|\t");
		if(player_one.current_block_id == i){
			printf("%s ",player_one.name);
		}if(player_two.current_block_id == i){
			printf("%s",player_two.name);
		}else{
			printf(" ");
		}
		if(int_counter(board[i].price)<=8){
			printf("\t\t");
		}else if(int_counter(board[i].price)<12){
			printf("\t");
		}
	}
	printf("|\n");
	
	for(i=0;i<145;i++){
		printf("-");
	}
	printf("\n");
	for(i=0;i<4;i++){
		printf("|\t");	
		printf("%s",board[point1-i].name);
		if(char_counter(board[point1-i].name)<8){
			printf("\t\t");
		}else if(char_counter(board[point1-i].name)<12){
			printf("\t");
		}
		printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\t");
		printf("%s",board[point2+i].name);
		printf("\t\t|\n");
		
		printf("|\t");	
		if(board[point1-i].type == property){
			printf("%d$",board[point1-i].price);
		}else if(board[point1-i].type == tax){
			printf("%d$",board[point1-i].rent);
		}
		if(int_counter(board[0].price)<=8){
			printf("\t\t");
		}else if(int_counter(board[0].price)<12){
			printf("\t");
		}
		printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\t");
		if(board[point2+i].type == property){
			printf("%d$",board[point2+i].price);
		}else if(board[point2+i].type == tax){
			printf("%d$",board[point2+i].rent);
		}
		printf("\t\t|\n");
		
		printf("|\t");	
			if(player_one.current_block_id == point1-i){
				printf("%s ",player_one.name);
			}if(player_two.current_block_id == point1-i){
				printf("%s",player_two.name);
			}else{
				printf(" ");
			}
			if(int_counter(board[5].price)<=8){
				printf("\t\t");
			}else if(int_counter(board[5].price)<12){
				printf("\t");
			}
		printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\t");
			if(player_one.current_block_id == point2+i){
				printf("%s ",player_one.name);
			}if(player_two.current_block_id == point2+i){
				printf("%s",player_two.name);
			}else{
				printf(" ");
			}
			if(int_counter(board[5].price)<=8){
				printf("\t\t");
			}else if(int_counter(board[5].price)<12){
				printf("\t");
			}
		printf("|\n");
		if(i!=3){
			for(j=0;j<25;j++){
				printf("-");
			}
			for(j=0;j<95;j++){
				printf(" ");
			}
			for(j=0;j<25;j++){
				printf("-");
			}
			printf("\n");
		}
	}
	for(i=0;i<145;i++){
		printf("-");
	}
	printf("\n");
	for(i=15;i>9;i--){
		printf("|\t");
		printf("%s",board[i].name);
		if(char_counter(board[i].name)<8){
			printf("\t\t");
		}else if(char_counter(board[i].name)<12){
			printf("\t");
		}
	}
	printf("|\n");
	
	for(i=15;i>9;i--){
		printf("|\t");
		if(board[i].type == property){
			printf("%d$",board[i].price);
		}else if(board[i].type == tax){
			printf("%d$",board[i].rent);
		}
		if(int_counter(board[i].price)<8){
			printf("\t\t");
		}else if(int_counter(board[i].price)<12){
			printf("\t");
		}
	}
	printf("|\n");
	
	for(i=15;i>9;i--){
	j=0;
		printf("|\t");
			if(player_one.current_block_id == i){
				printf("%s ",player_one.name);
			}if(player_two.current_block_id == i){
				printf("%s",player_two.name);
			}else{
				printf(" ");
			}
			
			if(int_counter(board[j].price)<=8){
				printf("\t\t");
			}else if(int_counter(board[j].price)<12){
				printf("\t");
			}
		j++;
	}
	printf("|\n");
	
	for(i=0;i<145;i++){

		printf("-");
	
	}
	printf("\n");
}

void show_properties(struct block board[20]){

	int i=0,input;
	printf("Please select a property to see details:\n");
	
	while(i<20){
		if(board[i].type == property){
			printf("%d -\t%s\n",board[i].block_id,board[i].name);
		}
		i++;
	}
	printf("0 -\tExit\n");
	
	do{
		scanf("%d",&input);
	}while(input<-1 && input>20);
		
	if(input!=0){	
		printf("\n\n\n");
		
		printf("---------------------------------\n");
		
		printf("|\t%s",board[input].name);
		
		if(char_counter(board[input].name)<8){
				printf("\t\t\t|\n");
		}else if(char_counter(board[input].name)<12){
			printf("\t\t|\n");
		}
		
		printf("---------------------------------\n");
		
		printf("|\tRent");
		if(int_counter(board[input].rent)<=8){
				printf("\t\t");
		}else if(int_counter(board[input].rent)<12){
			printf("\t");
		}
		printf("%d$\t|\n",board[input].rent);
		
		printf("|\tRent 1 H");
		if(int_counter(board[input].rent1)<=8){
				printf("\t");
		}
		printf("%d$\t|\n",board[input].rent1);
		
		printf("|\tRent 2 H");
		if(int_counter(board[input].rent2)<=8){
				printf("\t");
		}
		printf("%d$\t|\n",board[input].rent2);
		
		printf("|\tRent 3 H");
		if(int_counter(board[input].rent3)<=8){
				printf("\t");
		}
		printf("%d$\t|\n",board[input].rent3);
		
		printf("---------------------------------\n");
		
		printf("|\tHouse Price\t%d$\t|\n",board[input].house_price);
		
		printf("---------------------------------\n");
	}
}
int roll_dice(){
	int result;
	result = (rand()%6)+1;
	return result;
}
int check_block(struct player *current_player){			/*kaç tane mülkü var*/
	int i,counter=0;
	
	for(i=0;i<11;i++){
		if(current_player->owned_block_ids[i]!=-1){
			counter++;
		}
	}
	return counter;
}

int check_block_id(struct block *current_block, struct player *current_player,player_type type){
	int i;
	
	if(current_block->owner.type == type){
		return 1;
	}
	return 0;
}

void show_my_account(struct player *player){
	printf("Money left in %s's account: %d$ ",player->name,player->account);
}

void show_my_properties(struct player *player,struct block board[20]){/*sahip olduğu mülkleri bastırma*/
	int i,counter=0;
	
	for(i=0;i<11;i++){
		if(player->owned_block_ids[i]!=-1){
			printf("%d - %s  - %d House(s)",board[player->owned_block_ids[i]].block_id,board[player->owned_block_ids[i]].name,board[player->owned_block_ids[i]].house_count);
			printf(" - %d Payback\n",(board[player->owned_block_ids[i]].price + board[player->owned_block_ids[i]].house_price*board[player->owned_block_ids[i]].house_count)/2);
			counter++;
		}
	}
	if(counter==0){
		printf("There's no property\n");
	}
}
int go_until(struct player* current_player,int input){

	int i=0;
	while(current_player->owned_block_ids[i]!= input){
		i++;	
	}
	return i;
}

void sell_property(struct block board[20], struct player* current_player){
	int input,control,res;
	res = check_block(current_player);
	if(res>0){	
		show_my_properties(current_player,board);
		printf("Please enter Id of any property that you want to sell(-1 for exit):");
		scanf("\n%d",&input);
		control = check_block_id(&board[input],current_player,current_player->type);
		if(control == 1 && input != -1){
			current_player->account = current_player->account + (board[input].price + board[input].house_price*board[input].house_count)/2;
			board[input].owner.type = noone; 
			board[input].house_count = 0;
			current_player->owned_block_ids[go_until(current_player,input)] = -1;
		}else if(input == -1){
			printf("Exiting...\n");
		}else{
			printf("This property is not yours.\n");
		}
	}else{
		printf("You haven't got any property.\n");
	}
}


int buy_house(struct block* current_block, struct player* current_player){
	int count=0,counter=0;
	char scan;
	if(current_block->owner.type == current_player->type){
		if(current_block->house_count != 3){	
			if(current_player->account >= current_block->house_price){
				count = current_block->house_count;
				while(count<3){	
					printf("Do you want to buy %d. house(y/n)?",count+1);
					scanf("\n%c",&scan);
					if(current_player->account >= current_block->house_price){
						while(scan != 'y' && scan != 'Y' && scan != 'N' && scan != 'n'){
							printf("Entered wrong character. Please try again:");
							scanf("\n%c",&scan);
						}
						if(scan == 'y' || scan == 'Y'){
							current_player->account -= current_block->house_price;
							current_block->house_count++;
							count++;
							counter++;
							printf("%s have %d$ left\n",current_player->name,current_player->account);
						}else if(scan == 'n' || scan == 'N'){
							count = 5;/*To pass the while loop*/
						}else if(current_player->account < current_block->house_price){
							printf("You don't have enough money to buy more than %d house.",count);
							return 2;
						}
					}else{
						printf("You have to sell any of your property.\n");
						return 2;
					}
				}
				if(current_block->house_count == 3 && counter == 0){
					printf("You have already built 3 houses.\n");
				}
			}else{
				printf("You have to sell any of your property.\n");
				return 2;
			}
		}else if(current_block->house_count == 3 && counter == 0){
			printf("You have already built 3 houses.\n");
		}
	}else{
		printf("This block was either can't purchased or was purchased by the other user.\n ");
	}

}

void buy_property(struct block* current_block, struct player* current_player){

	char scan;
	int result,i;
	
	if(current_block->type == property){
		if(current_block->owner.type == noone){
			printf("%s have %d$\n",current_player->name , current_player->account);
			printf("Do you want to buy %s?(y/n):",current_block->name);
			getchar();
			scanf("\n%c",&scan);
			while(scan != 'y' && scan != 'Y' && scan != 'N' && scan != 'n'){
				printf("Entered wrong character. Please try again(y/n):");
				scanf("\n%c",&scan);
			}
			if(scan == 'y' || scan == 'Y'){
				if(current_player->account >= current_block->price){
					current_player->account =	current_player->account - current_block->price;
					current_block->owner.type = current_player->type;
					current_player->owned_block_ids[go_until(current_player,-1)] = current_block->block_id;
					printf("%s have %d$ left\n",current_player->name,current_player->account);
					printf("Do you want to buy house(s)?(y/n):");
					scanf("\n%c",&scan);
					while(scan != 'y' && scan != 'Y' && scan != 'N' && scan != 'n'){
						printf("Entered wrong character. Please try again(y/n):");
						scanf("\n%c",&scan);
					}
					if(scan == 'y' || scan == 'Y'){
						result = buy_house(current_block, current_player);
					}
				}else{
					if(check_block(current_player) > 0){	
						printf("You haven't got enough money to buy this property.You have to sell properties.\n");
					}else{
						printf("You haven't got any property.\n");
					}
				}
			}
			
		}else if(current_block->owner.type == cap){
			printf("You have already bought this property.\n");
		}else if(current_block->owner.type == car){						/*1. oyuncu 2.'nin olduğu yerde*/
			i = current_block->house_count;
			if(i==0){
				current_player->account = current_player->account - current_block->rent;
			}else if(i==1){
				current_player->account = current_player->account - current_block->rent1;
			}else if(i==2){
				current_player->account = current_player->account - current_block->rent2;
			}else if(i==3){
				current_player->account = current_player->account - current_block->rent3;
			}
		}
	}else if(current_block->type == tax){
		current_player->account = current_player->account - current_block->rent;
		printf("%s paid %d$ for %s\n",current_player->name, current_block->rent, current_block->name);
	}else if(current_block->type == punish){																/*punish*/
		current_player->turn_to_wait = current_block->rent;
	}

}


int menu(struct block board[20],struct player *player_one, struct player *player_two,int i){
	
	char decider_char,choice='2';
	int result,res=0;
	srand(time(NULL)); 
		if(i==PLAYERONE){
			printf("Cap's turn\n");
		}else{
			printf("Car's turn\n");
		}	
		printf("%s\n","1 - Roll The Dice" );
		printf("%s\n","2 - Show my account" );
		printf("%s\n","3 - Show my properties" );
		printf("%s\n","4 - Show property deeds" );
		printf("%s\n","5 - Buy property" );
		printf("%s\n","6 - Buy house" );
		printf("%s\n","7 - Sell property" );
		printf("%s","Please select an option to continue:" );
		while(1){	
			scanf("\n%c",&choice);
			while(choice<1 && choice>7){
				scanf("\n%c",&choice);
			}
			if(choice == '1'){
				return (roll_dice()%6)+1;
			
			}if(choice == '2' && i== PLAYERONE){
				show_my_account(player_one);
			}else if(choice == '2' && i== PLAYERTWO){
				show_my_account(player_two);
			}else if(choice == '3' && i== PLAYERONE){
				show_my_properties(player_one,board);
			}else if(choice == '3' && i== PLAYERTWO){
				show_my_properties(player_two,board);
			}else if(choice == '4'){
				show_properties(board);
			}else if(choice == '5'&& i==PLAYERONE){
				if(player_one->account >= board[player_one->current_block_id].price){
					buy_property(&board[player_one->current_block_id],player_one);
				}else if(player_one->account < board[player_one->current_block_id].price){
					printf("You haven't got enough money to buy this property. You have to sell one of your properties.\n");
					sell_property(board,player_one);
				}
			}else if(choice == '5'&& i==PLAYERTWO){
				if(player_two->account >= board[player_two->current_block_id].price){
					buy_property(&board[player_two->current_block_id],player_two);
				}else if(player_one->account < board[player_one->current_block_id].price){
					printf("You haven't got enough money to buy this property. You have to sell one of your properties.\n");
					sell_property(board,player_two);
				}
			}if(choice == '6'&& i==PLAYERONE){
				res = buy_house(&board[player_one->current_block_id],player_one);
				if(res == 2){
					choice = '7';
				}
			}if(choice == '6'&& i==PLAYERTWO){
				res = buy_house(&board[player_two->current_block_id],player_two);
				if(res == 2){
					choice = '7';
				}
				
			}if(choice == '7'&& i==PLAYERONE){
				sell_property(board,player_one);
			}if(choice == '7'&& i==PLAYERTWO){
				sell_property(board,player_two);
			}
			if(i==PLAYERONE){
				printf("\nCap's turn\n");
			}else{
				printf("\nCar's turn\n");
			}	
			printf("\n%s\n","1 - Roll The Dice" );
			printf("%s\n","2 - Show my account" );
			printf("%s\n","3 - Show my properties" );
			printf("%s\n","4 - Show property deeds" );
			printf("%s\n","5 - Buy property" );
			printf("%s\n","6 - Buy house" );
			printf("%s\n","7 - Sell property" );
			printf("%s","Please select an option to continue:" );	
		}	
	printf("\n\n");
}

int check_punish_id(struct block board[20],struct player *player){
	int i;
	for(i=0;i<20;i++){
		if(board[i].type == punish && player->current_block_id == i ){
			return 1;
		}
	}
	return 0;
}
int check_tax_id(struct block board[20],struct player *player){
	int i;
	for(i=0;i<20;i++){
		if(board[i].type == tax && player->current_block_id == i ){
			return 1;
		}
	}
	return 0;
}

void gameplay(struct block board[20],struct player *player_one, struct player *player_two){

	int side_changer,rolled_number,condition=0,punish_1=0,punish_2=0,count_1=0,count_2=0,i=0;
	char scan;
	 
	for(side_changer=0;side_changer>=0;side_changer++){	
	i=0;
		if(side_changer%2==PLAYERONE){
			if(player_two->account > 0 || check_block(player_two)>0){
				if(player_one->turn_to_wait==0){				/*eğer cezası bitmediyse giremesin*/
					player_one->current_block_id = player_one->current_block_id + menu(board,player_one,player_two,PLAYERONE);
					if(player_one->current_block_id>=20){
						player_one->current_block_id = player_one->current_block_id%20;
						player_one->account = player_one->account + 10000;
						i++;
					}
					show_board(board,*player_one,*player_two);
					if(i==1){
						printf("Cap got 10000$ because of passing from starting point\n");	
					}
					buy_property(&board[player_one->current_block_id] ,player_one);
					if((player_one->account < board[player_one->current_block_id].price || player_one->account < board[player_one->current_block_id].house_price) && check_block(player_one) > 0){
						printf("Do you want to sell any of your property(y/n)?:");
						scanf("\n%c",&scan);
						while(scan != 'n' && scan != 'N' ){
							while(scan != 'y' && scan != 'Y' && scan != 'N' && scan != 'n'){
								printf("Entered wrong character. Please try again(y/n):");
								scanf("\n%c",&scan);
							}
							if(scan == 'y' || scan == 'Y'){
								 sell_property(board, player_one);
							}
							printf("%s have %d$ left\n",player_one->name,player_one->account);
							printf("Do you want to sell any of your property(y/n)?:");
							scanf("\n%c",&scan);
						}
					}
				}else{
					player_one->turn_to_wait--;
				}
			}else{
				printf("Cap Wins\n");
				return;
			}									
		}
		i=0;
		if(side_changer%2==PLAYERTWO){
			if(player_one->account > 0 || check_block(player_one)>0){
				if(player_two->turn_to_wait==0){				/*eğer cezası bitmediyse giremesin*/
					player_two->current_block_id = player_two->current_block_id + menu(board,player_one,player_two,PLAYERTWO);
					if(player_two->current_block_id>=20){
						player_two->current_block_id = player_two->current_block_id%20;
						player_two->account = player_two->account + 10000;
						printf("Car got 10000$ because of passing from starting point\n");
						i++;
					}
					show_board(board,*player_one,*player_two);
					if(i==1){
						printf("Cap got 10000$ because of passing from starting point\n");	
					}
					buy_property(&board[player_two->current_block_id] ,player_two);
					if((player_two->account < board[player_two->current_block_id].price || player_two->account < board[player_two->current_block_id].house_price) && check_block(player_two) > 0){
						printf("Do you want to sell any of your property(y/n)?:");
						scanf("\n%c",&scan);
						while(scan != 'n' && scan != 'N' ){
							while(scan != 'y' && scan != 'Y' && scan != 'N' && scan != 'n'){
								printf("Entered wrong character. Please try again(y/n):");
								scanf("\n%c",&scan);
							}
							if(scan == 'y' || scan == 'Y'){
								 sell_property(board, player_two);
							}
							printf("%s have %d$ left\n",player_two->name,player_two->account);
							printf("Do you want to sell any of your property(y/n)?:");
							scanf("\n%c",&scan);
						}
					}
				}else{
					player_two->turn_to_wait--;
				}
			}else{
				printf("Car Wins\n");
				return;
			}									
		}
	}

}

int main(){

struct block board[20];
struct player player_one,player_two;

init_the_board(board);

init_player(&player_one,&player_two);
show_board(board,player_one,player_two);

gameplay(board,&player_one,&player_two);

}
