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

# print(db)
print(sequence)
print(strs)

for i in range(len(col_names)):
    target_str = col_names[i]
    # print(target_str)
    target_str_len = len(target_str)
    # print(target_str_len)
    #loop_range = floor(len(sequence) / target_str_len)
    # print(len(sequence))
    #print(len(sequence) - target_str_len)
    # print(loop_range)

    for j in range(len(sequence) - target_str_len):
        #print(f"i: {i} - {sequence[i:(i + target_str_len)]}, {target_str}", end="")
        if sequence[j:(j + target_str_len)] == target_str:
            #print(" - yeah baby!")
            strs[target_str] += 1

print(strs)
