
    let computerPoints = 0;
    let playerPoints = 0;
    let round = 1;
    const NUM_OF_ROUND = 5;
    let userName;

    function getUserName(){
        let user = prompt("Enter your name:", "player 1");
        if(user == null || user == " "){
            document.getElementById("playerName").innerHTML ="Player1";
            userName = "Player1";
        }
        else {
            document.getElementById("playerName").innerHTML = user;
            userName = user;
        }
    }

    function Rock(){
        let computer = computerPlay();
        let player = "rock";
        setUserChoice(player);
        setComputerChoice(computer);

        winner = getWinner(player,computer);
        playRound(player, computer, winner);
    }

    function Paper(){
        let computer = computerPlay();
        let player = "paper";
        setUserChoice(player);
        setComputerChoice(computer);

        winner = getWinner(player,computer);

        playRound(player, computer, winner);
    }
 
    function Scissors(){
        let computer = computerPlay();
        let player = "scissors";
        setUserChoice(player);
        setComputerChoice(computer);

        let winner = getWinner(player,computer);
        playRound(player, computer, winner);
    }


    function computerPlay() {
    choices = ["rock","paper","scissors"];
    return choices[Math.floor(Math.random() * choices.length)];
    }
   
    function getWinner(playerSelection, computerSelection){
        playerSelection = playerSelection.toLowerCase();

        if(playerSelection == computerSelection){
            return "tie";
        }
        else if( playerSelection == "rock" && computerSelection == "scissors" || playerSelection == "paper" && computerSelection == "rock" || playerSelection == "scissors" && computerSelection == "paper"){
            return "player";
        }
        else {
            return "computer";
        }
    }

    function playRound(playerSelection, computerSelection, winner) {
        playerSelection = playerSelection.toLowerCase();
        if(round > NUM_OF_ROUND){
            game();
        }
        else {
            round++;
            if(winner == "player"){
                ++playerPoints;
                document.getElementById("playerCount").innerHTML = playerPoints;
                document.getElementById("winMsg").innerHTML = `You Win! ${playerSelection} beats ${computerSelection}`;
            }
            else if(winner == "computer"){
                ++computerPoints;
                document.getElementById("computerCount").innerHTML = computerPoints;
                document.getElementById("winMsg").innerHTML = `You Lose! ${computerSelection} beats ${playerSelection}`;
            }
            else {
                document.getElementById("winMsg").innerHTML = `Draw of ${playerSelection}`;
            }
        }
    }

    function game() {
        round = 0;
        document.getElementById("userChoice").innerHTML = null;
        document.getElementById("computerChoice").innerHTML = null;
        if(computerPoints > playerPoints){
            document.getElementById("winMsg").innerHTML = `Computer Win with ${computerPoints} points!`;
        }
        else if(playerPoints > computerPoints){
            document.getElementById("winMsg").innerHTML = `${userName} Win with ${playerPoints} points!`;
        }
        else{
            document.getElementById("winMsg").innerHTML = `Draw of ${playerPoints} points!`;
        }
        computerPoints = 0;
        document.getElementById("computerCount").innerHTML = computerPoints;
        playerPoints = 0;
        document.getElementById("playerCount").innerHTML = playerPoints;
   }



   function newGame(){
       computerPoints = 0;
       document.getElementById("computerCount").innerHTML = computerPoints;
       playerPoints = 0;
       document.getElementById("playerCount").innerHTML = playerPoints;
       document.getElementById("winMsg").innerHTML = "";
       document.getElementById("userChoice").innerHTML = null;
       document.getElementById("computerChoice").innerHTML = null;
   }

   function setUserChoice(choice){
        document.getElementById("userChoice").innerHTML = getSymbol(choice);
    }

    function setComputerChoice(choice){
        document.getElementById("computerChoice").innerHTML = getSymbol(choice);
    }

    function getSymbol(choice){
        if (choice == "rock") return "<i class=\"fa fa-hand-rock-o\"></i>";
        if (choice == "paper") return "<i class=\"fa fa-hand-paper-o\"></i>";
        if (choice == "scissors") return "<i class=\"fa fa-hand-scissors-o\"></i>";
    }