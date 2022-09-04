struct Present { 
    l :u64,
    w :u64,
    h :u64,
}

impl Present {
    // constructor in rust
    fn new(l :u64, w :u64, h :u64) -> Self {
        Present{
            l,
            w,
            h,
        }
    }
    fn paper_needed(&self)->u64 {
        (3 * self.l * self.w) + (2 * self.l * self. h)  +  (2 * self.w * self.h)
    }

    fn volume(&self)->u64 { 
        self.l * self.w * self.h
    }

    fn ribbon_needed(&self)->u64 { 
        (2 * self.l + 2 * self.w)  + self.volume()
    }
}

// From converter trait
impl From<Vec<u64>> for Present {
    fn from(vec: Vec<u64>)->Present { 
        Present{
            l: vec[0],
            w: vec[1],
            h: vec[2],
        }
    }
}

fn main() {
    let data = include_str!("./input.txt");
    let mut total_paper = 0;
    let mut total_ribbon = 0;
    for line in data.lines() {
        /*
         * This is one way to handle the integer parsing for space separated integers
         *
        let dims: Vec<u64> = line.split("x").map(|d| {
            match d.parse() {
                Ok(n) => n,
                _ => panic!("Not an integer")
            }
        }).collect();

        *
        *
        */ 
        // or expect() will set this automatically for you
        let mut dims :Vec<u64> = line.split("x").map(|d| d.parse().expect("Not an integer")).collect();
        dims.sort();
        /*
         * Approach 1 for instantiation
         *
        let p :Present = Present {
            l: dims[0],
            w: dims[1],
            h: dims[2],
        };
        */
        
        /*
         * Approach 2 for instantiation
         *
        let p: Present = Present::new(dims[0], dims[1], dims[2]);
        */

        // approach 3: really liked this one
        let p:Present = dims.into();

        total_paper += p.paper_needed();
        total_ribbon += p.ribbon_needed();
    }

    println!("part 1: {}", total_paper);
    println!("part 2: {}", total_ribbon);
}
