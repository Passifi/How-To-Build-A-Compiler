from pathlib import Path
import subprocess

BASE_DIR = Path(__file__).resolve().parent
TEST_DIR = BASE_DIR.parent / "CTests"
BIN_DIR = BASE_DIR.parent / "bin"


class TestCase:
    def __init__(self,name,src,cmp):
        self.name = name
        self.src = src
        self.cmp = cmp


compiler = BIN_DIR / "compiler"
compareFiles = [None]

tests = [TestCase("basic Main","../CTests/main.c",None),TestCase("simple","../CTests/mathfunc.c",None)
         ]

for test in  tests:
    result = subprocess.run([compiler,test.src])
    output_file = BASE_DIR / (test.name.replace(" ","_") + ".txt") 
    with open(output_file,"w") as f:
        f.writelines(str(result))
