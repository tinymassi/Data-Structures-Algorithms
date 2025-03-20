import random

def generate_shuffled_padded_integers(output_file="random_padded.txt", count=4096000):
    """Generates zero-padded integers, shuffles them, and writes them to a file."""

    integers = []
    for i in range(count):
        i = i + 1
        padded_integer = str(i).zfill(9)
        integers.append(padded_integer)

    random.shuffle(integers)

    with open(output_file, "w") as f:
        for padded_integer in integers:
            f.write(padded_integer + "\n")

if __name__ == "__main__":
    generate_shuffled_padded_integers()
    print("Shuffled zero-padded integers written to random_padded.txt")
