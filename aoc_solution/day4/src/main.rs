use md5;
use std::env; 


fn solve(input :&str, num_of_chars :usize) { 
    let mut i = 1;
    loop {
        let key = format!("{input}{i}");
        let digest = md5::compute(key);
        //println!("{}", format!("{:0>5}", "0"));
        if &format!("{:x}", digest)[..num_of_chars] == &format!("{:0>num_of_chars$}", "0") { 
            println!("Found it -> {}", i);
            break;
        }
        i += 1
    }
}

fn main() {
    let data = include_str!("./input.txt").trim(); 
    let envs :Vec<String> = env::args().collect();
    let input = if envs.len() == 2 { &envs[1] } else { data };

    solve(input,5);

    solve(input,6);

    //println!("Part 1: {}", format!("{:x}", digest));
    println!("Part 2: {}",input);

}
