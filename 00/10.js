/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
const isMatch = function (s, p) {

    const altered_p = parse_regex(p);

    // Indexed as [string index to stop exclusive, altered_p index to stop exclusive]
    // true = matches. false = no match. undefined/empty = haven't checked.
    let solutions = construct_ground_cases(s.length, altered_p);

    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < altered_p.length; j++) {
            // Need to add one to these indexes because 0 means "0 length" rather than
            // "0th index". See comment on line 10
            solutions[i + 1][j + 1] = dynamic_programming_entry(i, j, solutions, s, altered_p);
        }
    }

    return solutions[s.length][altered_p.length];
};

function construct_ground_cases(s_length, altered_p) {
    let solutions = [];
    for (let i = 0; i <= s_length; i++) {
        solutions.push([]);
        for (let j = 0; j <= altered_p.length; j++) {
            solutions[i].push(undefined);
        }
    }

    solutions[0][0] = true; // Empty String matches No Regex

    for (let i = 1; i <= altered_p.length; i++) {
        solutions[0][i] = altered_p[i - 1].star && solutions[0][i - 1];
    }

    for (let i = 1; i <= s_length; i++) {
        solutions[i][0] = false;
    }

    return solutions;
}

function parse_regex(p) {
    let altered_p = [];

    for (let i = 0; i < p.length; i++) {
        let regex_matcher = {};
        regex_matcher.char = p[i];
        regex_matcher.star = false;
        if (next_location_star(i, p)) {
            regex_matcher.star = true;
            i++; // Skip past the star for next parse    
        }
        altered_p.push(regex_matcher);
    }

    return altered_p;
}

function string_char_matches_p_char(s_char, p_maybe_char) {
    if (p_maybe_char === undefined) {
        return false;
    }

    const p_char = p_maybe_char.char;

    return (p_char === ".") || (s_char === p_char);
}

function next_location_star(index, p) {
    const new_index = index + 1;
    return new_index !== p.length && p[new_index] === "*";
}

function solution_lookup(index_s, index_p, solutions) {
    return solutions[index_s][index_p];
}

// A single entry in the dynamic solution table
function dynamic_programming_entry(s_index, p_index, solutions, s, altered_p) {

    const p_value = altered_p[p_index];

    // If the current string character satisfies
    // the current character in the regex
    if (string_char_matches_p_char(s[s_index], p_value)
        // ... and the prefixing regex matches the prefixing string
        && solution_lookup(s_index, p_index, solutions)) {
        return true;
    }

    // If the character doesn't have a star, the above covers all
    // cases we need to return true.
    if (!p_value.star) {
        return false;
    }

    // Now we know we're dealing with a star charcter

    // Try matching 0 occurrences
    if (solution_lookup(s_index + 1, p_index, solutions)) {
        return true;
    }
    
    // Continue matching occurances until we exhaust the string or
    // a character which doesn't match appears.
    // If at any point we detect a regex match, we can return early.
    // If the prefix regex doesn't match but we have occurances, we
    // have to keep checking.
    for (let i = s_index; i >= 0 && string_char_matches_p_char(s[i], p_value); i--) {
        if (solution_lookup(i, p_index, solutions)){
            return true;
        }
    }

    return false;
}
