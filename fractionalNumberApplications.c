#include <stdlib.h>
#include <stdio.h>

void addFractions(int *numerator1, int *denominator1, int *numerator2, int *denominator2, int *newNum, int *newDenum);
void subtractFractions(int *numerator1, int *denominator1, int *numerator2, int *denominator2, int *newNum, int *newDenum);
void multiplyFractions(int *numerator1, int *denominator1, int *numerator2, int *denominator2, int *newNum, int *newDenum);
void divideFractions(int *numerator1, int *denominator1, int *numerator2, int *denominator2, int *newNum, int *newDenum);
int greatestCommonDivision (int *numerator1, int *denominator1);
void reTakingDenum(int *numerator1, int *denominator1, int *numerator2, int *denominator2);

int main(){

	int num1, denum1, num2, denum2, rnum, rdenum;
	char operator, answer;
	int gcd;

	printf("To start press y.\n");
	scanf(" %c", &answer);
	while (answer=='y')
	{
		printf("Enter numerators and denominators.\n");
		scanf("%d %d %d %d", &num1, &denum1, &num2, &denum2);
		if (denum1 == 0 || denum2 == 0){
			reTakingDenum(&num1, &denum1, &num2, &denum2);
		}
		printf("Enter the operator.\n");
		scanf(" %c", &operator);

		if (operator == '+'){
			addFractions(&num1, &denum1, &num2, &denum2, &rnum, &rdenum);
			gcd = greatestCommonDivision(&rnum, &rdenum);
			printf("new numerator: %d, new denominator: %d. Greatest common divisor is: %d.\n", rnum, rdenum, gcd);
		}
		else if (operator == '-'){
			subtractFractions(&num1, &denum1, &num2, &denum2, &rnum, &rdenum);
			gcd = greatestCommonDivision(&rnum, &rdenum);
			printf("new numerator: %d, new denominator: %d. Greatest common divisor is: %d.\n", rnum, rdenum, gcd);
		}
		else if (operator == '*'){
			multiplyFractions(&num1, &denum1, &num2, &denum2, &rnum, &rdenum);
			gcd = greatestCommonDivision(&rnum, &rdenum);
			printf("new numerator: %d, new denominator: %d. Greatest common divisor is: %d.\n", rnum, rdenum, gcd);
		}
		else if (operator == '/'){
			divideFractions(&num1, &denum1, &num2, &denum2, &rnum, &rdenum);
			gcd = greatestCommonDivision(&rnum, &rdenum);
			printf("new numerator: %d, new denominator: %d. Greatest common divisor is: %d.\n", rnum, rdenum, gcd);
		}

		printf("If you want to continue press y.\n");
		scanf(" %c", &answer);
	}
}

void addFractions(int *numerator1, int *denominator1, int *numerator2, int *denominator2, int *newNum, int *newDenum){

	*newNum= ((*numerator1 * *denominator2) + (*numerator2 * *denominator1));
	*newDenum= *denominator1 * *denominator2;
}
void subtractFractions(int *numerator1, int *denominator1, int *numerator2, int *denominator2, int *newNum, int *newDenum){

	*newNum = ((*numerator1 * *denominator2) - (*numerator2 * *denominator1));
	*newDenum = *denominator1 * *denominator2;
}
void multiplyFractions(int *numerator1, int *denominator1, int *numerator2, int *denominator2, int *newNum, int *newDenum){

	*newNum = *numerator1 * *numerator2;
	*newDenum = *denominator1 * *denominator2;	

	if (*numerator1 == 0 || *denominator1 == 0 || *numerator2 == 0 || *denominator2 == 0){
		*newNum = 0;
		*newDenum = 0;
	}
}
void divideFractions(int *numerator1, int *denominator1, int *numerator2, int *denominator2, int *newNum, int *newDenum){
	multiplyFractions(&*numerator1, &*denominator1, &*denominator2, &*numerator2, &*newNum, &*newDenum);
}

int greatestCommonDivision (int *numerator1, int *denominator1){

	int gcd=1; 

	for (int i=1; *numerator1>=i && *denominator1>=i; i++){
		if(*numerator1%i==0 && *denominator1%i==0)
            gcd = i;
	}

	*numerator1 = *numerator1 / gcd;
	*denominator1 = *denominator1/gcd;

	if (*numerator1 == 0 || *denominator1 == 0){s
		gcd = 0;
	}

	return gcd;
}

void reTakingDenum(int *numerator1, int *denominator1, int *numerator2, int *denominator2){
	while (*denominator1 == 0 || *denominator2 == 0) {
		printf("Denominator can not be 0. Try again.\n");
		scanf("%d %d %d %d", &*numerator1, &*denominator1, &*numerator2, &*denominator2);
	} 
}



