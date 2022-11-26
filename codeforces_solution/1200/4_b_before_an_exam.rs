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
struct Pair {
    first: i32,
    second: i32,
}

impl From<Vec<i32>> for Pair {
    fn from(buffer: Vec<i32>) -> Self {
        Pair {
            first: buffer[0],
            second: buffer[1],
        }
    }
}

fn solve() {
    read_vec!(arr as i32);
    let (d, time): (usize, i32) = (arr[0] as usize, arr[1]);
    let (mut slots, mut ans): (Vec<Pair>, Vec<i32>) = (vec![], vec![]);
    let (mut min_time, mut max_time, mut sum_time) = (0, 0, 0);
    for _ in 0..d {
        read_vec!(arr as i32);
        let p: Pair = arr.into();
        min_time += p.first;
        max_time += p.second;
        sum_time += p.first;
        ans.push(p.first);
        slots.push(p);
    }

    if time < min_time || time > max_time {
        println!("NO");
        return;
    } else {
        println!("YES");
        if sum_time < time {
            for i in 0..d {
                if sum_time == time {
                    break;
                }
                let diff = slots[i].second - slots[i].first;
                let mut j = 1;
                while j <= diff {
                    ans[i] += 1;
                    sum_time += 1;
                    if sum_time == time {
                        break;
                    }
                    j += 1;
                }
            }
        }

        for i in 0..d {
            print!("{} ", ans[i]);
        }
        println!();
    }
}
fn main() {
    let t = 1;
    //read!(t as i32);
    let mut t = t;
    while t > 0 {
        solve();
        t -= 1;
    }
}
