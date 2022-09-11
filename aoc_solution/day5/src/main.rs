use fancy_regex::Regex;
use lazy_static::lazy_static;
fn nice(line: &str) -> bool { 
    lazy_static!{
        static ref RE1: Regex = Regex::new(r"([aeiou].*){3}").unwrap();
        static ref RE2: Regex = Regex::new(r"(.)\1").unwrap();
        static ref RE3: Regex = Regex::new(r"(ab|cd|pq|xy)").unwrap();
    }

    return RE1.is_match(line).unwrap() &&
            RE2.is_match(line).unwrap() &&
            ! RE3.is_match(line).unwrap();
}

fn second_nice(line: &str) -> bool { 
    lazy_static!{
        static ref RE1: Regex = Regex::new(r"(..).*\1").unwrap();
        static ref RE2: Regex = Regex::new(r"(.).\1").unwrap();
    }

    return RE1.is_match(line).unwrap() &&
            RE2.is_match(line).unwrap();
}

fn main() {
    let data = include_str!("./input.txt");

    let part1 = data.lines()
                .filter(|line| nice(line))
                .count();

    let part2 = data.lines()
                .filter(|line| second_nice(line))
                .count();

    println!("part1: {}", part1);
    println!("part2: {}", part2);
}
