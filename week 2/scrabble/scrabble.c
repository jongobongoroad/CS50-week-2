#include <cs50.h>
#include <stdio.h>
#include <string.h>

int get_winner(string words[]);
int compare_scores(void);

const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int values[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int players = 2;
int scores[players];

int main(void)
{
    string arr[players];
    for (int p = 0; p < players; p++) // for each player
    {
        arr[p] = get_string("Player%i: ", p + 1); // get their word
    }
    int winner = get_winner(arr); // get the resulting case after score comparison
    !winner ? printf("Tie!\n") : printf("Player %i wins!\n", winner); // print the result winner
}

int get_winner(string words[])
{
    for (int p = 0; p < players; p++) // for each player
    {
        for (int cw = 0, slw = strlen(words[p]); cw < slw; cw++) // for each character of the word
        {
            for (int ca = 0, sla = strlen(chars); ca < sla; ca++) // for each character of the alphabet
            {
                if (words[p][cw] == chars[ca] ||
                    words[p][cw] == chars[ca] + 32) // check if character of the word and alphabet matches,
                {
                    scores[p] += values[ca]; // if so add corresponding score,
                    break;                   // and exit loop
                }
            }
        }
    }
    return compare_scores(); // compare scores and return case id
}

int compare_scores(void)
{
    if (scores[0] == scores[1])
    {
        return 0;
    }
    else if (scores[0] > scores[1])
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
