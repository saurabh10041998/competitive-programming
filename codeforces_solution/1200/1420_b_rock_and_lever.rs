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
    read!(n as i32);
    read_vec!(arr as i64);
    let mut ans: i64 = 0;
    for j in (0..30).rev() {
        let mut cnt = 0;
        for i in 0..n {
            if arr[i as usize] >= (1 << j) as i64 && arr[i as usize] < (1 << (j + 1)) as i64 {
                cnt += 1;
            }
        }
        ans += (cnt * (cnt - 1)) / 2;
    }
    println!("{}", ans);
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
