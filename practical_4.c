#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Insert a node at the beginning
void insertBeginning(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;

    if (last == NULL)
    {
        // First node
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }

    printf("%d inserted successfully\n", value);
}

// Insert a node at the end
void insertEnd(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;

    if (last == NULL)
    {
        // First node
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("%d inserted successfully\n", value);
}

// Delete a node from the beginning
void deleteBeginning()
{
    struct Node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    // Only one node
    if (temp == last)
    {
        last = NULL;
    }
    else
    {
        last->next = temp->next;
    }

    printf("%d deleted successfully\n", temp->data);
    free(temp);
}

// Delete a node from the end
void deleteEnd()
{
    struct Node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Only one node
    if (last->next == last)
    {
        printf("%d deleted successfully\n", last->data);
        free(last);
        last = NULL;
        return;
    }

    temp = last->next;

    // Find the node before last
    while (temp->next != last)
    {
        temp = temp->next;
    }

    temp->next = last->next;

    printf("%d deleted successfully\n", last->data);
    free(last);

    last = temp;
}

// Display the circular linked list
void display()
{
    struct Node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
