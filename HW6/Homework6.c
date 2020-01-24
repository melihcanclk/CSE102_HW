#include <stdio.h>

void sorting_arr(int inp_arr[], int left, int mid, int right){ 
	int i, j, k; 
	int size_of_arr1; 
	int size_of_arr2;
	
	size_of_arr1=(mid-left)+1; 
	size_of_arr2=right-mid;

	int temp_arr1[size_of_arr1], temp_arr2[size_of_arr2]; /*Temporary Arrays*/
	
	for (i=0;i<size_of_arr1;i++) 
		temp_arr1[i] = inp_arr[left+i]; 
	for (j=0;j<size_of_arr2;j++) 
		temp_arr2[j] = inp_arr[mid+1+j]; 
		
	i = 0; 		/* 0th Index Of First Subarray*/ 
	j = 0; 		/* 0th Index Of Second Subarray */
	k = left; 	/* 0th Index of Input Array */
	
	while (i<size_of_arr1&&j<size_of_arr2){ 
		if (temp_arr1[i] <= temp_arr2[j]){ 
			inp_arr[k] = temp_arr1[i]; 
			i++; /*First Index That Points Elements Of First Array*/
		} 
		else{ 
			inp_arr[k] = temp_arr2[j]; 
			j++; /*First Index That Points Elements Of Second Array*/
		} 
		k++; 
	} 
	while (i < size_of_arr1){ /*If There Is Remaining Element In First Array,Fill Input Array With Remaining Elements First Array*/
		inp_arr[k] = temp_arr1[i]; 
		i++; 
		k++; 
	}
	while (j < size_of_arr2){ /*If There Is Remaining Element In Second Array,Fill Input Array With Remaining Elements Second Array*/
		inp_arr[k] = temp_arr2[j]; 
		j++; 
		k++; 
	} 
} 
void dividing_arr(int inp_arr[],int left,int right){	/*Dividing Array Into Two Recursively*/
	if (left<right){ 
		int mid=left+(right-left)/2; 
		
		dividing_arr(inp_arr,left,mid); 		/*Sending First Part Of Array*/
		dividing_arr(inp_arr,mid+1,right); 	/*Sending Second Part Of Array*/

		sorting_arr(inp_arr,left,mid,right); 
	} 
} 

void printing_arr(int inp_arr[], int size_of_arr){ 
	int i; 
	for (i=0;i<size_of_arr;i++){
		printf("%d ", inp_arr[i]); 
	}
} 


int common(int number1, int number2,int common_number){

	if(number1!=number2){
		if(number1%common_number==0 && number2%common_number==0){
			return common_number;
		}else{
			return common(number1,number2,common_number-1);
		}
	
	}else{
		return number1;
	}
}

int f(int n){			/*Function For Hailstone Sequence*/
	if(n!=1){
		if(n%2==0){
			printf("%d ",n/2);
			f(n/2);
		}else{
			printf("%d ",(3*n)+1);
			f((3*n)	+1);
		}
	}
}

int find_digit(int input){		/*Function For Finding How Many Digits Are There In A Integer*/
	int counter=0;

	while(input!=0){
		input = input/10;
		counter++;
	}
	return counter;
}

int exponent(int input,int number_of_digits){	/*Finding Exponent Of A Integer With Using Recursion*/

	if(number_of_digits!=1){
		return input* exponent(input,number_of_digits-1);
	}

}

int f2(int input,int index){				/*Function For Calculate 4th Question*/
	int number_of_digits,sum=0;

	number_of_digits = find_digit(input);
	
	if(number_of_digits!=0){
		int temp=input/10;
		temp = temp*10;
		temp = input-temp;
		
		sum= exponent(temp,number_of_digits+index) + f2(input/10,index+1); 
	}
	return sum;
}

char find_first_capital(char str[255]){		/*Function For Finding First Capital Latter Recursively*/
	if(str[0]!='\0'){
	
		if(str[0]>64 && str[0]<91){
			printf("%c Is The First Capital Latter.\n",str[0]);
		}else{
			find_first_capital(&str[1]);
		}
	}else{
		printf("There's no capital latter.\n");
	}
}

void menu(){		

	char choice='2';
	char str[255];
	int result,number1,number2,common_number=1;
	int inp_arr[255];
	int size_of_arr,i;
	int n;
	int input;

	while(choice >'0' && choice<'7'){
		printf("%s\n","		*****MENU*****\n" );
		printf("%s\n","		1.Calculate GCD\n" );
		printf("%s\n","		2.Sort List Of Elements\n" );
		printf("%s\n","		3.Calculate Hailstone Sequence\n" );
		printf("%s\n","		4.Calculate If Entered Number Equal To Function Of Not\n");
		printf("%s\n","		5.Find First Capital Later Of 1 Word\n");
		printf("%s\n","		6.Exit\n");
		printf("%s","		Choice:" );

		scanf("%c",&choice);
		
		if(choice == '1'){
		
			printf("First number: ");
			scanf("%d",&number1);
			printf("\nSecond number: ");
			scanf("%d",&number2);
			
			if(number1>number2){
				result = common(number1,number2,number2);
			}else if(number2>number1){
				result = common(number1,number2,number1);
			}else{
				result = number1;
			}
			printf("Greatest common divisor of %d and %d is %d\n",number1,number2,result);
			
		}else if(choice == '2'){
			
			printf("Enter the length of the list: ");
			scanf("%d",&size_of_arr);
			printf("Enter the elements of list:\n");
			
			for(i=0;i<size_of_arr;i++){
				scanf("%d",&inp_arr[i]);
			}
			dividing_arr(inp_arr, 0, size_of_arr - 1); /*Sending Function Last And First Index*/

			printf("\nSorted array is: "); 
			printing_arr(inp_arr, size_of_arr); 
			printf("\n");
		
		}else if(choice == '3'){
		
			printf("Input: ");
			scanf("%d",&n);
			printf("Output: %d ",n);
			f(n);
			printf("\n");
			
		}else if(choice == '4'){
			
			printf("Input=: ");
			scanf("%d",&input);

			result = f2(input,0);
			printf("Output: ");

			(result==input)?printf("Equal\n") : printf("Not Equal\n");
			
		}else if(choice == '5'){
			
			printf("Input: ");	
			scanf("%s",str);

			find_first_capital(&str[0]);
		
		}else if(choice == '6'){
			printf("%s","EXITING...\n" );
			break;
		
		}	
			getchar();
			choice = '2';
	}
}

int main(){
	menu();
}

