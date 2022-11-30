use std::collections::HashSet;

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
    let mut hs = (1..3001).collect::<HashSet<i32>>();
    read!(_n as i32);
    read_vec!(arr as i32);
    let ans = 3001;
    for c in arr {
        if hs.contains(&c) {
            hs.remove(&c);
        }
    }
    let mut hs = hs.drain().collect::<Vec<i32>>();
    hs.sort();
    match hs.iter().next() {
        Some(v) => println!("{}", v),
        None => println!("{}", ans),
    }
}
fn main() {
    let t = 1;
    //read!(t as i32);
    let mut t = t;
    while t > 0 {
        solve();
        t -= 1;
    }
}
