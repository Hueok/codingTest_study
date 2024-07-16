use std::io::{self, BufRead, Write};

fn dfs(k: usize, n: usize, m: usize, arr: &Vec<i32>, visited: &mut Vec<bool>, used: &mut Vec<i32>) {
    if k == m {
        for i in 0..m {
            print!("{} ", used[i]);
        }
        println!();
        io::stdout().flush().unwrap();
        return;
    }
    for i in 0..n {
        if visited[i] {
            continue;
        }
        visited[i] = true;
        used[k] = arr[i];
        dfs(k + 1, n, m, arr, visited, used);
        visited[i] = false;
    }
}

fn main() {
    let stdin = io::stdin();
    let mut iter = stdin.lock().lines().map(|l| l.unwrap())
        .flat_map(|line| line.split_whitespace().map(|num| num.parse::<i32>().unwrap()).collect::<Vec<i32>>().into_iter());
    
    let n = iter.next().unwrap() as usize;
    let m = iter.next().unwrap() as usize;
    
    let mut arr = vec![0; n];
    for i in 0..n {
        arr[i] = iter.next().unwrap();
    }
    arr.sort();
    
    let mut visited = vec![false; n];
    let mut used = vec![0; m];
    
    dfs(0, n, m, &arr, &mut visited, &mut used);
}