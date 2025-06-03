impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {

        let mut biggest_area : i32 = 0;

        let mut left_pointer : usize = 0;
        let mut right_pointer : usize = height.len() - 1;

        while left_pointer != right_pointer {

            let width = (right_pointer - left_pointer) as i32;
            let box_height = i32::min(height[left_pointer], height[right_pointer]);
            let candidate_area = width * box_height;

            biggest_area = i32::max(biggest_area, candidate_area);

            if height[left_pointer] < height[right_pointer] {
                left_pointer += 1;
            }else{
                right_pointer -= 1;
            }
        }
        
        biggest_area
    }
}
