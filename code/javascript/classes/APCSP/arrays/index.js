// simple arrays

// creating an array of fruits
let fruits = ["Apple", "Banana", "Cherry"];

console.log("Original array:", fruits);

console.log("First fruit:", fruits[0]);
console.log("Second fruit:", fruits[1]);
console.log("Third fruit:", fruits[2]);

// -------------------------------------------------------------

// adding an element at the end (push)
fruits.push("Mango");
console.log("After push:", fruits);

// removing the last element (pop)
fruits.pop();
console.log("After pop:", fruits);

// adding an element at the beginning (unshift)
fruits.unshift("Orange");
console.log("After unshift:", fruits);

// removing the first element (shift)
fruits.shift();
console.log("After shift:", fruits);

// ---------------------------------------------------------------

// looping through an array
console.log("Looping through the array:");

for(let i = 0; i < fruits.length; i++) {
    console.log("Fruit #" + i + " is " + fruits[i]);
}

// finding an element
let i = fruits.indexOf("Banana");
console.log("Index of Banana:", i);

