
const container = document.getElementById('container');

function makeGrid(num){
    container.style.setProperty('--grid-rows', num);
    container.style.setProperty('--grid-column', num);
    for(let i = 0; i < (num*num); i++){
        let cell = document.createElement('div');
        cell.classList.add('grid-item');
        container.appendChild(cell);
    }
    mouseTrack('black');
}

//event lisnter to the erase button 
const eraser = document.getElementById('eraser');
eraser.addEventListener("click", function(e){
    container.addEventListener("mousedown", function(e){
        e.target.style.background = 'white';
    });
});
 


//event lisnter to the clear button 
const clear = document.getElementById('clear');
clear.addEventListener("click", function() {
    const cells = document.querySelectorAll('.grid-item');
    cells.forEach(element => {
        element.style.background = 'white';
    });
});

//event lisnter to the resize button
const resize = document.getElementById('resize');
resize.addEventListener("click", function(){
    let num = prompt("What size of grid do you want?");
    if(num == null || num <= 0)
    {
        return;
    }
    while (container.hasChildNodes()) {
        container.removeChild(container.lastChild); 
    }
    makeGrid(num);
});


// Create function to Choose a Color
let colorBtn = document.querySelector('#color-picker');
let colorPicker = new Picker(colorBtn);
colorPicker.onDone = function(color) {
    mouseTrack('rgba(' + color.rgba[0] + ', ' + color.rgba[1] + ', ' + color.rgba[2] + ', ' + color.rgba[3] + ')');
};

function mouseTrack(color) {
    let cells = document.querySelectorAll('.grid-item');
    let mouseHold = false;
    cells.forEach((item) => {
        //single click
        item.addEventListener('mousedown', function() {
            item.style.backgroundColor = color;
            mouseHold = true;
        });
        //Drag portion
        item.addEventListener('mouseover', function() {
                if (mouseHold) {  
                    item.style.backgroundColor = color;
                }
            });
            item.addEventListener('mouseup', function() {
                mouseHold = false;
                item.removeEventListener('mouseover', function() {
                    item.style.backgroundColor = color;
                });
            });
        
    });
}

function getRandomColor() {
    let letters = '0123456789ABCDEF';
    let color = '#';
    for (let i = 0; i < 6; i++) {
      color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
  }


const rand = document.getElementById('random');
rand.addEventListener("click", random);

function random() {
    let cells = document.querySelectorAll('.grid-item');
    let mouseHold = false;
    cells.forEach((item) => {
        //single click
        item.addEventListener('mousedown', function() {
            item.style.backgroundColor = getRandomColor();
            mouseHold = true;
        });
        //Drag portion
        item.addEventListener('mouseover', function() {
                if (mouseHold) {   
                   item.style.backgroundColor = getRandomColor();
                }
            });
            item.addEventListener('mouseup', function() {
                mouseHold = false;
                item.removeEventListener('mouseover', function() {
                    item.style.backgroundColor = getRandomColor();
                });
            });      
    });
    
}
