from flask import Flask, request, jsonify
import json


app = Flask(__name__)

@app.route("/search/<topic>",methods=['GET'])
def search(topic):
    with open('bookStore2.json', 'r') as f:
        data = f.read()
        output=[]
        records = json.loads(data)
        Book = records['Book']
        for record in Book:
            if record['topic'] == topic:
              output.append (record['item_number'])
              output.append (record['title'])
        if len(output) !=0:
            return jsonify(output)
        return jsonify({'Error': 'OPS! No Books With This Topic'})

@app.route("/info/<int:item_number>",methods=['GET'])
def info(item_number):
    with open('bookStore2.json', 'r') as f:
        data = f.read()
        records = json.loads(data)
        Book = records['Book']
        for record in Book:
            if record['item_number'] == int(item_number):
                return jsonify([{"title":record['title'],"number_of_items":record['number_of_items'],"cost":record['cost']}])
        return jsonify({'Error': 'OPS! No Book With This ID'})
        




@app.route("/decrease/<item_number>",methods=['PUT'])
def decrease(item_number):
    with open('bookStore2.json', 'r') as f:
        req =request.form.get('amount')
        data = f.read()
        records = json.loads(data)
        count=0
        new_records = []
        Book = records['Book']
        for record in Book:
            if record['item_number'] == int(item_number):
                y=int(req)
                x=record['number_of_items']
                if x-y < 0:
                    count=1
                if x-y >= 0:
                  update_records=record
                  record['number_of_items']=record['number_of_items']-y
                  count=2
            new_records.append(record)
        with open("bookStore2.json", "w") as jsonFile:
            json.dump({'Book':new_records},jsonFile)
            if count ==2:
               return jsonify({'topic':update_records['topic'],'Successful':'Decrease The Number Of Items In Stock'})
            if count ==1:
               return jsonify({'Error': 'OPS! The Book Is Out Of Stock'})
            return jsonify({'Error': 'OPS! No Book With This ID'})
if __name__ == '__main__':   app.run(debug=True, host='0.0.0.0', port=9000)
