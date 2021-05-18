#include <stdio.h>
#include <string.h>
struct BorrowerInfo {
    char borrowerID[12], name[20];
    int count;
};
typedef struct BorrowerInfo borrowerinfo;
struct bookInfo {
    char bookID[12], title[80], author[80];
    int count;
};
typedef struct bookInfo bookinfo;
struct dateInfo {
    int year, month, day;
};
typedef struct dateInfo dateinfo;
struct circulateInfo {
    borrowerinfo *borrower;
    bookinfo *book;
    dateinfo borrowDate, dueDate, returnDate;
};
typedef struct circulateInfo circulateinfo;
int main (){
    bookinfo book[50];
    borrowerinfo borrower[20];
    circulateinfo record[200];
    int bookTotal = 0, borrowerTotal = 0, recordTotal = 0,actionID = 12,i,popyear,max;
    char inputborrowerID[12],inputbookID[12];
    while (actionID!=0)
    {
        printf("Menu of NTOU CSE Library Circulation System\n") ;
        printf(" 1. Borrow a book.\n 2. Return a book.\n 3. Print all the borrowers.\n 4. Print all the books.\n 5. Print all the circulation records.\n 6. Add a new borrower.\n 7. Add a new book.\n 8. Find top-1 popular books of a year.\n 9. Find top-1 borrowers of a year.\n 10. Create a monthly table of circulations of a year.\n 11. List all borrowers who have not returned overdue books.\n 0. Exit.\n");
        printf("Please choose one action: ");
        scanf("%d",&actionID);
        switch(actionID) {
        case 1:
            getchar();
            printf("Input the borrower ID: ");
            gets(inputborrowerID);
            for (i = 0;i<borrowerTotal;i++)
            {
                borrower[i].count  = 0;
            }
            for (i = 0;i<borrowerTotal;i++)
            {
                if(!strcmp(inputborrowerID,borrower[i].borrowerID)) {record[recordTotal].borrower = &borrower[i]; borrower[i].count++;}
            }
            printf("Input the boook ID: ");
            gets(inputbookID);
            for (i = 0;i<bookTotal;i++)
            {
                book[i].count  = 0;
            }
            for (i = 0;i<bookTotal;i++)
            {
                if(!strcmp(inputbookID,book[i].bookID)){record[recordTotal].book =&book[i]; book[i].count++;}
            }
            printf("Input the borrowing date (year/month/day): ");
            scanf("%d/%d/%d",&record[recordTotal].borrowDate.year,&record[recordTotal].borrowDate.month,&record[recordTotal].borrowDate.day);
            printf("Input the due date (year/month/day): ");
            scanf("%d/%d/%d",&record[recordTotal].dueDate.year,&record[recordTotal].dueDate.month,&record[recordTotal].dueDate.day);
            record[recordTotal].returnDate.month = 0;
            record[recordTotal].returnDate.year = 0;
            record[recordTotal].returnDate.day = 0;
            printf("A circulation record has been created.\n");
            printf("\n");
            recordTotal++;
            break;
        case 2:
            getchar();
            printf("Input the borrower ID: ");
            gets(inputborrowerID);
            printf("Input the boook ID: ");
            gets(inputbookID);
            printf("Input the returning date (year/month/day): ");
            for (i = 0;i<recordTotal;i++)
            {
                if((!strcmp(inputborrowerID,record[i].borrower->borrowerID)&&!strcmp(inputbookID,record[i].book->bookID)))
                {
                   scanf("%d/%d/%d",&record[i].returnDate.year,&record[i].returnDate.month,&record[i].returnDate.day);
                   printf("A book has been returned.\n");
                   break;
                }
            }
            break;
        case 3:
            printf("\nData of all borrowers:\n");
            for (i = 0 ;i<borrowerTotal;i++)
            {
                printf("Borrower ID: %s, Name: %s\n",borrower[i].borrowerID,borrower[i].name);
                if (i == borrowerTotal -1)printf("\n");
            }
            break;
        case 4:
            printf("\nData of all books:\n");
            for (i = 0;i<bookTotal;i++)
            {
                printf("Book ID: %s\n",book[i].bookID);
                printf(" title: %s\n",book[i].title);
                printf(" authors: %s\n",book[i].author);
                if (i == bookTotal - 1) printf("\n");
            }
            break;
        case 5:
            printf("\nData of all circulation records:");
            for (i = 0;i<recordTotal;i++)
            {
                printf("%s         %s        %d/%d/%d      %d/%d/%d        %d/%d/%d\n",record[i].borrower->borrowerID,record[i].book->bookID,record[i].borrowDate.year,record[i].borrowDate.month,record[i].borrowDate.day,record[i].dueDate.year,record[i].dueDate.month,record[i].dueDate.day,record[i].returnDate.year,record[i].returnDate.month,record[i].returnDate.day);
            }
            break;
        case 6:
            getchar();
            printf("Borrower ID: ");
            gets(borrower[borrowerTotal].borrowerID);
            printf("Borrower Name: ");
            gets(borrower[borrowerTotal].name);
            borrowerTotal++;
            printf("\n");
            break;
        case 7:
            getchar();
            printf("Book ID: ");
            gets(book[bookTotal].bookID);
            printf("Book title: ");
            gets(book[bookTotal].title);
            printf("Authors: ");
            gets(book[bookTotal].author);
            bookTotal++;
            printf("\n");
            break;
        case 0:break;
        case 8:
            printf("Which year? ");
            scanf("%d",&popyear);
            printf("Data of all books:\n");
            for (i = 0;i<bookTotal;i++)
            {
                if(popyear==record[i].borrowDate.year)printf("The book [%s] has been borrowed %d time(s).",book[i].bookID,book.count);
                else i
            }
            printf("Top-1 popular books in 2017 are:\n");
            max = book[0].count;
            for (i = 0;i<bookTotal;i++)
            {
                if (book[i].count>max) max = book[i].count;
            }
            for (i = 0;i<bookTotal;i++)
            {
                if (book[i].count==max) printf("The book [%s] has been borrowed %d time(s).",book[i].bookID,book[i].count);
            }
            break;
        case 9:
            printf("Which year? ");
            scanf("%d",&popyear);
        default:continue;

        };
    }
printf("\nThanks for using NTOU CSE Library Circulation System!!");
return 0;
}
