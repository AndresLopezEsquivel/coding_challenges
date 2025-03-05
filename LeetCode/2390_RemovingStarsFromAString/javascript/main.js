var removeStars = function(s) {

    let stack = [];

    for(let i = 0; i < s.length; i++) {
        s[i] === '*' ? stack.pop() : stack.push(s[i]);
    }

    return stack.join('');
    
};

// TEST CASES
console.log(removeStars("leet**cod*e")); // output: "lecoe"
console.log(removeStars("erase*****")); // output: ""