
const workDisplay = document.getElementById('workDisplay'); 
const breakDisplay = document.getElementById('breakDisplay'); 
const minutes = document.getElementById('minutes');
const seconds = document.getElementById('seconds');

let isTimerOn = false; 
let isWorking = true;
let totalTime = 25*60;
let breakTime = 5;

let alarm = new Audio('alarm.mp3')


function work_up(){
    if(isTimerOn){
        return;
    }
    let num =  ++workDisplay.innerHTML;
    workDisplay.textContent = num;
    minutes.textContent = num;
    totalTime = num*60;
    setTime(totalTime);
}

function work_down(){
    if(isTimerOn){
        return;
    }
    if(workDisplay.innerHTML <= 1){
        workDisplay.textContent = 1;
        minutes.textContent = 01;
        totalTime = 60;
        setTime(totalTime);
    }
    else{
        let num = --workDisplay.innerHTML;
        workDisplay.textContent = num;
        minutes.textContent = num;
        totalTime = num*60;
        setTime(totalTime);
    } 
}


function break_up(){
    if(isTimerOn){
        return;
    }
    breakDisplay.textContent = ++breakTime;
}

function break_down(){
    if(isTimerOn){
        return;
    }
    if(breakDisplay.innerHTML <= 0){
        breakTime = 0;
        breakDisplay.textContent = breakTime;
    }
    else{
        breakDisplay.textContent = --breakTime;
    } 
}



function Play(){
    isTimerOn = true;
    setTimeout(counter, 1000);
}

function Pause(){
    isTimerOn = false;
}

function Reset(){
    isTimerOn = false;
    workDisplay.textContent = 25;
    breakDisplay.textContent = 5;
    minutes.textContent = 25;
    seconds.innerHTML = ":00";
    totalTime = 25 * 60;
    setWorkOrBreakTimer();
    setTime(totalTime);
}


function setTime(num) {
    setWorkOrBreakTimer();    
    minutes.innerHTML = Math.floor(num / 60);
    seconds.innerHTML = getDisplay(num);    
}

function getDisplay(num) {
    let secs = (num % 60)
    if ( secs < 10) {
        return ':0' + secs;
    } else {
        return ':'+secs;
    }
}

function counter() {
    if(!isTimerOn){
        return;
    } 
    -- totalTime;
    setTimeout(counter, 1000);
    setTime(totalTime);
}

function setWorkOrBreakTimer() {
    if(totalTime > 0){   
        return;
    } 
    else if (isWorking && totalTime == 0) {        
        isWorking = false;
        alarm.play();
        totalTime = breakTime * 60;
        $('#top').toggleClass("opacity", true);
        $("#bottom").toggleClass("opacity", false);
    }

    else {
        isWorking = true;
        totalTime = workDisplay.textContent*60;
        $('#top').toggleClass("opacity", false);
        $("#bottom").toggleClass("opacity", true);
    }
}