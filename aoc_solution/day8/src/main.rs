use regex::Regex;
fn main() {
    let data = include_str!("input.txt");
    let r1 = Regex::new(r"\\x[0-9a-fA-F]{2}").unwrap();
    let mut num_code = 0;
    let mut num_string = 0;
    for line in data.lines() {
        num_code += line.len();
        let tmp = r1.replace_all(line, "y").replace("\\\\", "y").replace("\\\"", "x").len() - 2;
        num_string += tmp;
    }

    num_code = 0;
    let mut num_encode = 0;
    // part 2
    for line in data.lines() {
        num_code += line.len();
        num_encode += line.escape_default().count() + 2;
    }
    
    println!("Part 1: {}", num_code - num_string);
    println!("Part 2: {}", num_encode - num_code);
}
