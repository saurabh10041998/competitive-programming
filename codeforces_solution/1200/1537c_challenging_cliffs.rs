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
    read!(n as usize);
    read_vec!(arr as i64);
    let mut arr = arr;
    arr.sort(); 
    if n == 2 {
        println!("{} {}", arr[0], arr[1]);
        return;
    }
    let (mut pos, mut min_diff):(usize, i64) = (0, i64::MAX);
    for i in 1..n { 
        if min_diff > arr[i] - arr[i - 1] {
            pos = i;
            min_diff = arr[i] - arr[i - 1];
        }
    } 
    for i in pos..n {
        print!("{} ", arr[i]);
    }
    for i in 0..pos { 
        print!("{} ", arr[i]);
    }
    println!();
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
