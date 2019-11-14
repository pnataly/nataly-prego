#include "mu_test.h"
#include "Author.h"
#include "Publisher.h"
#include "Book.h"
#include "isbn.h"
#include "Year.h"
#include "catalog.h"
#include <tr1/memory>
#include <string>
#include "IUpdate.h"
#include "IQuery.h"
#include "indexBy.h"
#include "Aggregator.h"

using namespace advcpp; 
using std::tr1::shared_ptr; 

UNIT(book) 	
	Catalog<Book> ct;
	ISBN isbn("123");
	Year year("1992");	
	shared_ptr<Author> au1 (new Author("nataly"));
	shared_ptr<Publisher> pub1 (new Publisher("prego"));
	
 	shared_ptr<Book> pb1(new Book(isbn,"The title", au1, year, pub1)); 	
 	ASSERT_THAT(ct.Add(pb1));	
 	shared_ptr<Book> p = ct.Get(isbn.GetISBN());
 	ASSERT_THAT(p == pb1);
END_UNIT


UNIT(publisher) 	
	ISBN isbn("123");
	Year year("1992");	
	shared_ptr<Author> au1(new Author("nataly"));
	shared_ptr<Publisher> pub1(new Publisher("prego"));
 	shared_ptr<Book> bk(new Book(isbn,"The title", au1, year, pub1)); 	
 	
 	pub1->AddBook(bk);
 	ASSERT_THAT(pub1->IsFound(bk));
END_UNIT 


UNIT(author) 	
	ISBN isbn("123");
	Year year("1987");	
	shared_ptr<Author> au1(new Author("Tom Clancy"));
	shared_ptr<Publisher> pub1(new Publisher("Putnam Publishing Group"));
 	shared_ptr<Book> bk(new Book(isbn,"Patriot Games", au1, year, pub1)); 	
 	
 	au1->AddBook(bk);
 	ASSERT_THAT(au1->IsFound(bk));
END_UNIT 


UNIT(catalog) 	
	Catalog<Author> ct;
	ISBN isbn("123");
	ISBN isbn2("456");
	Year year("1987");	
	Year year2("1994");
	shared_ptr<Author> au1(new Author("Tom Clancy"));	
	shared_ptr<Author> au2(new Author("John McMurry"));
	
	shared_ptr<Publisher> pub1(new Publisher("Putnam Publishing Group"));
	shared_ptr<Publisher> pub2(new Publisher("Prentice Hall"));
	
 	shared_ptr<Book> bk(new Book(isbn,"Patriot Games", au1, year, pub1)); 	
 	shared_ptr<Book> bk2(new Book(isbn2,"Chemistry", au2, year2, pub2)); 	
 	shared_ptr<Book> bk3(new Book(isbn,"Title", au1, year, pub1)); 	
 	
 	au1->AddBook(bk); 
 	au1->AddBook(bk2);
 	 
	ASSERT_THAT(ct.Add(au1));
	ASSERT_THAT(ct.Add(au2));
	ASSERT_THAT(!ct.Add(au1));
	shared_ptr<Author> res = ct.Get(au1->Get());
 	ASSERT_THAT(res == au1);
 	ASSERT_THAT(au1->IsFound(bk));
 	ASSERT_THAT(!au1->IsFound(bk3));
END_UNIT 

UNIT(aggregator) 	
	Aggregator ag;
	
	ISBN isbn("123");
	ISBN isbn2("456");
	Year year("1987");	
	Year year2("1994");
	shared_ptr<Author> au1(new Author("Tom Clancy"));	
	shared_ptr<Author> au2(new Author("John McMurry"));
	
	shared_ptr<Publisher> pub1(new Publisher("Putnam Publishing Group"));
	shared_ptr<Publisher> pub2(new Publisher("Prentice Hall"));
	
 	shared_ptr<Book> bk(new Book(isbn,"Patriot Games", au1, year, pub1)); 	
 	shared_ptr<Book> bk2(new Book(isbn2,"Chemistry", au2, year2, pub2)); 	
 	shared_ptr<Book> bk3(new Book(isbn,"Title", au1, year, pub1)); 	
 	
 	ag.Update(bk);
 	ag.Update(bk2);
 	
 	shared_ptr<Book> book = ag.SearchByISBN(isbn.GetISBN());
 	ASSERT_THAT(book == bk);
END_UNIT 


UNIT(index_by) 	
	IndexBy index;
	
	ISBN isbn("123");
	ISBN isbn2("456");
	Year year("1987");	
	Year year2("1994");
	shared_ptr<Author> au1(new Author("Tom Clancy"));
	shared_ptr<Publisher> pub1(new Publisher("Putnam Publishing Group"));
 	shared_ptr<Book> bk(new Book(isbn,"Patriot Games", au1, year, pub1)); 	
 	shared_ptr<Book> bk2(new Book(isbn2,"Chemistry", au1, year2, pub1)); 	
 	
 	index.Add(bk, "Games");
 	index.Add(bk2, "Chemistry");
 	
 	ASSERT_THAT((index.Get("Chemistry")) == bk2);
 	ASSERT_THAT((index.Get("Games")) == bk);
END_UNIT 

TEST_SUITE(C Unit Test Demo for mu_test!) 	
	TEST(book) 	
	TEST(publisher) 	
	TEST(author) 	
	TEST(catalog) 	
	TEST(aggregator) 
	TEST(index_by)	
END_SUITE

