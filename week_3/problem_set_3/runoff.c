#include <cs50.h>
#include <stdio.h>

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
} candidate;

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
	// For each candidate, initialize its candidates struct (name, 0 votes, not eliminated)
	for (int i = 0; i < candidate_count; i++)
	{
		candidates[i].name = argv[i + 1];
		candidates[i].votes = 0;
		candidates[i].eliminated = false;
	}
	// Prompt the user for the total number of voters
	voter_count = get_int("Number of voters: ");
	if (voter_count > MAX_VOTERS)
	{
		printf("Maximum number of voters is %i\n", MAX_VOTERS);
		return 3;
	}

	// Keep querying for votes
	// For each voter...
	for (int i = 0; i < voter_count; i++)
	{

		// Query for each rank
		// For each candidate, get a rank
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
bool vote(int voter, int rank, string name)
{
	// Check if candidate is in list of candidates
	// If it is, record in which column it is (integer value)
	bool is_valid_candidate;
	int candidates_column;
	for (int h = 0; h < candidate_count; h++)
	{
		// If it is, count the vote and return true
		if (strcmp(candidates[h].name, name) == 0)
		{
			is_valid_candidate = true;
			candidates_column = h;
		}
	}
	// If the candidate is on the list, then set the preference of voter i in column h to be rank
	if (is_valid_candidate)
	{
		preferences[voter][candidates_column] = rank;
		return true;
	}
	// Otherwise, return false
	return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
	// For each voter (row) in preferences...
	for (int i = 0; i < voter_count; i++)
	{
		// While this voter's vote has not been counted, look for the next non-eliminated candidate...
		int j = 0;
		bool voter_voted = false;
		int voters_valid_preference;
		while (!voter_voted)
		{
			// If candidate has not been eliminated...
			if (!candidates[j].eliminated)
			{
				voters_valid_preference = preferences[i][j];
				voter_voted = true;
			}
			j++;
		}
		candidates[voters_valid_preference].votes++;
	}
	return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
	// For each candidate...
	for (int j = 0; j < candidate_count; j++)
	{
		// If that candidate has more than 50% of votes...
		if (candidates[j].votes > voter_count / 2)
		{
			// Print the name of the winner
			printf("%s\n", candidates[j].name);
			return true;
		}
	}
	return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
	// Start at the maximum number of votes (since no candidate can have more votes than that)
	int min_votes = voter_count;
	// Check if there's a candidates with eliminated = false and less votes than the one registerd in min_votes
	for (int j = 0; j < candidate_count; j++)
	{
		if (candidates[j].votes < min_votes)
		{
			min_votes = candidates[j].votes;
		}
	}
	return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
	// TODO
	return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
	// TODO
	return;
}
