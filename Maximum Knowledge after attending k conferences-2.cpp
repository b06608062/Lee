// Maximum Knowledge after attending k conferences
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long d;
  int n, k;
  if (!(cin >> d >> n >> k))
    return 0;

  vector<long long> s(n), e(n), a(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> e[i] >> a[i];
  }

  // 收集所有候選 day：所有 s[i] 和 e[i]
  vector<long long> cand;
  cand.reserve(2 * n);
  for (int i = 0; i < n; ++i) {
    cand.push_back(s[i]);
    cand.push_back(e[i]);
  }
  sort(cand.begin(), cand.end());
  cand.erase(unique(cand.begin(), cand.end()), cand.end());

  long long ans = 0;

  for (long long day : cand) {
    // day 一定在 [1, d]，因為 s,e 都在這個範圍
    vector<long long> vals;
    vals.reserve(n);

    // 找出在這一天可參加的會議
    for (int i = 0; i < n; ++i) {
      if (s[i] <= day && day <= e[i]) {
        vals.push_back(a[i]);
      }
    }

    if (vals.empty())
      continue;

    // 取其中最大的 k 個
    int m = vals.size();
    if (m <= k) {
      long long sum = 0;
      for (long long v : vals)
        sum += v;
      ans = max(ans, sum);
    } else {
      // 排序後取最後 k 個
      sort(vals.begin(), vals.end()); // 升序
      long long sum = 0;
      for (int i = m - 1; i >= m - k; --i) {
        sum += vals[i];
      }
      ans = max(ans, sum);
    }
  }

  cout << ans << '\n';
  return 0;
}
