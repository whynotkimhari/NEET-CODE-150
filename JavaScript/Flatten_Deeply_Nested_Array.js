/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    if(!n) return arr

    let rs_arr = []
    for(let i = 0; i < arr.length; i++) {
        if(typeof arr[i] === 'object') {
          flat_n_arr = flat(arr[i], n - 1)
          for(let j = 0; j < flat_n_arr.length; j++) {
            rs_arr.push(flat_n_arr[j])
          }
        }
        else {
          rs_arr.push(arr[i])
        }
    }
    return rs_arr
    //console.log(typeof rs_arr)
};
