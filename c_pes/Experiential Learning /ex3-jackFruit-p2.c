#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;          // coefficient
    int power;         // power of x
    struct node* next;
};

struct node* createNode(int data, int power);
struct node* addPolynomials(struct node* poly1, struct node* poly2);
void printPolynomial(struct node* poly);

int main() {
    // Polynomial 1: 5x^3 + 4x^2 + 2x^1
    struct node* poly1 = createNode(5, 3);
    poly1->next = createNode(4, 2);
    poly1->next->next = createNode(2, 1);

    // Polynomial 2: 5x^2 + 5x^1 + 5x^0
    struct node* poly2 = createNode(5, 2);
    poly2->next = createNode(5, 1);
    poly2->next->next = createNode(5, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct node* result = addPolynomials(poly1, poly2);

    printf("Result: ");
    printPolynomial(result);

    return 0;
}

// Create node
struct node* createNode(int data, int power) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Add polynomials
struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node dummy;
    dummy.next = NULL;
    struct node* tail = &dummy;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power == poly2->power) {
            int sum = poly1->data + poly2->data;
            if (sum != 0) {
                tail->next = createNode(sum, poly1->power);
                tail = tail->next;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->power > poly2->power) {
            tail->next = createNode(poly1->data, poly1->power);
            tail = tail->next;
            poly1 = poly1->next;
        }
        else {
            tail->next = createNode(poly2->data, poly2->power);
            tail = tail->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        tail->next = createNode(poly1->data, poly1->power);
        tail = tail->next;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        tail->next = createNode(poly2->data, poly2->power);
        tail = tail->next;
        poly2 = poly2->next;
    }

    return dummy.next;
}

void printPolynomial(struct node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->data, poly->power);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

