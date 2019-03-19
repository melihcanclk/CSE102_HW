#include <stdio.h>
#include <stdlib.h>
#include <math.h>

						
void menu();														/*										*/
void menu_for_part1();												/*										*/
int add(int number1,int number2);									/*										*/
int sub(int number1,int number2);									/*			Predefinition Of			*/
int divis(int number1,int number2);									/*				Functions				*/
int multip(int number1,int number2);								/*										*/
int power(int number1,int number2);									/*										*/
int mod(int number1,int number2);									/*										*/
int doit(int f(int ,int),int first_number,int second_number);		/*										*/
void calculation();													/*										*/


int main(){

menu();

}

int add(int number1,int number2){
	int result;
	result = number1 + number2;
	return result;
}

int sub(int number1,int number2){
	int result;
	result = number1 - number2;
	return result;
}

int divis(int number1,int number2){
	int result;
	result = number1 / number2;
	return result;
}

int multip(int number1,int number2){
	int result;
	result = number1 * number2;
	return result;
}

int power(int number1,int number2){
	int result;
	result = pow(number1,number2);
	return result;
}

int mod(int number1,int number2){
	int result;
	result = number1 % number2;
	return result;
}


int doit(int f(int ,int),int first_number,int second_number){
	
	f(first_number,second_number);

}

void menu_for_part1(){
	
	printf("\e[2J");			  /* Command For Clearing The Screen*/
	printf("Welcome To Simple Calculator.\n");
	printf("There Is 6 Function That Is Implemented In This Calculator.\n");
 	printf("Operation list:\n");
 	printf("%s","(+) - Addition \n");
 	printf("%s","(-) - Subtraction \n");
 	printf("%s","(*) - Multipication\n");
 	printf("%s","(/) - Partition\n");
 	printf("%s","(**) - Exponent\n");
 	printf("%s","(%) - Modulation\n\n");

}

void calculation(){

	int number1=0,number2=0,flag=1,counter = 0;
	int res=0,temp;
	char operation,decide = ' ',enter;
	getchar();										/*To Abuse The '\n' Character From Menu*/
	
	menu_for_part1();			/*Menu For Make User To Understand The Sembols And Mechanic Of Calculator.*/
	
	while(flag==1){
		
		printf("Please Enter The Operation.");
		printf("Enter 'e' or 'E' To Exit From Calculator.\n");
	
		scanf("%c",&operation);
		
		if(operation == 'e' || operation == 'E'){		/*To Exit From The Calculator,User Have To Enter 'E' or 'e'*/
			flag=0;
			break;
		}
		printf("General Pattern Is:\n Number1-Space-Number2\n");
 		printf("If You Want To Do Operation With The Result, Pattern Is(Default Result is 0)\n Number that you want to operate.\n");
 		
 		temp = res;
 		
		scanf("%c%d%c",&enter,&number1, &decide);
	
		printf("enter %c",enter);
		printf("temp %d",temp);
		printf("number1 %d",number1);
		printf("decide %c",decide);
		
		if(decide == ' '){
			scanf("%d",&number2);
		
			printf("number2 %d",number2);
			if(operation == '+'){
				res = doit(add,number1,number2);
				printf("Result = %d\n",res);
				
			}else if(operation == '-'){
				res = doit(sub,number1,number2);
				printf("Result = %d\n",res);
				
			}else if(operation == '/'){
			
				if(number2 == 0){
					printf("Result = Infinity\n");							/*If Denumerator Equals To 0,Result Will Be Infinity*/
					res = 0;
					printf("Result Set Back To Default Value.\n");
				}else{
					res = doit(divis,res,number1);							/*Otherwise Calculate The Result*/
				}	
				printf("Result = %d\n",res);
				
			}else if(operation == '*' && enter != '*'){
				res = doit(multip,number1,number2);
				printf("Result = %d\n",res);
				
			}else if(operation == '*' && enter == '*'){
				res = doit(power,number1,number2);
				if(res == -2147483648){										/*Which Is HUGE_VAL*/
					printf("Result = Infinity\n");							/*0^-1 Equals Infinity So I Wrote As */
					res = 0;												/*Result Value Resetted*/
					printf("Result Set Back To Default Value.\n");
				}else{
					printf("Result = %d\n",res);
				}
					
			}else if(operation == '%'){
				res = doit(mod,number1,number2);
				printf("Result = %d\n",res);
				
			}
			
		}else if(decide == '\n'){
			
			if(operation == '+'){
				res = doit(add,temp,number1);
				printf("Result = %d\n",res);
				
			}else if(operation == '-'){
				res = doit(sub,temp,number1);
				printf("Result = %d\n",res);
				
			}else if(operation == '/'){
				if(number2 == 0){
					printf("Result = Infinity\n");
					res = 0;
					printf("Result Set Back To Default Value.\n");
				}else{
					res = doit(divis,temp,number1);
				}
				printf("Result = %d\n",res);
			}else if(operation == '*' && enter != '*'){
				res = doit(multip,temp,number1);
				printf("Result = %d\n",res);
			
			}else if(operation == '*' && enter == '*'){
				res = doit(power,temp,number1);
				if(res == -2147483648){					/*Which Is HUGE_VAL*/
					printf("Result = Infinity\n");
					printf("Result Set Back To Default Value.\n");
					res = 0;
				}else{
					printf("Result = %d\n",res);
				}
				
			}else if(operation == '%'){
				res = doit(mod,temp,number1);
				printf("Result = %d\n",res);
				
			}
			
		}	
		
		if(decide != '\n'){			/*To Solve The Buffer Problem, I Add Here A Getchar. So '\n' Character Is Gone*/
			getchar();
		}
	}	

}


int take_grades(int grades[]){
	int i;
	for(i=0;i<10;i++){
		printf("Please Enter %d. Grade: ",i+1);
		scanf("%d",&grades[i]);
	
	}

}
int take_exam_grades(int grades[]){
			
		printf("Please Enter Midterm: ");
		scanf("%d",&grades[0]);
	
		printf("Please Enter Final: ");
		scanf("%d",&grades[1]);
}

double calculate_homework(int hw_grades[]){
	int i;
	double sum=0;
	for(i=0;i<10;i++){
		sum = sum + hw_grades[i];
	}
	return sum;

}	

double calculate_lab(int lab_grades[]){
	int i;
	double sum=0;
	for(i=0;i<10;i++){
		sum = sum + lab_grades[i];
	}
	return sum;


}
double calculate_all(double hw_grade_sum ,int exam_grades[],double lab_grade_sum){

	double average;
	average = ((hw_grade_sum/10)+(lab_grade_sum/10)*2 +(double)exam_grades[0]*3+(double)exam_grades[1]*4)/10;
	return average;
}


void operations(){
		
		int i;
		int hw_grades[10];
		int lab_grades[10];
		int exam_grades[2];
		double hw_grade_sum, all_sum,lab_grade_sum;
		
		printf("-HOMEWORK GRADES-\n");
		take_grades(hw_grades);											/*Function That Takes Homework Grades From User*/
		printf("-LABORATORY GRADES-\n");
		take_grades(lab_grades);										/*Function That Takes Lab Grades From User*/
		printf("-EXAM GRADES-\n");
		take_exam_grades(exam_grades);									/*Function That Takes Exam Grades From User*/
		hw_grade_sum = calculate_homework(hw_grades);
		lab_grade_sum = calculate_lab(lab_grades);
		all_sum = calculate_all(hw_grade_sum ,exam_grades,lab_grade_sum);
		printf("%.2f\n",all_sum);
		
}


void solid_diamond(){
	int height,i,j;
	printf("Enter Height Of Diamond: ");
	scanf("%d",&height);
	
	
	for(i=1;i<height+1;i++){
		for(j=0;j<height - i;j++){
			printf(" ");
		}
		printf("/");
		for(j=0;j<i-1;j++){
			printf("**");
		}
		printf("\\\n");
		
	}
	for(i=1;i<height+1;i++){
		for(j=0;j<i-1;j++){
			printf(" ");
		}
		printf("\\");
		for(j=0;j<(height-i);j++){
			printf("**");
		}
		printf("/\n");
	}
}



void menu(){

	char decider_char,choice='2';

	while(choice >'0' && choice<'4'){
		printf("\e[2J");			 /* Command For Clearing The Screen*/
		printf("%s\n","		*****MENU*****\n" );
		printf("%s\n","		1.Calculator\n" );
		printf("%s\n","		2.Calculate Grades\n" );
		printf("%s\n","		3.Draw Solid Diamond\n" );
		printf("%s\n","		4.Exit\n");
		printf("%s","		Choice:" );

		scanf("%c",&choice);
		
		if(choice == '1'){
			calculation();
		
		}else if(choice == '2'){
			operations();
		
		}else if(choice == '3'){
			solid_diamond();
		
		}else if(choice == '4'){
			printf("%s","EXITING...\n" );
			break;
		}else{

			printf("%s","You entered wrong value. " );
		}
			printf("Press Any Key To Return To Menu...");	
			getchar();
			decider_char = getchar();
			choice = '2';
	}
}




