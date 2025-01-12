import random 

def generate_sequence(n):
    sequence = list(range(1, n + 1))
    
    random_idx = random.randint(0, len(sequence) - 1)
    missing_number = sequence.pop(random_idx)
    
    return sequence, missing_number

sequence, missing_number = generate_sequence(3)
print(f"Sequence: {sequence}, removed number: {missing_number}")