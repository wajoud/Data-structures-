#include<stdint.h>
#include<stdlib.h>
#include<assert.h>

#include "stack.h"

Stack* create_stack(){
	Stack* stck = (Stack*) malloc(sizeof(Stack));
	stck->head = NULL;
	stck->tail = NULL;
	stck->length = 0;
	return stck;
}
OprResult create_result(){
	
}

OprResult push(Stack* stck, int32_t data){
	stck.add_head((Slist*)stck,data);
}
OprResult pop(Stack* stck){

	stck.delete_head((Slist*)stck,data);
}
OprResult peek(){
	
}