use std::collections::HashMap;

impl Solution {
    pub fn count_largest_group(mut n: i32) -> i32 {
        let mut maxx = 0;
        let mut m = HashMap::new();

        let ndigits = |mut x: i32| -> i32 {
            let mut res = 0;
            while x > 0 {
                res += (x % 10);
                x /= 10;
            }
            return res;
        };

        while n > 0 {
            let r = ndigits(n);
            let c = m.entry(r).or_insert(0);
            *c += 1;
            maxx = maxx.max(*c);
            n -= 1;
        }

        let mut res = 0;
        for &v in m.values() {
            if v == maxx {
                res += 1;
            }
        }
        return res;
    }
}
