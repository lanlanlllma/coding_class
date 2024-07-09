#include "file_process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int count;
    struct contact* contacts = read_contact_file(&count);
    printf("Read %d contacts\n", count);
    if (contacts != NULL) {
        for (int i = 0; i < count; i++) {
            printf("%s %s %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
        }
        free(contacts); // Release dynamically allocated memory
    }
    //write
    struct contact con;
    strcpy(con.name, "John");
    strcpy(con.phone, "1234567890");
    strcpy(con.email, "");
    write_contact_file(con);
    return 0;
}
