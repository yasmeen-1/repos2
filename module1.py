from flask import Flask, request,jsonify
import requests

app = Flask(__name__)

@app.route("/search/<topic>",methods=['GET'])
def search(topic):
    # result=requests.get("http://192.168.136.5:4000/search/"+str(topic))
    result=requests.get("http://127.0.0.1:4000/search/"+str(topic))
    return (result.content)


@app.route("/info/<item_number>",methods=['GET'])
def info(item_number):
    # result=requests.get("http://192.168.136.5:4000/info/"+str(item_number))
    result=requests.get("http://127.0.0.1:4000/info/"+str(item_number))
    return (result.content)





if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)