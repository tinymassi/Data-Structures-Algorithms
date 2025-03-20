def generate_padded_integers(output_file="sorted.txt"):
    """Generates zero-padded integers (9 characters total) and writes them to a file."""

    with open(output_file, "w") as f:
        for i in range(300):  # Generate integers from 0 to 999999999
            i = i + 1
            padded_integer = str(i).zfill(9)
            f.write(padded_integer + "\n")

if __name__ == "__main__":
    generate_padded_integers()
    print("Zero-padded integers written to sorted.txt")