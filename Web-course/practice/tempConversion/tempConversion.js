
const ftoc = function(num) {
  let celcius = (num - 32)*(5/9);
  
  return Math.round( celcius * 10 ) / 10;
}

const ctof = function(num) {
  let fr = num*(9/5) +32;
  return Math.round( fr * 10 ) / 10;
}

module.exports = {
  ftoc,
  ctof
}
