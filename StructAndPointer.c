#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Contact data
struct Contact
{
    char name[50];
    char mobile_number[15];
    char office_number[15];
    char email[50];
    char company_name[50];
    struct Contact *next; // Pointer to the next Contact in the linked list
};

// Function to create a new Contact and return a pointer to it
struct Contact *createContact()
{
    struct Contact *contact = (struct Contact *)malloc(sizeof(struct Contact));
    if (contact == NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", contact->name);
    printf("Enter Mobile Number: ");
    scanf("%s", contact->mobile_number);
    printf("Enter Office Number: ");
    scanf("%s", contact->office_number);
    printf("Enter Email: ");
    scanf("%s", contact->email);
    printf("Enter Company Name: ");
    scanf(" %[^\n]", contact->company_name);

    contact->next = NULL; // Set the pointer to NULL

    return contact;
}

// Function to display Contact data
void displayContact(const struct Contact *contact)
{
    printf("==================Displaying Contact Data==================\n");
    printf("Name: %s\n", contact->name);
    printf("Mobile Number: %s\n", contact->mobile_number);
    printf("Office Number: %s\n", contact->office_number);
    printf("Email: %s\n", contact->email);
    printf("Company Name: %s\n", contact->company_name);
}

// Function to remove a Contact from the linked list and return a pointer to the previous Contact (or NULL if at the beginning)
struct Contact *removeContact(struct Contact *head, struct Contact *target)
{
    if (head == NULL)
    {
        printf("No Contact data to remove.\n");
        return NULL;
    }

    struct Contact *current = head;
    struct Contact *prev = NULL;

    while (current != NULL)
    {
        if (current == target)
        {
            if (prev == NULL)
            {
                // If the target is the first element
                head = current->next;
            }
            else
            {
                // If the target is not the first element
                prev->next = current->next;
            }
            free(current);
            printf("Contact data removed successfully.\n");
            return head; // Return the pointer to the head which may have changed
        }
        prev = current;
        current = current->next;
    }

    printf("Contact data not found.\n");
    return head;
}

// Function to clean up all memory associated with the Contact linked list
void removeAllContacts(struct Contact *head)
{
    while (head != NULL)
    {
        struct Contact *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to clear the screen
void clearScreen()
{
    printf("\033[H\033[J");
}

int main()
{
    struct Contact *head = NULL; // Pointer to the head of the Contact linked list
    int menu;

    printf("=================Contact Data Management=================\n");

    for (;;)
    {
        printf("\nMenu:\n");
        printf("1. Add Contact Data\n");
        printf("2. Display Contact Data\n");
        printf("3. Remove Contact Data\n");
        printf("4. Exit\n");
        printf("Choose a menu: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
        {
            struct Contact *newContact = createContact();
            if (head == NULL)
            {
                head = newContact;
            }
            else
            {
                struct Contact *current = head;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = newContact;
            }
        }
        break;
        case 2:
        {
            clearScreen(); // Clear the screen
            struct Contact *current = head;
            while (current != NULL)
            {
                displayContact(current);
                current = current->next;
            }
        }
        break;
        case 3:
        {
            if (head != NULL)
            {
                char nameToRemove[50];
                printf("Enter the name of the Contact to remove: ");
                scanf(" %[^\n]", nameToRemove);

                struct Contact *current = head;
                struct Contact *prev = NULL;
                int found = 0;

                while (current != NULL)
                {
                    if (strcmp(current->name, nameToRemove) == 0)
                    {
                        head = removeContact(head, current);
                        found = 1;
                        break;
                    }
                    prev = current;
                    current = current->next;
                }

                if (!found)
                {
                    printf("Contact not found.\n");
                }
            }
            else
            {
                printf("No Contact data to remove.\n");
            }
        }
        break;
        case 4:
            removeAllContacts(head);
            printf("Thank you! \n");
            return 0;
        default:
            printf("Invalid menu. Please choose another menu.\n");
            break;
        }
    }
}
