#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
	struct Node* next_node;
	void* data;
} VectorNode;

typedef struct {
	VectorNode* first_node;

	VectorNode* last_node;
	unsigned int length;
} VectorHead;

typedef VectorHead Vector;

Vector init_vector() {
	Vector vect;

	vect.first_node = NULL;
	vect.last_node = NULL;
	vect.length = 0;

	return vect;
}

void push_vector_data_i(Vector* vect, int data) {
	if (vect->last_node == NULL)
	{
		vect->last_node = malloc(sizeof(VectorNode));
		vect->last_node->data = malloc(sizeof(int));
		*(int*)vect->last_node->data = data;
		vect->last_node->next_node = NULL;

		vect->first_node = vect->last_node;
	}
	else {
		vect->last_node->next_node = malloc(sizeof(VectorNode));
		vect->last_node = vect->last_node->next_node;

		vect->last_node->data = malloc(sizeof(int));
		*(int*)vect->last_node->data = data;
		vect->last_node->next_node = NULL;
	}

	vect->length++;
}

void push_vector_data_f(Vector* vect, float data) {
	if (vect->first_node == NULL)
	{
		vect->last_node = malloc(sizeof(VectorNode));
		vect->last_node->data = malloc(sizeof(float));
		*(float*)vect->last_node->data = data;
		vect->last_node->next_node = NULL;

		vect->first_node = vect->last_node;
	}
	else {
		vect->last_node->next_node = malloc(sizeof(VectorNode));
		vect->last_node = vect->last_node->next_node;

		vect->last_node->data = malloc(sizeof(float));
		*(float*)vect->last_node->data = data;
		vect->last_node->next_node = NULL;
	}

	vect->length++;
}


void add_vector_data_at_pos_i(Vector* vect, int data, int pos) {
	if (pos >= vect->length || vect->length <= 0) {
		push_vector_data_i(vect, data);
	}
	else if (pos == 0) {
		VectorNode* temp = vect->first_node;

		vect->first_node = malloc(sizeof(VectorNode));
		vect->first_node->data = malloc(sizeof(int));
		*(int*)vect->first_node->data = data;
		vect->first_node->next_node = temp;

		printf("%d %d\n", temp, vect->first_node->next_node);
	}
	else {
		int i = 0;
		VectorNode** node = &(vect->first_node);

		while (i < (pos - 1)) {
			node = &((*node)->next_node);
			i++;
		}

		if (*node == NULL) {
			vect->first_node = malloc(sizeof(VectorNode));
			vect->first_node->next_node = *node;
			vect->first_node->data = malloc(sizeof(int));
			*(int*)vect->first_node->data = data;
		}
		else {
			VectorNode* temp = (*node)->next_node;

			(*node)->next_node = malloc(sizeof(VectorNode));
			(*node)->next_node->next_node = temp;
			(*node)->next_node->data = malloc(sizeof(int));
			*(int*)(*node)->next_node->data = data;
		}

		vect->length++;
	}
}


void add_vector_data_at_pos_f(Vector* vect, float data, int pos) {
	if (pos >= vect->length || vect->length <= 0) {
		push_vector_data_i(vect, data);
	}
	else if (pos == 0) {
		VectorNode* temp = vect->first_node;

		vect->first_node = malloc(sizeof(VectorNode));
		vect->first_node->data = malloc(sizeof(float));
		*(float*)vect->first_node->data = data;
		vect->first_node->next_node = temp;
	}
	else {
		int i = 0;
		VectorNode** node = &(vect->first_node);

		while (i < (pos - 1)) {
			node = &((*node)->next_node);
			i++;
		}

		if (*node == NULL) {
			vect->first_node = malloc(sizeof(VectorNode));
			vect->first_node->next_node = *node;
			vect->first_node->data = malloc(sizeof(float));
			*(float*)vect->first_node->data = data;
		}
		else {
			VectorNode* temp = (*node)->next_node;

			(*node)->next_node = malloc(sizeof(VectorNode));
			(*node)->next_node->next_node = temp;
			(*node)->next_node->data = malloc(sizeof(float));
			*(float*)(*node)->next_node->data = data;
		}

		vect->length++;
	}
}


void add_vector_data_ordered_i(Vector* vect, int data) {
	if (vect->length <= 0) {
		push_vector_data_i(vect, data);
	}
	else {

		VectorNode* node = vect->first_node;

		int i = 0;
		while (node != NULL && *(int*)node->data < data) {
			//	Change the node target
			node = node->next_node;
			i++;
		}

		add_vector_data_at_pos_i(vect, data, i);
	}
}


void add_vector_data_ordered_f(Vector* vect, float data) {
	if (vect->length <= 0) {
		push_vector_data_i(vect, data);
	}
	else {

		VectorNode* node = vect->first_node;

		int i = 0;
		while (node != NULL && *(float*)node->data < data) {
			//	Change the node target
			node = node->next_node;
			i++;
		}

		add_vector_data_at_pos_f(vect, data, i);
	}
}


int get_vector_element_i(Vector* vect, int index) {
	if (vect->length <= index)
		return NULL;
	
	VectorNode** node = &(vect->first_node);

	int i = 0;
	while (i < index) {
		node = &((*node)->next_node);
		i++;
	}

	return (*(int*)(*node)->data);
}

int* get_vector_element_ptr_i(Vector* vect, int index) {
	if (vect->length <= index)
		return NULL;

	VectorNode** node = &(vect->first_node);

	int i = 0;
	while (i < index) {
		node = &((*node)->next_node);
		i++;
	}

	return ((int*)(*node)->data);
}


float get_vector_element_f(Vector* vect, int index) {
	if (vect->length <= index)
		return -NAN;

	VectorNode** node = &(vect->first_node);

	int i = 0;
	while (i < index) {
		node = &((*node)->next_node);
		i++;
	}

	return (*(float*)(*node)->data);
}

float* get_vector_element_ptr_f(Vector* vect, int index) {
	if (vect->length <= index)
		return NULL;

	VectorNode** node = &(vect->first_node);

	int i = 0;
	while (i < index) {
		node = &((*node)->next_node);
		i++;
	}

	return ((float*)(*node)->data);
}

void pop_vector_element(Vector* vect) {
	VectorNode** last_node = NULL;
	VectorNode** last_last_node = NULL;

	VectorNode** node = &(vect->first_node);
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
	vect->last_node = last_last_node;

	vect->length--;
}


void free_vector(Vector* vect) {
	while (vect->length > 0) {
		pop_vector_element(vect);
	}

	vect->last_node = NULL;
	vect->first_node = NULL;
}



int* get_vector_as_array_i(Vector* vect) {
	int* out_vect = malloc(sizeof(int) * vect->length);

	int i = 0;
	while (i < vect->length) {
		out_vect[i] = get_vector_element_i(vect, i);
		i++;
	}

	return out_vect;
}


void set_vector_data_i(Vector* vect, int data, int index) {
	if (vect->length <= index)
		return;
	
	VectorNode* node = vect->first_node;

	int i = 0;
	while (i < index) {
		node = node->next_node;

		i++;
	}

	*(int*)node->data = data;
}


void set_vector_data_f(Vector* vect, float data, int index) {
	if (vect->length <= index)
		return;

	VectorNode* node = vect->first_node;

	int i = 0;
	while (i < index) {
		node = node->next_node;

		i++;
	}

	*(float*)node->data = data;
}

void delete_vector_data(Vector* vect, int index) {
	if (index < 0 || index >= vect->length) {
		pop_vector_element(vect);
	}
	else if (index == 0) {
		VectorNode* temp = vect->first_node->next_node;
		free(vect->first_node->data);
		free(vect->first_node);
		vect->first_node = temp;
	}
	else {
		VectorNode* node = vect->first_node;
		VectorNode* last_node = NULL;

		int i = 0;
		while (i < index) {
			last_node = node;
			node = node->next_node;

			i++;
		}

		VectorNode* temp = node->next_node;
		free(node->data);
		free(node);
		last_node->next_node = temp;
	}

	vect->length--;
}


void sort_vector_i(Vector* vect) {
	int us, sup = vect->length - 1;

	do
	{
		us = -1;
		for (int i = 0; i < sup; i++) {
			int temp1 = get_vector_element_i(vect, i);
			int temp2 = get_vector_element_i(vect, i + 1);

			if (temp1 > temp2) {
				set_vector_data_i(vect, temp2, i);
				set_vector_data_i(vect, temp1, i + 1);

				us = i;
			}
		}

		sup = us;
	} while (sup != -1);
}


void sort_vector_f(Vector* vect) {
	int us, sup = vect->length - 1;

	do
	{
		us = -1;
		for (int i = 0; i < sup; i++) {
			float temp1 = get_vector_element_f(vect, i);
			float temp2 = get_vector_element_f(vect, i + 1);

			if (temp1 > temp2) {
				set_vector_data_f(vect, temp2, i);
				set_vector_data_f(vect, temp1, i + 1);

				us = i;
			}
		}

		sup = us;
	} while (sup != -1);
}

int main() {
	Vector vect = init_vector();

	printf("%f\n", get_vector_element_f(&vect, 0));

	push_vector_data_i(&vect, 20);
	push_vector_data_i(&vect, 30);
	push_vector_data_i(&vect, 40);
	push_vector_data_f(&vect, 50.0);
	push_vector_data_f(&vect, 60.0);

	printf("%d\n", get_vector_element_i(&vect, 0));
	printf("%d\n", get_vector_element_i(&vect, 1));
	printf("%d\n", *get_vector_element_ptr_i(&vect, 2));
	printf("%f\n", get_vector_element_f(&vect, 3));
	printf("%f\n", *get_vector_element_ptr_f(&vect, 4));

	int* elem = get_vector_element_ptr_i(&vect, 2);
	printf("%d\n", get_vector_element_i(&vect, 2));
	*elem = 5;
	printf("%d\n", get_vector_element_i(&vect, 2));

	push_vector_data_f(&vect, 10.0);
	printf("%f\n", get_vector_element_f(&vect, 5));
	pop_vector_element(&vect);
	printf("%f\n", get_vector_element_f(&vect, 5));

	free_vector(&vect);

	push_vector_data_i(&vect, 0);
	push_vector_data_i(&vect, 1);
	push_vector_data_i(&vect, 2);
	push_vector_data_i(&vect, 3);
	push_vector_data_i(&vect, 4);
	add_vector_data_at_pos_i(&vect, 5, 2);
													
	int* temp = get_vector_as_array_i(&vect);		
	printf("%d %d\n", temp[0], temp[5]);				
	free(temp);

	free_vector(&vect);
	add_vector_data_at_pos_i(&vect, 5, 0);
	add_vector_data_at_pos_i(&vect, 4, 1);
	add_vector_data_at_pos_i(&vect, 3, 1);
	push_vector_data_i(&vect, 6);
	printf("%d %d\n", get_vector_element_i(&vect, 0), get_vector_element_i(&vect, 3));

	add_vector_data_at_pos_i(&vect, 5, 0);
	free_vector(&vect);

	push_vector_data_i(&vect, 0);
	push_vector_data_i(&vect, 1);
	push_vector_data_i(&vect, 2);
	push_vector_data_i(&vect, 5);
	push_vector_data_i(&vect, 6);
	add_vector_data_ordered_i(&vect, 4);
	add_vector_data_ordered_i(&vect, 3);


	for (int i = 0; i < 7; i++) {
		printf("%d ", get_vector_element_i(&vect, i));
	}
	printf("\n");

	free_vector(&vect);

	add_vector_data_ordered_i(&vect, 1);
	add_vector_data_ordered_i(&vect, 3);
	add_vector_data_ordered_i(&vect, 2);
	add_vector_data_ordered_i(&vect, 5);
	add_vector_data_ordered_i(&vect, 4);

	for (int i = 0; i < 5; i++) {
		printf("%d ", get_vector_element_i(&vect, i));
	}
	printf("\n");

	free_vector(&vect);
	push_vector_data_i(&vect, 1);
	push_vector_data_i(&vect, 1);
	push_vector_data_i(&vect, 1);
	set_vector_data_i(&vect, 9, 0);
	set_vector_data_i(&vect, 9, 1);
	set_vector_data_i(&vect, 9, 2);
	printf("%d\n", get_vector_element_i(&vect, 2));

	free_vector(&vect);
	push_vector_data_i(&vect, 2);
	push_vector_data_i(&vect, 1);
	push_vector_data_i(&vect, 5);
	push_vector_data_i(&vect, 3);
	push_vector_data_i(&vect, 4);
	sort_vector_i(&vect);
	for (int i = 0; i < 5; i++) {
		printf("%d ", get_vector_element_i(&vect, i));
	}
	printf("\n");

	free_vector(&vect);
	push_vector_data_f(&vect, 2.0);
	push_vector_data_f(&vect, 1.0);
	push_vector_data_f(&vect, 5.0);
	push_vector_data_f(&vect, 3.0);
	push_vector_data_f(&vect, 4.0);
	sort_vector_f(&vect);
	for (int i = 0; i < 5; i++) {
		printf("%f ", get_vector_element_f(&vect, i));
	}
	printf("\n");

	free_vector(&vect);


	push_vector_data_f(&vect, 2.0);
	push_vector_data_f(&vect, 4.0);
	push_vector_data_f(&vect, 6.0);
	delete_vector_data(&vect, 1);
	printf("%f", get_vector_element_f(&vect, 1));

	free_vector(&vect);

	return 0;
}