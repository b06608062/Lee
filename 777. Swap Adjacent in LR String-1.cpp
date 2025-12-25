class Solution {
public:
  bool canTransform(string start, string result) {
    int n = start.size(), m = result.size();
    if (n != m)
      return false;

    int i = 0, j = 0;
    while (true) {
      while (i < n && start[i] == 'X')
        i++;
      while (j < n && result[j] == 'X')
        j++;
      if (i == n && j == n)
        break;
      if (i == n || j == n)
        return false;
      if (start[i] != result[j])
        return false;
      if (start[i] == 'L' && j > i)
        return false;
      if (start[i] == 'R' && j < i)
        return false;
      i++, j++;
    }

    return true;
  }
};