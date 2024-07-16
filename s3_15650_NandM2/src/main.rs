use std::io::{self, BufRead};

fn choice(N:i32, M:i32, depth:i32, choose:i32, history:&str, result: &mut Vec<String>){
    if depth==N+1{
        if choose!=M {return;}
        result.push(history.to_string());
        return;
    }
    choice(N, M, depth+1, choose, history, result);
    choice(N, M, depth+1, choose+1, &format!("{}{} ", history, depth), result);


}

fn main() {
    let scanner = io::stdin().lock().lines().next().unwrap().unwrap();
    let mut ns = scanner.split_whitespace().map(|x| x.parse::<i32>().expect("Failed parse"));
    let n = ns.next().unwrap_or_else(|| -1);
    let m = ns.next().unwrap_or_else(|| -1);
    let mut result: Vec<String> = Vec::new();
    choice(n, m, 1, 0, &String::new(), &mut result);
    result.sort();
    for element in result{
        println!("{}", element);
    }
}
