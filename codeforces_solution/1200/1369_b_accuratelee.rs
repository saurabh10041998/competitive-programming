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
    read_str!(s);
    let mut flag = true;
    for i in 1..n {
        if &s[i - 1..i] > &s[i..i + 1] {
            flag = false;
            break;
        }
    }
    if flag {
        println!("{}", s);
        return;
    }
    let mut ans = String::new();
    ans.push('0');
    for c in s.chars() {
        match c {
            '0' => ans.push(c),
            _ => break,
        };
    }
    for c in s.chars().rev() {
        match c {
            '1' => ans.push(c),
            _ => break,
        };
    }
    println!("{}", ans);
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
