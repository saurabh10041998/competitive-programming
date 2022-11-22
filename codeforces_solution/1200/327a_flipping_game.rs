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
    read_vec!(arr as i32);
    let mut arr = arr;
    let mut res = 0;
    for c in arr.iter_mut() {
        if *c == 1 { 
            res += 1;
            *c  = -1;
        }else {
            *c = 1;
        }
    }
    // Kadane's algo for maximum sum subarray
    let (mut maximum_so_far, mut maximum_ending_here) = (i32::MIN, 0);
    for c in arr {
        maximum_ending_here += c;
        if maximum_so_far < maximum_ending_here {
            maximum_so_far = maximum_ending_here;
        }
        if maximum_ending_here < 0 {
            maximum_ending_here = 0;
        }
    }
    println!("{}", res + maximum_so_far);

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
