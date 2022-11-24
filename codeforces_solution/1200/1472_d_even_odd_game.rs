#[allow(unused_macros)]
macro_rules! read {
    ($out:ident as $type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A string");
        let $out = inner.trim().parse::<$type>().expect("A parsable");
    };
}
#[allow(unused_macros)]
macro_rules! read_str {
    ($out:ident) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A string");
        let $out = inner.trim();
    };
}
#[allow(unused_macros)]
macro_rules! read_vec {
    ($out:ident as $type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A string");
        let $out = inner
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<$type>().unwrap())
            .collect::<Vec<$type>>();
    };
}
fn solve() {
    read!(_n as usize);
    read_vec!(arr as i64);
    let mut arr = arr;
    arr.sort();
    let mut ans = 0;
    for (i, c) in arr.iter().rev().enumerate() {
        if i % 2 == 0 {
            if *c % 2 == 0 {
                ans += *c;
            }
        } else {
            if *c % 2 == 1 {
                ans -= *c;
            }
        }
    }
    if ans == 0 {
        println!("Tie");
    } else if ans > 0 {
        println!("Alice");
    } else {
        println!("Bob");
    }
}
fn main() {
    //let t = 1;
    read!(t as i32);
    let mut t = t;
    while t > 0 {
        solve();
        t -= 1;
    }
}
