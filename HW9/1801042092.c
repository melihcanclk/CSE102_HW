#include <stdio.h> 
#include <stdlib.h> 
  
struct person{

	char name[300];
	char surname[300];
	char musical_work[300];
	int age;
	struct person *next;
	
}*top = NULL;
 
int is_empty(struct person *s){ 		/*Utility function to chcek if stack is empty*/
	if (s == NULL){ 
		return 1;
	} 
	return 0; 
} 

void strn_cpy(char first[],char second[]){	/*Function for copying first string to second*/

	int i;
	for(i=0;second[i] != '\0';i++){
	
		first[i]=second[i];
	}
	first[i] = '\0';

}

void addNode(char name[],char surname[],char creation[],int age){
	
	struct person* temporary;
	temporary = (struct person*)malloc(sizeof(struct person));
	strn_cpy(temporary->name,name);
	strn_cpy(temporary->surname,surname);
	strn_cpy(temporary->musical_work,creation);
	temporary->age = age;
	if(top == NULL){
		temporary->next = NULL;
	}else{
		temporary->next = top;
	}
	top = temporary;
}

struct person* deleteNode(){

	if(top == NULL){
		printf("\nNo Music Added!!!\n");
	}else{
		struct person *temporary = top;
		top=temporary->next;	
		return temporary;
	}
	
	
}

void push(struct person **s, struct person* x){					//Helper push function
 
	struct person *p = (struct person *)malloc(sizeof(*p)); 

	if (p == NULL) 
	{ 
		fprintf(stderr, "Memory allocation failed.\n"); 
		return; 
	} 
	strn_cpy(p->name,x->name);
	strn_cpy(p->surname,x->surname);
	strn_cpy(p->musical_work,x->musical_work);
	p->age = x->age; 
	p->next = *s; 
	*s = p; 
} 
  
struct person* find_top(struct person *s){ 					//Function to find top item  
	return (s); 
} 
  

void sortedInsert(struct person **s, struct person* x,int mode){ 				/*Inserting data by sorting recursively*/
												/*If mode equals 1, it sort by age. If mode equals 2, it sort by name*/ 
	int i=0;
	if(mode == 1){       
		
		if (is_empty(*s) || x->age < find_top(*s)->age){  				// Base case: Either stack is empty or newly inserted 
												// item is greater than top (more than all existing) 
			push(s, x); 
			return; 
		}
		struct person* temp = deleteNode(); 						// If top is greater, remove the top item and recur 
		sortedInsert(s, x,1); 
		  
		push(s, temp);									// Put back the top item removed earlier 
	}else if(mode == 2){       
		while (is_empty(*s) || x->name[i] < find_top(*s)->name[i]){ 			// Base case: Either stack is empty or newly inserted if item is greater than top (more than all existing) 
		
			push(s, x);
			return; 
		}
		i++; 
		
		struct person* temp = deleteNode(); 						// If top is greater, remove the top item and recur 
		sortedInsert(s, x,2); 
		  
		push(s, temp); 									// Put back the top item removed earlier 
	}
} 
  

void Sort_Increasingly(struct person **s){ 		// Function to sort stack 
	
	if(!is_empty(*s)){ 				// If stack is not empty  
		struct person *x = deleteNode(); 	// Remove the top item 
		Sort_Increasingly(s); 			// Sort remaining stack 
		sortedInsert(s, x,1);  			// Push the top item back in sorted stack 
	} 
} 

void Sort_Alphabetically(struct person **s){ 
    
	if (!is_empty(*s)){ 					// If stack is not empty  
		struct person *x = deleteNode(); 		// Remove the top item
		Sort_Alphabetically(s); 			// Sort remaining stack 
		sortedInsert(s, x,2);				// Push the top item back in sorted stack  
	} 	
} 
  
void print_stack(struct person * top){				// Utility function to print contents of stack 
	int i=1;

	if(top == NULL){
		printf("\nNo Music Added!!!\n");
	}else{
		struct person *temporary = top ;
		while(temporary != NULL){
			printf("%d)",i);
			printf("%s\n",temporary->name);
			printf("  %s\n",temporary->surname);
			printf("  %s\n",temporary->musical_work);
			printf("  %d\n\n",temporary->age);
			temporary=temporary->next;
			i++;
		}
	}
}
void menu(){

	int input,age;
	char name[300],surname[300],creation[300];
	do{
		printf("*****Menu*****\n");
		printf("1- Add a Person to the Stack\n");
		printf("2- Pop a Person from the Stack\n");
		printf("3- Sort Alphabetical Order\n");
		printf("4- Sort Age in Increasing Order\n");
		printf("5- Exit menu\n");
		printf("**************\n");
		printf("Select your choice:");		
		scanf("%d",&input);
		getchar();
		if(input == 1){
			printf("Name:");
			scanf("%[^\n]",name);
			printf("Surname:");
			scanf("\n%[^\n]",surname);
			printf("Creation:");
			scanf("\n%[^\n]",creation);
			printf("Age:");
			scanf("%d",&age);
			printf("------------------\n");
			addNode(name,surname,creation,age);
			print_stack(top);
		}else if(input == 2){
			deleteNode();
			print_stack(top);
		}else if(input == 3){
			Sort_Alphabetically(&top);
			print_stack(top);
		}else if(input == 4){
			Sort_Increasingly(&top);
			print_stack(top);
		}
	}while(input != 5);
}
int main() 
{ 
    menu();
  
    return 0; 
} 

