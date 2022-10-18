use itertools::Itertools;

fn solve(num: String) -> String {
    let mut new_str = String::new();
    for (key, group) in &num.chars().group_by(|x| *x) {
        let lens = group.collect::<Vec<_>>().len();
        new_str.push_str(&lens.to_string());
        new_str.push(key);
    }
    new_str
}

fn main() {
    let data = include_str!("input.txt");
    let num = data.trim();
    let mut res = num.to_string();
    let mut part1: usize = 0;
    for i in 0..50 {
        if i == 40 {
            part1 = res.len();
        }
        res = solve(res);
    }
    println!("[+] Part 1: {}", part1);
    println!("[+] Part 2: {}", res.len());
}
