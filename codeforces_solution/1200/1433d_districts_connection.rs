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
    let mut idx = -1;
    let mut ans = Vec::new();
    for i in 1..n {
        if arr[i] != arr[0] {
            idx = i as i32;
            ans.push((1, (i + 1) as i32));
        }
    }
    if idx == -1 {
        println!("NO");
        return;
    }
    for i in 1..n {
        if arr[i] == arr[0] {
            ans.push((idx + 1, (i + 1) as i32));
        }
    }
    println!("YES");
    for (x, y) in ans.drain(..) {
        println!("{} {}", x, y);
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
