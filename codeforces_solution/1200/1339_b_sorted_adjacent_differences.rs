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
    read_vec!(arr as i32);
    let mut arr = arr;
    arr.sort();
    if n % 2 == 0 {
        let mut j = n.checked_div(2);
        let mut i = n.checked_div(2).unwrap().checked_sub(1);
        while let (Some(x), Some(y)) = (i, j) {
            print!("{} {} ", arr[y], arr[x]);
            j = y.checked_add(1);
            i = x.checked_sub(1);
        }
    } else {
        let mut j = n.checked_div(2);
        print!("{} ", arr[j.unwrap()]);
        let mut i = n.checked_div(2).unwrap().checked_sub(1);
        j = j.unwrap().checked_add(1);
        while let (Some(x), Some(y)) = (i, j) {
            print!("{} {} ", arr[x], arr[y]);
            j = y.checked_add(1);
            i = x.checked_sub(1);
        }
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
