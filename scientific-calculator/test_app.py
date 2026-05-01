import requests
import json

def test_calculator():
    url = "http://127.0.0.1:5000/calculate"
    headers = {'Content-Type': 'application/json'}
    
    tests = [
        {"expression": "2 + 2", "expected": 4},
        {"expression": "sin(pi/2)", "expected": 1.0},
        {"expression": "log10(100)", "expected": 2.0},
        {"expression": "sqrt(16)", "expected": 4.0},
        {"expression": "2 ** 3", "expected": 8}
    ]
    
    for test in tests:
        response = requests.post(url, data=json.dumps({"expression": test["expression"]}), headers=headers)
        if response.status_code == 200:
            result = response.json().get('result')
            print(f"Test '{test['expression']}': Result={result}, Expected={test['expected']} - {'PASS' if abs(result - test['expected']) < 1e-9 else 'FAIL'}")
        else:
            print(f"Test '{test['expression']}': FAILED with status code {response.status_code}")

if __name__ == "__main__":
    test_calculator()
