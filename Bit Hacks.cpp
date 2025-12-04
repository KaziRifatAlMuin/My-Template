#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ----- Basic Bit Operations -----
#define SetBit(x, k)      ( x |=  (1LL << (k)) )
#define ClearBit(x, k)    ( x &= ~(1LL << (k)) )
#define ToggleBit(x, k)   ( x ^=  (1LL << (k)) )
#define CheckBit(x, k)    ( ((x) >> (k)) & 1LL )

#define to_Binary(n)      ( bitset<8>(n).to_string() )
#define LowBit(x)         ( (x) & -(x) )                         // lowest 1-bit value
#define LowBitIndex(x)    ( __builtin_ctzll(x) )                 // index of lowest 1-bit
#define HighBitIndex(x)   ( 63 - __builtin_clzll(x) )            // index of highest 1-bit
#define CountBits(x)      ( __builtin_popcountll(x) )

// ----- Iterate Submasks (non-zero) -----
#define ForSubmask(s, m)  for (ll s = (m); s; s = (s - 1) & (m))

// ----- Iterate Supersets of m inside [0, 1<<n) -----
#define ForSuperset(s, m, n)  for (ll s = (m); s < (1LL << (n)); s = (s + 1) | (m))

// ----- Gosper's Hack — next mask with same popcount -----
inline ll NextCombination(ll x){
    ll u = x & -x;
    ll v = x + u;
    return v + (((v ^ x) / u) >> 2);
}

int main(){
    ll x = 42;                // 42 = 00101010
    SetBit(x, 3);             // expected: 00101010
    SetBit(x, 0);             // expected: 00101011
    ToggleBit(x, 3);          // expected: 00100011
    ClearBit(x, 0);           // expected: 00100010
    SetBit(x, 5);             // expected: 00100010
    cout << "Binary: " << to_Binary(x) << "\n";                // 00100010
    cout << "Lowest bit value: " << LowBit(x) << "\n";         // 2
    cout << "Lowest bit index: " << LowBitIndex(x) << "\n";    // 1
    cout << "Highest bit index: " << HighBitIndex(x) << "\n";  // 5
    cout << "Count bits: " << CountBits(x) << "\n";            // 2

    // Submask iteration example
    ll mask = 0b1101;        // 1101 (13)
    ForSubmask(s, mask) cout << to_Binary(s) << "\n";
    // expected: 00001101, 00001100, 00001001, 00001000, 00000101, 00000100, 00000001
    cout << to_Binary(0) << "\n";   // expected: 00000000
    // Next combination
    ll c = 0b0111;           // 0111 (7)
    cout << to_Binary(NextCombination(c)) << "\n";   // expected: 00001011
    // Superset iteration example (n = 4)
    ll m = 0b1101;           // 1101
    for(ll s = m; s < (1LL << 4); s = (s + 1) | m) cout << bitset<4>(s) << "\n";
    // expected: 1101, 1111
    return 0;
}