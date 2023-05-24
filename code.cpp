#include <string>
#include <algorithm>
class code {
  public: 
    const std::string code_value(std::string value) {
      int v = stoi(value);
      std::string tmp;
      while (v) {
        if (v % 2) 
          tmp.push_back('1');
        else 
          tmp.push_back('0');
        v /= 2;
      }
      
      while ((int)tmp.size() != 15) {
        tmp.push_back('0');
      }
      reverse(tmp.begin(), tmp.end());

      return tmp;
    }
    const std::string code_comp(std::string comp) {
      if (comp == "0") 
        return "0101010";
      if (comp == "1")
        return "0111111";
      if (comp == "-1")
        return "0111010";
      if (comp == "D")
        return "0001100";
      if (comp == "A") 
        return "0110000";    
      if (comp == "M")
        return "1110000";
      if (comp == "!D")
        return "0001101";
      if (comp == "!A")
        return "0110001";
      if (comp == "!M")
        return "1110001";
      if (comp == "-D")
        return "0001111";
      if (comp == "-A")
        return "0110011";
      if (comp == "-M")
        return "1110011";
      if (comp == "D+1")
        return "0011111";
      if (comp == "A+1")
        return "0110111";
      if (comp == "M+1")
        return "1110111";
      if (comp == "D-1")
        return "0001110";
      if (comp == "A-1")
        return "0110010";
      if (comp == "M-1")
        return "1110010";
      if (comp == "D+A")
        return "0000010";
      if (comp == "D+M")
        return "1000010";
      if (comp == "D-A")
        return "0010011";
      if (comp == "D-M")
        return "1010011";
      if (comp == "A-D")
        return "0000111";
      if (comp == "M-D")
        return "1000111";
      if (comp == "D&A")
        return "0000000";
      if (comp == "D&M")
        return "1000000";
      if (comp == "D|A")
        return "0010101";
      if (comp == "D|M")
        return "1010101";
      return "";
    }

    const std::string code_dest(std::string dest) {
      if (dest == "") return "000";
      if (dest == "M") return "001";
      if (dest == "D") return "010";
      if (dest == "DM" || dest == "MD") return "011";
      if (dest == "A") return "100";
      if (dest == "AM" || dest == "MA") return "101";
      if (dest == "AD" || dest == "DA") return "110";
      return "111";
    } 

    const std::string code_jump(std::string jump) {
      if (jump == "") return "000";
      if (jump == "JGT") return "001";
      if (jump == "JEQ") return "010";
      if (jump == "JGE") return "011";
      if (jump == "JLT") return "100";
      if (jump == "JNE") return "101";
      if (jump == "JLE") return "110";
      return "111";
    }
};