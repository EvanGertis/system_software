//demonstrates simple usage of structures
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct mystruct
{
	//struct mystruct s;//wrong: cannot contain a member of the same type as the struct itself
	struct mystruct *p;//OK: a member pointer pointing to an object of the same struct type
	//Other members here
};

struct mystruct m1;//declares a mystruct variable m1

struct Books//define the struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book; //declares a Books variable book
struct Books Book1; //declares a Books variable Book1

void UpdateBookTitle(struct Books b)//function parameter can be structure type
{
	int i;
	for(i=0;i<50 && b.title[i]!='\0';i++)
		b.title[i]=toupper(b.title[i]);//covert to upper case
	printf("Local b's title is %s\n",b.title);
}//UpdateBookTitle

struct Books CreateBook()//return an structure object is OK
{
	struct Books Book_Local_Creation;
	strcpy(Book_Local_Creation.title,"Local_Title");
	strcpy(Book_Local_Creation.author,"Local_Author");
	strcpy(Book_Local_Creation.subject,"Local_Subject");
	Book_Local_Creation.book_id=12345;
	return Book_Local_Creation;
}//CreateBook

int main(int argc, char *argv[])
{
	strcpy(book.title,"C Programming");//string copy function
	strcpy(book.author,"Nuha Ali");
	strcpy(book.subject,"C Programming Tutorial");
	book.book_id=6495407;
	
	strcpy(Book1.title,"Telecom Billing");
	strcpy(Book1.author,"Zara Ali");
	strcpy(Book1.subject,"Telecom Billing Tutorial");
	Book1.book_id=6495700;
	
	printf("book's title is %s\n",book.title);//%s for string
	printf("book's author is %s\n",book.author);
	printf("book's subject is %s\n",book.subject);
	printf("book's book_id is %d\n",book.book_id);//%d for integer
	
	printf("Book1's title is %s\n",Book1.title);
	printf("Book1's author is %s\n",Book1.author);
	printf("Book1's subject is %s\n",Book1.subject);
	printf("Book1's book_id is %d\n",Book1.book_id);
	
	struct Books *struct_pointer;
	struct_pointer = &Book1;//struct_pointer points to Book1
	printf("Book1's title is %s\n",struct_pointer->title);//one way of accessing the members of a structure using a pointer to that structure
	printf("Book1's author is %s\n",struct_pointer->author);
	printf("Book1's subject is %s\n",struct_pointer->subject);
	printf("Book1's book_id is %d\n",struct_pointer->book_id);
	
	struct_pointer = &book;//struct_pointer now points to book
	printf("book's title is %s\n",(*struct_pointer).title);//another equivalent way of accessing the members of a structure using a pointer to that structure
	printf("book's author is %s\n",(*struct_pointer).author);
	printf("book's subject is %s\n",(*struct_pointer).subject);
	printf("book's book_id is %d\n",(*struct_pointer).book_id);
	
	struct Books Book2=Book1;
	printf("Book2's title is %s\n",Book2.title);
	printf("Book2's author is %s\n",Book2.author);
	printf("Book2's subject is %s\n",Book2.subject);
	printf("Book2's book_id is %d\n",Book2.book_id);
	Book2.book_id=11;//Book2's book_id is updated to 11
	printf("Book2's new book_id is %d\n",Book2.book_id);
	printf("Book1's book_id is %d\n",Book1.book_id);//Note: Book1's book_id is NOT updated to 11.
	
	UpdateBookTitle(Book1);
	printf("Book1's updated title is %s\n",Book1.title);
	
	struct Books Book3=CreateBook();
	printf("Book3's title is %s\n",Book3.title);
	printf("Book3's author is %s\n",Book3.author);
	printf("Book3's subject is %s\n",Book3.subject);
	printf("Book3's book_id is %d\n",Book3.book_id);
	return 0;
}
