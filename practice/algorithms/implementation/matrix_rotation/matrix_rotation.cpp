#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> transfrom(const vector<vector<int>> & matrix, int num_rows, int num_cols)
{
    vector<vector<int>> res;
    int min_row = 0;
    int max_row = num_rows - 1;
    int min_col = 0;
    int max_col = num_cols - 1;
        
    while (min_row <= max_row && min_col <= max_col)
    {
        vector<int> tmp_row;
        for (int rn = min_row; rn < max_row; rn++)
        {
            tmp_row.push_back(matrix[rn][min_col]);
        }
        for (int cn = min_col; cn < max_col; cn++)
        {
            tmp_row.push_back(matrix[max_row][cn]);
        }
        for (int rn = max_row; rn > min_row; rn--)
        {
            tmp_row.push_back(matrix[rn][max_col]);
        }
        for (int cn = max_col; cn > min_col; cn--)
        {
            tmp_row.push_back(matrix[min_row][cn]);
        }
        res.push_back(tmp_row);
        
        min_row++;
        max_row--;
        min_col++;
        max_col--;
    }
        
    return res;
}
        
vector<vector<int>> inv_transfrom(const vector<vector<int>> & trans_matrix, int num_rows, int num_cols)
{
    vector<vector<int>> res(num_rows, vector<int>(num_cols));
    int min_row = 0;
    int max_row = num_rows - 1;
    int min_col = 0;
    int max_col = num_cols - 1;
    
    for (const auto & row : trans_matrix)
    {
        int cnt = 0;
        for (int rn = min_row; rn < max_row; rn++)
        {
            res[rn][min_col] = row[cnt];
            cnt++;
        }
        for (int cn = min_col; cn < max_col; cn++)
        {
            res[max_row][cn] = row[cnt];
            cnt++;
        }
        for (int rn = max_row; rn > min_row; rn--)
        {
            res[rn][max_col] = row[cnt];
            cnt++;
        }
        for (int cn = max_col; cn > min_col; cn--)
        {
            res[min_row][cn] = row[cnt];
            cnt++;
        }
        
        min_row++;
        max_row--;
        min_col++;
        max_col--;
    }
     
    return res;
}

vector<vector<int>> rotate(const vector<vector<int>> & trans_matrix, unsigned r)
{
    vector<vector<int>> res;
    for (const auto & row : trans_matrix)
    {
        auto crow = row;
        const size_t m = row.size();
        const size_t d = r % m;
        rotate(crow.begin(), crow.begin() + (m - d), crow.end());
        res.push_back(crow);
    }
    return res;
}

int main()
{
    unsigned m, n, r;
    cin >> m >> n >> r;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cin >> matrix[row][col];
        }
    }
    
    auto tmatrix = transfrom(matrix, m, n);
    auto rotated = rotate(tmatrix, r);
    auto res = inv_transfrom(rotated, m, n);
    
    for (const auto & row : res)
    {
        for (const auto & val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

