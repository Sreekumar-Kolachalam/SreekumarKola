let displayValue = '';
let historyValue = '';

function append(value) {
    displayValue += value;
    updateDisplay();
}

function clearDisplay() {
    displayValue = '';
    historyValue = '';
    updateDisplay();
}

function backspace() {
    displayValue = displayValue.slice(0, -1);
    updateDisplay();
}

function updateDisplay() {
    const display = document.getElementById('display');
    const history = document.getElementById('history');
    display.value = displayValue;
    history.innerText = historyValue;
}

async function calculate() {
    if (!displayValue) return;

    // Show loading or something?
    historyValue = displayValue + ' =';
    updateDisplay();

    try {
        const response = await fetch('/calculate', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ expression: displayValue }),
        });

        const data = await response.json();

        if (response.ok) {
            displayValue = data.result.toString();
        } else {
            displayValue = 'Error';
            console.error(data.error);
        }
    } catch (error) {
        displayValue = 'Error';
        console.error('Calculation error:', error);
    }
    updateDisplay();
}

// Keyboard support
document.addEventListener('keydown', (event) => {
    const key = event.key;
    if (/[0-9]/.test(key)) append(key);
    else if (['+', '-', '*', '/', '.', '(', ')', '%'].includes(key)) append(key);
    else if (key === 'Enter') calculate();
    else if (key === 'Backspace') backspace();
    else if (key === 'Escape') clearDisplay();
});
