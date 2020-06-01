//test.c

#include "Header_Test.h"
int subtract(int i, int j){
	return i-j;

}

int call_subtract(void){
	int a=5;
	int b=6;
	return subtract(a,b);
}


 

int conditional(int logical){
	if(logical==1){
		printf("This has been called\n");
	}
	else if(logical==0){
		printf("That has been called\n");
	}
	else{
		printf("an issue occured\n");
		return 0;
	}
	return 1;
}


int func(void){
	int a=10;
	int b=14;
	int res; 
	res=a+b;
	return res;
}
