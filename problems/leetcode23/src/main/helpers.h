vector<int> get_vectors(string line){
  vector<int> v;
  int i = 0;
  while (i < line.size()) {
    int j = i;
    while (j < line.size() && line[j] != ' ') {
      j++;
    }
    string s = line.substr(i, j - i);
    v.push_back(stoi(s));
    i = j + 1;
  }
  return v;
}