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
    read!(n as usize);
    read_vec!(arr as i64);
    let mut sum = 0;
    let mut i = 0;
    while i < n {
        let mut cur = arr[i];
        let mut j =  i + 1; 
        while j < n && arr[i].signum() == arr[j].signum() {
            cur = i64::max(cur, arr[j]);
            j += 1;
        }
        sum += cur; 
        i = j - 1;
        i += 1;
    }
    println!("{}", sum);    
}

fn main() {
    read!(t as i32);
    let mut t = t;
    while t > 0 {
        solve();
        t -= 1;
    }
}
