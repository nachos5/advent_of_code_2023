pub fn run_1(lines: &[String]) {
    let mut total_sum: i32 = 0;

    for line in lines {
        let digits: Vec<char> = line.chars().filter(|c| c.is_digit(10)).collect();

        if digits.is_empty() {
            continue;
        }

        let first_digit = digits.get(0).unwrap();
        let second_digit = digits.last().unwrap();

        let two_digit_number = format!("{}{}", first_digit, second_digit)
            .parse::<i32>()
            .unwrap_or(0);
        total_sum += two_digit_number;
    }

    println!("Sum: {}", total_sum);
}
