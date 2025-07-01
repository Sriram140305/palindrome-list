#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* insert(struct Node* head, char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void checkpalindrome(struct Node* head) {
    char str[100];
    int i = 0;

    struct Node* temp = head;
    while (temp) {
        str[i++] = temp->data;
        temp = temp->next;
    }
    str[i] = '\0';

    int len = strlen(str);
    int isPalin = 1;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            isPalin = 0;
            break;
        }
    }

    if (isPalin)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}

int main() {
    char input[100];
    scanf("%s", input);

    struct Node* head = NULL;

    for (int i = 0; input[i] != '\0'; i++) {
        head = insert(head, input[i]);
    }

    checkpalindrome(head);

    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *head = NULL;

// Global input and length
char input[100];
int n;

void insert(char in) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = in;
    newnode->next = head;
    head = newnode;
}

void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%c->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void checkpalindrome() {
    struct Node *temp = head;
    int isPalindrome = 0;
    for (int i = 0; i < n; i++) {
        if (input[i] == temp->data) {
            isPalindrome++;
            
        }
        temp = temp->next;
    }

    if (isPalindrome==n) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}

int main() {
    scanf("%s", input);
    n = strlen(input);
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        insert(input[i]);
    }

    display();
    checkpalindrome();
    return 0;
}
