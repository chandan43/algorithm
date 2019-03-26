#include <iostream>
using namespace std;
#include <string>

class SudokuSolver {
private:
	bool isvalid1(int in[9][9])
        {
		for(int r = 0; r < 9; r++) {
		    for(int c = 0; c < 9; c++) {
                        int d = in[r][c];
                        in[r][c] = 0;
                        if (!isvalid2(in, r, c ,d))
                            return false;
                        in[r][c] = d;
                    }
                }
            return true;
        }
	bool isvalid2(int in[9][9], int i, int j, int d)
	{
		for(int c = 0; c < 9; c++) {
			if(in[i][c] == d)
			    return false;
		}
		for(int r = 0; r < 9; r++) {
			if(in[r][j] == d)
			    return false;
		}
		int sr = (i/3)*3;
		int sc = (j/3)*3;
		for(int r = 0; r < 3; r++) {
			for(int c = 0; c < 3; c++) {
			 	if (in[r+sr][c+sc] == d)
					return false; 
			}
		}
		return true;
	} 
        void display(int in[9][9])
        {
		for(int r = 0; r < 9; r++) {
		    for(int c = 0; c < 9; c++) {
                        cout << in[r][c] << " ";
                    }
                    cout << endl;
                }
        
        }
	void auxsolver2(int i, int j, int in[9][9])
	{
                if (i == 9 ) {
                    display(in);
                    return;
                }
                    
		if (in[i][j] != 0)
			auxsolver2(j == 8 ? i+1 : i, (j + 1) % 9, in);
		else {
			for (int d = 1; d <= 9; ++d) {
				if(isvalid2(in, i, j, d)) {
					in[i][j] = d;
					auxsolver2(j == 8 ? i+1 : i, (j + 1) % 9, in);
				}
			}
                        in[i][j] = 0;
		}
					
	}
	void auxsolver1(int i, int j, int in[9][9])
	{
                if (i == 9 ) {
                    if (isvalid1(in))
                        display(in);
                    return;
                }
                    
		if (in[i][j] != 0)
			auxsolver1(j == 8 ? i+1 : i, (j + 1) % 9, in);
		else {
			for (int d = 1; d <= 9; ++d) {
				in[i][j] = d;
				auxsolver1(j == 8 ? i+1 : i, (j + 1) % 9, in);
			}
                        in[i][j] = 0;
		}
	}
public:
	void solver2(int in[9][9])
	{
		auxsolver2(0, 0, in);
	}
	void solver1(int in[9][9])
	{
		auxsolver1(0, 0, in);
	}
};

int main()
{
	int in[9][9] = { 
			{ 2, 7, 0, 0, 8, 0, 0, 5, 0 },
			{ 0, 0, 0, 3, 0, 2, 0, 0, 6 }, 
			{ 0, 0, 0, 0, 0, 1, 0, 0, 0 },
			{ 0, 8, 0, 0, 9, 0, 0, 0, 7 }, 
			{ 4, 0, 0, 0, 0, 0, 0, 8, 0 },
			{ 7, 0, 3, 0, 0, 0, 6, 0, 0 }, 
			{ 0, 1, 0, 0, 0, 0, 0, 0, 2 },
			{ 0, 0, 0, 0, 0, 5, 0, 0, 0 }, 
			{ 0, 0, 9, 6, 0, 8, 4, 1, 0 } 
	};

        SudokuSolver s;
        s.solver2(in);
        s.solver1(in);
}
