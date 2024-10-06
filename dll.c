#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Employee structure
typedef struct Employee {
    int SSN;
    char Name[50];
    char Department[50];
    char Designation[50];
    float Salary;
    long PhNo;
    struct Employee* prev;
    struct Employee* next;
} Employee;

typedef struct Head {
    int count;
    struct Employee* llink;
    struct Employee* rlink;
} HEAD;

// Function prototypes
void insfront(HEAD* head);
void insrear(HEAD* head);
void delfront(HEAD* head);
void delrear(HEAD* head);
void display(HEAD* head);
Employee* createEmployee(int SSN, const char* Name, const char* Department, const char* Designation, float Salary, long PhNo);

int main() {
    int ch;
    HEAD* head = (HEAD*)malloc(sizeof(HEAD));
    head->count = 0;
    head->llink = NULL;
    head->rlink = NULL;

    for (;;) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insfront(head);
                break;
            case 2:
                insrear(head);
                break;
            case 3:
                if (head->rlink == NULL)
                    printf("List Empty\n");
                else
                    delfront(head);
                break;
            case 4:
                if (head->rlink == NULL)
                    printf("List Empty\n");
                else
                    delrear(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// Insert at the front
void insfront(HEAD* head) {
    int SSN;
    char Name[50], Department[50], Designation[50];
    float Salary;
    long PhNo;

    printf("Enter details such as SSN Name Department Designation Salary PhNo: ");
    scanf("%d %s %s %s %f %ld", &SSN, Name, Department, Designation, &Salary, &PhNo);

    Employee* newEmployee = createEmployee(SSN, Name, Department, Designation, Salary, PhNo);

    newEmployee->next = head->rlink;
    if (head->rlink != NULL) {
        head->rlink->prev = newEmployee;
    }
    newEmployee->prev = NULL;
    head->rlink = newEmployee;

    if (head->llink == NULL) {
        // If the list was empty
        head->llink = newEmployee;
    }

    head->count++;
    printf("Inserted at the front successfully.\n");
}

// Insert at the rear
void insrear(HEAD* head) {
    int SSN;
    char Name[50], Department[50], Designation[50];
    float Salary;
    long PhNo;

    printf("Enter details such as SSN Name Department Designation Salary PhNo: ");
    scanf("%d %s %s %s %f %ld", &SSN, Name, Department, Designation, &Salary, &PhNo);

    Employee* newEmployee = createEmployee(SSN, Name, Department, Designation, Salary, PhNo);

    newEmployee->prev = head->llink;
    if (head->llink != NULL) {
        head->llink->next = newEmployee;
    }
    newEmployee->next = NULL;
    head->llink = newEmployee;

    if (head->rlink == NULL) {
        // If the list was empty
        head->rlink = newEmployee;
    }

    head->count++;
    printf("Inserted at the rear successfully.\n");
}

// Delete from the front
void delfront(HEAD* head) {
    Employee* temp = head->rlink;

    if (head->rlink == head->llink) {
        // Only one node in the list
        head->rlink = NULL;
        head->llink = NULL;
    } else {
        head->rlink = temp->next;
        temp->next->prev = NULL;
    }

    free(temp);
    head->count--;
    printf("Deleted from the front successfully.\n");
}

// Delete from the rear
void delrear(HEAD* head) {
    Employee* temp = head->llink;

    if (head->rlink == head->llink) {
        // Only one node in the list
        head->rlink = NULL;
        head->llink = NULL;
    } else {
        head->llink = temp->prev;
        temp->prev->next = NULL;
    }

    free(temp);
    head->count--;
    printf("Deleted from the rear successfully.\n");
}

// Display the list
void display(HEAD* head) {
    if (head->rlink == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Total number of records are %d\n", head->count);
    printf("Data in the list:\n");

    Employee* current = head->rlink;

    while (current != NULL) {
        printf("SSN: %d, Name: %s, Department: %s, Designation: %s, Salary: %.2f, PhNo: %ld\n",
               current->SSN, current->Name, current->Department, current->Designation, current->Salary, current->PhNo);
        current = current->next;
    }

    printf("\n");
}

// Helper function to create an Employee node
Employee* createEmployee(int SSN, const char* Name, const char* Department, const char* Designation, float Salary, long PhNo) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->SSN = SSN;
    strcpy(newEmployee->Name, Name);
    strcpy(newEmployee->Department, Department);
    strcpy(newEmployee->Designation, Designation);
    newEmployee->Salary = Salary;
    newEmployee->PhNo = PhNo;
    newEmployee->prev = NULL;
    newEmployee->next = NULL;

    return newEmployee;
}
