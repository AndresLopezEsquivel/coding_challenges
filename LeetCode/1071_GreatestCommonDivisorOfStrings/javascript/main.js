// i recommend taking a look at the following references:
// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/repeat
// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/substring
// https://www.w3schools.com/dsa/dsa_ref_euclidean_algorithm.php

const gcdOfStrings = function(str1, str2) { 
    // gcd(a, b) = gcd(b, b%a);
    let a = str1.length;
    let b = str2.length;
    let remainder;


    // compute the GCD of the string lengths using Euclidean algorithm
    while(b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    } 

    // extract the potencial GCD substring
    const gcdSubstring = str1.substring(0, a)

    // check if both strings can be constructed using the GCD substring
    if(str1 === gcdSubstring.repeat(str1.length / a) && str2 === gcdSubstring.repeat(str2.length / a)) {
        return gcdSubstring;
    } else {
        return "";
    }
};

// TEST CASES 
console.log("output:", gcdOfStrings("ABCABC", "ABC")); // "ABC"
console.log("output:", gcdOfStrings("LEET", "CODE")); // ""
console.log("output:", gcdOfStrings("ABABAB", "ABAB")); // "AB"
console.log("output:", gcdOfStrings("VALE", "LEON")); // ""


