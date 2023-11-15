#include<stdio.h>
#include<stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
    struct Student * next; 
};
void print_menu(const char * s, int flag);

void add_begin(struct Student ** ptr);

void add_end(struct Student ** ptr);

void add_middle(struct Student ** ptr);

void add_sorted(struct Student ** ptr);

void print_data(const struct Student * ptr);

int count_nodes(const struct Student * ptr);

void save_file(const struct Student * ptr);

void read_file(struct Student ** ptr);

void print_data_rec(const struct Student * ptr);

void print_data_rev_rec(const struct Student * ptr);

void print_data_rev(const struct Student * ptr);

void delete_all(struct Student ** ptr);

void delete_node(struct Student ** ptr);

void search_node(const struct Student * ptr);

void sort_nodes(struct Student ** ptr);

void reverse_links(struct Student ** ptr);
