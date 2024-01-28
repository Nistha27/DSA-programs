#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE last = NULL;
NODE head = NULL;

NODE create() {
    int data;
    NODE snode;
    snode = (NODE) malloc(sizeof(struct node));
    if (snode ==  NULL) {
        printf("Insufficient Memory");
        exit(0);
    }
    return snode; // Return the newly created node
}

NODE insert_front() {
    NODE temp = create();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (head->link == head) {
        head->link = temp;
        temp->link = head;
        last = temp;
        return temp;
    }
    temp->link = head->link;
    head->link = temp;
    return temp;
}

NODE insert_end() {
    NODE temp = create(), cur;
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (head->link == head) {
        head->link = temp;
        temp->link = head;
        last = temp;
        return head;
    }
    cur = head->link;
    while (cur->link != head) { // Removed the extra semicolon
        cur = cur->link;
    }
    temp->link = cur->link;
    cur->link = temp;
    last = temp;
    return head;
}

NODE delete_front() {
    NODE temp;
    if (head->link == head) {
        printf("Linked List Empty");
        return head;
    }
    temp = head->link;
    if (head->link == last) {
        printf("Single Node deleted: %d", temp->data);
        free(last);
        last = NULL;
        head->link = head;
        return head;
    } 
    head->link = temp->link;
    printf("Node deleted of %d", temp->data);
    free(temp);
    return head;
}

NODE delete_end() {
    NODE cur, prev;
    if (head->link == head) {
        printf("Linked List empty");
        return NULL;
    }
    cur = head->link;
    if (head->link == last) {
        printf("Single node deleted %d", last->data);
        free(last);
        last = NULL;
        head->link = head;
        return NULL;
    }
    while (cur->link != head) { // Removed the extra semicolon
        prev = cur;
        cur = cur->link;
    }
    prev->link = cur->link;
    printf("Last node deleted %d", cur->data);
    free(cur);
    last = prev;
    return head;
}

void display() {
    NODE cur;
    if (head->link == head) {
        printf("Linked List empty");
        return;
    }
    cur = head->link;
    while (cur != head) {
        printf("Data %d\n", cur->data);
        cur = cur->link;
    }
}

int main() {
    int choice, item;
    head = create();
    head->link = head;
    for (;;) {
        printf("1: Insert_Front 2: Delete_Front\n");
        printf("3: Display 4: Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                head = insert_front();
                break;
            case 2:
                head = delete_front();
                break;
            case 3: 
                display(); 
                break;
            default:
                exit(0);
        }
    }
    return 0;
}

