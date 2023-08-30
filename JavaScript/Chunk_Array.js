/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    arr_length = arr.length
    if(!arr_length) return arr

    if(arr_length <= size) return [arr]

    var rs_arr = []
    for(let i = 0; i < arr_length; i += size) {
        let sub_arr = []
        for(let j = i; j < Math.min(arr_length, i + size); j++) {
            sub_arr.push(arr[j])
        }
        rs_arr.push(sub_arr)
    }
    return rs_arr
};
