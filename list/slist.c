#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "slist.h"
#include<stdio.h>


Slist slist_new()
{
    Slist s={NULL,NULL,0};    //intilizr the head and tail to null
    return s;
}



static Node* slist_new_node(int32_t element)
{
    Node *new_node=(Node *)malloc(sizeof(Node));
    new_node -> data=element;
    new_node->next=NULL;
    return new_node;
}


Slist* slist_add_head(Slist *list,int32_t element)
{
assert(list!=NULL);
Node *new_node=slist_new_node(element);
new_node->next=list->head;
list->head=new_node;
if(list->tail ==NULL)
    {
        list->tail=new_node;
    }
++list->length;
assert((list->length==1 && list->head==list->tail) || (list->length>0 && list->head!=list->tail));
return list;
}


uint32_t slist_length(Slist *list)
{

        assert(list!=NULL);
        return list->length;

}


uint32_t slist_lookup(Slist *list,int32_t key)
{

        assert(list!=NULL);
        Node *cur;
        for(cur=list->head;cur!=NULL;cur=cur->next)
        {

                if(cur->data==key){
                        printf("%d found \n",key);
                        break;

                }
        }
        return (cur!=NULL);
}


Slist* slist_delete_head(Slist *list)
{
  Node* temp;
  if(list->head!=NULL){
        temp=list->head;
        list->head=list->head->next;
        if(list->head==NULL){
                list->tail=NULL;
        }
        --list->length;
  }free(temp);
  return list;
}

Slist* slist_add_tail(Slist *list,int32_t element)
{
        assert(list!=NULL);
        Node *new_node=slist_new_node(element);
        if(list->tail!=NULL){
                list->tail->next=new_node;
                list->tail=new_node;
        }
        else{
                list->tail=list->head=new_node;
        }
        ++list->length;
        return list;
}


Slist* slist_delete_tail(Slist *list)
{
        assert(list!=NULL);
        Node *cur,*temp;
        if(list->tail!=NULL)
        {
            temp=list->tail;
            for(cur=list->head;cur->next!=temp;cur=cur->next);
            list->tail=cur;
            cur->next=NULL;
            --list->length;
        }
        return list;
}

Slist* slist_display(Slist *list){
Node *temp;
int count=0;

    if(list->head == NULL)
    {
        printf("List is empty.");
        return list;
    }

    temp = list->head;
    while(temp != NULL)
    {
        count=count+1;
        printf("Data = %d\n", temp->data); // Print data of current node
        temp = temp->next;

     }
     printf("length of list: %d\n",count);
 }

Slist* slist_min_max(Slist *list) {                    
    Node *travel = list->head;
    int min=travel->data, max=0;
    assert(list!=NULL);
    while (travel!=NULL) {
        if (travel -> data < min) {
            min = travel -> data;
        }
        if (travel -> data > max) {
            max = travel -> data;
        }
        travel = travel -> next;
    }
    printf("min: %d max: %d\n",min,max);
}

Slist* slist_spec_ele(Slist *list, int32_t element,int32_t spec_ele)
{
    assert(list!=NULL);
    Node *new_node=slist_new_node(element);
    Node *temp;
    for(temp=list->head;temp!=NULL;temp=temp->next)
    {
        if(temp->data==spec_ele)
        {
            new_node->next=temp->next;
            temp->next=new_node;
            if(temp->next==NULL)
            {
                assert(temp->next==NULL);
                list->tail=new_node;
            }
        }

    }
    ++list->length;
    return list;

}

Slist* slist_spec_ele_delete(Slist *list, int32_t spec_ele)
{
    assert(list != NULL);
    Node *temp,*prev;
    if(list->length == 1){
        list->head=NULL;
        list->tail=NULL;
        list->length = 0;
    }
    else{
    for(temp=list->head;temp!=NULL;temp=temp->next){
        

        if(temp->data == spec_ele)
        {
            prev->next=temp->next;
        }
        prev = temp;
    }
    --list->length;
   }
    return list;
}

Slist* reverse_list(Slist *list)
{
    
}
