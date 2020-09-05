function itemsCount() {
    return document.getElementsByClassName('list');
}


function addItem(text) {

    const list = document.getElementById('lst');
    if(list.children.length >= 10) {
        alert("Max products reached!");
        return;
    }
    const item = document.createElement('li');
    
    item.classList.add('storedItem');
    item.innerText = text;
    item.id = 'item' + itemsCount();
    
    item.addEventListener('click', (e) => {
        e.target.classList.toggle('itemBought');
    })
    
    const icon = document.createElement('i');
    icon.classList.add('removeIcon');
    item.appendChild(icon);
    
    icon.addEventListener('click', (e) => {
        list.removeChild(item);
    })
    
    list.appendChild(item);
    

}

const inputField = document.getElementById('input');
inputField.addEventListener('keypress', (e) => {

    if(e.keyCode === 13) {
        addItem(inputField.value);
        inputField.value = '';
    }
})

const addButton = document.getElementById('btn');
addButton.addEventListener('click', () => {
    const inputField = document.getElementById('input');
    
    if(inputField.value.length){
        addItem(inputField.value);
        inputField.value = '';
        return;
    }
    window.alert("EMPTY STRING FOOL");
    
});
