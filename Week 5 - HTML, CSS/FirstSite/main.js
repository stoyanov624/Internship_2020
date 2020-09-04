let button_element = document.querySelector('button');
let counter = document.querySelector('p');
let practises = "0";
function f() {
    practises++;
    counter.textContent = "Practised " + practises + " times";
}

button_element.onclick = f;
