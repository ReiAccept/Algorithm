impl Solution {
    pub fn find_median_sorted_arrays(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> f64 {
        if nums1.len() > nums2.len() {
            std::mem::swap(&mut nums1, &mut nums2);
        }

        let (mut l, mut r) = (0, nums1.len());

        while l<=r {
            let mx = (l+r)/2;
            let my = (nums1.len()+ nums2.len() +1 )/2 - mx;

            let maxx = if mx<=0 {i32::MIN} else {nums1[mx-1]};
            let maxy = if my<=0 {i32::MIN} else {nums2[my-1]};

            let minx = if mx>=nums1.len() {i32::MAX} else {nums1[mx]};
            let miny = if my>=nums2.len() {i32::MAX} else {nums2[my]};

            if maxx<=miny && maxy<=minx {
                if (nums1.len() + nums2.len())%2 == 0 {
                    return (maxx.max(maxy) + minx.min(miny)) as f64 /2.0;
                } else {
                    return maxx.max(maxy) as f64;
                }
            } else if maxx >miny {
                r = mx-1;
            } else {
                l = mx+1;
            }
        }
        0.0 // make compiler happy
    }
}