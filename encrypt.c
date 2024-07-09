/*
encrypt the password using md5

caculate the sum of the md5 string

use the sum as the key to encrypt the contact.dat file

decrypt the contact.dat file using the same key

function:
decarser(char* password, char* contact ) -> decrypt the contact.dat
    return: char*

caeasar(char* contact, int key) -> caesar encrypt the contact.dat
    return: char*

cal_md5(char* password) -> calculate the md5 of the password
    return: char*

md5_str2int(char* md5) -> sum the md5 string
    return: sum%26
*/
#include "encrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Ensure OpenSSL is correctly installed and the include path is properly set
// If OpenSSL is installed but the issue persists, verify the include path in your IDE or build system
#include <openssl/md5.h>

char* cal_md5(char* password)
{
    MD5_CTX ctx;
    unsigned char md[16];
    char *mdString = (char *)malloc(33);
    if (mdString == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    int i;
    MD5_Init(&ctx);
    MD5_Update(&ctx, password, strlen(password));
    MD5_Final(md, &ctx);
    for (i = 0; i < 16; i++)
    {
        sprintf(&mdString[i * 2], "%02x", (unsigned int)md[i]);
    }
    return mdString;
}

int md5_str2int(char* md5)
{
    int sum = 0;
    int i;
    size_t len = strlen(md5);
    for (i = 0; i < len; i++)
    {
        sum += md5[i];
    }
    return sum % 26;
}

char* caesar(char* contact, char* mdString)
{
    int key = md5_str2int(mdString);
    size_t len = strlen(contact);
    int i;
    for (i = 0; i < len; i++)
    {
        if (contact[i] >= 'a' && contact[i] <= 'z')
        {
            contact[i] = (contact[i] - 'a' + key) % 26 + 'a';
        }
        else if (contact[i] >= 'A' && contact[i] <= 'Z')
        {
            contact[i] = (contact[i] - 'A' + key) % 26 + 'A';
        }
    }
    return contact;
}

char* decaesar(char* mdString, char* raw_contact)
{
    int key = md5_str2int(mdString);
    size_t len = strlen(raw_contact);
    int i;
    for (i = 0; i < len; i++)
    {
        if (raw_contact[i] >= 'a' && raw_contact[i] <= 'z')
        {
            raw_contact[i] = (raw_contact[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if (raw_contact[i] >= 'A' && raw_contact[i] <= 'Z')
        {
            raw_contact[i] = (raw_contact[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
    return raw_contact;
}
