#include <cs50.h>
#include <stdio.h>
#include<string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9


int preferences[MAX_VOTERS][MAX_CANDIDATES];


typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;


candidate candidates[MAX_CANDIDATES];


int voter_count;
int candidate_count;


bool vote(int voter, int rank, string name);
void tabulate(void);
int tabulateTeste(int i,int j);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{


    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

   
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

   
    for (int i = 0; i < voter_count; i++)
    {

       
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    
    while (true)
    {
        
        tabulate();

        
        bool won = print_winner();
        if (won)

        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

      
        eliminate(min);

        
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}


bool vote(int voter, int rank, string name)
{
  for(int i =0;i<candidate_count;i++){
     if(strcmp(name,candidates[i].name)==0){
        preferences[voter][rank]=i;
        return true;
     }
  } 
   return false;  
}


void tabulate(void)  
{
    tabulateTeste(0,0);
}
int tabulateTeste(int i,int j){
   if(i>voter_count){
    return 0;
   }else{
    if(j>candidate_count){
      tabulateTeste(i+1,0);
    }else if(candidates[preferences[i][j]].eliminated==true){
      int d=i;
      tabulateTeste(d,j+1);
    }else{
        candidates[preferences[i][j]].votes++;
        tabulateTeste(i+1,0);
    }
   }
}

bool print_winner(void)
{
    int o=voter_count/2;
    int numberWinner=o+1;
    for(int i=0;i<candidate_count;i++){
        if(candidates[i].votes>=numberWinner){
           printf("%s\n",candidates[i].name);
           return true;
        }
    }
    
    return false;
}

int find_min(void)
{
    int arrayVotes[candidate_count];

    for (int i = 0; i < candidate_count; i++){
    if(candidates[i].eliminated==false){
     arrayVotes[i]=candidates[i].votes;
    } 
  }
  for (int i = 0; i < candidate_count; i++)
  {

    for (int t = 0; t < candidate_count; t++)
    {
      if (arrayVotes[i] <arrayVotes[t])
      {
        int n = arrayVotes[i];
        arrayVotes[i] = arrayVotes[t];
        arrayVotes[t] = n;
      }
    }
  }

  int number=arrayVotes[0];
    
    return number;
}


bool is_tie(int min)
{
    int count=0;
    for(int i =0;i<candidate_count-1;i++){
      if (candidates[i].eliminated==false){
       if(candidates[i].votes==min){
       count=count+1;
       }
      }
    }
    if(count==candidate_count){
      return true;
    }
    return false;
}


void eliminate(int min)
{
    for(int i=0;i<candidate_count;i++){
       if(candidates[i].votes==min){
           candidates[i].eliminated=true;
       }
    }
    return;
}

