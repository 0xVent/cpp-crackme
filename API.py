from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/check_key', methods = ['POST'])
def home():
    data = request.get_json()
    key = data.get('key')
    print(key)
    if key == "7B9K-Z3MP-QT2V-W8N5":
        return 'VALID'
    else:
        return 'UNVALID'

if __name__ == '__main__':
    app.run(debug=True)