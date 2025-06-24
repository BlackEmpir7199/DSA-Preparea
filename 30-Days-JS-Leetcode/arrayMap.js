/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newArr = []
    arr.forEach((e,i)=>{
        newArr.push(fn(e,i));
    });
    return newArr;
};