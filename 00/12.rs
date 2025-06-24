impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut value : i32 = num;
        let mut result = String::from("");
        let divisors = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];

        for divisor in divisors {
            while value >= divisor {
                value -= divisor;
                result.push_str(divisor_char(divisor));
            }
        }

        result
        
    }
}

fn divisor_char(divisor : i32) -> &'static str{
    match divisor {
           1 => "I",
           4 => "IV",
           5 => "V",
           9 => "IX",
           10 => "X",
           40 => "XL",
           50 => "L",
           90 => "XC",
          100 => "C",
          400 => "CD",
          500 => "D",
          900 => "CM",
         1000 => "M",
         _ => unreachable!("Incorrect argument to divisor_char() : {}", divisor)
    }
}
