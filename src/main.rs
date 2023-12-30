mod problem_1;
use problem_1::problem_1::run_1;
use std::env;
use std::fs::File;
use std::io::{self, BufRead};
use std::time::Instant;

fn read_lines(problem_number: i8) -> io::Result<Vec<String>> {
    let file = File::open(format!("src/problem_{}/input.txt", problem_number))?;
    let reader = io::BufReader::new(file);
    reader
        .lines()
        .map(|line| line.map(|l| l.trim().to_string()))
        .collect()
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        eprintln!("Missing problem number");
        std::process::exit(1);
    }

    let problem_number = match args[1].parse::<i8>() {
        Ok(num) => num,
        Err(e) => {
            eprintln!("Error parsing problem number: {}", e);
            return; // Exit the program
        }
    };

    let lines = match read_lines(problem_number) {
        Ok(lines) => lines,
        Err(e) => {
            eprintln!("Error reading lines: {}", e);
            return; // Exit the program
        }
    };

    let start = Instant::now();

    match problem_number {
        1 => run_1(&lines),
        _ => panic!("Invalid problem number: {}", problem_number),
    }

    let duration = start.elapsed();

    println!("Time taken: {:?} seconds", duration.as_secs_f32());
}
