#include <string>
#include <string.h>
#include <iostream>
class parser {
public:
  std::string code;
  parser(std::string _code) {
    std::string tmp;
    for (int i = 0; i < (int)_code.size(); i ++)
      if(!isspace(_code[i]))
        tmp.push_back(_code[i]);
    
    code = tmp;
  }
  void change(std::string expr) {
    std::string tmp;
    for (int i = 0; i < (int)expr.size(); i ++)
      if(!isspace(expr[i]))
        tmp.push_back(expr[i]);
    code = tmp;
  }

  bool is_a() {
    return code[0] == '@';
  }

  std::string value() {
    std::string tmp;
    for (int i = 1; i < (int)code.size(); i ++)
      tmp.push_back(code[i]);
    return tmp;
  }

  std::string dest() {
    std::string tmp;
    int index = 0;
    for (; index < (int)code.size(); index ++)
      if (code[index] == '=') break;
    if (index == (int)code.size()) return "";
    for (int i = 0; i < (int)code.size(); i ++)
      if (code[i] != '=') 
        tmp.push_back(code[i]);
      else break;
    return tmp;
  }
  
  std::string comp() {
    int i = 0;
    while (i < (int)code.size() && code[i] != '=') 
      i ++;
    if (i == (int)code.size()) {
      int j = 0;
      std::string tmp1;
      while (j < (int)code.size() && code[j] != ';') {
        tmp1.push_back(code[j]);
        j ++;
      }
      return tmp1;
    } 
    std::string tmp;
    for (int ii = i + 1; ii < (int)code.size(); ii ++) {
      if (code[ii] != ';') 
        tmp.push_back(code[ii]);
      else break;
    }
    return tmp;
  }

  std::string jump() {
    int i = 0;
    while ( i < (int)code.size() && code[i] != ';') i ++;
    if (i == (int)code.size()) return "";
    std::string tmp;
    for (int ii = i + 1; ii < (int)code.size(); ii ++)
      tmp.push_back(code[ii]);
    return tmp;
  }
};