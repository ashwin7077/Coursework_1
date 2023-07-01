#include <stdio.h>
#include <string.h>

// Function prototypes
void addCredential(const char *fileName);
void searchCredential(const char *fileName);
void displayCredentials(const char *fileName);
void design();

// Function to store a credential in the file
void addCredential(const char *fileName) 
{
    system("cls");
    char website[100];
    char email[50];
    char password[50];
    char a;

    design();design();design();
    printf("\n\t\tCREDENTIAL STORE\n");
    design();design();design();
    printf("\nEnter website: ");
    fgets(website, 100, stdin);
    website[strcspn(website, "\n")] = '\0';

    printf("Enter email: ");
    fgets(email, 50, stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = '\0';

    FILE *file = fopen(fileName, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s|%s|%s\n", website, email, password);
    fclose(file);

    printf("\nCredential stored successfully.\n");
    printf("Enter any character : ");
    scanf("%c",&a);
}

// Function to search for a credential by website
void searchCredential(const char *fileName) 
{
    system("cls");
    char website[100];
    char a;
    int i=0;

    design();design();design();
    printf("\n\t\tSEARCH\n");
    design();design();design();
    printf("\nEnter website to search for password: ");
    fgets(website, 100, stdin);
    website[strcspn(website, "\n")] = '\0'; 

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char currWebsite[100];
    char email[50];
    char password[50];
    int found = 0;

        while (fscanf(file, "%[^|]|%[^|]|%[^\n]\n", currWebsite, email, password) == 3) 
        {
            if (strcmp(website, currWebsite) == 0) 
            {
                printf("\nWebsite: %s\nEmail: %s\nPassword: %s\n", currWebsite, email, password);
                found = 1;
                break;
            }
        }
    

    if (!found) {
        printf("\nNo password found for the given website.\n");
    }

    fclose(file);
    printf("\nEnter any character : ");
    scanf("%c",&a);
}

// Function to display all credentials
void displayCredentials(const char *fileName) {
    char a;
    system("cls");
    design();design();design();
    printf("\n\t\tDISPLAYING ALL CREDENTIALS\n");
    design();design();design();
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char website[100];
    char email[50];
    char password[50];

    printf("\nStored credentials:\n");
    while (fscanf(file, "%[^|]|%[^|]|%[^\n]\n", website, email, password) == 3) {
        printf("Website: %s\nEmail: %s\nPassword: %s\n\n", website, email, password);
    }

    fclose(file);
    printf("Enter any character : ");
    scanf("%c",&a);
}

// Adding design to the output
void design()
{
    printf(".......................");
}

int main() {
    system("cls");
    char fileName[100];

    printf("Enter the name of file where to store data or already stored: ");
    fgets(fileName, 100, stdin);
    fileName[strcspn(fileName, "\n")] = '\0'; 

    while (1) {
        system("cls");
        int choice;
        design();design();design();
        printf("\n\t\tWELCOME TO THE PASSWORD MANAGER\n");
        design();design();design();
        printf("\n1. Add a credential\n2. Search password by website\n3. Display all credentials\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addCredential(fileName);
                break;
            case 2:
                searchCredential(fileName);
                break;
            case 3:
                displayCredentials(fileName);
                break;
            case 4:
                printf("\nExiting the program.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
