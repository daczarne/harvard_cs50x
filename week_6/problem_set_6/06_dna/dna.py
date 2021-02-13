import sys
import csv
from math import floor

# Check number of arguments
if len(sys.argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

# Read csv into dictionaries
people = []
with open(sys.argv[1], "r") as f:
    reader = csv.DictReader(f)
    for person in reader:
        people.append(person)

# Build a dict with the column names (to store the counts)
col_names = list(people[0].keys())[1:]
strs = {col_names[i]: 0 for i in range(len(col_names))}

# Read de DNA sequence to be checked
with open(sys.argv[2], "r") as f:
    sequence = f.read()

# Compute matches
for i in range(len(col_names)):
    target_str = col_names[i]
    target_str_len = len(target_str)
    global_count = 0
    j = 0
    # Start checking one letter at a time
    while j < (len(sequence) - target_str_len):
        if sequence[j:(j + target_str_len)] == target_str:
            matching = True
            local_count = 1
            j += target_str_len
            while matching and j < (len(sequence) - target_str_len):
                if sequence[j:(j + target_str_len)] == target_str:
                    local_count += 1
                    j += target_str_len
                    if local_count > global_count:
                        global_count = local_count
                else:
                    matching = False
                    j += 1
                    if local_count > global_count:
                        global_count = local_count
        else:
            j += 1
    # Save the length of the longest chain
    strs[target_str] = global_count


# Find the person with these values
found = False
i = 0
n = len(people)
strs_values = list(strs.values())
while not found and i < n:
    # Get that person values
    people_values = [int(i) for i in list(people[i].values())[1:]]
    # If values are the same, we found the person
    if people_values == strs_values:
        found = True
    else:
        i += 1

# Print the name of the person
if not found:
    print("No match")
else:
    print(people[i]["name"])
