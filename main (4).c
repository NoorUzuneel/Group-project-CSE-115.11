#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct information
{
    char title[1000], author[1000];
    char name[20];
    int id;
    int code;
};
void authorityscan(struct information *B);
void studentscan();
void welcomePage();
void mainPage();
void allscan();
void option(int a);
void wbook(struct information *B);
void rbook();
FILE* open_borrowed_books_list (int y);
void borrow_book(int x);
void loading();
void style();

int main()
{

    welcomePage();
    mainPage();

    return 0;
}
void welcomePage()
{
    style();
    printf("WELCOME TO LIBRARY SYSTEM\n");
    sleep (3);
    system("cls"); //use control+command+l instead for mac
}

void mainPage()
{
   // loading();
    style();
    printf("Please select your option from the list\n");
    printf("\n\t\t1. Authority\n");
    printf("\n\t\t2. Student\n");
    allscan();
}

void allscan()
{
    int x;
    printf("\n\n\t\tPlease Input your Option : ");
    scanf("%d", &x);
    option(x);
    fflush(stdin);
}

void option(int a)
{
    struct information A[1000];
    system("cls");
   // loading();
    if (a == 1)
    {
        authorityscan(A);
    }
    else if (a == 2)
    {
        studentscan();

    }
    else
    {
        printf("\nINVALID OPTION TRY AGAIN\n");
        void mainPage();
    }

}




void authorityscan(struct information *B)
{
    sleep(1);
    style();
    int i,x;
    fflush(stdin);
    printf("Enter your password : ");
    char password[15];
    gets(password);
    int flag = strcmp(password, "hello");
    //loading();
    if (flag == 0)
    {
        style();
        printf("Please select your option from the list\n");
        printf("\n\t\t1. Enter new student information\n");
        printf("\n\t\t2. View existing student information\n");
        printf("\n\t\t3. Enter new book\n");
        printf("\n\t\t4. View existing book list\n");
        printf("\n\nPlease input your option: ");
        int option;
        scanf("%d", &option);
        printf("\n\n");

        FILE *fp;

      {
        if (option == 1)
        {
            style();
            fp = fopen("STUDENT.txt","a");

             if(fp!=0)
         {
             system("cls");
             style();
             //sleep(1);
           printf("Enter number of students whose information you want to input: ");
           int number;
           scanf("%d", &number);

             for(i=0; i<number; i++)
             {
               fflush(stdin);
               printf("NAME : ");
               gets(B[i].name);
               printf("ID : ");
               scanf("%d",&B[i].id);
               printf("\n");

               fprintf(fp,"NAME : %s\t",B[i].name);
               fprintf(fp,"ID : %d\n", B[i].id);
           }
        }


    fclose(fp);

        }

        else if (option == 2)
        {
            system("cls");
            style();
            printf("STUDENT LIST :\n");
           fp = fopen("STUDENT.txt","r");
            while (1)
            {
                char a = fgetc(fp);
                if (a == EOF)
                {
                    break;
                }
                printf("%c", a);
            }
            fclose (fp);

        }

    else if(option == 3)
    {
        system("cls");
        style();
        wbook(B);
    }

    else if(option == 4)
    {
        system("cls");
        style();
        printf("BOOK LIST : \n");
        rbook();
    }
      }
    /*else
    {
        style();
        printf("Incorrect password");
        mainPage();
    }*/

  }
}
void studentscan()
{
    int x;
    style();
    struct information A;
    printf("Pick an option:\n");
    printf("1. See your list of borrowed books\n");
    printf("2. See book list\n");
    printf("3. Borrow a book\n");

    int option;
    printf("Enter option: ");
    scanf("%d", &option);

    if (option == 2)
    {
       rbook();
    }
    else if (option == 3)

    {
         borrow_book(option);
    }

    else if(option == 1)
    {
        open_borrowed_books_list (option);
    }

    printf("\n");
}

void wbook(struct information *B)
{
    int i,x;
    FILE *fp;

    printf("\nHOW MAnY BOOKS : \n");
    scanf("%d",&x);
    fp = fopen("BOOK.txt","a");

    if(fp!=NULL)
    {
        for(i=0; i<x; i++)
        {
            fflush(stdin);
        printf("TITLE : ");
        gets(B[i].title);
        fflush(stdin);
        printf("AUTHOR : ");
        gets(B[i].author);
        fflush(stdin);
        printf("CODE : ");
        scanf("%d",&B[i].code);
        fflush(stdin);

        fprintf(fp,"TITLE : %s\t\t", B[i].title);
        fprintf(fp,"AUTHOR : %s\t\t",B[i].author);
        fprintf(fp,"CODE : %d\n",B[i].code);
        printf("\n");
        }

    }
    fclose(fp);
}
FILE* open_borrowed_books_list (int y)
{
    fflush(stdin);
    char name [15];
    char id[10];

    printf("Enter your name: ");
    gets(name);
    fflush(stdin);
    printf("Enter your id: ");
    gets (id);
    fflush(stdin);
    FILE *ptr;
    char file_name [50];
    strcpy (file_name, name);
    strcat (file_name, " ");
    strcat (file_name, id);
    strcat (file_name, ".txt");

    if (y==1)
    {
        ptr = fopen (file_name, "r+");
        if (ptr!=NULL)
        {
            while(1)
            {
                char a = fgetc(ptr);
                if(a==EOF)
                {
                    break;
                }
                printf("%c",a);
            }
        }
        fclose(ptr);

    }
    else if (y==3)
    {
        ptr = fopen (file_name, "a+");
    }

    if (ptr == NULL)
    {
        printf("You are not a registered member\n");
    }
    else
    {
        return ptr;
    }
}
void rbook()
{
    int i;
    FILE *fp;


    fp = fopen("BOOK.txt","r");

    if(fp!=NULL)
    {
     while (1)
            {
                char a = fgetc(fp);
                if (a == EOF)
                {
                    break;
                }
                printf("%c", a);



          }
          fclose(fp);
    }
}


void borrow_book(int x)
{
     rbook();
    FILE *fp = open_borrowed_books_list(x);


    char book [40], issue_date [20], isbn[10];
    printf("Enter name of book: ");
    gets (book);
    printf("Enter CODE: ");
    gets (isbn);
    fflush(stdin);
    printf("Enter date of issue in day, month format: ");
    gets (issue_date);
    char book_data_entry [150];
    strcpy(book_data_entry, book);
    strcat(book_data_entry, "                      ");
    strcat(book_data_entry, issue_date);
    strcat(book_data_entry, "                         ");
    strcat(book_data_entry, isbn);

    fputs(book_data_entry, fp);
    fclose (fp);


}



void loading()
{
    system("cls");
    int i;
    sleep(1);
    for(i=0; i<3; i++)
    {
        printf(".");
        sleep(1);
    }
    printf("LOADING");
    sleep(1);
    for(i=0; i<3; i++)
    {
        printf(".");
        sleep(1);
    }
    system("cls");
}

void style()
{
    COORD c;
    c.X = 50;
    c.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
