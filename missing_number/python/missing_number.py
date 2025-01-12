import random 

def generate_sequence(n):
    sequence = list(range(1, n + 1))
    
    random_idx = random.randint(0, len(sequence) - 1)
    missing_number = sequence.pop(random_idx)
    
    return sequence, missing_number

# sequence, missing_number = generate_sequence(4)
# print(f"Sequence: {sequence}, removed number: {missing_number}")

def find_missing_number(sequence, n):
    total_sum = n * (n + 1) // 2 # find the total sum
    current_sum = sum(sequence) # calculate the current_sum
    the_number = total_sum - current_sum # the missing number
    return the_number

n = 4
sequence, the_number = generate_sequence(n)
print(f"sequence: {sequence}, removed number: {the_number}")

calculated_missing = find_missing_number(sequence, n)
print(f"this is the calculated missing number: {calculated_missing}")