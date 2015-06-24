import json

class Response:
    data = []

    def to_JSON(self):
        return json.dumps(self, default=lambda o: o.__dict__, sort_keys=True)

class Menu:
    name = 'abc'
    children = []

    def __init__(self, name, children):
        self.name = name
        self.children = children



objList = []
objList.append(Menu('a',[1,2,3]))
objList.append(Menu('b',[1,2,3]))
objList.append(Menu('c',[1,2,3]))
objList.append(Menu('d',[1,2,3]))
objList.append(Menu('e',[1,2,3]))

r = Response()
r.data = objList
print r.to_JSON()
