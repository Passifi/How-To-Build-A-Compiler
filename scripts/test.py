import subprocess


class TestCase:
    def __init__(self,name,src,cmp):
        self.name = name
        self.src = src
        self.cmp = cmp


sourceFiles = ["../CTests/main.c"]
compareFiles = [None]

tests = [TestCase("basic Main","../CTests/main.c",None)]

for test in  tests:
    result = subprocess.run(["../bin/compiler",test.src])
    with open(str(test.name.replace(' ', "_") + ".txt"),"w") as f:
        f.writelines(str(result))
