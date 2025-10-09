class Solution {
public:
  string predictPartyVictory(string s) {
    queue<char> q;

    int cntR = 0, cntD = 0;
    for (char c : s) {
      q.push(c);
      if (c == 'R')
        cntR++;
      else
        cntD++;
    }

    int banR = 0, banD = 0;
    while (cntR && cntD) {
      char c = q.front();
      q.pop();
      if (c == 'R') {
        if (banR)
          banR--, cntR--;
        else {
          banD++;
          q.push('R');
        }
      } else {
        if (banD)
          banD--, cntD--;
        else {
          banR++;
          q.push('D');
        }
      }
    }

    return cntR ? "Radiant" : "Dire";
  }
};
