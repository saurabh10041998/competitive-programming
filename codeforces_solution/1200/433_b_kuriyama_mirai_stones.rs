#[allow(unused_macros)]
macro_rules! read {
    ($out:ident as $type: ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A String");
        let $out = inner.trim().parse::<$type>().expect("Parsable");
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
        std::io::stdin().read_line(&mut inner).unwrap();
        let $out = inner
                .trim()
                .split_whitespace()
                .map(|s| s.parse::<$type>().unwrap())
                .collect::<Vec<$type>>();
    };
}

struct Query {
    ty : i32,
    l :usize,
    r: usize,
}

impl From<Vec<i32>> for Query {
    fn from(buffer: Vec<i32>) -> Self {
        Query {
            ty: buffer[0],
            l: buffer[1] as usize,
            r : buffer[2] as usize,
        }
    }
}

fn solve() {
    read!(n as usize);
    read_vec!(arr as i64);
    let mut arr = arr;
    let mut v = vec![0];
    v.append(&mut arr);
    let mut u = v.clone();
    u.sort();
    for i in 1..n + 1 {
        v[i] += v[i - 1];
        u[i] += u[i - 1];
    }
    
    read!(m as i32);
    let mut m = m;
    while m > 0 {
        read_vec!(qvec as i32);
        let q:Query = qvec.into();
        if q.ty == 1 {
            println!("{}", v[q.r] - v[q.l - 1]);
        }else {
            println!("{}", u[q.r] - u[q.l - 1]);
        }
        m -= 1;
    }
}

fn main() {
    //read!(t as i32);
    let t = 1;
    let mut t = t;
    while t > 0 {
        solve();
        t -= 1;
    }
}
