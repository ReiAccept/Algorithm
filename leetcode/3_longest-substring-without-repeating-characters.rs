impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut maxl = 0i32;
        let mut pos: [usize; 128] = [0; 128];
        let mut start = 0usize;
        for (end, c) in s.chars().enumerate() {
            start = start.max(pos[c as usize]);
            maxl = maxl.max((end - start + 1) as i32);
            pos[c as usize] = end + 1; // 更新位置，将 pos[c] 更新到当前字符的下一个位置
        }
        return maxl;
    }
}
