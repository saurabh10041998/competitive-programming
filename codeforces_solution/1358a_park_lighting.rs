use std::io;


fn solve() {
    let mut line = String::new(); 
    io::stdin()
        .read_line(&mut line).expect("input: ");
    let nums = line.trim().split(' ').flat_map(str::parse::<u64>).collect::<Vec<_>>();
    let a = nums[0];
    let b = nums[1];
    let mut ans = 0; 
    ans += a/2 * b;
    if a % 2 != 0 {
        ans += b/2;
        if b % 2 != 0 {
            ans += 1;
        }
    }
    println!("{}", ans);
}

fn main() { 
    let mut test_case = String::new();
    io::stdin()
        .read_line(&mut test_case)
        .expect("failed to read from stdin");

    let trimmed = test_case.trim();
    let mut t = 0;
    match trimmed.parse::<u64>() {
        Ok(i) =>t = i,
        Err(..) => println!("this was not as integer: {}", trimmed),
    };
    while t != 0 {
        solve();
        t -= 1;
    }
}
