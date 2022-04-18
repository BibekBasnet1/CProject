# include <stdio.h>
# include <stdlib.h>
# include <string.h>
void mainMenu();
void changeProduct();
void choose();
void buyProducts();
int productRate();
void deleteRecord();
void searchRecord();
int ifCodeIsThere(char[]);
void displayProducts();
# define USERNAME "bibek"
# define PASSWORD "*****"

struct items
{
    char prodCode[40];
    char prodName[40];
    int rate;
    int quantity;
    int total;
}item;
int main()
{
    // system("clear");
    mainMenu();
    return 0;
}

void mainMenu()
{
    char password[10],username[30];
    int n,i;
    char ch;
    n = 1;
    printf("\t\t\t\t\t\t\033[0;35mSasto Maal Departmental admin system\n");
    printf("\n");
    printf("\t\t\t\t\t|********************************************|\n");
    printf("\t\t\t\t\t|--------------------------------------------|\n");
    printf("\t\t\t\t\t\tPlease enter the username: ");
    scanf("%s",username);
    printf("\t\t\t\t\t\tPlease enter the password: ");
    scanf("%s",password);
    // for(i=0;i<8;i++)
    // {
    //     ch = getchar();
    //     password[i] = ch;
    //     ch = '*' ;
    //     printf("%c",ch);
    // }
    // printf("\t\t\t\t\t\t\033[0;35mSasto Maal Departmental admin system\n");
    printf("\n");
    printf("\t\t\t\t\t|********************************************|\n");
    printf("\t\t\t\t\t|--------------------------------------------|\n");
    while(n)
    {
        if ((strcmp(USERNAME, username)) == 0 && (strcmp(PASSWORD, password)) == 0)
        {
            printf("\033[0;32m");
            printf("\v");
            choose();            
        }
        else
        {
            system("clear");
            printf("\033[0;31m");
            printf("\t\t\t\tPlease enter the correct username and password!!\n");
            printf("\033[0;35m");
            printf("\t\t\t\t\tPlease try it again!!!\n");
            break;
        }
    }

}

void choose()
{
    int choice,number;
    printf("\t\t\t\t____Welcome to sasto maal departmental store____\n");
    printf("\v");
    printf("\t\t\t\033[0;31m|\t\t\tPress 1. \033[0;31m  To Add\t\t\t |\n");
    printf("\t\t\t|\t\t\tPress 2.   \033[0;31mTo Display\t\t\t |\n");
    printf("\t\t\t|\t\t\tPress 3.   \033[0;31mTo Delete\t\t\t |\n");
    printf("\t\t\t|\t\t\tPress 4.   \033[0;31mTo Exit  \t\t\t |\n");
    printf("\t\t\t|\t\t\tPress 5.   \033[0;31mTo Edit\t\t\t |\n");
    printf("\t\t\t|\t\t\tPress 6.   \033[0;31mTo Search\t\t\t |\n");
    printf("\v");
    printf("\t\t\t\033[0;36mEnter your choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
            system("clear");
            buyProducts();
            break;       

        case 2:
            system("clear");
            displayProducts();
            break;

        case 3:
            system("clear");
            deleteRecord();
            break;

        case 4:
            system("clear");
            printf("\v");
            printf("\t\t\t\t\t\t++++++System ended successfully+++++\n");
            printf("\t\t\t\t\t\t""   |___________________________|\n");
            printf("\t\t\t\t\t\t""   |---------------------------|\n");
            printf("\t\t\t\t\t\t""   |---------------------------|\n");
            printf("\t\t\t\t\t\t""   |---------------------------|\n");
            printf("\t\t\t\t\t\t""   |___________________________|\n");
            printf("\v\v");
            exit(0);

        case 5:
            // system("clear");
            changeProduct();
            break;
        
        case 6:
            searchRecord();
            break;

        default:
            printf("\t\t\t+++++++++++Please enter the valid choice++++++++++\n");
    }
}

void buyProducts()
{
    printf("\v\t\t\t\t\t-------Add Product-------\n");
    printf("\t\t\t\t\t_+_+_+_+_+_+_+_+_+_+_\n");
    FILE *fp;
    char code[40];
    int rate;
    int exist;
    fp = fopen("store.txt", "ab");
    printf("\n\t\t\t\t\tEnter the \" exit \" to exit");
    printf("\n\t\t\t\t\tEnter Product code: ");
    scanf("%s", code);
    // scanf("%s", x);
    if (strcmp(code, "exit") == 0)
    {
        system("clear");
        mainMenu();
    }
    exist = ifCodeIsThere(code);
    if (exist == 1)
    {
        system("clear");
        printf("\033[1;31m");
        printf("\n\v\t\t\t\t\t\tProduct already exists there.\n");
        printf("\033[0m");
        choose();
    }
    else
    {
    strcpy(item.prodCode,code);
    // printf("It will be stored in same code no.");
    printf("\t\t\t\t\tEnter Product Name: ");
    scanf("%s", item.prodName);
    printf("\n\t\t\t\t\tEnter Product Rate: ");
    rate = productRate();
    item.rate = rate;
    printf("\n\t\t\t\t\tEnter Quantity: ");
    scanf("%d", &item.quantity);
    item.total = item.rate * item.quantity;
    // writing structure to a file
    fwrite(&item, sizeof(item), 1, fp);
    fclose(fp);
    }
} 

int productRate()
{
    unsigned input;
    char ch;
    while (scanf("%u", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
        system("clear");
        printf("\033[1;31m");
        printf("\n\v\t\t\t\t\t\tRate cant be negative.\n");
        printf("\033[0m");
        printf("\t\t\t\t\tEnter rate  in positive integer: ");
        }
        // system("clear");
        // printf("\033[1;31m");
        // printf("\n\v\t\t\t\t\t\tRate cant be negative.\n");
        // printf("\033[0m");
        // printf("\t\t\t\t\tEnter rate  in positive integer: ");
    }

    return input;
}

void displayProducts()
{
    printf("\v\v\t\t\t\t\t----Sasto Maal ko saman haru----\n");
    printf("\t\t\t\t\t_+_+_+_+_+_+_+_+_+_+_+_+_+_+\n");
    FILE *fp;
    int count = 0;
    fp = fopen("store.txt", "rb");
    printf("\t------------------------------------------------------------------------------------------------------\n");
    printf("\tCODE\t||\tNAME\t\t||\tRATE\t||\tQUANTITY\t||\tTOTAL\n");
    printf("\t------------------------------------------------------------------------------------------------------\n");
    if (fp == NULL)
    {
        printf("\t\t\t\t=====There is no products currently added in it!=======\n");
        choose();
    }
    while (fread(&item, sizeof(item), 1, fp))
    {
        printf("\t%s\t||\t%s\t\t||\t%d\t||\t %d\t\t||\t%d\n",item.prodCode,item.prodName,item.rate,item.quantity,item.total);
        count++;
    }
    printf("\t------------------------------------------------------------------------------------------------------\n");
    if (count == 0)
    {
        system("clear");
        printf("\033[1;31m");
        printf("\n\v\t\t\t\t\t\t Product is not available.\n");
        printf("\033[0m");

    }
    fclose(fp);
}

void deleteRecord()
{
    FILE *fp1, *fp2;
    int i,len;
    char code[30], product[30];
    int valid;
    fp1 = fopen("store.txt", "rb");
    displayProducts();
    printf("\n\t\t\t\tEnter the Product code to delete: ");
    scanf("%s", code);
    system("clear");
    valid = ifCodeIsThere(code);
    if (valid == 0)
    {
        system("clear");
        printf("\033[1;31m");
        printf("\n\t\t\t\t------Product is not available---------\n");
        printf("\033[0m");
    }
    else
    {
        fp2 = fopen("temporary.txt", "wb");
        while (fread(&item, sizeof(item), 1, fp1))
        {
            strcpy(product, item.prodCode);
            if (strcmp(product, code) != 0)
            {
                fwrite(&item, sizeof(item), 1, fp2);
            }
        }
        fclose(fp1);
        fclose(fp2);
        fp1 = fopen("store.txt", "wb");
        fp2 = fopen("temporary.txt", "rb");
        while (fread(&item, sizeof(item), 1, fp2))
        {
            fwrite(&item, sizeof(item), 1, fp1);
        }
        printf("\n\v\t\t\t\t|+|+|+| Product deleted sucessfully!! |+|+|+|\n\n");
        fclose(fp1);
        fclose(fp2);
    }
}
void changeProduct()
{
    printf("\v\v\t\t\t\t\t\t\tChange Product\n");
    printf("\t\t\t\t\t\t************************\n");
    FILE *file1, *file2;
    char code[10], product[20];
    int available;
    printf("enter the Product code to edit the record:");
    scanf("%s",code);
    available = ifCodeIsThere(code);
    if (available == 0)
    {
        system("clear");
        printf("\033[1;31m");
        printf("\n\v\t\t\t\t\t\t\tProduct not found to update\n");
        printf("\033[0m");
    }
    else
    {
        file1 = fopen("store.txt", "rb");
        file2 = fopen("temporary.txt", "wb");
        while (fread(&item, sizeof(item), 1, file1))
        {
            strcpy(product, item.prodCode);
            if (strcmp(product, code) != 0)
            {
                fwrite(&item, sizeof(item), 1, file2);
            }
            else
            {
                printf("\n\t ***Making changes on previous product***%s\n", code);
                printf("enter Product Name: ");
                scanf("%s", item.prodName);
                printf("Enter Product Rate: ");
                scanf("%d", &item.rate);
                printf("Enter Quantity: ");
                scanf("%d", &item.quantity);
                printf("\n\n");
                fwrite(&item, sizeof(item), 1, file2);
            }
        }
        fclose(file1);
        fclose(file2);
        file1 = fopen("store.txt", "wb");
        file2 = fopen("temporary.txt", "rb");
        while (fread(&item, sizeof(item), 1, file2))
        {
            fwrite(&item, sizeof(item), 1, file1);
        }
        fclose(file1);
        fclose(file2);
    }
} 
// end.
void searchRecord()
{
    FILE *file;
    char code[10], product[20];
    int available;
    // printf("\v\t\t\t\t\tEnter \"end\" for back to menu.\n");
    printf("\v\t\t\t\t\tEnter the Product code to search: ");
    scanf("%s", code);
    if (strcmp(code, "exit") == 0)
    {
        system("clear");
        choose();
    }
    system("clear");
    printf("\v\v\t\t\t\t\t\tProduct information\n");
    printf("\t\t\t\t\t\t\t**********************\n");
    available = ifCodeIsThere(code);
    if (available == 0)
    {
        // system("clear");
        system("clear");
        printf("\033[1;31m");
        printf("\n\t\t\t\t\t\tProduct code is not found.\n");
        printf("\033[0m");
    }
    else
    {
        file = fopen("store.txt", "rb");
        while (fread(&item, sizeof(item), 1, file))
        {
            strcpy(product, item.prodCode);
            if (strcmp(product, code) == 0)
            {
                printf("\n\t\t\t\t\t\tProduct Code : %s", item.prodCode);
                printf("\n\t\t\t\t\t\tProduct Name : %s", item.prodName);
                printf("\n\t\t\t\t\t\tProduct Rate : %d", item.rate);
                printf("\n\t\t\t\t\t\tProduct quantity : %d", item.quantity);
                printf("\n\t\t\t\t\t\tTotal(in. Rs): %d", item.total);
            }
        }
        fclose(file);
    }
}
int ifCodeIsThere(char code[])
{
    FILE *fp;
    fp = fopen("store.txt", "r");
    while (!feof(fp))
    {
        fread(&item, sizeof(item), 1, fp);
        if (strcmp(code, item.prodCode) == 0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
