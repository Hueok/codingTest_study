use std::io::{self, BufRead};

fn dfs(N:i32, M:i32, last_use:i32, sequence:&mut Vec<i32>){
    if sequence.len() == M as usize{
        for value in sequence.iter(){
            print!("{} ", value);
        }
        println!();
        return;
    }
    for i in last_use..=N{
        sequence.push(i);
        dfs(N, M, i, sequence);
        sequence.pop().expect("sequence is empty");
    }
}

fn main() {
    let scanner = io::stdin().lock().lines().next().unwrap().unwrap();
    let mut iter = scanner.split_ascii_whitespace().map(|x| x.parse::<i32>().unwrap());
    let n = iter.next().unwrap_or_else(|| -1);
    let m = iter.next().unwrap_or_else(|| -1);
    let mut v : Vec<i32> = Vec::new();
    dfs(n, m, 1, &mut v);
}
