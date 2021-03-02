#include "list.h"

List init_list() {
	List list;

	list.first_node = NULL;
	list.last_node = NULL;
	list.length = 0;

	return list;
}


void push_list_data_i(List* list, int data) {
	if (list->last_node == NULL)
	{
		list->last_node = malloc(sizeof(ListNode));
		list->last_node->data = malloc(sizeof(int));
		*(int*)list->last_node->data = data;
		list->last_node->next_node = NULL;

		list->first_node = list->last_node;
	}
	else {
		list->last_node->next_node = malloc(sizeof(ListNode));
		list->last_node = list->last_node->next_node;

		list->last_node->data = malloc(sizeof(int));
		*(int*)list->last_node->data = data;
		list->last_node->next_node = NULL;
	}

	list->length++;
}

void push_list_data_f(List* list, float data) {
	if (list->first_node == NULL)
	{
		list->last_node = malloc(sizeof(ListNode));
		list->last_node->data = malloc(sizeof(float));
		*(float*)list->last_node->data = data;
		list->last_node->next_node = NULL;

		list->first_node = list->last_node;
	}
	else {
		list->last_node->next_node = malloc(sizeof(ListNode));
		list->last_node = list->last_node->next_node;

		list->last_node->data = malloc(sizeof(float));
		*(float*)list->last_node->data = data;
		list->last_node->next_node = NULL;
	}

	list->length++;
}


void pop_list_element(List* list) {
	ListNode** last_node = NULL;
	ListNode** last_last_node = NULL;

	ListNode** node = &(list->first_node);
	last_node = NULL;
	last_last_node = NULL;

	while ((*node) != NULL) {
		last_last_node = last_node;
		last_node = node;
		node = &((*node)->next_node);
	}

	//	node is NULL. We cannot use it!
	if (last_node != NULL) {
		free((*last_node)->data);
		free(*last_node);
	}
	if (last_last_node != NULL) {
		(*last_last_node)->next_node = NULL;
	}
	list->last_node = last_last_node;

	list->length--;
}


void add_list_data_at_pos_i(List* list, int data, int pos) {
	if (pos >= list->length || list->length <= 0) {
		push_list_data_i(list, data);
	}
	else if (pos == 0) {
		ListNode* temp = list->first_node;

		list->first_node = malloc(sizeof(ListNode));
		list->first_node->data = malloc(sizeof(int));
		*(int*)list->first_node->data = data;
		list->first_node->next_node = temp;
	}
	else {
		int i = 0;
		ListNode* node = list->first_node;

		while (i < (pos - 1)) {
			node = node->next_node;
			i++;
		}

		if (node == NULL) {
			list->first_node = malloc(sizeof(ListNode));
			list->first_node->next_node = node;
			list->first_node->data = malloc(sizeof(int));
			*(int*)list->first_node->data = data;
		}
		else {
			ListNode* temp = node->next_node;

			node->next_node = malloc(sizeof(ListNode));
			node->next_node->next_node = temp;
			node->next_node->data = malloc(sizeof(int));
			*(int*)node->next_node->data = data;
		}

		list->length++;
	}
}


void add_list_data_at_pos_f(List* list, float data, int pos) {
	if (pos >= list->length || list->length <= 0) {
		push_list_data_i(list, data);
	}
	else if (pos == 0) {
		ListNode* temp = list->first_node;

		list->first_node = malloc(sizeof(ListNode));
		list->first_node->data = malloc(sizeof(float));
		*(float*)list->first_node->data = data;
		list->first_node->next_node = temp;
	}
	else {
		int i = 0;
		ListNode* node = list->first_node;

		while (i < (pos - 1)) {
			node = node->next_node;
			i++;
		}

		if (node == NULL) {
			list->first_node = malloc(sizeof(ListNode));
			list->first_node->next_node = node;
			list->first_node->data = malloc(sizeof(float));
			*(float*)list->first_node->data = data;
		}
		else {
			ListNode* temp = node->next_node;

			node->next_node = malloc(sizeof(ListNode));
			node->next_node->next_node = temp;
			node->next_node->data = malloc(sizeof(float));
			*(float*)node->next_node->data = data;
		}

		list->length++;
	}
}


void add_list_data_ordered_i(List* list, int data) {
	if (list->length <= 0) {
		push_list_data_i(list, data);
	}
	else {

		ListNode* node = list->first_node;

		int i = 0;
		while (node != NULL && *(int*)node->data < data) {
			//	Change the node target
			node = node->next_node;
			i++;
		}

		add_list_data_at_pos_i(list, data, i);
	}
}


void add_list_data_ordered_f(List* list, float data) {
	if (list->length <= 0) {
		push_list_data_i(list, data);
	}
	else {

		ListNode* node = list->first_node;

		int i = 0;
		while (node != NULL && *(float*)node->data < data) {
			//	Change the node target
			node = node->next_node;
			i++;
		}

		add_list_data_at_pos_f(list, data, i);
	}
}


int get_list_element_i(List* list, int index) {
	if (list->length <= index)
		return NULL;

	ListNode* node = list->first_node;

	int i = 0;
	while (i < index) {
		node = node->next_node;
		i++;
	}

	return (*(int*)node->data);
}

int* get_list_element_ptr_i(List* list, int index) {
	if (list->length <= index)
		return NULL;

	ListNode* node = list->first_node;

	int i = 0;
	while (i < index) {
		node = node->next_node;
		i++;
	}

	return ((int*)node->data);
}


float get_list_element_f(List* list, int index) {
	if (list->length <= index)
		return -NAN;

	ListNode* node = list->first_node;

	int i = 0;
	while (i < index) {
		node = node->next_node;
		i++;
	}

	return (*(float*)node->data);
}

float* get_list_element_ptr_f(List* list, int index) {
	if (list->length <= index)
		return NULL;

	ListNode* node = list->first_node;

	int i = 0;
	while (i < index) {
		node = node->next_node;
		i++;
	}

	return ((float*)node->data);
}



void set_list_data_i(List* list, int data, int index) {
	if (list->length <= index)
		return;

	ListNode* node = list->first_node;

	int i = 0;
	while (i < index) {
		node = node->next_node;

		i++;
	}

	*(int*)node->data = data;
}

void set_list_data_f(List* list, float data, int index) {
	if (list->length <= index)
		return;

	ListNode* node = list->first_node;

	int i = 0;
	while (i < index) {
		node = node->next_node;

		i++;
	}

	*(float*)node->data = data;
}


void delete_list_element(List* list, int index) {
	if (index < 0 || index >= list->length) {
		pop_list_element(list);
	}
	else if (index == 0) {
		ListNode* temp = list->first_node->next_node;
		free(list->first_node->data);
		free(list->first_node);
		list->first_node = temp;
	}
	else {
		ListNode* node = list->first_node;
		ListNode* last_node = NULL;

		int i = 0;
		while (i < index) {
			last_node = node;
			node = node->next_node;

			i++;
		}

		ListNode* temp = node->next_node;
		free(node->data);
		free(node);
		last_node->next_node = temp;
	}

	list->length--;
}


void sort_list_i(List* list) {
	int us, sup = list->length - 1;

	do
	{
		us = -1;
		for (int i = 0; i < sup; i++) {
			int temp1 = get_list_element_i(list, i);
			int temp2 = get_list_element_i(list, i + 1);

			if (temp1 > temp2) {
				set_list_data_i(list, temp2, i);
				set_list_data_i(list, temp1, i + 1);

				us = i;
			}
		}

		sup = us;
	} while (sup != -1);
}


void sort_list_f(List* list) {
	int us, sup = list->length - 1;

	do
	{
		us = -1;
		for (int i = 0; i < sup; i++) {
			float temp1 = get_list_element_f(list, i);
			float temp2 = get_list_element_f(list, i + 1);

			if (temp1 > temp2) {
				set_list_data_f(list, temp2, i);
				set_list_data_f(list, temp1, i + 1);

				us = i;
			}
		}

		sup = us;
	} while (sup != -1);
}


int* get_list_as_array_i(List* list) {
	int* out_list = malloc(sizeof(int) * list->length);

	int i = 0;
	while (i < list->length) {
		out_list[i] = get_list_element_i(list, i);
		i++;
	}

	return out_list;
}



void free_list(List* list) {
	while (list->length > 0) {
		pop_list_element(list);
	}

	list->last_node = NULL;
	list->first_node = NULL;
}