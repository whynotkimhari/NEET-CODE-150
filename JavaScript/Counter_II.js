/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var counter = {
        init: init,
        base: init,
        increment: function() {
            return ++this.init;
        },
        decrement: function() {
            return --this.init;
        },
        reset: function() {
            this.init = this.base;
            return this.init;
        }
    }
    return counter;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
