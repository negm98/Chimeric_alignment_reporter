#include <iostream>
#include <string>
#include <fstream>
#include "read_class.h"
#include "table.h"
#include <stdlib.h>
using namespace std;

read store_read(string line);
int get_num_repr_reads();

int main(int argc, char** argv){


ifstream test_file(argv[1], ios::in);

if (test_file.is_open()) {

  string line;
  table file_table;

  while (getline(test_file, line)) {

      read line_read = store_read(line);

      string Qname = read.getQname;

      string cmd = "./get_num_repr_chim_line.sh " + Qname + " " + argv[1];

      system(cmd.c_str());

      int num_repr_reads = get_num_repr_reads();

      file_table.hashF(line_read, num_repr_reads);

  }

  test_file.close();
}

else {
  cerr << "Unable to open file\n";
}

  return 0;
}




read store_read(string line){
  string delimiter = "\t";
  string token;
  int pos;

  read dump_read;
  int field_counter = 0;

  while ((pos = line.find(delimiter)) != -1) {
      token = line.substr(0, pos);

      if(field_counter==0){
        dump_read.setQname(token);
      }
      else if(field_counter==1){
        dump_read.setFlag(stoi(token));
      }
      else if(field_counter==2){
        dump_read.setRname(token);
      }
      else if(field_counter==3){
        dump_read.setPos(stoi(token));
      }
      else if(field_counter==4){
        dump_read.setMapQ(stoi(token));
      }
      else if(field_counter==5){
        dump_read.setLen(stoi(token));
        break;
      }

      line.erase(0, pos + delimiter.length());
      field_counter++;
  }
  return dump_read;
}




int get_num_repr_reads(){

  int num_repr_reads;

ifstream one_read("num_rep_reads.txt", ios::in);
if (one_read.is_open()) {
  string line;
  while (getline(one_read, line)) {
    num_repr_reads = stoi(line);
  }
  one_read.close();
}
else {
  std::cerr << "Unable to open file\n";
}

  return num_repr_reads;
}
