// Accepting user input

// 1. EASY WAY - window prompt
// 2. PROFESSIONAL WAY - HTML text box

/*
// --- EASY WAY ---
let username = window.prompt("What's your username?");
console.log(username);
*/

// --- PROFESSIONAL WAY ---
document.getElementById("mySubmit").onclick = function() {
    let username = document.getElementById("myText").value;
    document.getElementById("myH1").textContent = `Hello ${username}`
}