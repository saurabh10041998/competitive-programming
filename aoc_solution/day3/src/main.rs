use std::collections::HashMap;

fn main() {
    let data = include_str!("./input.txt");
    
    let mut pos = (0, 0);
    let mut santa = (0, 0);
    let mut robot = (0, 0);

    let mut house = HashMap::new();
    let mut house2 = HashMap::new();

    let mut current: &mut(i32, i32);   // mutable binding of mutable reference
    house.insert(pos, 1);
    house2.insert(santa, 2);

    for (i, c) in data.chars().enumerate() {
        current = if i % 2 == 0 { &mut santa } else { &mut robot };  // return the mutable reference..
        match c {
            '>' => { 
                pos.0 += 1;
                current.0 += 1;
            }, 
            '<' => { 
                pos.0 -= 1;
                current.0 -= 1;
            },
            '^' => {
                pos.1 += 1;
                current.1 += 1;
            },
            'v' => {
                pos.1 -= 1;
                current.1 -= 1;
            },
            _ => println!("Ignoring input"),
        }
        /*
         * Rusts way to say modify the value of 'pos' key to +1 if present
         * if key is not present,  insert 1 as default value for that key
         */
        house.entry(pos).and_modify(|h| *h += 1).or_insert(1);
        house2.entry(*current).and_modify(|h| *h += 1).or_insert(1); 
    }

    println!("Part 1: {}", house.len());
    println!("Part 2: {}",  house2.len()); 
}
