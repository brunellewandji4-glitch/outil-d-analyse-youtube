#include <stdio.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void supprimer_occurrences(Node** head, int val) {
    Node *temp, *prev = NULL;
    while (*head && (*head)->data == val) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    Node* curr = *head;
    while (curr) {
        if (curr->data == val) {
            temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            free(temp);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}
void inserer_triee(Node** head, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!*head || (*head)->data >= val) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next && curr->next->data < val)
        curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
}
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

void inserer_triee_double(DNode** head, int val) {
    DNode* newNode = malloc(sizeof(DNode));
    newNode->data = val;
    newNode->next = newNode->prev = NULL;
    if (!*head || (*head)->data >= val) {
        newNode->next = *head;
        if (*head) (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    DNode* curr = *head;
    while (curr->next && curr->next->data < val)
        curr = curr->next;
    newNode->next = curr->next;
    if (curr->next) curr->next->prev = newNode;
    curr->next = newNode;
    newNode->prev = curr;
}
void inserer_tete_circulaire(Node** last, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    if (!*last) {
        newNode->next = newNode;
        *last = newNode;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
    }
}

void inserer_queue_circulaire(Node** last, int val) {
    inserer_tete_circulaire(last, val);
    *last = (*last)->next;
}
void inserer_tete_double_circulaire(DNode** last, int val) {
    DNode* newNode = malloc(sizeof(DNode));
    newNode->data = val;
    if (!*last) {
        newNode->next = newNode->prev = newNode;
        *last = newNode;
    } else {
        DNode* first = (*last)->next;
        newNode->next = first;
        newNode->prev = *last;
        first->prev = newNode;
        (*last)->next = newNode;
    }
}

void inserer_queue_double_circulaire(DNode** last, int val) {
    inserer_tete_double_circulaire(last, val);
    *last = (*last)->next;
}