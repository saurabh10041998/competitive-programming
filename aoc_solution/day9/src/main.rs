use itertools::Itertools;
use std::collections::HashMap;
use std::collections::HashSet;

fn main() {
    let mut routes = HashMap::new();
    let mut cities = HashSet::new();
    let input = include_str!("./input.txt");
    for line in input.lines() {
        let tokens = line.split_ascii_whitespace().collect::<Vec<&str>>();
        let (c1, c2, dist) = (
            String::from(tokens[0]),
            String::from(tokens[2]),
            tokens[4].parse::<i32>().unwrap(),
        );
        routes.insert((c1.clone(), c2.clone()), dist);
        routes.insert((c2.clone(), c1.clone()), dist);
        cities.insert(c1);
        cities.insert(c2);
    }
    let (mut min_dist, mut max_dist) = (i32::MAX, i32::MIN);

    for perm in cities.iter().permutations(cities.len()) {
        let mut dist = 0;
        let mut iter = perm.iter();
        let mut c1 = iter.next().unwrap();
        while let Some(c2) = iter.next() {
            dist += *routes.get(&(c1.to_string(), c2.to_string())).unwrap();
            c1 = c2;
        }
        min_dist = i32::min(min_dist, dist);
        max_dist = i32::max(max_dist, dist);
    }

    println!("Part1: {:#?}", min_dist);
    println!("Part2: {:#?}", max_dist);
}
