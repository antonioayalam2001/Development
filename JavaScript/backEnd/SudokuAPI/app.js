const puzzleBoard = document.querySelector("#board");
const solveButton = document.querySelector("#button");
const squares = 81;
const submission = [];

for (let i = 0; i < squares; i++) {
    const inputElement = document.createElement("input");
    inputElement.setAttribute("type", "number");
    inputElement.setAttribute("min", "1");
    inputElement.setAttribute("max", "9");
    puzzleBoard.appendChild(inputElement);
    if (
        ((i % 9 == 0 || i % 9 == 1 || i % 9 == 2) && i < 21) ||
        ((i % 9 == 6 || i % 9 == 7 || i % 9 == 8) && i < 27) ||
        ((i % 9 == 3 || i % 9 == 4 || i % 9 == 5) && (i > 27 && i < 53)) ||
        ((i % 9 == 0 || i % 9 == 1 || i % 9 == 2) && i > 53) ||
        ((i % 9 == 6 || i % 9 == 7 || i % 9 == 8) && i > 53)
    ) {
        inputElement.classList.add('color')
    }
}

const joinValues = () => {
    const inputs = document.querySelectorAll("input");
    inputs.forEach((input) => {
        if (input.value) {
            if (input.value == 'a') {
                alert('no')
            } else {
                submission.push(input.value);
                
            }
        } else {
            submission.push(".");
        }
    });
    console.log(submission);
};

const populateValues = (isSolvable, solution) => {
    const inputs = document.querySelectorAll('input');
    // console.log(solution[0][0]);
    const generalSolution = []
    solution.forEach((solutions) => {
        solutions.forEach((x) => {
            generalSolution.push(x.toString())
        })
    })
    const response = generalSolution.join("")
    console.log(response);
    console.log(generalSolution);
    if (isSolvable == 'True' && solution) {
        inputs.forEach((input, i) => {
            input.value = response[i]
        })
    } else {
        alert('No se puede resolver')
    }

}

const solve = () => {
    joinValues()
    const data = submission.join("")
    console.log('data', data);
    fetch('http://localhost:8000/solve', {
        method: 'POST',
        header: {
            'Content-Type': 'application/json',
            'Accept': 'application/json'
        }
    }).then(response => response.json())
        .then(data=> console.log(data))
        .catch((err) => {
            console.log(err)
        })
};

solveButton.addEventListener("click", solve);
