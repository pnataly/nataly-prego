const repeatString = function(string, num) {
    let repstring = '';
    if(num < 0 ){
        return 'ERROR';
    }
    for(let i = num; i > 0; i--){
        repstring += string;
    }
    return repstring;
}

module.exports = repeatString
