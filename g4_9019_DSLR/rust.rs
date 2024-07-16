use std::collections::VecDeque;
use std::io;

fn d(n: i32) -> i32 {
    (2 * n) % 10000
}

fn s(n: i32) -> i32 {
    if n == 0 { 9999 } else { n - 1 }
}

fn l(n: i32) -> i32 {
    (n % 1000) * 10 + n / 1000
}

fn r(n: i32) -> i32 {
    (n / 10) + (n % 10) * 1000
}

fn bfs(origin_reg: i32, target_reg: i32) -> String {
    let mut visited = vec![false; 10000];
    let mut commands = vec![String::new(); 10000];
    let mut q = VecDeque::new();
    q.push_back(origin_reg);
    visited[origin_reg as usize] = true;
    while let Some(n) = q.pop_front() {
        if n == target_reg {
            return commands[n as usize].clone();
        }
        let next = l(n);
        if !visited[next as usize] {
            visited[next as usize] = true;
            commands[next as usize] = format!("{}L", commands[n as usize]);
            q.push_back(next);
        }
        let next = r(n);
        if !visited[next as usize] {
            visited[next as usize] = true;
            commands[next as usize] = format!("{}R", commands[n as usize]);
            q.push_back(next);
        }
        let next = s(n);
        if !visited[next as usize] {
            visited[next as usize] = true;
            commands[next as usize] = format!("{}S", commands[n as usize]);
            q.push_back(next);
        }
        let next = d(n);
        if !visited[next as usize] {
            visited[next as usize] = true;
            commands[next as usize] = format!("{}D", commands[n as usize]);
            q.push_back(next);
        }
    }
    String::new()
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let t : i32 = input.trim().parse().expect("Failed to parse integer");
    for _ in 0..t {
        input.clear();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        let mut numbers = input.split_whitespace().map(|s| s.parse::<i32>().unwrap_or(0));
        let origin_reg = numbers.next().unwrap_or(0);
        let target_reg = numbers.next().unwrap_or(0);
        println!("{}", bfs(origin_reg, target_reg));
    }
}