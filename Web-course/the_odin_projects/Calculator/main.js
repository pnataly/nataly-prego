 
const screen = document.getElementById('expression'); 
const buttons = document.querySelectorAll('button');
const decimalButton = document.getElementById('dcml');
let newScreen = true;
let keyPress = false;

const numButtons = document.querySelectorAll('.number');
numButtons.forEach(button => button.addEventListener('click', numButtonClick));

const opButtons = document.querySelectorAll('.operator');
opButtons.forEach(button => button.addEventListener('click', opButtonClick));

const calculate = {
    total : null,
    num2 : null,
    operator : null,
    decimal : false
}

function Add(a,b){
    return a+b;
}

function Subtract(a,b){
    return a-b;
}

function Multiply(a,b){
    return a*b;
}

function Divide(a,b){
    return a/b;
}

function Power(a,b){
    return a**b;
}

function Sqrt(a){
    return Math.sqrt(a);
}

function Operate(operator,a,b){
    switch(operator){
        case "plus": 
            return Add(a,b);
            
        case "minus":
            return Subtract(a,b);

        case "mtp":
           return Multiply(a,b);

        case "divde":
            return Divide(a,b);

        case 'power':
            return Power(a,b);

        case 'sqrt':
            return Sqrt(a);
    }
}


document.addEventListener('keydown', e => {
    getKeyboardInput(e);
    if ( ['Enter', 'Return', '/', 'c'].includes(e.key) ){
        e.preventDefault(); 
    } 
});

document.addEventListener('keyup', e => getKeyboardInput(e));

function backspace() {
    let back = [...screen.textContent.split('')];
    back.splice(-1, 1);
    back = back.join('');
    screen.textContent = `${back}`;
}

function clearAll() {
    calculate.operator = null;
    calculate.total = null;
    calculate.num2 = null;
    calculate.decimal = false;
    newScreen = true;
    screen.textContent = '';

    if (buttons[1].disabled === true){
        buttons.forEach(button => {

            if (button.id !== 'clear') {
                button.disabled = false;
                button.classList.remove('disabled');
            }
        });
    }
}

function decimalClick() {
    if (!(`${screen.textContent}`.includes('.'))){
        calculate.decimal = false;
    } 
    if (calculate.decimal === false || newScreen) {
        if (newScreen){
            screen.textContent = '';
        } 
        screen.textContent = (screen.textContent.length + 1) <= 9 ? screen.textContent += decimalButton.textContent : "ERROR";
        calculate.decimal = true;
        newScreen = false;
    }
}

function numButtonClick() {
    if (newScreen) {
        screen.textContent = '';
        newScreen = false;
    }
    screen.textContent = (screen.textContent.length + 1) <= 9 ? screen.textContent += this.textContent : "ERROR";
}


function opButtonClick() {
    if (calculate.total !== null && calculate.num2 === null && newScreen === false){
        calculate.num2 = Number(screen.textContent);
    } 
    if (screen.textContent !== '' && calculate.total === null){
        calculate.total = Number(screen.textContent);
    } 
    if (calculate.num2 !== null){
        total();
    } 
    if (calculate.total === null) {
        calculate.operator = null;
    }
    else {
        calculate.operator = this.id;
    }

    if (calculate.operator === 'sqrt'){
        total();
    } 
    calculate.decimal = false;
    newScreen = true;
}

function round(num, precision) {

    return Number(Math.round(num + 'e' + precision) + 'e-' + precision);
}

function findPrecision(num) {
    num = `${num}`.split('.');
    return 9-(num[0].length + 1);
}

function toggleButton(key, e) {
    let button = document.getElementById(key);
    if (e.type === 'keydown') {
        button.classList.add('key-press');
    }
    else {
        button.click();
        button.classList.remove('key-press');
    }
}


function total() {
    if (calculate.total !== null && calculate.operator !== null) {
        calculate.num2 = Number(screen.textContent);
        calculate.total = Operate(calculate.operator, calculate.total, calculate.num2);
        calculate.num2 = null;
        calculate.operator = null;
        screen.textContent = `${round(calculate.total, findPrecision(calculate.total))}`;
    }

    if (screen.textContent === 'Infinity' || screen.textContent === 'NaN'){
        screen.textContent = "ERROR";
    } 
}


function getKeyboardInput(e) {
    if (e.key >= 0 && e.key < 10) {
        numButtons.forEach(button => {
            if (button.innerText === e.key){
                toggleButton(button.id, e);
            } 
        });
    }
    else {
        switch (e.key) {

            case '+':
            case 'Add':
                toggleButton('plus', e);
                break;

            case '-':
            case 'Subtract':
                toggleButton('minus', e);
                break;

            case '=':
            case 'Enter':
            case 'enter':
                toggleButton('eqls', e);
                break;

            case '/':
            case 'Divide':
                toggleButton('divde', e);
                break;
            
            case '*':
            case 'Multiply':
                toggleButton('mtp', e);
                break;

            case '.':
                toggleButton('dcml', e);
                break;

            case 'c':
            case 'Clear':
                toggleButton('clear', e);
                break;

            case 'Backspace':
                toggleButton('bsp', e);
                break;

            case '^':
                toggleButton('power', e);
                break;

            case 's':
            case '√':
                toggleButton('sqrt', e);
        }
    }
}