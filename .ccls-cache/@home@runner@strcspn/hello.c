llist_add(LinkedList * list, int value) {
  ListNode * n;
  n->value = value;

  n->next = list->head;
  list->head = n;
  
}

llist_exists(LinkedList * list, int value) {
  ListNode *n;
  n = list->head;

  while(n != NULL) {
    if(n->value == value) {
      return 1;
    }
    n = n->next;
  }
}
llist_remove(LinkedList * list, int value) {
  ListNode *n;
  ListNode *temp;
  n = list->head;
  temp = NULL;

  while(n != NULL) {
    if(n->value == value){
      if(n == list->head) {
        list->head = list->head->next;
      } else {
            temp->next = n->next;
      }
    }
    temp = n;
    n = n->next;
  }
}

llist_get_ith(LinkedList * list, int ith, int *value) {
  ListNode *n;
  n = list->head;
  int count =0;
  while(n!=NULL) {
    if(count == ith) {
      *value = n->value;
    }
    n = n->next;
    count++;
  }
}

llist_remove_ith(LinkedList * list, int ith){
  ListNode *n;
  ListNode *temp;
  n = list->head;
  temp = NULL;
  while(n!=NULL) {
    if(count == ith) {
      temp->next = n->next;
    }
    temp = n;
    n = n->next;
    count++;
  }
}

llist_sort(LinkedList * list, int ascending) {
  ListNode *n;
  ListNode *e;
  n = list->head;
  e = list->head;
  int temp;
  
  while(e!=NULL) {
    while(n!=NULL && n->next != NULL){
      if (n->value > n->next->value){
        temp = n->value;
        n->value = n->next->value;
        n->next->value = temp;
      }
      n = n->next;
    }
    e = e->next;
  }
  llist_remove_first(LinkedList * list, int * value) {
    ListNode *n = malloc;
    n = list->head;
    *value = n->value;
    list->head = list->head->next;
    free(n);
    
  }
  llist_remove_last(LinkedList * list, int *value) {
    ListNode *n;
    n = list->head;

    while(n->next->next !=NULL) {
      n = n->next;
    }
    ListNode *last = n->next;
    *value = last->value;
    n->next = NULL;
    free(last);
  }
  llist_insert_first(LinkedList * list, int value){
    ListNode *n;
    n->value = value;
    n->next = list->head;
    list->head = n;
  }
  llist_insert_last(LinkedList * list, int value) {
    ListNode *n = malloc;
    n->value = value;
    n->next = NULL;

    if(list->head == NULL){
      list->head = n;
    }else {
      ListNode *last;
      last = list->head;
      while(last->next!= NULL) {
        last = last->next;
      }
      last->next = n;
    }
  }
  llist_clear(LinkedList *list) {
    ListNode *n;
    n = list->head;
    while(n!=NULL) {
      list->head = list->head->next;
      free(n);
      n = list->head;
    }
    
  }

  llist_read(LinkedList * list, char * file_name) {
    int content;
    FILE *file;
    file = fopen(file_name, "r");
    if(file == NULL){
      return 0;
    }

    while(fscanf(file,"%d",&content) !=EOF) {
      ListNode *n = malloc;
      n->value = content;
      n->next = list->head;
      list->head = n;
    }
  }

  llist_save(LinkedList * list, char * file_name) {
    
    FILE *file;
    file = fopen(file_name, "w");

    ListNode *n;
    n = list->head;
    if(file == NULL) {
      return 0;
    }
    while(n!= NULL) {
      fprintf(file,"%d\n",n->value);
      n=n->next;
    }
    fclose(file)
  }

  llist_reverse( LinkedList * list ) {
    ListNode *current;
    ListNode *prev;
    ListNode *after;
    current = list->head;
    prev = NULL;
    after = NULL;
    while(current != NULL) {
      after = current->next;
      current->next = prev;
      prev = current;
      current = after;
    }
    list->head = prev;
  }
}