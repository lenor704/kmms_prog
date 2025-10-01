#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, q, k, l, r, otv = 0;
    cout << "n q k" << endl;
    cin >> n >> q >> k;
    vector<int> v(n, 0);
    vector<int> a(k+1, 0);
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    for (int i = 0; i < n; i++)
        a[v[i]]++;
    
    for (int i = 1; i < k+1; i++)
        a[i] += a[i-1]; 

    for (int i = 0; i < q; i++) {
        cout << "l r" << endl;
        cin >> l >> r;
		if (l <= 0) 
			cout << a[r] << endl;
		else if (r > k && l > k) 
			cout << 0 << endl;
		else if (r > k) {
			r = k;
			cout << a[r] - a[l-1] << endl;
        } else 
			cout << a[r] - a[l-1] << endl;
    }

}
