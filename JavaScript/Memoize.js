/**
 * @param {Function} fn
 */
function memoize(fn) {
    var memory = {};
    return function(...args) {
        var key;
        if(args.length == 2) key = `${args[0]}-${args[1]}`;
        else key = args[0];
        
        if(!(key in memory)) {
            memory[key] = fn(args[0], args[1]);
        }
        return memory[key];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
