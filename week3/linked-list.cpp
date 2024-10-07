#include<stdio.h>
#include<cstdlib>
#include<cstring>

struct node{
    int data; 
    struct node* next;
};

node* makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        // C++: cout << node->data;
        head = head->next;
    }
}

int count(node *head){
    int dem = 0;
    while(head != NULL){
        ++dem;
        head=head->next;
    }
    return dem;
}

void pushFront(node **head, int x){
    node* newNode = makeNode(x);
    newNode->next = (*head);
    (*head) = newNode;
}

void pushBack(node **head, int x){
    node* tmp = *head;
    node* newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void insert(node **head, int k, int x){
    int n = count(*head);
    if(k<1 || k>n+1) return;
    if(k==1){
        pushFront(head,x); return;
    }
    node *tmp = *head;
    for(int i=1;i<=k-2;i++){
        tmp = tmp->next;
    }
    node *newNode = makeNode(x);
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void popFront(node **head){
    if(*head == NULL) return;
    node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void popBack(node **head){
    if(*head == NULL) return;
    node *tmp = *head;
    if(tmp->next == NULL){
        *head = NULL;
        free(tmp);
        return;
    }
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    node *last = tmp->next;
    tmp->next = NULL;
    free(last);
}

void erase(node **head, int k){
    int n = count(*head);
    if(k<1 || k>n) return;
    if(k==1) popFront(head);
    else{
        node *tmp = *head;
        for(int i=1;i<=k-2;i++){
            tmp = tmp->next;
        }
        node *kth = tmp->next;
        tmp->next = kth->next;
        free(kth);
    }
}

node* reverse(node* head) {
    node *prev, *current, *next;
    prev = NULL;
    current = head;
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;
    }
    return prev; 
}

bool checkExist(node *head, int x){
    node* current = head;
    while(current){
        if(current->data==x) return true;
        current = current->next;
    }
    return false;
}

int findIndex(node* head, int x) {
    node* current = head;
    int index = 1;

    while (current != NULL) {
        if (current->data == x) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

int main(){
    node *head = NULL;
    int n, x;
    char s[20];
    char alast[]="addlast", afirst[]="addfirst", aafter[]="addafter",
    abefore[]="addbefore", rmv[]="remove", rverse[]="reverse", ex[]="#";
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        pushBack(&head,x);
    }
    while(1){
        scanf("%s", s);
        if(strcmp(s,alast)==0){
            scanf("%d", &x);
            if(checkExist(head,x)==false){
                pushBack(&head, x);
            }
        } else if(strcmp(s,afirst)==0){
            scanf("%d",&x);
            if(checkExist(head,x)==false){
                pushFront(&head,x);
            }
        } else if(strcmp(s,aafter)==0){
            scanf("%d", &x);
            int v; scanf("%d", &v);
            if(checkExist(head,x)==false && checkExist(head,v)==true){
                insert(&head,findIndex(head,v)+1,x);
            }
        } else if(strcmp(s,abefore)==0){
            scanf("%d", &x);
            int v; scanf("%d", &v);
            if(checkExist(head,x)==false && checkExist(head,v)==true){
                insert(&head,findIndex(head,v),x);
            }
        } else if(strcmp(s,rmv)==0){
            scanf("%d", &x);
            if(checkExist(head,x)==true){
                erase(&head,findIndex(head,x));
            }
        } else if(strcmp(s,rverse)==0){
            head=reverse(head);
        } else if(strcmp(s,ex)==0){
            duyet(head);
            return 0;
        }
    }
}
