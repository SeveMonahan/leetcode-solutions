impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let u_num_rows = num_rows as usize;

        let mut square : Vec<Vec<char>> = vec![Vec::new(); u_num_rows];

        let mut current_row : usize = 0;
        let mut going_down = false;
        for character in s.chars() {
            square[current_row].push(character);
            if (current_row == u_num_rows - 1) || (current_row == 0) {
                going_down = !going_down;
            }

            current_row = if going_down {current_row + 1} else {current_row - 1};

            if u_num_rows == 1{
                current_row = 0;
            }
        }

        let mut result : String = "".to_string();

        for i in square{
            for character in i {
                result.push(character);
            }
        }

        return result
    }
}
