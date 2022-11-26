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
    for i in 0..(n - 1) { 
        if arr[i] == 0 && arr[i + 1] == 1 {
            for j in 0..i + 1 { 
                print!("{} ", j +  1);
            }
            print!("{} ", n + 1);
            for j in i + 1..n { 
                print!("{} ", j + 1);
            }
            println!();
            return;
        }
    }
    if arr[0] == 1 {
        print!("{} ", n  + 1);
        for i in 0..n {
            print!("{} ", i + 1);
        }
        println!()
    }else {
        for i in 0..n {
            print!("{} ", i + 1);
        }
        println!("{}", n + 1);
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
