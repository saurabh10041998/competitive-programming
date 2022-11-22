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

fn solve() {
    read_vec!(arr as i32);
    let (n, x) = (arr[0], arr[1]);
    let mut f = vec![0i32;2];
    read_vec!(arr as i32);
    for y in arr{        
        f[(y % 2) as usize] += 1;
    }
    let mut flag = false;
    let mut i = 1;
    while i <= f[1] && i<= x {
        let need = x - i;
        if need <= f[0] {
            flag = true; 
            break;
        }
        i += 2;
    }
    match flag {
        true => println!("Yes"),
        false => println!("No"),
    };
}

fn main() {
    read!(t as i32);
    let mut t = t;
    while t > 0 {
        solve();
        t -= 1;
    }
}
