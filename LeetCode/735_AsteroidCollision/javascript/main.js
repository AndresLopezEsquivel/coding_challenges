const asteroidCollision = function(asteroids) {
    let stack = [];

    for(let i = 0; i < asteroids.length; i++) {
        if(asteroids[i] > 0) {
            stack.push(asteroids[i]);
        } else if(asteroids[i] < 0) {
            while(stack.length > 0 && stack[stack.length - 1] > 0) {
                if(Math.abs(asteroids[i]) > Math.abs(stack[stack.length - 1])) {
                    stack.pop();
                } else if(Math.abs(asteroids[i]) === Math.abs(stack[stack.length - 1])) {
                    stack.pop();
                    break;
                } else {
                    break;
                }
            }
        }

    }

    return stack; 
};


// TEST CASES 
console.log(asteroidCollision([5, 10, 15])); 
// Expected Output: [5, 10, 15]
console.log(asteroidCollision([5, 10, -5, 8, -8, -7, 3])); 
// Expected Output: [3]
console.log(asteroidCollision([10, -10, 5, -5])); 
// Expected Output: []
console.log(asteroidCollision([8, -8])); 
// Expected Output: []