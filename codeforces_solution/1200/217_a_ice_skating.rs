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
pub struct Solver {
    visited: Vec<bool>,
    x: Vec<i32>,
    y: Vec<i32>,
    n: i32,
}

impl Solver {
    fn new(visited: Vec<bool>, x: Vec<i32>, y: Vec<i32>) -> Self {
        Solver {
            n: visited.len() as i32,
            visited,
            x,
            y,
        }
    }

    fn dfs_wrapper(&mut self) -> i32 {
        let mut result = 0;
        for i in 0..self.n {
            if !self.visited[i as usize] {
                result += 1;
                self.dfs(i);
            }
        }
        result
    }

    fn dfs(&mut self, i: i32) {
        self.visited[i as usize] = true;
        for v in 0..self.n {
            if self.visited[v as usize] {
                continue;
            } else if self.x[i as usize] == self.x[v as usize]
                || self.y[i as usize] == self.y[v as usize]
            {
                self.dfs(v);
            }
        }
    }
}

fn solve() {
    read!(n as i32);
    let (mut x, mut y) = (Vec::new(), Vec::new());
    for _ in 0..n {
        read_vec!(arr as i32);
        let (_x, _y) = (arr[0], arr[1]);
        x.push(_x);
        y.push(_y);
    }
    let mut visited = vec![];
    visited.resize(n as usize, false);
    let mut s = Solver::new(visited, x, y);
    let res = s.dfs_wrapper();
    println!("{}", res - 1);
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
