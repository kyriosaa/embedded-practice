// Voting Eligibility Checker

// check voting eligibility
function canVote(age) {
    return age >= 18;    // returns true if age is 18 or above, false otherwise
}

// Function to demonstrate boolean logic
function booleanOperations() {
    const label1 = document.getElementById("label1");
    const label2 = document.getElementById("label2");

    // const label1Result = document.getElementById("label1Result");
    // const label2Result = document.getElementById("label2Result");
    // let result;

    let age1 = 16;
    let age2 = 20;
    
    label1.textContent = `Age: ${age1}, Eligible to vote: ${canVote(age1)}`;
    label2.textContent = `Age: ${age2}, Eligible to vote: ${canVote(age2)}`;

    if(canVote(age1) == true) {
        result = `You may enter the voting booth`;
        label1Result.textContent = result;
    } else {
        result = `You may not enter the voting booth`;
        label1Result.textContent = result;
    }

    if(canVote(age2) == true) {
        result = `You may enter the voting booth`;
        label2Result.textContent = result;
    } else {
        result = `You may not enter the voting booth`;
        label2Result.textContent = result;
    }

}

booleanOperations();
