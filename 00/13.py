class Solution:
    def romanToInt(self, s: str) -> int:
        value = {
        "I" : 1,
        "V" : 5,
        "X" : 10,
        "L" : 50,
        "C" : 100,
        "D" : 500,
        "M" : 1000,
        "J" : 0}

        last_symbol = "J"
        result = 0
        for i in s:
            if value[i] > value[last_symbol]:
                result -= 2 * value[last_symbol]
            result += value[i]

            last_symbol = i

        return result
