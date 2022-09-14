use regex::Regex;
struct Instruction { 
    inst: String,
    start: Vec<usize>,
    end: Vec<usize>
}

impl From<&str> for Instruction {
    fn from(line: &str) -> Self {
        let parser = Regex::new(r"(?P<inst>turn on|turn off|toggle) (?P<start>\d+,\d+) through (?P<end>\d+,\d+)").unwrap();

        let captures = parser.captures(line).ok_or("no matches").unwrap();

        let instruction = captures
                     .name("inst")
                     .map_or("", |m| m.as_str()).to_string();

        let start:Vec<usize> = captures
                    .name("start")
                    .map_or("", |m| m.as_str())
                    .split(",")
                    .map(|m| m.parse().expect("Parse Error: {m} is not an int"))
                    .collect();
        let end:Vec<usize> = captures
                         .name("end")
                         .map_or("", |m| m.as_str())
                         .split(",")
                         .map(|m| m.parse().expect("Parse error: {m} is not an int"))
                         .collect();
        Instruction { inst: instruction, start: start, end: end}
    }
}

struct Grid {
    grid: [[u8; 1000]; 1000],
}

impl Grid {
    fn new()-> Self {
        Self {
            grid: [[0u8;1000]; 1000]
        }
    }

    fn process_instruction(&mut self,i : &Instruction) {
        for r in i.start[0]..i.end[0]+1 {
            for c in i.start[1]..i.end[1]+1 {
                match i.inst.as_str() {
                    "turn on" => self.grid[r][c] = 1,
                    "turn off" => self.grid[r][c] = 0,
                    "toggle" => self.grid[r][c] = 1 - self.grid[r][c],
                    _ => panic!("Unexpected instruction: {}", i.inst),
                }
            }
        }
    }

    fn process_instruction2(&mut self, i: &Instruction){
        for r in i.start[0]..i.end[0] + 1 { 
            for c in i.start[1]..i.end[1] + 1 {
                match i.inst.as_str(){
                    "turn on" => self.grid[r][c] += 1,
                    "turn off" => {
                        if self.grid[r][c] > 0 {
                            self.grid[r][c] = self.grid[r][c] - 1
                        }
                    },
                    "toggle" => self.grid[r][c] += 2,
                    _ => panic!("Unexpected instruction: {}", i.inst)
                }
            }
        }

    }

    fn sum_lights(&self) -> usize {
        self.grid.iter()
        .fold(0, |ans, row| ans + row
                                                                .iter()
                                                                .fold(0, |inner_ans, cell| inner_ans + *cell as usize) as usize)

    }

}

fn main() {
    let data = include_str!("input.txt");
    let mut g: Grid = Grid::new();
    let mut g2: Grid = Grid::new();
    for line in data.lines() { 
        let i: Instruction = line.into();
        // apply on grid..
        g.process_instruction(&i);
        g2.process_instruction2(&i);
    }
    println!("[*] Part 1: {}", g.sum_lights());
    println!("[*] Part 2: {}", g2.sum_lights());
}
