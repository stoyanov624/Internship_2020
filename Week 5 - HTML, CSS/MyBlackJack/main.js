let suites = ["spades","hearts","clubs","diamonds"];
let values = ["2","3","4","5","6","7","8","9","10","J","Q","K","A"];

const deck = makeDeck();
score = 0;
let screen_score = document.getElementById('score');

let player_hand = document.getElementById('p_cards');
let dealer_hand = document.getElementById('d_cards');

let player_console = document.getElementById('p_console')
let deck_pic = document.getElementById('deck_pic');

let dealer_hand_value = document.getElementById('d_value')
let player_hand_value = document.getElementById('p_value')

let start_btn = document.getElementById('start');
let quit_btn = document.getElementById('quit');
let hit_btn = document.getElementById('hit');
let stand_btn = document.getElementById('stand');

function makeDeck() {
    let deck = new Array();

    for (let i = 0; i < suites.length; i++) {
        for (let j = 0; j < values.length; j++) {
            let card = {Value : values[j], Suit : suites[i]};
            deck.push(card);
        }
    }
    
    return deck;
}

function dealer_draw() {
    dealer_hand.removeChild(dealer_hand.children[1]);
    while(parseInt(dealer_hand_value.innerText) < 17) {
        hand_value_increase(dealer_hand_value);
        draw(deck,dealer_hand);
    }
}


function shuffle() {
    for (let i = 0; i < 1000; i++) {
        var placement1 = Math.floor((Math.random()) * deck.length);
        var placement2 = Math.floor((Math.random()) * deck.length);
        [deck[placement1],deck[placement2]] = [deck[placement2],deck[placement1]];
    }
}

function draw(deck,drawer_hand) {
    let card_name = "cards/" + deck[0].Value + "_of_" + deck[0].Suit + ".svg";
    let card = document.createElement('img');

    card.classList.add('card');
    card.id = deck[0].Value + "_of_" + deck[0].Suit;
    card.src = card_name;

    drawer_hand.appendChild(card);
    console.log(card_name);

    deck.push(deck.shift());

}

function hand_value_increase(hand_value) {
    
    var value = parseInt(hand_value.innerText);
    if (deck[0].Value == "J" || deck[0].Value == "Q" || deck[0].Value == "K") {
        value += 10;
        hand_value.innerText = value;
        return;
    }

    if(deck[0].Value == "A" && value + 11 <= 21) {
        value += 11;
        hand_value.innerText = value;
        return;
    }

    if(deck[0].Value == "A") {
        value += 1;
        hand_value.innerText = value;
        return;
    }
    
    value += parseInt(deck[0].Value);
    hand_value.innerText = value;
    return;
}

function win_game() {

    
    screen_score.innerText = "You won!"

    setTimeout(function() {
        score++;
        screen_score.innerText = "Score:  " + score;}, 2000);

    setTimeout(clear_board, 3000);
    setTimeout(start_new_game, 3000);
}

function lose_game() {

    screen_score.innerText = "You lost!";
 
     setTimeout(function() {
         score--;
         screen_score.innerText = "Score:  " + score;}, 2000);

    setTimeout(clear_board, 5000);
    setTimeout(start_new_game, 5000);
}

function clear_board() {

    while(player_hand.firstChild){
        player_hand.removeChild(player_hand.firstChild);
    }

    while(dealer_hand.firstChild){
        dealer_hand.removeChild(dealer_hand.firstChild);
    }

    player_hand_value.innerText = 0;
    dealer_hand_value.innerText = 0;
}

function start_new_game() {
    hand_value_increase(player_hand_value);
    draw(deck,player_hand);
    hand_value_increase(player_hand_value);
    draw(deck,player_hand);

    hand_value_increase(dealer_hand_value);
    draw(deck,dealer_hand);

    let back = new Image;
    back.src = 'cards/back.jpg';
    dealer_hand.appendChild(back);


    if(player_hand_value.innerText == 21){
        screen_score.innerText = "BlackJack!"
        win_game();
        return;
    }
}

start_btn.addEventListener('click', () => {
    
    start_btn.disabled = true;
    quit_btn.disabled = false;
    player_console.style.visibility='visible'
    deck_pic.style.visibility='visible';
    dealer_hand_value.style.visibility='visible';
    player_hand_value.style.visibility='visible';
    
    shuffle();
    
    player_hand_value = document.getElementById('p_value');

    start_new_game();
});

quit_btn.addEventListener('click', () => {
    player_console.style.visibility='hidden';
    quit_btn.disabled = true;
    start_btn.disabled = false;
    score = 0;
    screen_score.innerText = "Score: 0";
    clear_board();
});

hit_btn.addEventListener('click', () => {
    hand_value_increase(player_hand_value);
    draw(deck,player_hand);

    if(parseInt(player_hand_value.innerText) > 21) {
        dealer_draw();
        lose_game();
        return;
    }
});

stand_btn.addEventListener('click', () => {
    dealer_draw();
    if (parseInt(dealer_hand_value.innerText) > 21) {
        win_game();
        return;
    }

    if(parseInt(dealer_hand_value.innerText) > parseInt(player_hand_value.innerText)) {
        lose_game();
        return;
    }
    else {
        win_game();
        return;
    }
});