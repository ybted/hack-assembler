#include <map>
#include <string>
class symboltable {
  public:
    int c;
    std::map<std::string, int> m;
    symboltable() {
      c = 16;
      m["R0"] = 0;
      m["R1"] = 1;
      m["R2"] = 2;
      m["R3"] = 3;
      m["R4"] = 4;
      m["R5"] = 5;
      m["R6"] = 6;
      m["R7"] = 7;
      m["R8"] = 8;
      m["R9"] = 9;
      m["R10"] = 10;
      m["R11"] = 11;
      m["R12"] = 12;
      m["R13"] = 13;
      m["R14"] = 14;
      m["R15"] = 15;
      m["SP"] = 0;
      m["LCL"] = 1;
      m["ARG"] = 2;
      m["THIS"] = 3;
      m["THAT"] = 4;
      m["SCREEN"] = 16384;
      m["KBD"] = 24576;
    }
    
    void map(std::string a, int b) {
      m[a] = b;
    }

    bool find(std::string key) {
      return m.find(key) != m.end();
    }

    int value(std::string v) {
      return m[v];
    }

    int count() {
      c ++;
      return c - 1;
    }

};