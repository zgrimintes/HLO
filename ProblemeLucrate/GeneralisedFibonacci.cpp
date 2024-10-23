#include <iostream>

using namespace std;

int a, b, c;
int n, m;
int MOD;

class Matrix
{
public:
	long long mat[3][3];

	Matrix(int a, int b, int c) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				mat[i][j] = 0;

		mat[0][0] = a;
		mat[0][1] = b;
		mat[0][2] = c;
		mat[1][0] = 1;
		mat[2][2] = 1;
	}

	Matrix(int x) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				mat[i][j] = 0;

		mat[0][0] = mat[1][1] = mat[2][2] = x;
	}

	Matrix operator * (Matrix m2) {
		Matrix result(a, b, c);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result.mat[i][j] = 0;

				for (int k = 0; k < 3; k++)
					result.mat[i][j] = result.mat[i][j] + (mat[i][k] * m2.mat[k][j] % MOD);
			}
		}

		return result;
	}
};

Matrix binary_pow(Matrix x) {
	Matrix rasp(1);
	n -= 2;

	while (n)
	{
		if (n % 2)
			rasp = rasp * x;

		x = x * x;
		n /= 2;
	}

	return rasp;
}

void solve() {
	Matrix knMat(a, b, c);
	Matrix powMat(a, b, c);

	knMat.mat[0][0] = 1;
	knMat.mat[1][0] = 1;
	knMat.mat[2][0] = 1;

	powMat = binary_pow(powMat);

	Matrix result = (powMat * knMat);

	cout << result.mat[0][0] % MOD;
}

int main() {
	cin >> a >> b >> c >> n >> m;

	MOD = m;

	solve();

	return 0;
}

///GFG variant
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    class Matrix
    {
    public:
    	long long mat[3][3];
    	long long A, B, C;
    	long long MOD;
    
    	Matrix(long long a, long long b, long long c, long long m) {
    	    A = a;
    	    B = b;
    	    C = c;
    	    MOD = m;
    	    
    		for (int i = 0; i < 3; i++)
    			for (int j = 0; j < 3; j++)
    				mat[i][j] = 0;
    
    		mat[0][0] = a;
    		mat[0][1] = b;
    		mat[0][2] = c;
    		mat[1][0] = 1;
    		mat[2][2] = 1;
    	}
    
    	Matrix(long long x, long long a, long long b, long long c, long long m) {
    	    A = a;
    	    B = b;
    	    C = c;
    	    MOD = m;
    	    
    		for (int i = 0; i < 3; i++)
    			for (int j = 0; j < 3; j++)
    				mat[i][j] = 0;
    
    		mat[0][0] = mat[1][1] = mat[2][2] = x;
    	}
    
    	Matrix operator * (Matrix m2) {
    		Matrix result(A, B, C, MOD);
    
    		for (int i = 0; i < 3; i++) {
    			for (int j = 0; j < 3; j++) {
    				result.mat[i][j] = 0;
    
    				for (int k = 0; k < 3; k++)
    					result.mat[i][j] = result.mat[i][j] + (mat[i][k] * m2.mat[k][j] % MOD);
    			}
    		}
    
    		return result;
    	}
    };
  
    Matrix binary_pow(Matrix x, long long a, long long b, long long c, long long m, long long n) {
    	Matrix rasp(1, a, b, c, m);
    	n -= 2;
    
    	while (n)
    	{
    		if (n % 2)
    			rasp = rasp * x;
    
    		x = x * x;
    		n /= 2;
    	}
    
    	return rasp;
    }
  
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        Matrix knMat(a, b, c, m);
        Matrix powMat(a, b, c, m);
        
        knMat.mat[0][0] = 1;
        knMat.mat[1][0] = 1;
        knMat.mat[2][0] = 1;
        
        powMat = binary_pow(powMat, a, b, c, m, n);
        
        Matrix result = (powMat * knMat);
        
        return result.mat[0][0] % m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends
