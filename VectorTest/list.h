#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define clear_list(vect) free_list(vect)

typedef struct Node {
	struct Node*	next_node;
	void*			data;
} ListNode;

typedef struct {
	ListNode*		first_node;

	ListNode*		last_node;
	unsigned int	length;
} ListHead;

typedef ListHead List;

List	init_list();

void	push_list_data_i		(List*, int);
void	push_list_data_f		(List*, float);

void	pop_list_element		(List*);

void	add_list_data_at_pos_i	(List*, int, int);
void	add_list_data_at_pos_f	(List*, float, int);
void	add_list_data_ordered_i	(List*, int);
void	add_list_data_ordered_f	(List*, float);

int		get_list_element_i		(List*, int);
int*	get_list_element_ptr_i	(List*, int);
float	get_list_element_f		(List*, int);
float*	get_list_element_ptr_f	(List*, int);

void	set_list_data_i			(List*, int, int);
void	set_list_data_f			(List*, float , int);

void	delete_list_element		(List*, int);

void	sort_list_i				(List*);
void	sort_list_f				(List*);

int*	get_list_as_array_i		(List*);

void	free_list				(List*);