const gcdOfStrings = function(str1, str2) {
    // the eucledian algorithm: 
    // gcd(a, b) = gcd(b, b%a);
    let a = str1.length;
    let b = str2.length;
    let remainder;

    while(b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    } 

    const gcd = str1.substring(0, a) // 

    // check the docs for reference of the .repeat() method:
    // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/repeat
    if(str1 === gcd.repeat(str1.length / a) && str2 === gcd.repeat(str2.length / a)) {
        return gcd;
    } else {
        return "";
    }
};

// TEST CASES 
console.log("output:", gcdOfStrings("ABCABC", "ABC")); // "ABC"
console.log("output:", gcdOfStrings("LEET", "CODE")); // ""
console.log("output:", gcdOfStrings("ABABAB", "ABAB")); // "AB"
console.log("output:", gcdOfStrings("VALE", "LEON")); // ""


