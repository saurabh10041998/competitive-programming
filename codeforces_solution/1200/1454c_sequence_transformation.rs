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
    let mut res = vec![];
    res.resize(n + 1, 1i32);
    read_vec!(arr as i32);
    let mut arr = arr;
    arr.dedup();
    let n =  arr.len();
    for i in 0..n { 
        res[arr[i] as usize] += 1;
    }
    res[arr[0] as usize] -= 1;
    res[arr[n - 1] as usize] -= 1; 
    let mut min_ele = i32::MAX;
    for i in 0..n {
        min_ele = i32::min(min_ele, res[arr[i] as usize]);
    }
    println!("{}", min_ele);
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
