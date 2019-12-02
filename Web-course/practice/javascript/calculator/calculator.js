function add (a ,b) {
	return a+b;
}

function subtract (a,b) {
	return a-b;
}

function sum (array) {
	if(array === undefined)
	{ 
		return 0;
	}
	let sum = 0;
	array.forEach(element => {
		sum += element;
	});
	return sum;
}

function multiply (array) {
	if(array === undefined)
	{ 
		return 0;
	}
	let mult = 1;
	array.forEach(element => {
		mult *= element;
	});
	return mult;
}

function power(a,b) {
	return a**b;
}

function factorial(num) {
	let fact = 1;
	if(num == 0){
		return fact;
	}
	for(let i=1; i<=num; i++){
		fact *= i;
	}
	return fact;
}

module.exports = {
	add,
	subtract,
	sum,
	multiply,
    power,
	factorial
}