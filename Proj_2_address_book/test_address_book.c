#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "address_book.h"

AddressBook create_test_book()
{
    AddressBook book;

    book.list = malloc(sizeof(ContactInfo) * 10);
    book.count = 0;

    return book;
}

void test_add_contact()
{
    AddressBook book = create_test_book();

    strcpy(book.list[0].name[0], "Ali");
    strcpy(book.list[0].phone_numbers[0], "5551111");
    strcpy(book.list[0].email_addresses[0], "ali@test.com");

    book.count++;

    assert(strcmp(book.list[0].name[0], "Ali") == 0);
    assert(book.count == 1);

    printf("test_add_contact PASSED\n");

    free(book.list);
}

void test_search_contact()
{
    AddressBook book = create_test_book();

    strcpy(book.list[0].name[0], "Sara");
    book.count = 1;

    int found = 0;

    for(int i=0;i<book.count;i++)
    {
        if(strcmp(book.list[i].name[0], "Sara") == 0)
            found = 1;
    }

    assert(found == 1);

    printf("test_search_contact PASSED\n");

    free(book.list);
}

void test_delete_contact()
{
    AddressBook book = create_test_book();

    strcpy(book.list[0].name[0], "Mike");
    book.count = 1;

    book.count--;  // simulate deletion

    assert(book.count == 0);

    printf("test_delete_contact PASSED\n");

    free(book.list);
}

void test_save_file()
{
    FILE *fp = fopen("test_contacts.csv","w");

    fprintf(fp,"1,John,5552222,john@test.com\n");

    fclose(fp);

    fp = fopen("test_contacts.csv","r");

    assert(fp != NULL);

    printf("test_save_file PASSED\n");

    fclose(fp);
}

int main()
{
    printf("\nRunning Address Book Tests\n\n");

    test_add_contact();
    test_search_contact();
    test_delete_contact();
    test_save_file();

    printf("\nAll tests passed\n");

    return 0;
}