#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *print_message(void *ptr);
int main() {


}
void *print_message(void *ptr){
	char *message;
	message = (char *) ptr;
	printf("%s \n", message);
}

