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
    read_vec!(arr as i32);
    let (n, _k) = (arr[0], arr[1]);
    read_str!(st);
    read_vec!(buffer as char);
    let hs: HashSet<char> = HashSet::from_iter(buffer);
    let (mut i, mut ans): (usize, i64) = (0, 0);

    while i < n as usize {
        let mut j = i;
        while j < n as usize && hs.contains(&st[j..j + 1].chars().nth(0).unwrap()) {
            j = j + 1;
        }
        let len = (j - i) as i64;
        ans = ans + (len * (len + 1)) / 2;
        i = j;
        i = i + 1;
    }
    println!("{}", ans);
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
