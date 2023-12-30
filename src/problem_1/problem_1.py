def run_1(lines: list[str]) -> None:
    total_sum = 0

    for line in lines:
        digits = [char for char in line if char.isdigit()]
        if digits:
            total_sum += int(f"{digits[0]}{digits[-1]}")

    print(f"Sum: {total_sum}")
