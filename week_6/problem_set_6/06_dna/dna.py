import sys
import pandas as pd
from math import floor

# Check number of arguments
if len(sys.argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

# Read the db into a pandas df
db = pd.read_csv(sys.argv[1])

# Build a dict with the column names (to store the counts)
col_names = list(db.columns)[1:]
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


# print(db)
print(strs)
