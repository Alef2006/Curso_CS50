#include <cs50.h>
#include <stdio.h>
#include <string.h>


#define MAX 9


typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];


int candidate_count;


bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{

    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }


    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");


    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");


        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for(int i=0;i<candidate_count;i++){
       if(strcmp(candidates[i].name,name)==0){
          candidates[i].votes++;
           return true;
       }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
candidate candidateAposApuracao[candidate_count];

     for(int i=0;i<candidate_count-1;i++){
       
     }
    
    
    for(int i=0;i<candidate_count;i++){
      printf("Candidato: %s\n Votos: %d\n",candidates[i].name,candidates[i].votes);
    }
    return;
}
