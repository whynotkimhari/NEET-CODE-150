/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */

// Cause the symbol is not enumerate => So it will
// not be considered as a key when using Object.keys()
Function.prototype.callPolyfill = function(context, ...args) {
    let symbol = Symbol('Function');
    context[symbol] = this;
    return context[symbol](...args);
}

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
