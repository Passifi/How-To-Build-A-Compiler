from sys import argv
def parse(path):
    enumContainer = []
    enumContainer.append("enum TokenType {")
    arrayContainer = []

    with open(path) as f:
        
        lines = f.readlines()
        tokenNo = len(lines)
        arrayContainer.append(f"std::array<std::pair<TokenType, std::string_view>,{tokenNo}> token_to_string = {{{{")    
        for line in lines:
            value = line.replace("\n","").upper()
            enumContainer.append(f"{value},\n")     
            arrayContainer.append(f"{{TokenType::{value}, \"{value}\"}},\n") 
    enumContainer.append("};\n")
    arrayContainer.append("}};\n")
    lines = ["#include <array>\n", "#include <string_view>\n"] 
    lines += enumContainer + arrayContainer
    
    with open("tokens.h", "w") as f:
        f.writelines(lines)

if(len(argv)> 1):
    parse(argv[1])


