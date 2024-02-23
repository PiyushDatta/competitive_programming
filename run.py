#!/usr/bin/env python
# Used to run and test c++ code used for competitive programming.
# python3
from os import system, path, makedirs
from time import time


def main():
    print()
    output_dir = "out"
    # Create "out" directory if it does not exist.
    if not path.exists(output_dir):
        makedirs(output_dir)
    # Compile.
    start_time = time()
    system(""" g++ main.cc -o "out/main.out" """)
    print(f"Time taken to compile: {time()-start_time:.2f} seconds")
    # Run.
    executable_path = path.join(output_dir, "main.out")
    start_time = time()
    system(executable_path)
    print(f"Time taken to execute: {time()-start_time:.2f} seconds")
    # Check.
    system(""" g++ check.cc -o "out/check.out" & "out/check.out" """)
    print()


if __name__ == "__main__":
    main()
