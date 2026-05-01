from flask import Flask, render_template, request, jsonify
import math

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate():
    try:
        data = request.json
        expression = data.get('expression', '')
        
        # Replace mathematical functions with math module equivalents
        # This is a simple implementation. For a more robust one, a proper parser would be better.
        # But for a "simple" calculator, eval with a limited scope is okay if handled carefully.
        # However, it's safer to use local scientific functions.
        
        safe_dict = {
            'abs': abs, 'min': min, 'max': max,
            'sin': math.sin, 'cos': math.cos, 'tan': math.tan,
            'asin': math.asin, 'acos': math.acos, 'atan': math.atan,
            'sinh': math.sinh, 'cosh': math.cosh, 'tanh': math.tanh,
            'log': math.log, 'log10': math.log10, 'exp': math.exp,
            'sqrt': math.sqrt, 'pi': math.pi, 'e': math.e,
            'pow': pow
        }

        # We'll use a very limited eval for simplicity in this example
        # In a real-world app, use a proper expression parser like 'simpleeval' or 'sympy'
        result = eval(expression, {"__builtins__": None}, safe_dict)
        
        return jsonify({'result': result})
    except Exception as e:
        return jsonify({'error': str(e)}), 400

if __name__ == '__main__':
    app.run(debug=True)
