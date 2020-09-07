let start_btn = document.getElementById('start');
let quit_btn = document.getElementById('quit');

let suites = ["spades","hearts","clubs","diamonds"];
let values = ["2","3","4","5","6","7","8","9","10","J","Q","K","A"];

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


function shuffle(deck) {
    for (let i = 0; i < 1000; i++) {
        var placement1 = Math.floor((Math.random()) * deck.length)
        var placement2 = Math.floor((Math.random()) * deck.length)
        var tmp = deck[placement1];

        deck[placement1] = deck[placement2];
        deck[placement2] = tmp;
    }
}

function draw(deck) {
    let card_name = "/cards/" + deck[0].Value + "_of_" + deck[0].Suit + ".svg";
    let hand = document.getElementById('p_cards');
    let card = document.createElement('img');
    card.classList.add('card');
    card.id = deck[0].Value + "_of_" + deck[0].Suit;
    card.src = card_name;
    hand.appendChild(card);
    console.log(card_name);
}

let deck = makeDeck();
shuffle(deck);
draw(deck);

let player_console = document.getElementById('p_console')
start_btn.addEventListener('click', () => {
    player_console.style.visibility='visible'
    
});

quit_btn.addEventListener('click', () => {
    player_console.style.visibility='hidden'
});