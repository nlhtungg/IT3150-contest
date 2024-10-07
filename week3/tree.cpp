#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
    int id;
    struct Node *children[MAX_NODES];
    int childCount;
};

struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->childCount = 0;
    return newNode;
}

struct Node* getNode(struct Node* nodes[], int id) {
    if (nodes[id] == NULL) {
        nodes[id] = createNode(id);
    }
    return nodes[id];
}

void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->id);
    for (int i = 0; i < root->childCount; ++i) {
        preOrder(root->children[i]);
    }
}

void inOrder(struct Node* root) {
    if (root == NULL) return;
    if (root->childCount > 0) {
        inOrder(root->children[0]);
    }
    printf("%d ", root->id);
    for (int i = 1; i < root->childCount; ++i) {
        inOrder(root->children[i]);
    }
}

void postOrder(struct Node* root) {
    if (root == NULL) return;
    for (int i = 0; i < root->childCount; ++i) {
        postOrder(root->children[i]);
    }
    printf("%d ", root->id);
}

int main() {
    struct Node* nodes[MAX_NODES] = { NULL };
    char action[15];
    int u, v;

    struct Node* root = NULL;

    while (1) {
        scanf("%s", action);
        if (action[0] == '*') {
            break;
        } else if (action[0] == 'M') {
            scanf("%d", &u);
            root = getNode(nodes, u);
        } else if (action[0] == 'I' && action[1] == 'n' && action[2] == 's') {
            scanf("%d %d", &u, &v);
            struct Node* node_u = getNode(nodes, u);
            struct Node* node_v = getNode(nodes, v);
            int found = 0;
            for (int i = 0; i < node_v->childCount; ++i) {
                if (node_v->children[i]->id == u) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                node_v->children[node_v->childCount++] = node_u;
            }
        } else if (action[0] == 'P' && action[1] == 'r'){
            preOrder(root);
            printf("\n");
        } else if(action[0] == 'I' && action[1] == 'n' && action[2] == 'O'){
            inOrder(root);
            printf("\n");
        } else if(action[0] == 'P' && action[1] == 'o'){
            postOrder(root);
            printf("\n");
        }
    }
    return 0;
}
