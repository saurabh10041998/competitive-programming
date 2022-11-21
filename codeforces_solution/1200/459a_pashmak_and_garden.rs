use std::ops::Sub;

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

struct Coordinate {
    x1: i32,
    y1: i32,
    x2: i32,
    y2: i32,
}

impl From<Vec<i32>> for Coordinate {
    fn from(buffer: Vec<i32>) -> Self {
        Coordinate {
            x1: buffer[0],
            y1: buffer[1],
            x2: buffer[2],
            y2: buffer[3],
        }
    }
}

fn abs<T: PartialOrd + Sub<Output = T>>(x: T, y: T) -> T {
    if x > y {
        return x - y;
    }
    y - x
}

fn solve() {
    read_vec!(arr as i32);
    let c: Coordinate = arr.into();
    if (c.x1 != c.x2) && (c.y1 != c.y2) && abs(c.x1, c.x2) != abs(c.y1, c.y2) {
        println!("{}", -1);
    } else if c.x1 == c.x2 {
        println!(
            "{} {} {} {}",
            c.x1 + abs(c.y1, c.y2),
            c.y1,
            c.x2 + abs(c.y1, c.y2),
            c.y2
        );
    } else if c.y1 == c.y2 {
        println!(
            "{} {} {} {}",
            c.x1,
            c.y1 + abs(c.x1, c.x2),
            c.x2,
            c.y2 + abs(c.x1, c.x2)
        );
    } else {
        println!("{} {} {} {}", c.x1, c.y2, c.x2, c.y1);
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
