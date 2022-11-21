use std::ops::Sub;
#[allow(unused_macros)]
macro_rules! read {
    ($out:ident as $type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A string");
        let $out  = inner.trim().parse::<$type>().expect("A parsable");
    };
}

#[allow(unused_macros)]
macro_rules! read_vec {
    ($out:ident as $type:ty) => {
        let mut inner = String::new(); 
        std::io::stdin().read_line(&mut inner).expect("A string");
        let $out = inner.trim()
                    .split_whitespace()
                    .map(|s| s.parse::<$type>().unwrap())
                    .collect::<Vec<$type>>();
    };
}

fn abs<T:PartialOrd + Sub<Output = T>>(x: T, y: T) -> T {
    if x > y {
        return x - y;
    }
    y - x
}


fn solve() {
    read!(n as usize);
    read_vec!(arr as i32);
    let mut arr = arr; 
    read!(m as usize);
    read_vec!(brr as i32);
    let mut brr = brr;
    arr.sort(); 
    brr.sort();
    let mut result  = 0;
    for i in 0..n { 
        for j in 0..m {
            if abs(arr[i], brr[j]) <= 1 {
                brr[j] = 1000;
                result+=1;
                break;
            }
        }
    }
    println!("{}", result);
}

fn main() {
    let t  = 1;
    let mut t = t;
    while t > 0 {
        solve();
        t -= 1;
    }
}
