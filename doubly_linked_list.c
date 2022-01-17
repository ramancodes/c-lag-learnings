#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void printlist(struct node *head) //printinglist
{
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *ptr = head;
        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n\n");
    }
}

void printlistrev(struct node *head) //printinglist
{
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->prev;
        }
        printf("NULL\n\n");
    }
}

struct node *create(struct node *head, int data) //creating a node
{
    head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = data;
    head->next = NULL;
    return head;
}

struct node *add_at_beg(struct node *head, int data) // addition at the begnning
{
    struct node *temp = create(temp, data);

    temp->next = head;
    head->prev = temp;

    head = temp;
    printf("\n");
    return head;
}

void add_at_end(struct node *head, int data) //addition at the end
{
    struct node *new = create(new, data);

    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new;
    new->prev = ptr;
    printf("\n");
}

struct node *add_at_pos(struct node *head, int data, int pos) // addition at any position
{
    struct node *temp = head;
    struct node *ptr = head;
    struct node *temp2 = NULL;
    struct node *new = NULL;
    int count = 0;

    if (pos == 1) // if addition at the 1st pos
    {
        new = create(new, data);
        new->next = head;
        head->prev = new;
        head = new;
        printf("\n");
        return head;
    }

    while (ptr != NULL) // count of elements
    {
        count++;
        ptr = ptr->next;
    }

    if (pos > (count + 1)) // if the position is +1 more than the no of elements
    {
        printf("No of elements in the list = %d\n\n", count);
        return head;
    }

    pos--;
    while (pos != 1) // traversing to the required pos
    {
        temp = temp->next;
        pos--;
    }

    if (temp->next == NULL) // addition at the last position
    {
        new = create(new, data);
        temp->next = new;
        new->prev = temp;
    }
    else // addition at a pos
    {
        new = create(new, data);
        temp2 = temp->next;
        temp->next = new;
        new->prev = temp;
        new->next = temp2;
        temp2->prev = new;
    }

    printf("\n");
    return head;
}

struct node *del_at_beg(struct node *head) // delete the first node
{
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    printf("The first node is deleted\n");
    return head;
}

void del_at_end(struct node *head) // delete the last node
{
    struct node *ptr = head;
    struct node *temp = NULL;
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp = ptr->prev;
        free(ptr);
        ptr = NULL;
        temp->next = NULL;
        printf("The last node is deleted\n");
    }
}

struct node *del_at_pos(struct node *head, int pos) // delete at any position
{
    struct node *ptr = head;
    struct node *temp = head;
    struct node *temp2 = NULL;
    int count = 0;

    if (head == NULL) // the list is empty
    {
        printf("The list is empty\n");
        return head;
    }

    if (pos == 1) // the pos is the first node
    {
        if (head->next == NULL) // if there is only one node
        {
            free(head);
            head = NULL;
        }
        else
        {
            head = head->next;
            free(head->prev);
            head->prev = NULL;
        }
        printf("The first node is deleted\n");
        return head;
    }

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    if (pos > count) // if the position is greater than the no of elements
    {
        printf("No of elements in the list = %d\n\n", count);
        return head;
    }

    while (pos != 1) // traversing to the required pos
    {
        temp = temp->next;
        pos--;
    }

    if (temp->next == NULL) // delete the last node
    {
        temp2 = temp->prev;
        free(temp);
        temp = NULL;
        temp2->next = NULL;
    }
    else    // delete at any position
    {
        temp2 = temp->next;
        temp = temp->prev;
        free(temp->next);
        temp->next = temp2;
        temp2->prev = temp;
    }
    printf("The node is deleted\n");
    return head;
}

struct node *reverse_list(struct node *head)    //reversing the list
{
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2!=NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }

    head = ptr1;
    printf("The list is reversed\n");
    return head;
}

void choose_operation() // operations of doubly linked list
{
    struct node *head = NULL;
    int val, choice, pos;
    char ch;

    do
    {
        printf("Enter your option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value of first node\n");
            scanf("%d", &val);
            head = create(head, val);
            printf("\n");
            break;
        case 2:
            printlist(head);
            break;
        case 3:
            printlistrev(head);
            break;
        case 4:
            do
            {
                printf("Enter the value the node\n");
                scanf("%d", &val);
                head = add_at_beg(head, val);
                getchar();
                printf("Do you want to add more(y/n)? : ");
                scanf("%c", &ch);
            } while (ch != 'n');
            printf("\n");
            break;
        case 5:
            do
            {
                printf("Enter the value the node\n");
                scanf("%d", &val);
                add_at_end(head, val);
                getchar();
                printf("Do you want to add more(y/n)? : ");
                scanf("%c", &ch);
            } while (ch != 'n');
            printf("\n");
            break;
        case 6:
            do
            {
                printf("Enter the value the node\n");
                scanf("%d", &val);
                printf("Enter the location of the node to be inserted\n");
                scanf("%d", &pos);
                add_at_pos(head, val, pos);
                getchar();
                printf("Do you want to add more(y/n)? : ");
                scanf("%c", &ch);
            } while (ch != 'n');
            printf("\n");
            break;
        case 7:
            head = del_at_beg(head);
            printf("\n");
            break;
        case 8:
            del_at_end(head);
            printf("\n");
            break;
        case 9:
            printf("Enter the location of the node to be inserted\n");
            scanf("%d", &pos);
            head = del_at_pos(head, pos);
            printf("\n");
            break;
        case 10:
            head = reverse_list(head);
            printf("\n");
            break;
        default:
            if (choice == 0)
            {
                printf("Successfully exited!\n");
            }
            else
            {
                printf("Enter the correct option\n");
            }
            break;
        }
    } while (choice != 0);
}

int main()
{
    printf("Choose from the following\n");
    printf("1. Create Node\n");
    printf("2. Display the nodes\n");
    printf("3. Display the nodes in reverse order\n");
    printf("4. Insert at the begnning\n");
    printf("5. Insert at the end\n");
    printf("6. Insert at any position\n");
    printf("7. Delete the first node\n");
    printf("8. Delete the last node\n");
    printf("9. Delete node at a position\n");
    printf("10. Reverse the list\n");
    printf("0. Exit\n");

    choose_operation();
    return 0;
}