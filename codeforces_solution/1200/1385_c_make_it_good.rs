#[allow(unused_macros)]
macro_rules! read { 
    ($out:ident as $type:ty) => { 
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A string");
        let $out = inner.trim().parse::<$type>().expect("A parsable");
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

fn solve() {
    read!(n as i32);
    read_vec!(arr as i32);
    let mut pos = (n - 1) as usize;
    while pos > 0 && arr[pos - 1] >= arr[pos] { 
        pos -= 1;
    }
    while pos > 0 && arr[pos - 1] <= arr[pos] {
        pos -= 1;
    }
    println!("{}", pos);
}

fn main() {
    read!(t as i32);
    let mut t = t;
    while t > 0  { 
        solve();
        t -= 1;
    }
}
