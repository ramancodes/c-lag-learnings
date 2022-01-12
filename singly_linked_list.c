#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printlist(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("\nThe linked list is empty\n\n");
    }
    else
    {
        printf("\nThe elements are\n");
        while (ptr != NULL)
        {
            printf("| %d |-> ", ptr->data);
            ptr = ptr->next;
        }
        if(ptr==NULL)
        {
            printf("| NULL |");
        }
        printf("\n");
    }
}

struct node *creation(struct node *head, int data)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    printf("\n");
    return head;
}

void insert_at_beg(struct node **head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = *head;
    *head = new;
    printf("\n");
}

struct node *insert_at_end(struct node *ptr, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    ptr->next = new;
    printf("\n");
    return new;
}

void insert_at_pos(struct node *head, int pos, int data)
{
    struct node *temp = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }

    new->next = temp->next;
    temp->next = new;
    printf("\n");
}

struct node *del_at_beg(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    printf("The first node is deleted\n\n");
    return head;
}

struct node *del_at_end(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n\n");
        printf("\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        printf("The last node is deleted\n\n");
        return NULL;
    }

    struct node *second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    free(second_last->next);

    second_last->next = NULL;

    printf("The last node is deleted\n\n");
    return second_last;
}

void del_at_pos(struct node **head, int pos)
{
    struct node *curr = *head;
    struct node *prev = *head;

    if (*head == NULL)
    {
        printf("The list is empty\n\n");
    }
    else if (pos == 1)
    {
        *head = curr->next;
        free(curr);
        curr = NULL;
    }
    else
    {
        while (pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        free(curr);
        curr = NULL;
    }
    printf("The node is deleted\n\n");
}

struct node *del_list(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }
    printf("\nThe list is deleted\n\n");
    return head;
}

void search_in_list(struct node *head, int search_data)
{
    struct node *ptr = head;
    int flag = 0;
    while (ptr != NULL)
    {
        if (search_data == ptr->data)
        {
            printf("\nThe data item %d is availale in the list\n\n", ptr->data);
            flag = 1;
        }
        ptr = ptr->next;
    }
    if (flag == 0)
    {
        printf("\nThe data item %d is not availble in the list\n\n", search_data);
    }
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    head = prev;
    printf("The list is revesed\n");

    return head;
}

struct node *move_to_front(struct node *head)
{
    struct node *prev = NULL, *next = head;
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else if (head->next == NULL)
    {
        printf("There is only one node in the list\n");
    }
    else
    {
        while (next->next != NULL)
        {
            prev = next;
            next = next->next;
        }
        prev->next = NULL;
        next->next = head;
        head = next;

        printf("The last element is moved to the front\n");
    }

    return head;
}

int main()
{
    struct node *head = NULL;
    struct node *ptr = NULL;
    int choose, val, pos, flag = 0;
    char op;
    do
    {
        if (flag == 0)
        {
            printf("Do you want to create a list (y/n)\n");
            scanf("%c", &op);
        }
        if (op == 'y' && flag == 0)
        {
            printf("Enter the first element\n");
            scanf("%d", &val);
            head = creation(head, val);
            ptr = head;
            flag = 1;
        }
        else if (op != 'y' && op != 'n')
        {
            printf("Enter the correct option\n\n");
        }
        else if (flag == 1)
        {
            printf("Choose from the following operations\n");
            printf("1. Display the list\n");
            printf("2. Seach data in the list\n");
            printf("3. Insert at the begning\n");
            printf("4. Insert at the end\n");
            printf("5. Insert at any pos\n");
            printf("6. Delete the last node\n");
            printf("7. Delete the first node\n");
            printf("8. Delete at any pos\n");
            printf("9. Delete the list\n");
            printf("10. Reverse the list\n");
            printf("11. Move the last element to front\n");
            printf("0. Exit\n");

            do
            {
                printf("Enter your choice : ");
                scanf("%d", &choose);
                switch (choose)
                {
                case 1:
                    printlist(head);
                    break;

                case 2:
                    printf("Enter the data you want to search\n");
                    scanf("%d", &val);
                    search_in_list(head, val);
                    break;

                case 3:
                    printf("Enter the element\n");
                    scanf("%d", &val);
                    insert_at_beg(&head, val);
                    break;

                case 4:
                    printf("Enter the element\n");
                    scanf("%d", &val);
                    ptr = insert_at_end(ptr, val);
                    break;

                case 5:
                    printf("Enter the position where you want to insert\n");
                    scanf("%d", &pos);
                    printf("Enter the element\n");
                    scanf("%d", &val);
                    insert_at_pos(head, pos, val);
                    break;

                case 6:
                    ptr = del_at_end(head);
                    break;

                case 7:
                    head = del_at_beg(head);
                    break;

                case 8:
                    printf("Enter the position where you want to delete\n");
                    scanf("%d", &pos);
                    del_at_pos(&head, pos);
                    break;

                case 9:
                    head = del_list(head);
                    break;

                case 10:
                    head = reverse(head);
                    break;

                case 11:
                    head = move_to_front(head);
                    break;

                default:
                    if (choose > 11)
                    {
                        printf("Wrong Input\n");
                    }
                    break;
                }
            } while (choose != 0);
            if (choose == 0)
            {
                printf("Successfully exited!\n");
                head = del_list(head);
                flag = 0;
            }
        }
        getchar();
    } while (op != 'n');
    if (op == 'n')
    {
        printf("\nSuccessfully Excited\nThank You!\n");
    }
    return 0;
}