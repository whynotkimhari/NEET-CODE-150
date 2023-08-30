var TimeLimitedCache = function() {
    this.dictionary = []
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let doesHas = false
    item = {
        key: key,
        value: value,
        isExist: true,
        duration: duration,
        autoTerminated: function() {
            setTimeout(() => {
                this.isExist = false
            }, this.duration)
        }
    }

    for(let i = 0; i < this.dictionary.length; i++) {
        if(this.dictionary[i] === item) {
            return true;
        }
        else if(this.dictionary[i].key === key && this.dictionary[i].isExist) {
            this.dictionary[i].isExist = false
            doesHas = true
        }
    }
    
    this.dictionary.push(item);
    item.autoTerminated();

    return doesHas;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    for(let i = 0; i < this.dictionary.length; i++) {
        if(this.dictionary[i].isExist && this.dictionary[i].key === key) {
            return this.dictionary[i].value
        }
    }
    return -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    let cnt = 0
    for(let i = 0; i < this.dictionary.length; i++) {
        if(this.dictionary[i].isExist) {
            cnt++
        }
    }
    return cnt;
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
