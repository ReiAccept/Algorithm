use std::io::{prelude::*, stdin, stdout, BufReader, BufWriter};

fn main() {
    let std_in = stdin();
    let input = BufReader::new(std_in.lock());

    let std_out = stdout();
    let mut output = BufWriter::new(std_out.lock());

    let mut lines = input.lines().map(|r| r.unwrap());

    let s = lines.next().unwrap();
    let mut it = s.split_whitespace().map(|s| s.parse::<usize>().unwrap());

    let t = it.next().unwrap();

    for _ in 0..t {
        let p = lines.next().unwrap().parse::<usize>().unwrap();

        writeln!(&mut output, "{} {}", 2, p - 1).unwrap();
    }
}
