from crypt import methods
from flask import Flask, request, jsonify
import json
app = Flask(__name__)
@app.route("/")
def home():
    return "hello world"
@app.route("/info/<id>",methods=['GET'])
def info(id):
    with open('BooksDB.json', 'r') as DBfile:
        data = DBfile.read()
        jsonObject = json.loads(data)
        BooksRecords = jsonObject['BOOK']
        idInt = int(id)

