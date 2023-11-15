#include"header.h"
#include"function.c"
int main(void) {
    int op, c, i, rows;
    char menu[][30] = {"Add begin","Add end","Add middle","Add sorted" ,"Print data", "Count nodes", "Save to file", "Read from file", "Print recursively", "Recursively Reverse","Print Reverse","Delete all", "Delete Node", "Search Node", "Sort Data", "Reverse Links", "Exit"};
    rows = sizeof(menu)/sizeof(menu[0]);
    struct Student * headptr = 0;
    while(1) {
        printf("\033[34mEnter your choice\033[0m\n");
        for(i = 0;i < rows;i++) print_menu(menu[i], 0);
        print_menu("\n", 1);
        scanf("%d", &op);
        switch(op) {
            case 1:
                add_begin(&headptr);
                break;
            case 2:
                add_end(&headptr);
                break;
            case 3:
                add_middle(&headptr);
                break;
            case 4:
                add_sorted(&headptr);
                break;
            case 5:
                print_data(headptr);
                break;
            case 6:
                c = count_nodes(headptr);
                printf("count = %d\n", c);
                break;
            case 7:
                save_file(headptr);
                break;
            case 8:
                read_file(&headptr);
                break;
            case 9:
                print_data_rec(headptr);
                break;
            case 10:
                print_data_rev_rec(headptr);
                break;
            case 11:
                print_data_rev(headptr);
                break;
            case 12:
                delete_all(&headptr);
                break;
            case 13:
                delete_node(&headptr);
                break;
            case 14:
                search_node(headptr);
                break;
            case 15:
                sort_nodes(&headptr);
                break;
            case 16:
                reverse_links(&headptr);
                break;
            case 17:
                return 0;
                break;
            default:
                printf("Invalid value given. Try again...\n");
                break;
        }
    }
    return 0;
}



void print_menu(const char * s, int flag){
    static int i = 1;
    if(flag == 1){
        i = 1;
        return;
    }
    printf("\033[32m%d)\033[0m",i++);
    printf("\033[36m%s\033[0m\n", s);

}
