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
struct Question {
    x: i32,
    y: i32,
}
impl From<Vec<i32>> for Question {
    fn from(buffer: Vec<i32>) -> Self {
        Question {
            x: buffer[0],
            y: buffer[1],
        }
    }
}
fn solve() {
    read!(n as usize);
    let (mut p, mut c, mut flag) = (0, 0, true);
    for _ in 0..n {
        read_vec!(arr as i32);
        let q: Question = arr.into();
        if q.x < p || q.y < c || q.y - c > q.x - p {
            flag = false;
        } else {
            (p, c) = (q.x, q.y);
        }
    }
    match flag {
        true => println!("YES"),
        false => println!("NO"),
    };
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
