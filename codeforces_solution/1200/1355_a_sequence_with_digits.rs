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

pub struct Question {
    x: i64,
    k: i64,
}

impl From<Vec<i64>> for Question {
    fn from(buffer: Vec<i64>) -> Self {
        Question {
            x: buffer[0],
            k: buffer[1],
        }
    }
}

fn get_add(x: i64) -> i64 {
    let mut x = x;
    let (mut m1, mut m2) = (i64::MAX, i64::MIN);
    while x != 0 {
        let m = x % 10;
        x = x / 10;
        m1 = i64::min(m1, m);
        m2 = i64::max(m2, m);
    }
    m1 * m2
}

fn solve() {
    read_vec!(arr as i64);
    let q: Question = arr.into();
    let (mut x, mut k) = (q.x, q.k);
    k -= 1;
    while k > 0 {
        let y = get_add(x);
        if y == 0 {
            break;
        }
        x += y;
        k -= 1;
    }
    println!("{}", x);
}

fn main() {
    read!(t as i32);
    let mut t = t;
    while t > 0 {
        solve();
        t -= 1;
    }
}
