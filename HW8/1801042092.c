#include <stdio.h>
#include <string.h>
#include <time.h>												/*BİLGİSAYARIN SATMA OLAYINI + ZAR ATMADA FAZLA ÇIKIYOR*/
#include <stdlib.h>
#define PROPERTY_COUNT 13
#define ONE_THIRD_OF_ALL_PROPERTIES 4

typedef enum block_type{start=0,property,fortune,tax,punish}b_type;
typedef enum player_type{noone=-1,car,cap}player_type;

typedef struct{
	player_type type;
	int current_block_id;
	int owned_blocks[PROPERTY_COUNT];
	int account;
	int turn_to_wait;
	char *player_name;
}player;

typedef struct block{
    int id;
    char * name;
    int price;
    int rent;
    int rent_1;
    int rent_2;
    int rent_3;
    int house_price;
    int h_count;
    player owner;
    b_type type;
    struct block *next;
    
}block;

typedef struct fortune_card{

	int card_no;
	char* card_name;

}fortune_card;

void init_struct(block * node_p,int id_p,char* name_p, int price_p, int rent_p, int rent1_p, int rent2_p, int rent3_p,int house_price_p,int h_count_p,b_type type_p){
	
	if(id_p==0){
		node_p->next = (block*)malloc(sizeof(block));
		node_p->id = id_p;
		node_p->name = name_p;
		node_p->price = price_p;
		node_p->rent = rent_p;
		node_p->rent_1 = rent1_p;
		node_p->rent_2 = rent2_p;
		node_p->rent_3 = rent3_p;
		node_p->house_price = house_price_p;
		node_p->h_count = h_count_p;
		node_p->owner.type = noone;
		node_p->type = type_p;
	}else{
		node_p->next = (block*)malloc(sizeof(block));
		node_p->id = id_p;
		node_p->name = name_p;
		node_p->price = price_p;
		node_p->rent = rent_p;
		node_p->rent_1 = rent1_p;
		node_p->rent_2 = rent2_p;
		node_p->rent_3 = rent3_p;
		node_p->house_price = house_price_p;
		node_p->h_count = h_count_p;
		node_p->owner.type = noone;
		node_p->type = type_p;
	}
}


void fill_struct_in(block *node_p){

	for(int i=0;i<24;i++){
		if(i==0){init_struct(node_p,0,"Start",0,0,0,0,0,0,0,start);}
		else if(i==1){init_struct(node_p,1,"Esenyurt",16000,800,4000,9000,25000,10000,0,property);}
		else if(i==2){init_struct(node_p,2,"Car Park",1500,0,0,0,0,0,0,tax);}
		else if(i==3){init_struct(node_p,3,"Fortune Card",0,0,0,0,0,0,0,fortune);}
		else if(i==4){init_struct(node_p,4,"Tuzla",16500,850,4250,9500,26000,12000,0,property);}
		else if(i==5){init_struct(node_p,5,"Arnavutkoy",17000,875,4500,10000,28000,12000,0,property);}
		else if(i==6){init_struct(node_p,6,"Wait 2 Turn",2,0,0,0,0,0,0,punish);}
		else if(i==7){init_struct(node_p,7,"Catalca",20000,1000,5000,12000,30000,13000,0,property);}
		else if(i==8){init_struct(node_p,8,"Beykoz",23000,1100,5500,12500,33000,13000,0,property);}
		else if(i==9){init_struct(node_p,9,"Fortune Card",0,0,0,0,0,0,0,fortune);}
		else if(i==10){init_struct(node_p,10,"Car Fix",1750,0,0,0,0,0,0,tax);}
		else if(i==11){init_struct(node_p,11,"Maltepe",30000,1350,7000,15000,40000,15000,0,property);}
		else if(i==12){init_struct(node_p,12,"Bills",2000,0,0,0,0,0,0,tax);}
		else if(i==13){init_struct(node_p,13,"Sisli",33000,1500,8000,16000,42000,16000,0,property);}
		else if(i==14){init_struct(node_p,14,"Oil",2250,0,0,0,0,0,0,tax);}
		else if(i==15){init_struct(node_p,15,"Fortune Card",0,0,0,0,0,0,0,fortune);}
		else if(i==16){init_struct(node_p,16,"Atasehir",35000,1600,8500,17000,45000,17000,0,property);}
		else if(i==17){init_struct(node_p,17,"Sariyer",40000,1750,9500,19000,48000,19000,0,property);}
		else if(i==18){init_struct(node_p,18,"Wait 1 Turn",1,0,0,0,0,0,0,punish);}
		else if(i==19){init_struct(node_p,19,"Kadikoy",43000,1900,11000,21500,55000,23000,0,property);}
		else if(i==20){init_struct(node_p,20,"Besiktas",60000,2500,15000,28000,60000,30000,0,property);}
		else if(i==21){init_struct(node_p,21,"Fortune Card",0,0,0,0,0,0,0,fortune);}
		else if(i==22){init_struct(node_p,22,"Vocation",3500,0,0,0,0,0,0,tax);}
		else if(i==23){init_struct(node_p,23,"Bebek",70000,3500,20000,35500,65000,35000,0,property);}
		node_p = node_p->next;
	}
	node_p->next=NULL;
}
int roll_dice()
{

    int i=rand()%6+1;
    return i;
}

block * go_until(block * node_p,int i){											/*x'inci digit'e gitmeye yarıyor*/

	while(node_p->id != i){
		node_p = node_p->next;
	}
	return node_p; 
}

void show_property_deed(block * node_p)
{
    int exit_flag=0,i,selection;
    while (exit_flag==0)
    {
        printf("Please select a property to see details:\n");
        for (i = 0; i < 24; ++i) {
            if (go_until(node_p,i)->type==property)
                printf("%d -\t%s \n",go_until(node_p,i)->id,go_until(node_p,i)->name);
        }
        printf("0 -\tExit\n");
        scanf("%d",&selection);
        if (selection==0)
            exit_flag=1;
        else {
            if (selection > 0 && selection <24 && go_until(node_p,selection)->type == property) {
                printf("\n\n---------------------------------\n");
                if (strlen(go_until(node_p,selection)->name) < 8)
                    printf("|\t\t%s\t\t|\n", go_until(node_p,selection)->name);
                else
                    printf("|\t    %s\t\t|\n", go_until(node_p,selection)->name);
                printf("---------------------------------\n");
                printf("|\tRent \t\t%d$\t|\n", go_until(node_p,selection)->rent);
                printf("|\tRent 1 H \t%d$\t|\n", go_until(node_p,selection)->rent_1);
                printf("|\tRent 2 H \t%d$\t|\n", go_until(node_p,selection)->rent_2);
                printf("|\tRent 3 H \t%d$\t|\n", go_until(node_p,selection)->rent_3);
                printf("---------------------------------\n");
                printf("|\tHouse Price \t%d$\t|\n", go_until(node_p,selection)->house_price);
                printf("|\tHouse count \t%d\t|\n", go_until(node_p,selection)->h_count);
                printf("---------------------------------\n\n\n");
            } else printf("\nWrong Selection! Please Try Again.\n\n");
        }
    }
}

void show_board(block *node_p, player computer, player player_)
{
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int i=0,space_flag=0;
	for (i=0;i<7;i++)
	{
        if (strlen(go_until(node_p,i)->name)<8)
		    printf("|\t%s\t\t",go_until(node_p,i)->name);
        else
            printf("|\t%s\t",go_until(node_p,i)->name);
	}
	printf("|\n");
	for (i=0;i<7;i++)
	{
		if (go_until(node_p,i)->type==property || go_until(node_p,i)->type==tax)
		    printf("|\t%d$ \t\t",go_until(node_p,i)->price);
		else if (strlen(go_until(node_p,i)->name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
	}
    printf("|\n");
    for (i=0;i<7;i++)
    {
        space_flag=0;
        printf("|\t");
        if (i==computer.current_block_id && i==player_.current_block_id)
        {
            printf("%s, %s \t",computer.player_name,player_.player_name);
            space_flag=1;
        }
        else {
            if (i == computer.current_block_id) {
                printf("%s \t\t", computer.player_name);
                space_flag = 1;
            }
            if (i == player_.current_block_id) {
                printf("%s \t\t", player_.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(go_until(node_p,i)->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    //Middle
    for (i=0;i<5;i++)
    {
        //Names

        if (strlen(go_until(node_p,23-i)->name)<8)
            printf("|\t%s\t\t|",go_until(node_p,23-i)->name);
        else
            printf("|\t%s\t|",go_until(node_p,23-i)->name);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        if (strlen(go_until(node_p,i+7)->name)<8)
            printf("|\t%s\t\t|",go_until(node_p,i+7)->name);
        else
            printf("|\t%s\t|",go_until(node_p,i+7)->name);
        printf("\n");
        //prices
        if (go_until(node_p,23-i)->type==property || go_until(node_p,i+7)->type==tax)
            printf("|\t%d$ \t\t|",go_until(node_p,23-i)->price);
        else if (strlen(go_until(node_p,23-i)->name)<8)
            printf("|\t     \t|");
        else
            printf("|\t\t \t|");


        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        if (go_until(node_p,i+7)->type==property || go_until(node_p,i+7)->type==tax)
            printf("|\t%d$ \t\t",go_until(node_p,i+7)->price);
        else if (strlen(go_until(node_p,i+7)->name)<8)
            printf("|\t     \t");
        else
            printf("|\t\t \t");

        printf("|\n");
        //spaces

        space_flag=0;
        printf("|\t");
        if (23-i==computer.current_block_id && 23-i==player_.current_block_id)
        {
            printf("%s, %s \t|",computer.player_name,player_.player_name);
            space_flag=1;
        }
        else {
            if (23 - i == computer.current_block_id) {
                printf("%s \t\t|", computer.player_name);
                space_flag = 1;
            }
            if (23 - i == player_.current_block_id) {
                printf("%s \t\t|", player_.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(go_until(node_p,23-i)->	name)<8)
                printf("\t\t|");
            else
                printf("    \t\t|");
        }

        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        space_flag=0;
        printf("|\t");
        if (7+i==computer.current_block_id && 7+i==player_.current_block_id)
        {
            printf("%s, %s \t",computer.player_name,player_.player_name);
            space_flag=1;
        }
        else {

            if (7+i==computer.current_block_id)
            {
                printf("%s \t\t",computer.player_name);
                space_flag=1;
            }
            if (7+i==player_.current_block_id)
            {
                printf("%s \t\t",player_.player_name);
                space_flag=1;
            }
        }

        if (space_flag==0) {
            if (strlen(go_until(node_p,i+7)->name)<8)
                printf("\t\t");
            else
                printf("    \t\t");
        }

        printf("|\n");
        if (i!=4) {
            printf("-------------------------");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            printf("-------------------------");
            printf("\n");
        }

    }

    //bottom row
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=18;i>=12;i--)
    {
        if (strlen(go_until(node_p,i)->name)<8)
            printf("|\t%s\t\t",go_until(node_p,i)->name);
        else
            printf("|\t%s\t",go_until(node_p,i)->name);
    }
    printf("|\n");
    for (i=18;i>=12;i--)
    {
        if (go_until(node_p,i)->type==property || go_until(node_p,i)->type==tax)
            printf("|\t%d$ \t\t",go_until(node_p,i)->price);
        else if (strlen(go_until(node_p,i)->name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
    }
    printf("|\n");
    for (i=18;i>=12;i--)
    {
        space_flag=0;
        printf("|\t");
        if (i==computer.current_block_id && i==player_.current_block_id)
        {
            printf("%s, %s \t",computer.player_name,player_.player_name);
            space_flag=1;
        }
        else {
            if (i == computer.current_block_id) {
                printf("%s \t\t", computer.player_name);
                space_flag = 1;
            }
            if (i == player_.current_block_id) {
                printf("%s \t\t", player_.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(go_until(node_p,i)->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }

    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

void show_player_properties(block* node_p, player current_player)
{
    int i,counter=0,selection;
    while (selection!=0) {
        printf("----------------------------------------\n");
        for (i = 0; i < PROPERTY_COUNT; i++) {
            if (current_player.owned_blocks[i] != -1) {
                printf("%d - %s\n", go_until(node_p,current_player.owned_blocks[i])->id,
                      go_until(node_p,current_player.owned_blocks[i])->name);
                counter++;
            }

        }
        if (counter == 0)
        {
            printf("You have not owned any property yet.\n");
            printf("----------------------------------------\n");
            selection=0;
        }
        else
        {

            printf("0 - Back \n");
            printf("----------------------------------------\n");
            printf("Please select an property to see details.\n");
            scanf("%d", &selection);

            if (selection!=0) {
                if (go_until(node_p,selection)->owner.type != current_player.type)
                    printf("You made a wrong selection!\n");
                else {
                    printf("\n\n---------------------------------\n");
                    if (strlen(go_until(node_p,selection)->name) < 8)
                        printf("|\t\t%s\t\t|\n", go_until(node_p,selection)->name);
                    else
                        printf("|\t    %s\t\t|\n", go_until(node_p,selection)->name);
                    printf("---------------------------------\n");
                    printf("|\tRent \t\t%d$\t|\n", go_until(node_p,selection)->rent);
                    printf("|\tRent 1 H \t%d$\t|\n", go_until(node_p,selection)->rent_1);
                    printf("|\tRent 2 H \t%d$\t|\n", go_until(node_p,selection)->rent_2);
                    printf("|\tRent 3 H \t%d$\t|\n", go_until(node_p,selection)->rent_3);
                    printf("---------------------------------\n");
                    printf("|\tHouse Price \t%d$\t|\n", go_until(node_p,selection)->house_price);
                    printf("|\tHouse count \t%d\t|\n", go_until(node_p,selection)->h_count);
                    printf("---------------------------------\n\n\n");
              }
         }
      }


   }

}

int build_house(block* current_block, player* current_player)
{
    int flag=0;
    if (current_player->type==current_block->owner.type)
    {
        if (current_block->h_count<3)
        {
            if (current_block->house_price<=current_player->account)
            {
                flag=1;
                current_player->account-=current_block->house_price;
                current_block->h_count+=1;
                if(current_block->h_count > 1){
                	printf("You have built %d houses.\n",current_block->h_count);
                	if(current_block->h_count == 3){
                		return 0;
                	}
		}else if(current_block->h_count==1){
			printf("You have built 1 house.\n");
		}
            }
            else
                printf("You don't have enough money to build house!\n");
       }
       else
            printf("You can't buy more than 3 houses in a property!\n");
    }
    else
        printf("You don't have permission to build house on this property!\n ");
    return flag;
}

int count_properties(player current_player)
{
    int i,count=0;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        if (current_player.owned_blocks[i]!=-1)
            count++;
    }
    return count;
}

void sell_property(block* node_p , player* current_player)
{
    int property_id,flag=0,is_owned=-1,i,index,counter=0;
        if (count_properties(*current_player)!=0)
        {
            for (i = 0; i < PROPERTY_COUNT; i++) {
                if (current_player->owned_blocks[i] != -1) {
                    printf("%d - %s\n", go_until(node_p,current_player->owned_blocks[i])->id,
                           go_until(node_p,current_player->owned_blocks[i])->name);
                    counter++;
                }

            }
            printf("0 - Back\n");
            printf("Please select to sell the property:\n");

            scanf("%d",&property_id);
            if (property_id!=0)
            {
                for(i=0;i<PROPERTY_COUNT;i++)
                {
                    if (current_player->owned_blocks[i]==property_id)
                    {
                        is_owned=1;
                        index=i;
                        break;
                    }
                }
                if(is_owned!=-1)
                {
                    current_player->owned_blocks[index]=-1;
                    player temp;
                    go_until(node_p,property_id)->owner.type=noone;
                    if(go_until(node_p,property_id)->h_count==0)
                    {
                    	current_player->account+=go_until(node_p,property_id)->price/2;
                    
                    }
                    if(go_until(node_p,property_id)->h_count==1)
                    {
                        current_player->account+=(go_until(node_p,property_id)->price+go_until(node_p,property_id)->house_price)/2;
                    }
                    if(go_until(node_p,property_id)->h_count==2)
                    {
                        current_player->account+=(go_until(node_p,property_id)->price+(2*go_until(node_p,property_id)->house_price))/2;
                    }
                    if(go_until(node_p,property_id)->h_count==3)
                    {
                        current_player->account+=(go_until(node_p,property_id)->price+(3*go_until(node_p,property_id)->house_price))/2;
                    }
                }
            }
        } else
        {
            printf("You don't have any property to sell.\n");
        }

}
int go_until_blocks(player* current_player,int input){			/*Function for finding if there is a number named "input" in owned_block_ids array*/

	int i=0;
	while(current_player->owned_blocks[i]!= input){
		i++;	
	}
	return i;
}

block*	select_highest(block * node_p,player* current_player){
	
	int i=0,j=0,temp;
	block *max_price_block;
	
	max_price_block = go_until(node_p,current_player->owned_blocks[0]);
	for(i=0;i<count_properties(*current_player);i++){
		if(go_until(node_p,current_player->owned_blocks[i])->price>max_price_block->price){
			max_price_block = go_until(node_p,current_player->owned_blocks[i]);
		}
	
	}
	return max_price_block;
}

int insufficient_fund_computer(block *node_p, player* current_player,int required_money)
{
    int selection,flag=1;
    while (current_player->account<required_money && count_properties(*current_player)!=0)
    {
        printf("Computer doesn't have enough money to continue your transaction.It needs %d$ more. \n",required_money-current_player->account);
       	current_player->account = current_player->account + (select_highest(node_p,current_player)->price +select_highest(node_p,current_player)->house_price*select_highest(node_p,current_player)->h_count)/2;
	select_highest(node_p,current_player)->owner.type = noone; 
	select_highest(node_p,current_player)->h_count = 0;
	current_player->owned_blocks[go_until_blocks(current_player,select_highest(node_p,current_player)->id)] = -1;
    }
    return flag;

}

int insufficient_fund_player(block *node_p, player* current_player,int required_money)
{
    int selection,flag=1;
    while (selection!=4 && current_player->account<required_money && count_properties(*current_player)!=0)
    {
        printf("You don't have enough money to continue your transaction.You need %d$ more. Please select an option to continue: \n",required_money-current_player->account);
        printf("1- Sell Property\n");
        printf("2- Show my Properties\n");
        printf("3- Show my Account\n");
        printf("0- Back\n");
        scanf("%d",&selection);
        switch (selection)
        {
            case 1:
                sell_property(node_p,current_player);
                break;
            case 2:
                show_player_properties(node_p,*current_player);
                break;
            case 3:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 0:
                flag=0;
                break;
            default:
                printf("You made a wrong selection!\n");
                break;

        }
    }
    return flag;

}

void pay_rent(block *node_p, player* current_player,player * owner)
{
    int rent=0,owned_property_count;
    rent=go_until(node_p,current_player->current_block_id)->rent;
    if (go_until(node_p,current_player->current_block_id)->h_count==1)rent=go_until(node_p,current_player->current_block_id)->rent_1;
    if (go_until(node_p,current_player->current_block_id)->h_count==2)rent=go_until(node_p,current_player->current_block_id)->rent_2;
    if (go_until(node_p,current_player->current_block_id)->h_count==3)rent=go_until(node_p,current_player->current_block_id)->rent_3;
    if (rent>current_player->account)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            insufficient_fund_player(node_p,current_player,rent);
            owned_property_count=count_properties(*current_player);
        }
    }
    if (rent<current_player->account)
    {
        current_player->account-=rent;
        owner->account+=rent;
    } else
        current_player->account=0;
}

void add_to_owned(player* current_player)
{
    for (int i = 0; i < PROPERTY_COUNT; ++i) {
        if (current_player->owned_blocks[i]==-1) {
            current_player->owned_blocks[i] = current_player->current_block_id;
            printf("Current block id %d\n",current_player->current_block_id);
            break;
        } else
            printf("%d ",current_player->owned_blocks[i]);
    }
    printf("\n");
}

void copy_owner(player* old, player* new)
{
    old->type=new->type;
    old->account=new->account;
    old->turn_to_wait=new->turn_to_wait;
    old->player_name=new->player_name;
    old->current_block_id=new->current_block_id;
    for (int i = 0; i < PROPERTY_COUNT; ++i) {
        old->owned_blocks[i]=new->owned_blocks[i];
    }
}

void buy_property(block* current_block, player* current_player)
{
    if (current_block->price<=current_player->account)
    {
        current_player->account-=current_block->price;
        copy_owner(&current_block->owner,current_player);
        add_to_owned(current_player);
	
        printf("Congratiulations! You have buy %s.\n",current_block->name);
        printf("You left %d$ in your account.\n",current_player->account);

    }
    else
        printf("You don't have enough money to buy this property!\n");
}

void house_dialog_player(block *node_p, player* current_player)
{
    int house_flag=1,selection,insuf_flag=1,build_flag=1;
    while (house_flag && build_flag) {
        printf("Do you want to build house on %s ?\n",
              go_until(node_p,current_player->current_block_id)->name);
        printf("1- Yes\n");
        printf("2- No\n");
        scanf("%d", &selection);
        if (selection == 1) {

            if (current_player->account < go_until(node_p,current_player->current_block_id)->house_price) {
                while (count_properties(*current_player)!=0 && current_player->account<go_until(node_p,current_player->current_block_id)->house_price && insuf_flag==1)
                    insuf_flag=insufficient_fund_player(node_p,current_player,go_until(node_p,current_player->current_block_id)->house_price);
            }
            if (current_player->account >= go_until(node_p,current_player->current_block_id)->house_price)
                build_flag=build_house(go_until(node_p,current_player->current_block_id), current_player);
                if(go_until(node_p,current_player->current_block_id)->h_count > 1){
                	printf("You have built %d houses.\n",go_until(node_p,current_player->current_block_id)->h_count);
                	if(go_until(node_p,current_player->current_block_id)->h_count == 3){
                		return;
                	}
		}else if(go_until(node_p,current_player->current_block_id)->h_count==1){
			printf("You have built 1 house.\n");
		}
            else
                house_flag=0;


        } else
            house_flag=0;
    }
}
int property_average(block *node_p,player * current_player){
	int sum=0;

	while(node_p != NULL){
		if(node_p->type == property){
			sum = sum + node_p->price;
			
		}
		node_p = node_p->next;
	}
	sum = sum / 12;
	return sum;	
}

void fortune_card_func(block * node_p,player* current_player,player * other){

	int rolled_dice = (rand()%5)+1;
	printf("Fortune Card:");
	if(rolled_dice == 1){
		printf("Free House\n");
		if(count_properties(*current_player)>1){
			build_house(select_highest(node_p,current_player),current_player);
			current_player->account+=select_highest(node_p,current_player)->house_price;/*build_house fonksiyonundaki para azaltmayı sıfırlamak için*/
		}else{
			printf("You haven't got any property.");
		}
	}else if(rolled_dice == 2){
		printf("Time Travel\n");
		rolled_dice = roll_dice();
		printf("%d",rolled_dice);
		if(rolled_dice >=1 && rolled_dice<=3){
			current_player->current_block_id += 2;
		}else{
			current_player->current_block_id -= 2; /*start'tan geçince 10000 dolar verme işini yapmamıza gerek yok çünkü herjangi bir fortune card'a gelince start'tan geçemiyoruz.*/	
		}
	}else if(rolled_dice == 3){
		printf("Garnishment\n");
		current_player->account -= 5000;
	}else if(rolled_dice == 4){
		printf("Generosity\n");
		other->account += 10000;
		current_player->account -= 10000;
	}else if(rolled_dice == 5){
		printf("Treasure Hunter\n");
		current_player->account += 20000;
	}
	

}

void after_dice_menu_computer(block *node_p, player* current_player, player* other){
    int selection,insuf_flag=1,rolled_dice=0;
   
    switch (go_until(node_p,current_player->current_block_id)->type)
    {
        case property:
            printf("%s has arrived %s \n",current_player->player_name,go_until(node_p,current_player->current_block_id)->name);
            if (go_until(node_p,current_player->current_block_id)->owner.type==noone)/*Unowned property*/
            {
		if (current_player->account<go_until(node_p,current_player->current_block_id)->price){
                        while (count_properties(*current_player)!=0 && current_player->account<go_until(node_p,current_player->current_block_id)->price && insuf_flag==1 ){
                            insuf_flag=insufficient_fund_computer(node_p,current_player,go_until(node_p,current_player->current_block_id)->price);
                        }
                }else if(go_until(node_p,current_player->current_block_id)->price < property_average(node_p,current_player)){
		    		
		    		buy_property( go_until(node_p,current_player->current_block_id),current_player);
		}else{
    		    rolled_dice = roll_dice();;
    		    if(rolled_dice>=1 && rolled_dice<=3){
    			buy_property( go_until(node_p,current_player->current_block_id),current_player);
    		    }
	    	}	
	    }else if(go_until(node_p,current_player->current_block_id)->owner.type==cap){
	    	if(count_properties(*current_player)>=ONE_THIRD_OF_ALL_PROPERTIES){
	    		rolled_dice =roll_dice();
	    		if(rolled_dice>=1 && rolled_dice<=3){
	    			build_house(go_until(node_p,current_player->current_block_id),current_player);
	    		}else{
	    			return;
	    		}
	    	}else{
	    		printf("Computer didn't get the one third of all properties.\n");
	    	}	
            }else
            {
                pay_rent(node_p,current_player,other);
            }
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",current_player->player_name,go_until(node_p,current_player->current_block_id)->name);
            while (count_properties(*current_player)!=0 && current_player->account<go_until(node_p,current_player->current_block_id)->price) {
                insuf_flag = insufficient_fund_player(node_p, current_player,
                                              go_until(node_p,current_player->current_block_id)->price);
                if (insuf_flag == 0 && current_player->account < go_until(node_p,current_player->current_block_id)->price)
                    printf("You must pay your tax!\n");
            }
            if (current_player->account>go_until(node_p,current_player->current_block_id)->price)
                current_player->account=current_player->account-go_until(node_p,current_player->current_block_id)->price;
            else
            {
                current_player->account=0;
            }
            break;
        case punish:
            printf("%s has punished for %d turn. \n",current_player->player_name,go_until(node_p,current_player->current_block_id)->price);
            current_player->turn_to_wait+=go_until(node_p,current_player->current_block_id)->price;
            break;
        case fortune:
            fortune_card_func(node_p,current_player,other);
            break;
    }
}
void after_dice_menu_player(block *node_p, player* current_player, player* other){
    int selection,insuf_flag=1;
    
    switch (go_until(node_p,current_player->current_block_id)->type)
    {
        case property:
            printf("%s has arrived %s \n",current_player->player_name,go_until(node_p,current_player->current_block_id)->name);
            if (go_until(node_p,current_player->current_block_id)->owner.type==noone)
            {
                printf("Do you want to buy %s ?\n",go_until(node_p,current_player->current_block_id)->name);
                printf("1- Yes\n");
                printf("2- No\n");
                scanf("%d",&selection);
                if (selection==1)
                {

                    if (current_player->account<go_until(node_p,current_player->current_block_id)->price)
                    {
                        while (count_properties(*current_player)!=0 && current_player->account<go_until(node_p,current_player->current_block_id)->price && insuf_flag==1 )
                        {
                            insuf_flag=insufficient_fund_player(node_p,current_player,go_until(node_p,current_player->current_block_id)->price);
                        }
                    }
                    buy_property(go_until(node_p,current_player->current_block_id),current_player);
                    if (current_player->type==go_until(node_p,current_player->current_block_id)->owner.type)
                    {
                        house_dialog_player(node_p,current_player);
                    }

                }

            } else
            {
                pay_rent(node_p,current_player,other);
            }
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",current_player->player_name,go_until(node_p,current_player->current_block_id)->name);
            while (count_properties(*current_player)!=0 && current_player->account<go_until(node_p,current_player->current_block_id)->price) {
                insuf_flag = insufficient_fund_player(node_p, current_player,
                                              go_until(node_p,current_player->current_block_id)->price);
                if (insuf_flag == 0 && current_player->account < go_until(node_p,current_player->current_block_id)->price)
                    printf("You must pay your tax!\n");
            }
            if (current_player->account>go_until(node_p,current_player->current_block_id)->price)
                current_player->account=current_player->account-go_until(node_p,current_player->current_block_id)->price;
            else
            {
                current_player->account=0;
            }
            break;
        case punish:
            printf("%s has punished for %d turn. \n",current_player->player_name,go_until(node_p,current_player->current_block_id)->price);
            current_player->turn_to_wait+=go_until(node_p,current_player->current_block_id)->price;
            break;
        case fortune:
            fortune_card_func(node_p,current_player,other);
            break;
    }
}

void turn_computer(block *node_p, player* current_player, player * other){
    int flag=1,next_block,rolled_dice=0;
    while(flag)
    {
        if (current_player->turn_to_wait==0) {
            rolled_dice = roll_dice();
            next_block=(current_player->current_block_id + rolled_dice);
            if (next_block>=20)current_player->account+=10000;
            current_player->current_block_id = next_block % 20;
            show_board(node_p,*current_player,*other);
            printf("Computer rolled dice:%d\n",rolled_dice);
            after_dice_menu_computer(node_p,current_player,other);
            flag = 0;
        } else
        {
            printf("You need to wait %d turn to continue.\n",current_player->turn_to_wait);
            current_player->turn_to_wait-=1;
            flag=0;
        }
    }
}

void turn_player(block *node_p, player* current_player, player * other){
    int flag=1,next_block;
    while(flag)
    {
        int selection;
        printf("1 - Roll the dice\n");
        printf("2 - Show my account\n");
        printf("3 - Show my properties\n");
        printf("4 - Show property deeds\n");
        printf("5 - Buy Property\n");
        printf("6 - Buy house \n");
        printf("7 - Sell property\n");
        printf("Please select an option to continue (%s):\n",current_player->player_name);
        scanf("%d",&selection);
        switch(selection)
        {
            case 1:
                if (current_player->turn_to_wait==0) {
                    next_block=(current_player->current_block_id + roll_dice());
                    if (next_block>=20)current_player->account+=10000;
                    current_player->current_block_id = next_block % 20;
                    show_board(node_p,*current_player,*other);
                    after_dice_menu_player(node_p,current_player,other);
                    flag = 0;
                } else
                {
                    printf("You need to wait %d turn to continue.\n",current_player->turn_to_wait);
                    current_player->turn_to_wait-=1;
                    flag=0;
                }
                break;
            case 2:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 3:
                show_player_properties(node_p,*current_player);
                break;
            case 4:
                show_property_deed(node_p);
                break;
            case 5:
                if (go_until(node_p,current_player->current_block_id)->type==property && go_until(node_p,current_player->current_block_id)->owner.type==-1)
                buy_property(go_until(node_p,current_player->current_block_id),current_player);
                else
                {

                    printf("You don't have permission to buy this block!\n");
                }

                break;
            case 6:
                if (current_player->type==go_until(node_p,current_player->current_block_id)->owner.type) {
                    house_dialog_player(node_p,current_player);
                }else
                {
                    printf("You don't have permission to build house on this block!\n");
                }
                break;
            case 7:
                sell_property(node_p,current_player);
                break;
            default:
                printf("Wrong selection!\n");
        }
    }
}

int check_end(player current_player)
{
    int owned_property_count=count_properties(current_player);
    if (current_player.account<=0 && owned_property_count==0)return 1;
    else return 0;
}

void play_game(block *node_p, player* computer, player* player_)
{
    int is_end=0;
    printf("Welcome to Monopoly! %s will roll the dice first.\n",computer->player_name);
    while(is_end!=1)
    {
        printf("%s :%d$ , %s:%d$\n",computer->player_name,computer->account,player_->player_name,player_->account);
        turn_computer(node_p,computer,player_);
        //show_board(node_p,*computer,*player_);
        is_end=check_end(*computer);
        if (is_end==0)
        {
            printf("%s :%d$ , %s:%d$\n",computer->player_name,computer->account,player_->player_name,player_->account);
            turn_player(node_p,player_,computer);
            //show_board(node_p,*computer,*player_);
            is_end=check_end(*player_);
            if (is_end==1)
                printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_->player_name,player_->player_name);
        } else
            printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",computer->player_name,computer->player_name);

    }

}
	
void init_owned(player* current_player)
{
    int i;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        current_player->owned_blocks[i]=-1;
    }

}

int main() {

	block * head;
	head = (block*)malloc(sizeof(block));
	fill_struct_in(head);
	srand(time(NULL));
	player player_;
	player computer;

	computer.player_name="Cap";
	computer.type=cap;
	computer.current_block_id=0;
	computer.turn_to_wait=0;
	computer.account=100000;
	init_owned(&computer);

	player_.player_name="Car";
	player_.type=car;
	player_.current_block_id=0;
	player_.turn_to_wait=0;
	player_.account=100000;
	init_owned(&player_);
	
	//show_property_deed(head);
	show_board(head,computer,player_);
	play_game(head,&computer,&player_);

	return 0;
}
