#include <stdio.h>
#include "list.h"

int main() {
	List vect = init_list();

	printf("%f\n", get_list_element_f(&vect, 0));

	push_list_data_i(&vect, 20);
	push_list_data_i(&vect, 30);
	push_list_data_i(&vect, 40);
	push_list_data_f(&vect, 50.0);
	push_list_data_f(&vect, 60.0);

	printf("%d\n", get_list_element_i(&vect, 0));
	printf("%d\n", get_list_element_i(&vect, 1));
	printf("%d\n", *get_list_element_ptr_i(&vect, 2));
	printf("%f\n", get_list_element_f(&vect, 3));
	printf("%f\n", *get_list_element_ptr_f(&vect, 4));

	int* elem = get_list_element_ptr_i(&vect, 2);
	printf("%d\n", get_list_element_i(&vect, 2));
	*elem = 5;
	printf("%d\n", get_list_element_i(&vect, 2));

	push_list_data_f(&vect, 10.0);
	printf("%f\n", get_list_element_f(&vect, 5));
	pop_list_element(&vect);
	printf("%f\n", get_list_element_f(&vect, 5));

	clear_list(&vect);

	push_list_data_i(&vect, 0);
	push_list_data_i(&vect, 1);
	push_list_data_i(&vect, 2);
	push_list_data_i(&vect, 3);
	push_list_data_i(&vect, 4);
	add_list_data_at_pos_i(&vect, 5, 2);
													
	int* temp = get_list_as_array_i(&vect);		
	printf("%d %d\n", temp[0], temp[5]);				
	free(temp);

	clear_list(&vect);
	add_list_data_at_pos_i(&vect, 5, 0);
	add_list_data_at_pos_i(&vect, 4, 1);
	add_list_data_at_pos_i(&vect, 3, 1);
	push_list_data_i(&vect, 6);
	printf("%d %d\n", get_list_element_i(&vect, 0), get_list_element_i(&vect, 3));

	add_list_data_at_pos_i(&vect, 5, 0);
	clear_list(&vect);

	push_list_data_i(&vect, 0);
	push_list_data_i(&vect, 1);
	push_list_data_i(&vect, 2);
	push_list_data_i(&vect, 5);
	push_list_data_i(&vect, 6);
	add_list_data_ordered_i(&vect, 4);
	add_list_data_ordered_i(&vect, 3);


	for (int i = 0; i < 7; i++) {
		printf("%d ", get_list_element_i(&vect, i));
	}
	printf("\n");

	clear_list(&vect);

	add_list_data_ordered_i(&vect, 1);
	add_list_data_ordered_i(&vect, 3);
	add_list_data_ordered_i(&vect, 2);
	add_list_data_ordered_i(&vect, 5);
	add_list_data_ordered_i(&vect, 4);

	for (int i = 0; i < 5; i++) {
		printf("%d ", get_list_element_i(&vect, i));
	}
	printf("\n");

	clear_list(&vect);
	push_list_data_i(&vect, 1);
	push_list_data_i(&vect, 1);
	push_list_data_i(&vect, 1);
	set_list_data_i(&vect, 9, 0);
	set_list_data_i(&vect, 9, 1);
	set_list_data_i(&vect, 9, 2);
	printf("%d\n", get_list_element_i(&vect, 2));

	clear_list(&vect);
	push_list_data_i(&vect, 2);
	push_list_data_i(&vect, 1);
	push_list_data_i(&vect, 5);
	push_list_data_i(&vect, 3);
	push_list_data_i(&vect, 4);
	sort_list_i(&vect);
	for (int i = 0; i < 5; i++) {
		printf("%d ", get_list_element_i(&vect, i));
	}
	printf("\n");

	clear_list(&vect);
	push_list_data_f(&vect, 2.0);
	push_list_data_f(&vect, 1.0);
	push_list_data_f(&vect, 5.0);
	push_list_data_f(&vect, 3.0);
	push_list_data_f(&vect, 4.0);
	sort_list_f(&vect);
	for (int i = 0; i < 5; i++) {
		printf("%f ", get_list_element_f(&vect, i));
	}
	printf("\n");

	clear_list(&vect);


	push_list_data_f(&vect, 2.0);
	push_list_data_f(&vect, 4.0);
	push_list_data_f(&vect, 6.0);
	delete_list_element(&vect, 1);
	printf("%f", get_list_element_f(&vect, 1));

	free_list(&vect);

	return 0;
}