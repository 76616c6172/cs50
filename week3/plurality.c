#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
// accessible by candidate[1].name
// and candidate[1].votes
typedef struct {
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[]) {
    // Check for ERROR /invalid usage, not enough candidates
    if (argc < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Check for ERROR too many candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Populate array of candidates
    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++) {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name)) {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name) {

    // loop through all candidates
    for (int i = 0; i < candidate_count; i++) {
        // if name matches a candidate, return true
        // and update that candidates vote count
        if ((strcmp(name, candidates[i].name)) == 0) {
            candidates[i].votes++;
            return true; 
        }
    }
    // otherwise, do nothing and return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void) {

    int winner_array_position = 0;
    int highest_vote_count = 0;
    bool is_tie = false;

    // Determine the winner, save their votecount
    // and their position in the candidates[] array
    // if there is a tie, whoever is last in the array will be saved
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > highest_vote_count) {
            highest_vote_count = candidates[i].votes;
            winner_array_position = i;
        }
    }

    for (int i = 0; i < candidate_count; i++) {
        //check for tie
        if ( ( candidates[i].votes == highest_vote_count ) && ( i != winner_array_position ) ) {
            is_tie = true;
            //we have a tie so print out everyone who is tied for the win
            printf("TIE: %s with %d votes!\n", candidates[i].name, candidates[i].votes);
        }
    }

    if ( is_tie == false) {
        // If there is no tie, print out the winner
        printf("%s is the winner with %d votes!\n", candidates[winner_array_position].name, candidates[winner_array_position].votes);
        return;
    }else{
        // Since there is a tie we still have to print out the saved "winner" in the last position of the array.
        printf("TIE: %s with %d votes!\n", candidates[winner_array_position].name, candidates[winner_array_position].votes);
    }

    return;
}
