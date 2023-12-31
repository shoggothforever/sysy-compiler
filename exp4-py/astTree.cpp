#include "astTree.h"
#include <string.h>
#include <iostream>
#include <fstream>

std::ofstream out_file;

void open_output_file(const std::string &filename)
{
  out_file.open(filename);
  if (!out_file.is_open())
  {
    std::cerr << "Error open file:" << filename << std::endl;
  }
}

void write_to_output(const std::string &text)
{
  std::cout << text;
  if (out_file.is_open())
  {
    out_file << text;
  }
}

void astTree::print()
{
  open_output_file("ast_output.txt");

  if (!this->root)
  {
    std::cout << "parse not complete!\n";
    return;
  }
  std::cout << "pre order print\n";
  if (!root->declByFlex)
  {
    write_to_output("layer: (" + std::to_string(1) + ") line: (" + std::to_string(root->line) + ") name: (" + root->name + ") val: " + root->val + "\n");
  }
  // std::cout<<"layer: "<<1<<" name:"<<root->name<<" val:"<<root->val<<"\n";
  this->root->print("", 2);
}

AstTree NewTree(Ast root)
{
  AstTree tree = new astTree(root);
  return tree;
}
class astNode;
astNode::astNode(string name, string val, int line) : line(line),
                                                      name(name),
                                                      val(val) {}
void astNode::print(string tab, int layer)
{
  std::string output_line;
  // if (this->childs.size() == 0)
  // {
  if (!this->declByFlex)
  {
    output_line = tab + "layer: (" + std::to_string(layer) + ") line: (" + std::to_string(this->line) + ") name: (" + this->name + ") val: " + this->val + "\n";
  }
  else
  {
    if (this->name == "Ident")
    {
      output_line = tab + "layer: (" + std::to_string(layer) + ") line: (" + std::to_string(this->line) + ") name: " + this->name + " val:" + this->val + "\n";
    }
    else
    {
      output_line = tab + "layer: (" + std::to_string(layer) + ") name: (" + this->name + ")\n";
    }
  }
  write_to_output(output_line);
  // }

  if (this->childs.size() == 1)
  {
    this->childs[0]->print(tab + " ", layer + 1);
  }
  else if (this->childs.size() > 1)
  {
    if (this->name.compare("CompUnit"))
    {
      for (auto v : this->childs)
      {
        v->print(tab + " ", layer + 1);
      }
    }
    else
    {
      for (auto v : this->childs)
      {
        v->print(tab, layer);
      }
    }
  }
}

Ast NewAst(string name, int line, int num, ...)
{
  Ast node = new astNode(name, name, line);
  // std::cout<<"create (key: "<<node->name<<" val: "<<node->val<<")\n";
  va_list list;
  va_start(list, num);
  Ast tmp;
  if (num > 0)
  {
    for (int i = 0; i < num; i++)
    {
      tmp = va_arg(list, Ast);
      // std::cout<<"insert (key: "<<tmp->name<<" val: "<<tmp->val<<") into parent (" <<node->name<<")\n";
      node->childs.push_back(tmp);
    }
  }
  va_end(list);

  return node;
}

Ast NewAst(string name, string val, int line, int num, ...)
{
  Ast node = new astNode(name, val, line);
  va_list list;
  va_start(list, num);
  Ast tmp;
  if (num > 0)
  {
    tmp = va_arg(list, Ast);
    node->childs.push_back(tmp);
  }

  return node;
}
string rc_string(RC rc)
{
  switch (rc)
  {
#define RETURNRCSTRING(name) \
  case name:                 \
    return #name;
    RETURNRCSTRINGS()
#undef RETURNRCSTRING
  default:
    return "UndefinedError";
  }
}
