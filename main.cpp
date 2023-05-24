#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <unistd.h>
#include "code.cpp"
#include "parser.cpp"
#include "symboltable.cpp"

void trans_no_symbol(std::ifstream &file, std::ofstream &out) {
  char buffer[100];
  while (file.getline(buffer, 100)) {
    std::string tmp1(buffer);
    std::string tmp;
    for (int i = 0; i < (int)tmp1.size(); i ++) {
      if (isspace(tmp1[i])) 
        continue;
      if (tmp1[i] == '/')
        break;
      else 
        tmp.push_back(tmp1[i]);
    }
    if (tmp.empty()) 
      continue;
    parser p(tmp);
    code c;
    if (p.is_a()) {
      std::string value = p.value();
      std::string new_code = "0" + c.code_value(value);
      out << new_code;
      out << std::endl; 
    } else {
      std::string dest = p.dest();
      std::string comp = p.comp();
      std::string jump = p.jump();
      std::string new_code = "111" + c.code_comp(comp) + c.code_dest(dest) + c.code_jump(jump);
      out << new_code;
      out << std::endl; 
    }
  }
}

void trans_symbol(std::ifstream &input, std::ofstream &output) {
  symboltable s;
  char buffer[100];
  int count = 0;
  while (input.getline(buffer, 100)) {
    std::string tmp1(buffer);
    std::string tmp;
    for (int i = 0; i < (int)tmp1.size(); i ++) {
      if (isspace(tmp1[i])) 
        continue;
      if (tmp1[i] == '/')
        break;
      else 
        tmp.push_back(tmp1[i]);
    }
    if (tmp.empty()) 
      continue;
    std::string symbol;
    if (tmp[0] == '(') {
      for (int i = 1; ; i ++) {
        if (tmp[i] == ')') 
          break;
        symbol.push_back(tmp[i]);
      }
      count --;
    }
    count ++;
    if (!symbol.empty())
      s.map(symbol, count); 
  }
  input.clear();
  input.seekg(0);
  while (input.getline(buffer, 100)) {
    std::string tmp1(buffer);
    std::string tmp;
    for (int i = 0; i < (int)tmp1.size(); i ++) {
      if (isspace(tmp1[i])) 
        continue;
      if (tmp1[i] == '/' || tmp1[i] == '(')
        break;
      else 
        tmp.push_back(tmp1[i]);
    }
    if (tmp.empty()) 
      continue;
    if (tmp[0] == '@') {
      std::string symbol;
      for (int i = 1; i < (int)tmp.size(); i ++) 
        symbol.push_back(tmp[i]);
      if (isdigit(symbol[0])) {
        output << tmp << std::endl;
        continue;
      }
      if (s.find(symbol) == true) 
      {
        std::string value = "@" + std::to_string(s.value(symbol));
        output << value << std::endl;
      } else {
        int num = s.count();
        s.map(symbol, num);
        std::string value = "@" + std::to_string(s.value(symbol));
        output << value << std::endl;
      }
    } else {
      output << tmp << std::endl;
    }
  }
  return ;
}


int main(int argc, char* argv[])
{
  if (argc < 2) {
    printf("please enter the file you want to assemble!");
    exit(1);
  }
  std::string filename(argv[1]);
  std::string output;
  for (int i = 0; i < strlen(argv[1]); i ++) {
    if (argv[1][i] != '.') 
      output.push_back(argv[1][i]);
    else break;
  }
  std::string outfile = output.append(".hack");
  std::string tmpfile = output.append(".temp");

  std::ifstream file(filename, std::ios::in);
  std::ofstream out(outfile, std::ios::out);
  std::ofstream tmp(tmpfile, std::ios::out);
  if (!file.is_open() | !out.is_open() | !tmp.is_open()) {
    std::cerr << "cannot open the file" << std::endl;
    exit(1);
  }
  trans_symbol(file, tmp);
  tmp.close();
  std::ifstream tmp1(tmpfile, std::ios::in);
  trans_no_symbol(tmp1, out);
  unlink(tmpfile.c_str());
  file.close();
  out.close();
  tmp.close();
}
