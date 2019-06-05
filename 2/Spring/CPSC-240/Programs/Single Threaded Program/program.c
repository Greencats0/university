#include <stdio.h>
#include <pthread.h>

#define MAX 1000000000

int main() {
	int counter = 0;
	for(int i = 1; i < MAX; i++){	

	}
	printf("%i\n", counter);
	return 0;
}

void function_called(int* counter, int i){
	if(MAX % i == 0){ counter++; }

}
