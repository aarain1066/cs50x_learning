#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
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

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
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

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}



// Record preference if vote is valid
bool vote(int voter, int rank, string name){

    // inside the main func, it is inately iterative
    // therefore, we only care to capture each value(s) of iteration
    // which comes as voter (ballot), ballot ranking for each voter, and a name

    // here, it is obv, that voter and rank int will help us fill the index of
    // our preferences multi-dim array to be filled out.

    // and it is hinted, that name, will be used to confirm validation
    // of a proper ballot entry

    // therefore, begin with iterating through candidate array, IoT
    // strcmp for validation

    for(int c = 0; c < candidate_count; c++){

        if(strcmp(name, candidates[c].name) == 0){

            preferences[voter][rank] = c;
            return true;
        }
    }
    return false;

}



// Tabulate votes for non-eliminated candidates
void tabulate(void){


    // scroll through prefernces
    // by each voter, look at their ballot (iterate here then)

        // then by each ballot entry (pref[j])
        // if the bool is false
            // uptick their vote
            // break, so you don't continue to run-away tick

    for(int i = 0; i < voter_count; i++){

        for(int j = 0; j < candidate_count; j++){

            int candidate_indexer = preferences[i][j];

            if(candidates[candidate_indexer].eliminated == false){

                candidates[candidate_indexer].votes += 1;
                break;
            }
        }
    }

}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for(int i = 0; i < candidate_count; i++){

        if(candidates[i].votes > (voter_count / 2)){

            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}


// Return the minimum number of votes any remaining candidate has
int find_min(void)
{

    int lowest_vote_finder = candidates[0].votes;

    for(int i = 0; i < candidate_count; i++){

        if(candidates[i].eliminated == false && candidates[i].votes <= lowest_vote_finder){

            lowest_vote_finder = candidates[i].votes;
        }

    }

    return lowest_vote_finder;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{

    int running_candidates = 0;
    int candidates_min = 0;

    for(int i = 0; i < candidate_count; i++){

        if(candidates[i].eliminated == false){

            running_candidates += 1;
        }
    }

    for(int i = 0; i < candidate_count; i++){

        if(candidates[i].votes == min){

            candidates_min += 1;
        }
    }

    if(candidates_min == running_candidates){

        return true;
    }
    else return false;


}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for(int i = 0; i < candidate_count; i++){

        if(candidates[i].eliminated == false && candidates[i].votes == min){

            candidates[i].eliminated = true;
        }
    }
    return;
}
