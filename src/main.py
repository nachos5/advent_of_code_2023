import sys
import time
from pathlib import Path

from problem_1.problem_1 import run_1


def get_lines(problem_number: int) -> list[str]:
    current_script_folder = Path(__file__).parent

    with open(current_script_folder / f"problem_{problem_number}/input.txt") as file:
        lines = [l.strip() for l in file.readlines()]

    return lines


def main() -> None:
    if len(sys.argv) < 2:
        raise ValueError("Missing problem number")

    problem_number = int(sys.argv[1])

    lines = get_lines(problem_number)

    start = time.time()

    match problem_number:
        case 1:
            run_1(lines)
        case _:
            raise ValueError(f"Invalid problem number: {problem_number}")

    end = time.time()

    print(f"Time taken: {end - start} seconds")


if __name__ == "__main__":
    main()
