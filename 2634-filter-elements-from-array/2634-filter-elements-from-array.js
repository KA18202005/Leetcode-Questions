/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const transformedArr = [];
    for(let i = 0; i < arr.length; i++) {
        if(fn(arr[i], i)) transformedArr.push(arr[i]);
    }
    return transformedArr;
};