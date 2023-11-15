void add_begin(struct Student ** ptr){
    struct Student * new;
    //create new node
    new = malloc(sizeof(struct Student));
    //scan data
    printf("Enter values for student\n");
    printf("Roll no : ");
    scanf("%d", &new->rollno);
    printf("Name : ");
    scanf(" %s", new->name);
    printf("Marks : ");
    scanf("%f", &new->marks);
    //update ptr
    new->next = *ptr;
    //update headptr
    *ptr = new;
    return; 
}

void add_end(struct Student ** ptr) {
    struct Student * new, *cur;
    if(*ptr == 0){
        add_begin(ptr);
        return;
    }
    cur = *ptr;
    while(cur->next) {
        cur = cur->next;
    }
    //create new node
    new = malloc(sizeof(struct Student));
    //scan data
    printf("Enter values for student\n");
    printf("Roll no : ");
    scanf("%d", &new->rollno);
    printf("Name : ");
    scanf(" %s", new->name);
    printf("Marks : ");
    scanf("%f", &new->marks);
    //IMP : update ptr of new->next
    new->next = 0;
    //update ptr of current
    cur->next = new;
    return;
}


void add_middle(struct Student ** ptr) {
    int i, c, cmax;
    cmax = count_nodes(*ptr);
    struct Student * new, *cur;
    //take input from user where you want to add 
    printf("count = %d\n", cmax);
    printf("Enter index where you want to add data : ");
    scanf("%d",&c);
    //if the index is greater than count say not possible
    if(c >= cmax) {
        printf("index greater than count of data\n");
        return;
    }
    if(c == 0) {
        add_begin(ptr);
        return;
    }
    i = 0;
    cur = *ptr;
    while(i < (c - 1)) {
        i++;
        cur=cur->next;
    }
    //create new node
    new = malloc(sizeof(struct Student));
    //scan data
    printf("Enter values for student\n");
    printf("Roll no : ");
    scanf("%d", &new->rollno);
    printf("Name : ");
    scanf(" %s", new->name);
    printf("Marks : ");
    scanf("%f", &new->marks);
    //update ptrs
    new->next = cur->next;
    cur->next = new;
    return;
}

void add_sorted(struct Student ** ptr) {
    struct Student * new, * cur;
    cur = *ptr;
    //check if data previously in sorted order
    while(cur) {
        if(cur->next != 0 && cur->rollno > cur->next->rollno) {
            printf("data is not sorted\n");
            return;
        }
        cur = cur->next;
    }
    //add data if already previously sorted
    //create new node
    new = malloc(sizeof(struct Student));
    //scan data
    printf("Enter values for student\n");
    printf("Roll no : ");
    scanf("%d", &new->rollno);
    printf("Name : ");
    scanf(" %s", new->name);
    printf("Marks : ");
    scanf("%f", &new->marks);
    cur = *ptr;
    //if no data or first record's rollno is higher
    if(cur == 0 || cur->rollno > new->rollno) {
        new->next = *ptr;
        *ptr = new;
        return;
    }
    //else 
    while(cur->next != 0 && cur->next->rollno < new->rollno){
        cur = cur->next;
    }
    new->next = cur->next;
    cur->next = new;
}

void print_data(const struct Student * ptr) {
    //check if data exist
    if(ptr == 0) {
        printf("No data to print\n");
    }
    // print header
    printf("Roll No\t|%10s\t|Marks\n","Name");
    // print data
    while(ptr) {
        printf("%7d\t|%10s\t|%f\n",ptr->rollno,ptr->name,ptr->marks);
        ptr = ptr->next;
    }
}

int count_nodes(const struct Student * ptr){
    int c = 0;
    while(ptr) {
        ptr = ptr->next;
        c++;
    }
    return c;
}

void save_file(const struct Student * ptr) {
    char a[20];
    FILE *fp;
    //get file name from user
    printf("Enter name of file : ");
    scanf("%s",a);
    //open file
    fp = fopen(a,"w");
    while(ptr) {
        fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
        ptr = ptr->next;
    }
    fclose(fp);
}

void read_file(struct Student ** ptr) {
    struct Student * new, *cur;
    char a[20], ans = 'a';
    FILE *fp;
    // get file from user
    printf("Enter name of file : ");
    scanf("%s",a);
    //open file
    fp = fopen(a,"r");
    // if data already exists ask user if want to include
    if(*ptr != 0) {
        printf("Data already exists would you want to append or rewrite a/r/n : ");
        scanf(" %c", &ans);
        switch(ans) {
            case 'a':
                break;
            case 'r':
                //delete all data if chosen r
                delete_all(ptr);
                break; 
            case 'n':
                return;
            default :
                printf("Invalid option\n");
                return;
        }
    }
    //if no data add 1st record
    if(*ptr == 0){
        //create new node
        new = malloc(sizeof(struct Student));
        //scan data
        if(fscanf(fp,"%d %s %f", &new->rollno, new->name, &new->marks) == -1){
            printf("No data");
            return;
        }
        *ptr = new;
        new->next = 0;
    }
    //now add at end by rotating till u reach end
    cur = *ptr;
    while(cur->next) {
        cur = cur->next;
    }
    //add all records
    while(1){
        // new node
        new = malloc(sizeof(struct Student));
        // scan data
        if(fscanf(fp,"%d %s %f", &new->rollno, new->name, &new->marks) == -1){
            //on failure to scan i.e. records end
            //point to 0
            cur->next = 0;
            //free new malloc
            free(new);
            break;
        }
        cur->next = new;
        cur = cur->next;
    }

}


void print_data_rec(const struct Student * ptr) {
    static int a = 1;
    if(a) {
        if(ptr == 0) {
            printf("No data to print\n");
            return;
        }
        printf("Roll No\t|%10s\t|Marks\n","Name");
        a = 0;
    }
    if(ptr == 0) {
        a = 1;
        return;
    }
    else {
        printf("%7d\t|%10s\t|%f\n",ptr->rollno,ptr->name,ptr->marks);
        print_data_rec(ptr->next);
    }
}

void print_data_rev_rec(const struct Student * ptr) {
    static int a = 1;
    if(a) {
        if(ptr == 0) {
            printf("No data to print\n");
            return;
        }
        printf("Roll No\t| %10s\t| Marks\n","Name");
        a = 0;
    }
    if(ptr == 0) {
        return;
    }
    else {
        print_data_rev_rec(ptr->next);
        printf("%7d\t|%10s\t| %f\n",ptr->rollno,ptr->name,ptr->marks);
        a = 1;
    }
}

void print_data_rev(const struct Student * ptr) {
    int c = count_nodes(ptr), i;
    const struct Student **p = malloc(c * sizeof(struct Student *));
    i = 0;
    while(ptr){
        p[i] = ptr;
        ptr = ptr->next;
        i++;
    }
    printf("Roll No\t| %10s\t| Marks\n","Name");
    for(i = c - 1; i >= 0;i--) {
        printf("%7d\t|%10s\t| %f\n",p[i]->rollno,p[i]->name,p[i]->marks);
    }
    free(p);
    /*
       another logic is using 2 for loops
       struct Student *p;
       int c = count_nodes(ptr);
       int i, j;
       printf("Roll No\t| %10s\t| Marks\n","Name");
       for(i = 0; i < c; i++) {
       p = ptr;
       for(j = 0; j < c - i - 1;j++) {
       p = p->next;
       }
       printf("%7d\t|%10s\t| %f\n",p->rollno,p->name,p->marks);
       }

     */
}

void delete_all(struct Student ** ptr) {
    struct Student *cur, *temp;
    cur = *ptr;
    while(cur) {
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    *ptr = 0;
}

void delete_node(struct Student ** ptr) {
    int cmax = count_nodes(*ptr), c, i;
    struct Student *cur, *temp;
    //take input from user where you want to delete
    printf("count = %d\n", cmax);
    if(cmax == 0) {
        printf("No data to delete");
        return;
    }
    printf("Enter index where you want to delete data : ");
    scanf("%d",&c);
    if(c>=cmax) {
        printf("Invalid index");
        return;
    }
    //if we have to delete first
    if(c == 0) {
        cur = *ptr;
        cur = cur->next;
        free(*ptr);
        *ptr = cur;
    }
    else {
        // rotate till index
        i = 0;
        cur = *ptr;
        while(i < (c - 1)) {
            i++;
            cur=cur->next;
        }
        // modify ptrs to delete data
        temp = cur;
        cur = cur->next;
        temp->next = cur->next;
        //free cur
        free(cur);
    }
}

void search_node(const struct Student * ptr) {
    const struct Student *cur;
    int rollno, c;
    printf("Enter roll no to search for : ");
    scanf("%d", &rollno);
    cur = ptr;
    c = 0;
    while(cur != 0 && cur->rollno != rollno){
        cur = cur->next;
        c++;
    }
    if(cur == 0) {
        printf("Roll no not found\n");
        return;
    }
    printf("Rollno found at index %d\nData : Roll No %d, Name %s, Marks %f", c,cur->rollno,cur->name, cur->marks);

}

void sort_nodes(struct Student ** ptr) {
    struct Student *p ,*cur, *n;
    int flag;
    if(*ptr == 0) {
        printf("No data\n");
        return;
    }
    while(1) {
        flag = 0;
        p = *ptr;
        cur = p->next;
        if(cur != 0 && p->rollno > cur->rollno) {
            flag = 1;
            n = cur->next;
            cur->next = p;
            p->next = n;
            *ptr = cur;
        }
        p = *ptr;
        cur = p->next;
        while(cur) {
            if(cur->next != 0 && cur->rollno > cur->next->rollno) {
                 flag = 1;
                 n = cur->next->next;
                 p->next = cur->next;
                 cur->next->next = cur;
                 cur->next = n;
            }
            p = p->next;
            cur = p->next;
        }
        if(flag == 0) {
            return;
        }
    }
}

void reverse_links(struct Student ** ptr) {
    struct Student *cur, *curr, *temp;
    cur = *ptr;
    curr = cur->next;
    cur->next = 0;
    while(curr){
        temp = curr->next;
        curr->next = cur;
        cur = curr;
        curr = temp;
    }
    *ptr = cur;
}
