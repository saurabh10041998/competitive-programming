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
        let $out = inner
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<$type>().unwrap())
            .collect::<Vec<$type>>();
    };
}

struct Question {
    n: i32,
    m: i32,
    a: i32,
    b: i32,
}

impl From<Vec<i32>> for Question {
    fn from(buffer: Vec<i32>) -> Self {
        Question {
            n: buffer[0],
            m: buffer[1],
            a: buffer[2],
            b: buffer[3],
        }
    }
}

fn solve() {
    read_vec!(arr as i32);
    let q: Question = arr.into();
    let (n, m, a, b) = (q.n, q.m, q.a, q.b);
    if m * a <= b {
        println!("{}", n * a);
    } else {
        println!("{}", (n / m) * b + i32::min((n % m) * a, b));
    }
}

fn main() {
    let t = 1;
    let mut t = t;
    while t > 0 {
        solve();
        t -= 1;
    }
}
