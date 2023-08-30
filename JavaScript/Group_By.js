/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    let return_object = {}

    for(let i = 0; i < this.length; i++) {
        let newKey = fn(this[i])

        if(newKey in return_object) {
            return_object[newKey].push(this[i])
        }
        else {
            return_object[newKey] = [this[i]]
        }
    }

    return return_object
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
