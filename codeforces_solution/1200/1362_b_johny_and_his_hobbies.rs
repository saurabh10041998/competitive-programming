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

struct Cacher<T>
where
    T: Fn(i32) -> bool,
{
    calculation: T,
}

impl<T> Cacher<T>
where
    T: Fn(i32) -> bool,
{
    fn new(calculation: T) -> Self {
        Cacher { calculation }
    }

    fn value(&self, val: i32) -> bool {
        (self.calculation)(val)
    }
}

fn solve() {
    read!(_n as i32);
    read_vec!(arr as i32);
    let mut frr = arr.clone();
    let hs: HashSet<i32> = frr.drain(..).collect();

    let check = Cacher::new(|i: i32| -> bool {
        for c in arr.iter() {
            if !hs.contains(&(*c ^ i)) {
                return false;
            }
        }
        return true;
    });

    for i in 1..1024 {
        if check.value(i) {
            println!("{}", i);
            return;
        }
    }
    println!("-1");
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
