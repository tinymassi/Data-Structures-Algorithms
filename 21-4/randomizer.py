import random

def generate_shuffled_padded_integers(output_file="random_padded.txt", count=100000):
    """Generates zero-padded random integers, shuffles them, and writes them to a file."""
    
    integers = [str(random.randint(0, 999999999)).zfill(9) for _ in range(count)]
    random.shuffle(integers)
    
    with open(output_file, "w") as f:
        for padded_integer in integers:
            f.write(padded_integer + "\n")
    
if __name__ == "__main__":
    generate_shuffled_padded_integers()
    print("Shuffled zero-padded random integers written to random_padded.txt")