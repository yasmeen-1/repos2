from itertools import cycle
import json
from flask import Flask, request,jsonify
import requests
import time
class Quiery:
  def __init__(self,operation,parameter,output,count):
    self.operation = operation
    self.parameter=parameter
    self.output=output
    self.count=count
swap=cycle(["http://127.0.0.1:4000","http://127.0.0.1:9000"])
swap2=cycle(["http://127.0.0.1:7000","http://127.0.0.1:10000"])
list_cache = [] 
app = Flask(__name__)
def my_function(oper,par):
    for x in list_cache:
     if ((x.operation)==oper) and ((x.parameter)==par):
        x.count = x.count + 1
        return x.output
    return "not in cache"

def min_count():
    min=list_cache[0].count
    index1=0
    index2=0
    for x in list_cache:
        if(x.count<min) :
          min=x.count
          index2=index1
        index1=index1+1
    list_cache.pop(index2)

def delete_info(para):
    index=0
    for x in list_cache:
        if ((x.operation)=="info") and((x.parameter)==para):
            list_cache.pop(index)
        index=index+1

def delete_search(para):
    index=0
    for x in list_cache:
        if ((x.operation)=="search") and((x.parameter)==para):
            list_cache.pop(index)
        index=index+1

@app.route("/search/<topic>",methods=['GET'])
def search(topic):
    start = time.time()
    value=my_function("search",str(topic))
    end = time.time()
    if("not in cache"==value):
      result=requests.get(next(swap)+"/search/"+str(topic))
      print("Time consumed in server: ",result.elapsed.total_seconds()+(end - start))
      if(len(list_cache) < 5):
       list_cache.append(Quiery("search",str(topic),result.content,0))
      else:
        min_count()
        list_cache.append(Quiery("search",str(topic),result.content,0))
      return (result.content)
    else:
     print("Time consumed in cache: ",end - start)
     return value

@app.route("/info/<item_number>",methods=['GET'])
def info(item_number):
    start = time.time()
    value=my_function("info",item_number)
    end = time.time()
    if("not in cache"==value):
      result=requests.get(next(swap)+"/info/"+str(item_number))
      print("Time consumed in server: ",result.elapsed.total_seconds()+(end - start))
      if(len(list_cache) < 5):
       list_cache.append(Quiery("info",item_number,result.content,0))
      else:
        min_count()
        list_cache.append(Quiery("info",item_number,result.content,0))
      return (result.content)
    else:
     print("Time consumed in cache: ",end - start)
     return value   




@app.route("/decrease/<item_number>",methods=['PUT'])
def decrease(item_number):
    result=requests.put(next(swap)+"/decrease/"+str(item_number),data={'amount':request.json['amount']})
    result2=requests.put(next(swap)+"/decrease/"+str(item_number),data={'amount':request.json['amount']})
    next(swap)
    delete_info(item_number)
    res=json.loads(result.content)
    delete_search(res["topic"])
    return (res["Successful"])

@app.route("/purchase/<item_number>",methods=['PUT'])
def purchase(item_number):
    result=requests.put(next(swap2)+"/purchase/"+str(item_number))
    delete_info(item_number)
    res=json.loads(result.content)
    delete_search(res["topic"])
    return jsonify({'Successful':'You Have Bought The Book You Wanted Successfully'})

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=3000)


