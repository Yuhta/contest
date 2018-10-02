#ifndef _DEBUG_HH_
#define _DEBUG_HH_

#define debug(...) \
  cerr << __FILE__ << ":" << __LINE__ << ": {" << #__VA_ARGS__ << "} = ", _debug(__VA_ARGS__)

string to_string(const char * s) {
  string ans = "\"";
  for (int i = 0; s[i]; i++) {
    if (s[i] == '"') ans += "\\\"";
    else ans += s[i];
  }
  ans += '"';
  return ans;
}

string to_string(char * s) {
  return to_string((const char *)s);
}

string to_string(const string & s) {
  return to_string(s.c_str());
}

template <typename A, typename B>
string to_string(const pair<A, B> & kv) {
  return "{" + to_string(kv.first) + "," + to_string(kv.second) + "}";
}

template <typename A>
string to_string(const A & xs) {
  string ans = "{";
  bool first = true;
  for (const auto & x: xs) {
    if (!first) ans += ',';
    first = false;
    ans += to_string(x);
  }
  ans += '}';
  return ans;
}

void _debug2() {
  cerr << '}' << endl;
}

template <typename Head, typename... Tail>
void _debug2(Head h, Tail... t) {
  cerr << ", " << to_string(h);
  _debug2(t...);
}

template <typename Head, typename... Tail>
void _debug(Head h, Tail... t) {
  cerr << '{' << to_string(h);
  _debug2(t...);
}

#endif
