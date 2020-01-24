#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct bst{

	int data;
	struct bst * right;
	struct bst * left;
	
}bst;

typedef struct queue{

	int data;
	struct queue * next;
	
}queue;

typedef struct stack{

	int data;
	struct stack * next;
	
}stack;

void push_stack(stack ** stack_p , int data){				/*push function for stacks*/		

	stack *temp = (stack*)malloc(sizeof(stack));
	temp->data = data;
	temp->next = NULL;
	if(*stack_p){
		temp->next = (*stack_p);
	}
	(*stack_p) = temp;
}
stack * pop_stack(stack ** stack_){				/*pop function for stacks*/

	stack * tmp = (stack *)malloc(sizeof(stack));
	tmp->data = (*stack_)->data;
	(*stack_)= (*stack_)->next;
	return tmp;
}

void push_queue(queue ** queue_,int data){
	queue * temp = (queue*)malloc(sizeof(queue));
	temp->data = data;
	temp->next = NULL;
	if(*queue_){
		(*queue_)->next = temp; 
		(*queue_) = (*queue_)->next;
	}else{
		(*queue_) = temp;
	}
}

void push_bst(bst ** bst_, int data){

	if((*bst_) == NULL){
		bst * temp = (bst*)malloc(sizeof(bst));
		temp->data = data;
		(*bst_) = temp;
		(*bst_)->right = NULL;
		(*bst_)->left = NULL;
		(*bst_) = temp;
	}else{
		if(data < (*bst_)->data){
			push_bst(&((*bst_)->left),data);
		}else if(data>=(*bst_)->data){				/*Eşitse sağa koydum*/
			push_bst(&((*bst_)->right),data);
		}
	}
}
void print_decending_order_stack(stack ** stack_){
	
	clock_t begin = clock();

	stack * copy_stack;			
	stack * temp_stack;	
	stack * temp = (*stack_);
	stack * temp2;
	int max,counter,value,i=0,j;
	while(i<20){					/*YEDEK BİR STACK OLUŞTURDUM. ÇÜNKÜ BU FONKSİYON İÇERİSİNDE NORMAL STACK POİNTERİNİ DEĞİŞTİRİRSEM SEGMENTATİON FAULT VERİYORDU*/	
		push_stack(&copy_stack, temp->data);
		temp = temp->next;	
		i++;
	}	
	temp = copy_stack;
	while(i>0){
		j=i;
		counter = 0;
		max = temp->data;
		while(j>0){
			if(temp->data > max){
				max = temp->data;
			}
			temp = temp->next;
			j--;
		}
		printf("%d ",max);
		temp = copy_stack;
		value = pop_stack(&copy_stack)->data;
		while(value != max){
			push_stack(&temp_stack,value);
			value = pop_stack(&copy_stack)->data;
			counter++;
		}
		while(counter > 0){
			value = pop_stack(&temp_stack)->data;
			push_stack(&copy_stack,value);
			counter--;			
		}
		temp = copy_stack;
		i--;
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("Execution time: %f",time_spent);
	
}

void print_decending_order_queue(queue ** queue_){
	
	clock_t begin = clock();
	*queue_ = (*queue_)->next;					/*BUNU YAPMAMIN SEBEBİ QUEUE KURARKEN BİR TANE TEMP NODE OLUŞTURMAM. ÖNDE BİR TANE GEREKSİ 
									  SAYI BULUNUYODU. BU YÜZDEN GERÇEK QUEUE'YA ULAŞMAK İÇİN BİR TANE ATLAMAK ZORUNDA KALDIM*/
	queue * temp1;							/*YEDEK QUEUE OLUŞTURMAK VE BU QUEUE'DAKİ MAKSİMUM SAYIYI BULMAK İÇİN KULLANDIĞIM POİNTER*/
	temp1 = *queue_;
	queue * temp2;							/*QUEUE'NUN BAŞINI UNUTMAMAK İÇİN POİNTER*/
	temp2 = *queue_;
	
	queue * copy_queue;	
	int max,value,i=0,j;
	while(i<20){
		push_queue(&copy_queue,temp1->data);
		temp1 = temp1->next;
		i++;
	}
	copy_queue = temp2;
	while(i>0){
		j=i;
		temp1 = copy_queue;
		max = temp1->data;							/*EN ÜSTTEKİ SAYIYI MAX'A EŞİTLİYORUZ*/
		while(j>0){
			if(temp1->data > max){
				max = temp1->data;
			}
			temp1 = temp1->next;
			j--;
		}
		printf("%d ",max);
		temp1 = copy_queue;
		value = temp1->data;
		temp2 = temp1;
		if(value == max){							/*EĞER MAKSİMUM SAYI EN BAŞTA İSE*/
			copy_queue = copy_queue->next;
		}
		while(value != max){
			temp2 = temp1;
			temp1 = temp1->next;
			value = temp1->data;
		}
		temp2->next = temp1->next;
		i--;
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("Execution time: %f",time_spent);

}

void print_decending_order_tree(bst * bst_){ 

	
	if (bst_ == NULL){ 
		return; 
	}
	print_decending_order_tree(bst_->right); 

	printf("%d ", bst_->data);   

	print_decending_order_tree(bst_->left); 
	
}

void search_stack(stack ** stack_,int val_to_search){
	
	
	stack * copy_stack;			
	stack * copy_stack2;	
	stack * temp = (*stack_);
	stack * temp2;
	int counter = 0,i=0,arr[20] = {0},x=0;
	while(i<20){					/*YEDEK BİR STACK OLUŞTURDUM. ÇÜNKÜ BU FONKSİYON İÇERİSİNDE NORMAL STACK POİNTERİNİ DEĞİŞTİRİRSEM SEGMENTATİON FAULT VERİYORDU*/	
		push_stack(&copy_stack, temp->data);
		temp = temp->next;
		i++;
	}
	i=0;
	while(i<20){
		if(copy_stack->data == val_to_search){
			counter++;
			arr[x] = i+1;
			x++;
		}
		free(pop_stack(&copy_stack));
		i++;
	}
	if(counter == 0){
		printf("This number is not in this queue.\n");
	}else{
		x=0;
		printf("%d result at ",counter);
		while(arr[x] != 0){
			printf("%d ",arr[x]);
			x++;
		}
	}
	
}

void search_queue(queue ** queue_,int val_to_search){

	*queue_ = (*queue_)->next;					/*BUNU YAPMAMIN SEBEBİ QUEUE KURARKEN BİR TANE TEMP NODE OLUŞTURMAM. ÖNDE BİR TANE GEREKSİ 
									  SAYI BULUNUYODU. BU YÜZDEN GERÇEK QUEUE'YA ULAŞMAK İÇİN BİR TANE ATLAMAK ZORUNDA KALDIM*/
	int i=19,j,counter=0,position=0,arr[20] = {0},x=0;
	queue * temp;
	queue * temp2;
	queue * reverse_queue = (queue*)malloc(sizeof(queue));
	temp2 = reverse_queue;
	temp = (*queue_);
	for(i=19;i>=0;i--){
		j=0;
		temp = (*queue_);								/*QUEUE REVERSE*/
		while(j<i){
			temp = temp->next;
			j++;
		}
		push_queue(&reverse_queue,temp->data);
	}
	temp2 = temp2->next;
	reverse_queue = temp2;						/*REVERSE QUEUE İTERATE OLDUĞU İÇİN ONU BAŞLANGIÇINA GERİ GETİRDİM*/
	while(i<19){							/*i = position +1*/
		if(reverse_queue->data == val_to_search){
			counter++;
			arr[x] = i+2;
			x++;
		}
		reverse_queue = reverse_queue->next;
		i++;
	}
	if(counter == 0){
		printf("This number is not in this queue.\n");
	}else{
		x=0;
		printf("%d result at ",counter);
		while(arr[x] != 0){
			printf("%d ",arr[x]);
			x++;
		}
	}
}

int search_bst(bst ** bst_, int key){ 
	bst * temp = (*bst_);
	int counter=0,arr[20] = {0},i=0,x=0;
	while(1){
		if(key >= temp->data ){
			if(key == temp->data){
				counter++;
				arr[x] = i+1;
				x++;
			}
			if(temp->right != NULL){
				temp = temp->right;
			}else{
				break;
			}
		}else if(key < temp->data ){
			if(temp->left != NULL){
				temp = temp->left;
			}else{
				break;
			}
		}
		i++;
	}
	if(counter == 0){
		printf("This number is not in this queue.\n");
	}else{
		x=0;
		printf("%d result at ",counter);
		while(arr[x] != 0){
			printf("%d ",arr[x]);
			x++;
		}
	}
} 

void special_traverse_stack(stack ** stack_){
	
	stack * copy_stack;			
	stack * temp_stack;	
	stack * temp = (*stack_);
	stack * temp2;
	int max,min,counter,value,i=0,j;
	while(i<20){					/*YEDEK BİR STACK OLUŞTURDUM. ÇÜNKÜ BU FONKSİYON İÇERİSİNDE NORMAL STACK POİNTERİNİ DEĞİŞTİRİRSEM SEGMENTATİON FAULT VERİYORDU*/	
		push_stack(&copy_stack, temp->data);
		temp = temp->next;	
		i++;
	}	
	temp = copy_stack;	
	while(i>0){
		j=i;
		counter = 0;
		max = temp->data;
		while(j>0){
			if(temp->data > max){
				max = temp->data;
			}
			temp = temp->next;
			j--;
		}
		printf("%d ",max);
		temp = copy_stack;
		value = pop_stack(&copy_stack)->data;
		while(value != max){
			push_stack(&temp_stack,value);
			value = pop_stack(&copy_stack)->data;
			counter++;
		}
		while(counter > 0){
			value = pop_stack(&temp_stack)->data;
			push_stack(&copy_stack,value);
			counter--;			
		}
		temp = copy_stack;
		i--;
		if(i==0){break;}
		j=i;
		counter = 0;
		min = temp->data;
		while(j>0){
			if(temp->data < min){
				min = temp->data;
			}
			temp = temp->next;
			j--;
		}
		printf("%d ",min);
		temp = copy_stack;
		value = pop_stack(&copy_stack)->data;
		while(value != min){
			push_stack(&temp_stack,value);
			value = pop_stack(&copy_stack)->data;
			counter++;
		}
		while(counter > 0){
			value = pop_stack(&temp_stack)->data;
			push_stack(&copy_stack,value);
			counter--;			
		}
		temp = copy_stack;
		i--;
	}
	
}

void special_traverse_queue(queue ** queue_){
	
	*queue_ = (*queue_)->next;					/*BUNU YAPMAMIN SEBEBİ QUEUE KURARKEN BİR TANE TEMP NODE OLUŞTURMAM. ÖNDE BİR TANE GEREKSİ 
									  SAYI BULUNUYODU. BU YÜZDEN GERÇEK QUEUE'YA ULAŞMAK İÇİN BİR TANE ATLAMAK ZORUNDA KALDIM*/
	queue * temp1;							/*YEDEK QUEUE OLUŞTURMAK VE BU QUEUE'DAKİ MAKSİMUM SAYIYI BULMAK İÇİN KULLANDIĞIM POİNTER*/
	temp1 = *queue_;
	queue * temp2;							/*QUEUE'NUN BAŞINI UNUTMAMAK İÇİN POİNTER*/
	temp2 = *queue_;
	
	queue * copy_queue;	
	int max,value,i=0,j;
	while(i<20){
		push_queue(&copy_queue,temp1->data);
		temp1 = temp1->next;
		i++;
	}
	copy_queue = temp2;
	while(i>0){
		j=i;
		temp1 = copy_queue;
		max = temp1->data;							/*EN ÜSTTEKİ SAYIYI MAX'A EŞİTLİYORUZ*/
		while(j>0){
			if(temp1->data > max){
				max = temp1->data;
			}
			temp1 = temp1->next;
			j--;
		}
		printf("%d ",max);
		temp1 = copy_queue;
		value = temp1->data;
		temp2 = temp1;
		if(value == max){							/*EĞER MAKSİMUM SAYI EN BAŞTA İSE*/	
			copy_queue = copy_queue->next;
		}
		while(value != max){
			temp2 = temp1;
			temp1 = temp1->next;
			value = temp1->data;
		}
		temp2->next = temp1->next;
		i--;
	}
	

}

void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[20]){

	int i;
	*bst_ = NULL;
	queue * temp = (queue*)malloc(sizeof(queue));
	*queue_ = temp;
	
	for(i=19;i>=0;i--){
		push_stack(&(*stack_), data[i]);
	}
	for(i=0;i<20;i++){
		push_queue(&temp, data[i]);
	}
	for(i=0;i<20;i++){
		push_bst(&(*bst_), data[i]);
	}
}

void ordered_print(stack * stack_, queue * queue_, bst * bst_){
	stack * temp_stack = stack_;
	queue * temp_queue = queue_;
	bst * temp_bst = bst_;
	
	print_decending_order_stack(&temp_stack);
	printf("\n");
	print_decending_order_queue(&temp_queue);
	printf("\n");
	clock_t begin = clock();
	print_decending_order_tree(temp_bst);
	clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("Execution time: %f",time_spent);
	printf("\n");
	free(temp_stack);
	free(temp_queue);
	free(temp_bst);
}

int main()
{
	int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17,8, 23, 4};
	bst * bst_;									/*pointer for binary tree*/
	queue * queue_;									/*pointer for queue*/
	stack * stack_;									/*pointer for stack*/
	fill_structures(&stack_, &queue_, &bst_, data);
	ordered_print(stack_, queue_, bst_);
	//search(stack_, queue_, bst_, 5);
	//special_traverse(stack_, queue_, bst_);
	return 0;
}
