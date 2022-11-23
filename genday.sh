#!/bin/bash
source ~/.cargo/env
cargo new --bin $1
cat > $1/src/main.rs << EOF
#[allow(unused_macros)]
macro_rules! read {
    (\$out:ident as \$type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A string");
        let \$out = inner.trim().parse::<\$type>().expect("A parsable");
    };
}
#[allow(unused_macros)]
macro_rules! read_str {
    (\$out:ident) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A string");
        let \$out = inner.trim();
    };
}
#[allow(unused_macros)]
macro_rules! read_vec {
    (\$out:ident as \$type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A string");
        let \$out = inner.trim()
                        .split_whitespace()
                        .map(|s| s.parse::<\$type>().unwrap())
                        .collect::<Vec<\$type>>();
    };
}
fn solve() {

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
EOF
cd $1
cargo fmt
cargo check
