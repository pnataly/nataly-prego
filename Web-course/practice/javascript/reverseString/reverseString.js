const reverseString = function(st) {
    let array = [];
    const len = st.length-1;

    for(let i = len; i>=0; i--){
        array.push(st[i]);
    }
    let revstring = array.join("");
    return revstring;
}

module.exports = reverseString
