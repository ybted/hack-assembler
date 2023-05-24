#include "../parser.cpp"
#include <iostream>
#include <string>
using namespace std;
int main() {
  string expr = "M=D+1; JLE";
  parser p(expr);
  cout << "dest: " << p.dest() << endl;
  cout << "comp: " << p.comp() << endl;
  cout << "jump: " << p.jump() << endl;
  expr = "AM=D&M";
  p.change(expr);
  cout << "dest: " << p.dest() << endl;
  cout << "comp: " << p.comp() << endl;
  cout << "jump: " << p.jump() << endl;
  expr = "D; JMP";
  p.change(expr);
  cout << "dest: " << p.dest() << endl;
  cout << "comp: " << p.comp() << endl;
  cout << "jump: " << p.jump() << endl;
}