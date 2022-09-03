use std::fs; 

fn main() {
    // part 1
    let input = fs::read_to_string("./input.txt")
                .expect("Should have been able to read the file");


    let up = input.matches("(").count();
    let down = input.matches(")").count();

    println!("Ans = {}", up - down);

    //part 2
    let mut floor = 0;

    for (i, c) in input.chars().enumerate() {
        match c {
            '(' => floor += 1,
            ')' => floor -= 1,
            _ => panic!("Unrecognized character")
        };
        if floor == -1 {
            println!("{}",i + 1);
            break;
        }
    }

}
