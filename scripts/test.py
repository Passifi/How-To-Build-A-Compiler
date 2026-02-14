import subprocess
sourceFiles = []
outputFiles = []


result = subprocess.run(["..\\bin\\compiler.exe","..\\CTests\\main.c"])

print(result)
