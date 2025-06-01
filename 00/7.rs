impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let negative : bool = x < 0;
        let mut number : i32 = x;

        if(x == i32::MIN){
            return 0;
        }

        if(negative){
            number = -1 * x;
        }

        let mut result = 0;
        let big_num : i32 = i32::MAX;
        let next_will_violate = big_num / 10;

        while(number > 0){
            let remainder : i32 = number % 10;
            number = number / 10;
            // Finnicky logic to get around the fact the problem statemnet forbids using
            // i64
            if(result > next_will_violate){
                return 0;
            }

            if(big_num - remainder < 10 * result){
                return 0;
            }

            result = 10 * result + remainder;
        }

        if(negative){
            return -1 * result;
        }
        
        return result;
    }
}
