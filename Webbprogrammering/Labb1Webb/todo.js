const addButton = document.getElementById('add');
const removeAllButton = document.getElementById('removeEntireList');
const boxText = document.getElementById('inputText');
const taskList = document.getElementById('taskList');

function addTask() {
    const contents = boxText.value;
    if (contents.trim() !== "") {
        const newTask = `<li>
            <span>${contents}</span> 
            <button class="delete-item">Ta bort</button>
        </li>`;
        
        taskList.insertAdjacentHTML('beforeend', newTask);
        boxText.value = "";
    }
}

function removeallTasks() {
    taskList.innerHTML = "";
}

addButton.addEventListener("click", addTask);
removeAllButton.addEventListener("click", removeallTasks);

taskList.addEventListener("click", function(event) {
    if (event.target.classList.contains('delete-item')) {
        event.target.parentElement.remove();
    }
});