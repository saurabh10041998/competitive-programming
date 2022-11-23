use std::collections::HashSet;

use lazy_static::lazy_static;
use fancy_regex::Regex;
use itertools::Itertools;

#[derive(Debug)]
pub struct Password {
    pass: String,
}

impl Password {
    fn new(data: &str) -> Self {
        Password {
            pass: String::from(data),
        }
    }
    fn inc(&mut self) {
        let mut chars = self.pass.chars().rev().collect::<Vec<char>>();
        for c in chars.iter_mut() {
            if *c == 'z' {
                *c = 'a';
            } else {
                *c = (*c as u8 + 1) as char;
                break;
            }
        }
        self.pass = chars.iter().rev().collect::<String>();
    }

    fn is_valid(&self) -> bool {
        // should not contain 'i', 'o', 'l'
        if self.pass.contains('l') || self.pass.contains('o') || self.pass.contains('i') {
            return false;
        }
        // should  contains atleast 2 non-overlapping pairs
        lazy_static! {
            static ref RE:Regex = Regex::new(r"(.)\1").unwrap();
        }
        let m = RE.find_iter(&self.pass)
                                                    .map(|m| m.unwrap().as_str())
                                                    .collect::<HashSet<&str>>();
        if m.len() < 2 {
            return false;
        }
        // should have three cronological letter
        for (a, b, c) in self.pass.chars().tuple_windows() {
            if a as u8 ==  b as u8 - 1 && a as u8 == c as u8 - 2 {
                return true;
            }
        }
        false
    }

    fn next_valid(&mut self) {
        loop {
            self.inc();
            if self.is_valid() {
                return;
            }
        }
    }
}

fn main() {
    let data = include_str!("./input.txt");
    let mut p = Password::new(data.trim());
    p.next_valid();
    println!("Part 1: {:?}", p);
    p.next_valid();
    println!("Part 2: {:?}", p);
}
