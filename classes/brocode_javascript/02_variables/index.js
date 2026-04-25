// variable = A container that stores a value.
//            Behaves as if it were the value it contains.

// 1. declaration   let x;
// 2. assignment    x = 100;

/*
// --- numbers ---
let age = 23;
let price = 10.99;
let gpa = 2.1;

console.log(typeof age);
console.log(`You are ${age} years old`);
console.log(`The price is $${price}`);
console.log(`Your GPA is: ${gpa}`);
// ---------------

// --- strings ---
let firstName = "Kin";
let favFood = "Pizza";
let email = "kin123@gmail.com";

console.log(typeof firstName);
console.log(`Your name is ${firstName}`);
console.log(`You like ${favFood}`);
console.log(`Your email is ${email}`);
// ---------------

// --- booleans ---
let online = false;
let forSale = true;
let isStudent = true;

console.log(typeof online);
console.log(`Kin is online: ${online}`);
console.log(`Is this car for sale?: ${forSale}`);
console.log(`I am a student: ${isStudent}`);
// ----------------
*/

let fullName = "Kin H";
let age = 23;
let isStudent = true;

document.getElementById("p1").textContent = `Your name is ${fullName}`;
document.getElementById("p2").textContent = `You are ${age} years old`;
document.getElementById("p3").textContent = `You are enrolled in school: ${isStudent}`;