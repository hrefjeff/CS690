#include <stdio.h>
#include "calc.h"

int main(){
	int x = 5;
	int y = 2;
	int mysum;
	int mydiff;

	mysum = sum(x, y);
	mydiff = sub(x, y);

	printf("The sum is %d\n", mysum);
	printf("The diff is %d\n", mydiff);

	return 0;
}

