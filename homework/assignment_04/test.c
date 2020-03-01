#include <stdlib.h>
struct Books //define the struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book1;
struct Books book, *book2;

int main(){
	Book1 = book;
	book.book_id = Book1.book_id;
	book2 = &Book1;
	book.title = Book1.title;
	book2->author;
	(*book2).subject;
	return 0;
}
