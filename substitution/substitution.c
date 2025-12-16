#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_key_invalid(int argc, string argv[]);
bool is_not_alphabetical(string key);
bool is_not_complete_alphabet(string key);
string encrypt(string text, string key);

const int KEY_LENGTH = 26;
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    if (is_key_invalid(argc, argv))
    {
        return 1;
    }
    const string PLAINTEXT = get_string("plaintext:  ");
    const string CIPHERTEXT = encrypt(PLAINTEXT,argv[1]);
    printf("ciphertext: %s\n", CIPHERTEXT);
    return 0;
}

int is_key_invalid(int argc, string argv[])
{
    if (argc != 2) // wrong number of arguments
    {
        printf("Usage: ./substitution key\n");
        return true;
    }
    else if (strlen(argv[1]) != KEY_LENGTH) // wrong lenght of key
    {
        printf("Key must contain 26 characters.\n");
        return true;
    }
    else if (is_not_alphabetical(argv[1])) // contains non alphabetical characters
    {
        printf("Key must contain only alphabetical characters.\n");
        return true;
    }
    else if (is_not_complete_alphabet(argv[1])) // doesn't contain the complete alphabet
    {
        printf("Key must contain all alphabet letters one time each.\n");
        return true;
    }
    return false; // it's a valid key
}

bool is_not_alphabetical(string key)
{
    for (int i = 0; i < KEY_LENGTH; i++) // iterate thru given key letters
    {
        if (!isalpha(key[i])) // if not a letter
        {
            return true; // exit
        }
    }
    return false;
}

bool is_not_complete_alphabet(string key)
{
    int arr[KEY_LENGTH] = {};

    for (int i = 0; i < KEY_LENGTH; i++) // iterate thru given key letters
    {
        for (int j = 0; j < KEY_LENGTH; j++) // iterate thru alphabet
        {
            if (toupper(key[i]) == ALPHABET[j]) // when a match is found
            {
                arr[j]++; // add 1 in the array at the corresponding place of the letter matched
                          // from the alphabet
                if (arr[j] > 1) // if the place content value is greater than 1 the key is invalid
                                // and it exit.
                {
                    return true;
                }
                break; // exit the loop and procede with other logic
            }
        }
    }
    return false;
}

string encrypt(string text, string key)
{
    for(int i = 0, l = strlen(text); i < l; i++) // iterate thru text
    {
        if (isalpha(text[i])) // check if character is a letter
        {
            for (int j = 0; j < KEY_LENGTH; j++) // iterate thru alphabet
            {
                if (toupper(text[i]) == ALPHABET[j]) // when a match is found
                {
                    text[i] = isupper(text[i]) ? toupper(key[j]) : tolower(key[j]); // replace character with encrypted character
                    break; // exit the loop and procede with other logic
                }
            }
        }
    }
    return text;
}
