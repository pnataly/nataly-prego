// const removeFromArray = function(array, item1, item2) {
//     for(let i =0; i<array.length; i++){
//         if (array[i] ==  item1 || array[i] == item2){
//             array.splice(i,1);
//             i--;
//         }
//     }
//     return array;
// }

const removeFromArray = function(...args) {
    const array = args[0];
    let newarr = [];

    array.forEach((item) => {
        if (!args.includes(item)) {
          newarr.push(item);
        }
      });
    return newarr;
}

module.exports = removeFromArray


