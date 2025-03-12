const asteroidCollision = function(asteroids) {
    let stack = [];

    // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Loops_and_iteration#for...of_statement
    for(const asteroid of asteroids) {
        if(asteroid > 0) {
            // right-moving asteroids are always safe to push!
            stack.push(asteroid);
        } else if(asteroid < 0) {
            // while the stack is not empty and the last asteroid is moving right but is smaller in size
            while(stack.length && stack[stack.length - 1] > 0 && stack[stack.length - 1] < -asteroid) {
                stack.pop(); // the smaller right-moving asteroid gets destroyed
            }

            // if there's a match in size, COLLISION HAPPENS!
            if(stack.length && stack[stack.length - 1] === -asteroid) {
                stack.pop()
            } 

            // otherwise, if the stack is empty and the last asteroid is also moving left, push it
            else if (!stack.length || stack[stack.length - 1] < 0) {
                stack.push(asteroid);
            }
        }
    }

    return stack; 
};


// TEST CASES 
console.log(asteroidCollision([5,10,-5])); 
// Expected Output: [5, 10]
console.log(asteroidCollision([8,-8])); 
// Expected Output: []
console.log(asteroidCollision([10,2,-5])); 
// Expected Output: [10]
console.log(asteroidCollision([1, -1])); 
// Expected Output: [] (they cancel each other out)
console.log(asteroidCollision([2, 3, 4, -5]));  
// Expected Output: [-5] (all right-moving asteroids are destroyed)
console.log(asteroidCollision([-2, -1, 1, 2]));  
// Expected Output: [-2, -1, 1, 2] (no collisions, since left-moving asteroids don't collide with each other)
