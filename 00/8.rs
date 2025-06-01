use std::iter::Peekable;
use std::str::Chars;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {

        let mut iter = s.chars().peekable();

        while let Some(&ch) = iter.peek() {
            if ch != ' ' {
                break;
            }
            iter.next();
        }

        let negative : bool = determine_if_neg_and_consume(&mut iter);

        let mut result_i64 = 0i64;

        while let Some(digit) = maybe_digit(&mut iter){
            result_i64 = result_i64
                        .saturating_mul(10)
                        .saturating_add(digit);

                if result_i64 > i32::MAX as i64 && !negative{
                    return i32::MAX;
                }else if result_i64 > -1 * (i32::MIN as i64) && negative{
                    return i32::MIN;
                }
            
            iter.next();
        }

        if negative {
            result_i64 = -1 * result_i64;
        }

        return result_i64 as i32
        
    }
}

fn determine_if_neg_and_consume(iter: &mut Peekable<Chars>) -> bool{
    let maybe_char = iter.peek();
    match maybe_char {
        Some(&'-') => {
            iter.next();
            true
        }
        Some(&'+') => {
            iter.next();
            false
        }
        _ => {
            false
        }

    }
}

// Mutation is only necessare because Peekable's internals change
// There's not mutation occuring which is relevant to the greater context
fn maybe_digit(iter: &mut Peekable<Chars>) -> Option<i64>{
    iter
    .peek()
    .map(|x| x.to_digit(10))
    .flatten()
    .map(|z| z as i64)
}
