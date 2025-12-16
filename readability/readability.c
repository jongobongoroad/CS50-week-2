#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void count_letters_words_sentences(string text);
int get_coleman_liau_index(void);
void print_coleman_liau_index(int cli);

int letters_count = 0;
int words_count = 1;
int sentences_count = 0;

int main(void)
{
    string text = get_string("Text: ");
    count_letters_words_sentences(text);
    int coleman_liau_index = get_coleman_liau_index();
    print_coleman_liau_index(coleman_liau_index);
}

void count_letters_words_sentences(string text)
{
    for (int c = 0, l = strlen(text); c <= l; c++)
    {
        if (text[c] == ' ')
        {
            words_count++;
        }
        else if (text[c] == '.' || text[c] == '!' || text[c] == '?')
        {
            sentences_count++;
        }
        else if (isalpha(text[c]))
        {
            letters_count++;
        }
    }
}

int get_coleman_liau_index(void)
{
    float l = (float) letters_count / (float) words_count * 100.0;
    float s = (float) sentences_count / (float) words_count * 100.0;
    float coleman_liau_index = 0.0588 * l - 0.296 * s - 15.8;
    return round(coleman_liau_index);
}

void print_coleman_liau_index(int cli)
{
    if (cli < 1)
    {
        printf("Before Grade 1\n");
    } else if (cli>16)
    {
        printf("Grade 16+\n");
    } else
    {
        printf("Grade %i\n",cli);
    }
}
