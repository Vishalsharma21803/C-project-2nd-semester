#include <stdio.h>
#include <string.h>

// structure to store account information
struct account
{
    int account_number;
    char name[50];
    float balance;
    char password[20];
    char payee[50];
};

// function to display account status
void account_status(struct account acc)
{
    printf("Account Number: %d\n", acc.account_number);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

// function to open a new account
void account_opening(struct account *acc)
{
    printf("Enter account number: ");
    scanf("%d", &acc->account_number);
    printf("Enter name: ");
    scanf("%s", acc->name);
    printf("Enter initial balance: ");
    scanf("%f", &acc->balance);
    printf("Enter password: ");
    scanf("%s", acc->password);
}

// function to change account password
void change_password(struct account *acc)
{
    char old_password[20];
    printf("Enter current password: ");
    scanf("%s", old_password);
    if (strcmp(old_password, acc->password) == 0)
    {
        printf("Enter new password: ");
        scanf("%s", acc->password);
        printf("Password changed successfully!\n");
    }
    else
    {
        printf("Incorrect password, please try again.\n");
    }
}

// function to manage payees
void payee_management(struct account *acc)
{
    printf("Enter payee name: ");
    scanf("%s", acc->payee);
    printf("Payee added successfully!\n");
}

// function to view account statement
void view_statement(struct account acc)
{
    printf("Account Number: %d\n", acc.account_number);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
    printf("Payee: %s\n", acc.payee);
}

// main function
int main()
{
    int choice;
    struct account acc;
    printf("Welcome to Online Banking System\n");
    while (1)
    {
        printf("\n1. Account Status\n");
        printf("2. Account Opening\n");
        printf("3. Change Password\n");
        printf("4. Payee Management\n");
        printf("5. View Statement\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            account_status(acc);
            break;
        case 2:
            account_opening(&acc);
            break;
        case 3:
            change_password(&acc);
            break;
        case 4:
            payee_management(&acc);
            break;
        case 5:
            view_statement(acc);
            break;
        case 6:
            printf("Thank you for using our Online Banking System!\n");
            return 0;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    }
}