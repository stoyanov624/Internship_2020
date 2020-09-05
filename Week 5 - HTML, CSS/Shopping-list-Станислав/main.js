function itemsCount() {
    return document.getElementsByTagName('li').length;
}

function addItem(text) {

    const newItem = document.createElement('li');
    newItem.classList.add('listItem');
    newItem.innerText = text;
    newItem.id = 'item' + itemsCount();
    
    newItem.addEventListener('click', (e) => {
        e.target.classList.toggle('itemBought');
    })

    const icon = document.createElement('i');
    icon.classList.add('closeIcon');
    icon.addEventListener('click', (e) => {
        const list = document.getElementById('list');
        list.removeChild(e.target.parentElement);
    });

    newItem.appendChild(icon);

    const list = document.getElementById('list');
    list.appendChild(newItem);
}

const inputField = document.getElementById('inputBox');
inputField.addEventListener('keypress', (e) => {
    if(e.keyCode === 13) {
        addItem(inputField.value);
        inputField.value = '';
    }
});

const addButton = document.getElementById('addButton');
addButton.addEventListener('click', () => {
    const inputField = document.getElementById('inputBox');
    
    addItem(inputField.value);
    inputField.value = '';
    
});