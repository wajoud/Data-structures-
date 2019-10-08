/*
 *	Author : Deepak
 *	Date   : 23 August 2019
 *	Specification file for Single Linked List
 *	Contain test cases to test various functionalities
 *	of Single Linked List.
*/


#include <assert.h>
#include "slist.h"

void test_empty_list()
{
	Slist s = slist_new();
	Slist *list = &s;
	assert (slist_length(list) == 0);
}

void test_addition_at_head()
{
    Slist s = slist_new();
	Slist *list = &s;
	list = slist_add_head(list, 13);
	assert (slist_length(list) == 1);

	list = slist_add_head(list, 26);
	list = slist_add_head(list, 35);
	list = slist_add_head(list, 49);
	list = slist_add_head(list, 55);
	list = slist_add_head(list, 65);
	list = slist_add_tail(list, 99);

	assert (slist_length(list) == 7);
	assert (slist_lookup(list, 49));
	list = slist_delete_head(list);
	list = slist_delete_tail(list);
	
	slist_display(list);
	slist_min_max(list);
	list = slist_spec_ele(list,100,26);
	slist_display(list);
	list = slist_spec_ele_delete(list,35);
	slist_display(list);

}

int main()
{
	test_empty_list();
	Slist s = slist_new();
	Slist *list = &s;
	list = slist_add_head(list, 10);
	list = slist_add_head(list, 20);
	list = slist_add_head(list, 30);
	list = slist_add_head(list, 40);
	//slist_display(list);
	list = slist_spec_ele(list,100,10);
	//list = slist_spec_ele_delete(list,50);
	//assert (slist_lookup(list, 50)==0);
	slist_display(list);

	//test_addition_at_head();
	return 0;
}

/*
 *	Running your programs. Assume that already you have
 *	'slist.h', 'slist.c' and 'slist_spec.c' files.
 *
 *	gcc slist.c slist_spec.c -o slist
 *
 *	If you get errors, fix them. Otherwise you have exe file
 *	with name 'slist' (due to -o slist option used during compilation)
 *
 *	Running exe file:	./a.out slist
 *	If you don't get any message in terminal, code executed perfectly
 *	( No news good news!!!!!!!)
 *
*/
